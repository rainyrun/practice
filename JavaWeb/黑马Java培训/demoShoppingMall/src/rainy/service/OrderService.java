package rainy.service;

import rainy.domain.Cart;
import rainy.domain.Customer;
import rainy.domain.Order;
import rainy.domain.PageModel;

public interface OrderService {
	// 根据购物车中的信息，生成订单
	Order generateOrder(Cart cart, Customer cust);
	// 根据分页信息，获取对应的订单，生成PageModel
	PageModel getOrdersWithPage(Customer cust, int currentPage);
	// 获取到某个订单的信息
	Order getOrder(String oid);
}
