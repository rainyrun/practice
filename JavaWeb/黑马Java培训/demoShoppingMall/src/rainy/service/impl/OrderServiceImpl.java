package rainy.service.impl;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import rainy.dao.OrderDao;
import rainy.dao.impl.OrderDaoImpl;
import rainy.domain.Cart;
import rainy.domain.CartItem;
import rainy.domain.Customer;
import rainy.domain.Order;
import rainy.domain.OrderItem;
import rainy.domain.PageModel;
import rainy.service.OrderService;
import rainy.utils.UUIDUtils;

public class OrderServiceImpl implements OrderService {
	
	OrderDao orderDao = new OrderDaoImpl();

	@Override
	public Order generateOrder(Cart cart, Customer cust) {
		// 前提：购物车不为空
		// 创建一个新订单
		Order order = new Order();
		// 配置订单
		order.setOid(UUIDUtils.getId());
		order.setOrdertime(new Date());
		order.setState(1);
		order.setCustomer(cust);
		List<OrderItem> items = new ArrayList<OrderItem>();
		order.setItems(items);
		// 遍历购物车中的购物项，生成订单项
		for (CartItem cartItem : cart.getValues()) {
			// 创建新的订单项
			OrderItem orderItem = new OrderItem(cartItem.getProd(), cartItem.getNum());
			// 加入到订单项列表
			items.add(orderItem);
			// 配置订单项
			orderItem.setItemid(UUIDUtils.getId());
			orderItem.setOrder(order);
		}
//		// 测试：打印Order中的信息
//		System.out.println(order);
//		for (OrderItem orderItem : order.getItems()) {
//			System.out.println("    " + orderItem);
//		}
		// 清空购物车
		cart.clear();
		// 将订单注册到数据库
		orderDao.addOrder(order);
		return order;
	}

	@Override
	public PageModel getOrdersWithPage(Customer cust, int currentPage) {
		// 查询cust用户对应的订单有多少条
		int orderRecords = orderDao.queryOrderRecordsByCustomer(cust);
		if(orderRecords == 0) {
			// 该用户没有订单
			return null;
		}
		// 生成pageModel
		PageModel pageModel = new PageModel(currentPage, orderRecords);
		// 配置pageModel
		pageModel.setPageSize(3);
		pageModel.setUrl("OrderServlet?method=toOrderList");
		// 查询本页对应的订单
		List<Order> orders = orderDao.queryOrdersByCustomerWithPage(cust, pageModel.getStartIndex(), pageModel.getPageSize());
		pageModel.setRecords(orders);
		return pageModel;
	}

	@Override
	public Order getOrder(String oid) {
		return orderDao.queryOrder(oid);
	}

}
