package rainy.web.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.alibaba.fastjson.JSON;

import rainy.domain.Category;
import rainy.domain.PageModel;
import rainy.domain.Product;
import rainy.service.CategoryService;
import rainy.service.impl.CategoryServiceImpl;
import rainy.utils.JedisUtils;
import rainy.web.base.BaseServlet;
import redis.clients.jedis.Jedis;

/**
 * Servlet implementation class CategoryServlet
 */
// 注2
public class CategoryServlet extends BaseServlet {
	private static final long serialVersionUID = 1L;
	private static CategoryService categoryService = new CategoryServiceImpl();
	private static String msg = "";

	// 处理获取分类信息的请求
	public String categories(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String jsonStr = "";
		Jedis j = JedisUtils.getJedis();
		// 注3
		jsonStr = j.get("categories");
		if (null == jsonStr || "".equals(jsonStr)) {
			System.out.println("缓存中没有数据");
			// 查询分类信息
			List<Category> categories = categoryService.getCategories();
			// 转换成JSON数组（注1）
			jsonStr = JSON.toJSONString(categories);
			// 存储到redis
			j.set("categories", jsonStr);
		} else {
			System.out.println("缓存中有数据");
		}
		// 返回响应(Ajax方式过来的请求，不用“重定向”或者“请求转发”)
		response.setContentType("application/json;charset=utf-8");
		response.getWriter().write(jsonStr);
		return null;
	}

	// 分类商品列表
	public String productsByCategory(HttpServletRequest request, HttpServletResponse response) {
		// 取得分类id
		String cid = request.getParameter("cid");
		// 获取页面id
		String currentPageStr = request.getParameter("currentPage");
		int currentPage = (currentPageStr == null) ? 1 : Integer.parseInt(currentPageStr);
		// 获取分类商品列表
		PageModel pageModel = categoryService.getProductsByCategory(cid, currentPage);
		// 存储到request作用域
		request.setAttribute("pageModel", pageModel);
		// 跳转
		return "jsp/productsByCategory.jsp";
	}

}
/*
 * 注1: categories == null 时，jsonStr == null 注2:
 * 在调试时一直出现405错误，即使直接拼写url也到不了categories方法。结果发现继承的类写成类HttpServlet而不是BaseServlet
 * 注3: 需要将redis服务器开启，才能正确连接到数据库
 */
