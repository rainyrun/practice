package rainy.dao.impl;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanListHandler;
import org.apache.commons.dbutils.handlers.MapListHandler;
import org.apache.commons.dbutils.handlers.ScalarHandler;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import rainy.dao.OrderDao;
import rainy.domain.Customer;
import rainy.domain.Order;
import rainy.domain.OrderItem;
import rainy.domain.Product;
import rainy.utils.JDBCUtils;
import rainy.utils.MyBeanUtils;

public class OrderDaoImpl implements OrderDao {
	// DateSource
	private static ComboPooledDataSource ds = new ComboPooledDataSource();
	// QueryRunner
	private static QueryRunner runner = new QueryRunner(ds);

	@Override
	public void addOrder(Order order) {
		// sql语句。订单表：订单ID、下单时间、总金额、订单状态、收货地址、收货人、电话、用户ID（外键）
		String sqlAddOrder = "insert into `order` values(?, ?, ?, ?, ?, ?, ?, ?);";
		// 参数
		Object[] params = { order.getOid(), order.getOrdertime(), order.getTotal(), order.getState(),
				order.getAddress(), order.getName(), order.getPhone(), order.getCustomer().getUid() };
		// 执行sql
		Connection conn = null;
		try {
			// 添加订单需要使用事务，以保证订单和订单项能够一起添加成功。
			conn = ds.getConnection();
			// 开启事务
			JDBCUtils.startTrasaction(conn);
			runner.update(sqlAddOrder, params);
			// 遍历订单中的订单项，将订单项注册到数据库
			for (OrderItem item : order.getItems()) {
				addOrderItem(item);
			}
			// 提交
			JDBCUtils.commit(conn);
		} catch (SQLException e) {
			// 回滚
			JDBCUtils.rollBack(conn);
			e.printStackTrace();
		} finally {
			// 关闭连接
			JDBCUtils.closeConn(conn);
		}
	}

	@Override
	public void addOrderItem(OrderItem orderItem) throws SQLException {
		// sql语句。订单项：订单项ID、商品数量、价格小计、商品ID、订单ID（外键）
		String sqlAddOrderItem = "insert into orderitem values(?, ?, ?, ?, ?);";
		// 参数
		Object[] params = { orderItem.getItemid(), orderItem.getQuantity(), orderItem.getTotal(),
				orderItem.getProduct().getPid(), orderItem.getOrder().getOid() };
		// 执行
		runner.update(sqlAddOrderItem, params);
	}

	@Override
	public List<Order> queryOrdersByCustomerWithPage(Customer cust, int startIndex, int pageSize) {
		// 创建空的结果集
		List<Order> orders = null;
		// sql语句，查询cust用户对应的订单，以订单时间降序排列
		String sqlQueryOrdersByCustomerWithPage = "select * from `order` where uid = ? order by ordertime desc limit ?, ?;";
		// 参数
		Object[] params = { cust.getUid(), startIndex, pageSize };
		try {
			// 查询
			orders = runner.query(sqlQueryOrdersByCustomerWithPage, new BeanListHandler<Order>(Order.class), params);
			// 遍历每一个订单，查询订单中的订单项
			for (Order order : orders) {
				// 配置order中到Customer对象
				order.setCustomer(cust);
				// 查询order对应的订单项
				List<OrderItem> items = queryOrderItemsByOrder(order);
				// 将订单项加入到order中
				order.setItems(items);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return orders;
	}

	@Override
	public int queryOrderRecordsByCustomer(Customer cust) {
		// sql语句
		String sqlueryOrderRecordsByCustomer = "select count(*) from `order` where uid=?";
		// 执行
		Long result = 0L;
		try {
			result = (Long) runner.query(sqlueryOrderRecordsByCustomer, new ScalarHandler(), cust.getUid());
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return result.intValue();
	}

	@Override
	public List<OrderItem> queryOrderItemsByOrder(Order order) {
		// 结果集合
		List<OrderItem> items = new ArrayList<OrderItem>();
		// sql语句，查询订单对应的订单项，同时查出商品信息
		String sqlQueryOrderItemsByOrder = "select * from orderitem oi, product p where oi.pid = p.pid and oi.`oid` = ?";
		// 查询
		try {
			List<Map<String, Object>> result = runner.query(sqlQueryOrderItemsByOrder, new MapListHandler(),
					order.getOid());
			for (Map<String, Object> map : result) {
				// 装载OrderItem对象
				OrderItem item = new OrderItem();
				MyBeanUtils.populate(item, map);
				// 装载Product对象
				Product product = new Product();
				MyBeanUtils.populate(product, map);
				// 配置OrderItem，并加入到结果集合
				item.setProduct(product);
				item.setOrder(order);
				// 需要手动计算“小计”
				item.setTotal();
				items.add(item);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}

		return items;
	}

	@Override
	public Order queryOrder(String oid) {
		// sql语句，查询订单及对应的用户
		String sqlQueryOrder = "select * from `order` o, customer c where o.uid = c.uid and `oid` = ?;";
		// 执行
		Order order = null;
		try {
			// 因一个oid对应一个订单，所以result数组只有一个map元素
			List<Map<String, Object>> result = runner.query(sqlQueryOrder, new MapListHandler(), oid);
			// 装载Order对象
			order = new Order();
			MyBeanUtils.populate(order, result.get(0));
			// 装载Customer对象
			Customer cust = new Customer();
			MyBeanUtils.populate(cust, result.get(0));
			// 配置order对象
			order.setCustomer(cust);
			// 查询订单对应的订单项
			List<OrderItem> items = queryOrderItemsByOrder(order);
			order.setItems(items);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return order;
	}
}
