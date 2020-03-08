package rainy.dao;

import java.sql.SQLException;
import java.util.List;

import rainy.domain.Customer;
import rainy.domain.Order;
import rainy.domain.OrderItem;

public interface OrderDao {
	// 添加订单
	void addOrder(Order order);
	// 添加订单项
	void addOrderItem(OrderItem orderItem) throws SQLException;
	// 查询某用户的某页的订单
	List<Order> queryOrdersByCustomerWithPage(Customer cust, int startIndex, int pageSize);
	// 查询某用户的订单总数
	int queryOrderRecordsByCustomer(Customer cust);
	// 查询某订单的所有订单项
	List<OrderItem> queryOrderItemsByOrder(Order order);
	// 查询某个订单的信息
	Order queryOrder(String oid);
}
