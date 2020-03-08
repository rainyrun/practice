package rainy.web.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.alibaba.fastjson.JSON;

import rainy.domain.Product;
import rainy.service.ProductService;
import rainy.service.impl.ProductServiceImpl;
import rainy.web.base.BaseServlet;

/**
 * Servlet implementation class ProductServlet
 */
public class ProductServlet extends BaseServlet {
	private static final long serialVersionUID = 1L;
	private static ProductService prodService = new ProductServiceImpl();
	private static String msg = "";
       
	public String hotProducts(HttpServletRequest request, HttpServletResponse response) throws IOException {
		// 获取前9个热门商品
		List<Product> hotProducts = prodService.getHotProducts();
		// 转成json字符串
		String jsonStr = JSON.toJSONString(hotProducts);
		// 传递给前端
		response.setContentType("application/json;charset=utf-8");
		response.getWriter().write(jsonStr);
		return null;
	}
	
	public String productByPid(HttpServletRequest request, HttpServletResponse response) {
		// 获取参数pid
		String pid = request.getParameter("pid");
		// 根据pid获取商品
		Product prod = prodService.getProductByPid(pid);
		// 将商品存入request作用域
		if(prod != null) {
			// 能够找到对应的商品
			request.setAttribute("product", prod);
			// 跳转到商品详情页
			return "jsp/product.jsp";
		}
		msg = "商品ID有误";
		request.setAttribute("msg", msg);
		return "/jsp/info.jsp";
	}

	

}
