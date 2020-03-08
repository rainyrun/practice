package rainy.web.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import rainy.domain.Cart;
import rainy.service.CartService;
import rainy.service.impl.CartServiceImpl;
import rainy.web.base.BaseServlet;

/**
 * Servlet implementation class CartServlet
 */
public class CartServlet extends BaseServlet {
	private static final long serialVersionUID = 1L;
	CartService cartService = new CartServiceImpl();

	// 跳转到购物车
	public String toCart(HttpServletRequest request, HttpServletResponse response) {
		return "/jsp/cart.jsp";
	}

	// 添加商品到购物车
	public String addToCart(HttpServletRequest request, HttpServletResponse response) throws IOException {
		// 获取商品参数
		String pid = request.getParameter("pid");
		int num = Integer.parseInt(request.getParameter("num"));
		System.out.println("pid:" + pid + ";   num:" + num);
		// 获取购物车对象
		Cart cart = (Cart) request.getSession().getAttribute("cart");
		if(cart == null) {
			cart = new Cart();
		}
		// 将商品添加到购物车
		cartService.addToCart(cart, pid, num);
		// 将信息放回到前端
		request.getSession().setAttribute("cart", cart);
		// 跳转到购物车
		response.sendRedirect("jsp/cart.jsp");
		return null;
	}

	// 从购物车中删除商品
	public String deleteFromCart(HttpServletRequest request, HttpServletResponse response) {
		System.out.println("删除商品。。。");
		// 获取参数
		String pid = request.getParameter("pid");
		// 获取购物车对象
		Cart cart = (Cart) request.getSession().getAttribute("cart");
		// 将商品从购物车中删除
		cartService.deleteFromCart(cart, pid);
		// 将购物车传递给前端
		request.getSession().setAttribute("cart", cart);
		// 在ajax里刷新购物车界面
		return null;
	}

	// 修改商品数量
	public String modifyProduct(HttpServletRequest request, HttpServletResponse response) throws IOException {
		// 获取参数
		String pid = request.getParameter("pid");
		int num = Integer.parseInt(request.getParameter("num"));
		// 获取购物车对象
		Cart cart = (Cart) request.getSession().getAttribute("cart");
		// 修改商品数量
		cartService.modifyProduct(cart, pid, num);
		// 将购物车放在session作用域内
		request.getSession().setAttribute("cart", cart);
		return null;
	}

	// 清空购物车
	public String clear(HttpServletRequest request, HttpServletResponse response) {
		// 获取购物车对象
		Cart cart = (Cart) request.getSession().getAttribute("cart");
		// 清除购物车
		cartService.clear(cart);
		request.getSession().removeAttribute("cart");
		return "/jsp/cart.jsp";
	}
}
