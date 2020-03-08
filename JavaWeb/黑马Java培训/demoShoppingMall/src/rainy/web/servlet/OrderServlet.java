package rainy.web.servlet;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import rainy.domain.Cart;
import rainy.domain.Customer;
import rainy.domain.Order;
import rainy.domain.PageModel;
import rainy.service.OrderService;
import rainy.service.impl.OrderServiceImpl;
import rainy.web.base.BaseServlet;

/**
 * Servlet implementation class OrderServlet
 */
public class OrderServlet extends BaseServlet {
	private static final long serialVersionUID = 1L;
	
	OrderService orderService = new OrderServiceImpl();
	
	// 购物车的“提交订单” --> 订单详情页
	public String toOrder(HttpServletRequest request, HttpServletResponse response) {
		// 获取购物车中的商品
		HttpSession session = request.getSession();
		Cart cart = (Cart) session.getAttribute("cart");
		if(cart == null || cart.getCartItems().size() == 0) {
			// 如果没有商品，则提示“请先添加商品到购物车”
			request.setAttribute("msg", "请先添加商品到购物车");
			return "/jsp/info.jsp";
		}
		// 获取登录用户
		Customer cust = (Customer) session.getAttribute("loginCustomer");
		if(cust == null) {
			// 用户没有登录
			request.setAttribute("msg", "请先登录");
			return "/jsp/info.jsp";
		}
		// 生成订单(清空购物车）
		Order order = orderService.generateOrder(cart, cust);
		// 将订单信息放到request作用域
		session.setAttribute("cart", cart);
		request.setAttribute("order", order);
		// 跳转到订单提交页
		return "/jsp/orderInfo.jsp";
	}
	
	// 导航条的“我的订单” --> 订单列表页
	public String toOrderList(HttpServletRequest request, HttpServletResponse response) {
		// 获取到用户(用户此时肯定已登录)
		Customer cust = (Customer) request.getSession().getAttribute("loginCustomer");
		// 获取到页面号
		int currentPage = Integer.parseInt(request.getParameter("currentPage"));
		// 获取到该用户订单的pageModel
		PageModel pageModel = orderService.getOrdersWithPage(cust, currentPage);
		if(pageModel == null) {
			// 用户没有订单
			request.setAttribute("msg", "您还没有订单～");
			return "/jsp/orderList.jsp";
		}
		// 将信息存储到request作用域内
		request.setAttribute("pageModel", pageModel);
		// 跳转到订单列表页
		return "/jsp/orderList.jsp";
	}
	
	// 订单列表的“去付款”按钮 --> 订单详情页
	public String toOrderInfo(HttpServletRequest request, HttpServletResponse response) {
		// 获取订单号
		String oid = request.getParameter("oid");
		// 查询订单信息
		Order order = orderService.getOrder(oid);
		// 存储在request作用域
		request.setAttribute("order", order);
		// 跳转到订单详情页
		return "/jsp/orderInfo.jsp";
	}
}
