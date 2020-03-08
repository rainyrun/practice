package rainy.web.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.alibaba.fastjson.JSON;

import rainy.domain.Category;
import rainy.service.CategoryService;
import rainy.service.impl.CategoryServiceImpl;
import rainy.utils.JedisUtils;
import rainy.utils.UUIDUtils;
import rainy.web.base.BaseServlet;
import redis.clients.jedis.Jedis;

/**
 * Servlet implementation class AdminCategoryServlet
 */
public class AdminCategoryServlet extends BaseServlet {
	private static final long serialVersionUID = 1L;
	private static CategoryService categoryService = new CategoryServiceImpl();

	// 获取分类信息
	public String getCategories(HttpServletRequest request, HttpServletResponse response) {
		List<Category> categories = categoryService.getCategories();
		request.setAttribute("categories", categories);
		return "/ManagementSystem/categoryList.jsp";
	}

	// 跳转到添加分类页面
	public String toAddCategory(HttpServletRequest request, HttpServletResponse response) {
		return "/ManagementSystem/addOrModifyCategory.jsp";
	}

	// 跳转到修改分类页面
	public String toModifyCategory(HttpServletRequest request, HttpServletResponse response) {
		// 获取cid参数
		String cid = request.getParameter("cid");
		// 获取cname
		String cname = request.getParameter("cname");
		// 传到前端
		request.setAttribute("cid", cid);
		request.setAttribute("cname", cname);
		return "/ManagementSystem/addOrModifyCategory.jsp";
	}

	// 添加或修改分类
	public String addOrModifyCategory(HttpServletRequest request, HttpServletResponse response) throws IOException {
		// 获取cid参数
		String cid = request.getParameter("cid");
		String cname = request.getParameter("cname");
		if (cid == null || cid.equals("")) {
			// 添加分类
			Category cate = new Category();
			cate.setCid(UUIDUtils.getId());
			cate.setCname(cname);
			categoryService.addCategory(cate);
		} else {
			// 修改分类
			Category cate = new Category();
			cate.setCid(cid);
			cate.setCname(cname);
			categoryService.updateCategory(cate);
		}
		// 删除redis中的缓存
		Jedis j = JedisUtils.getJedis();
		j.del("categories");
		// 跳转到分类列表
		response.sendRedirect("AdminCategoryServlet?method=getCategories");
		return null;
	}

	// 删除分类
	public String deleteCategory(HttpServletRequest request, HttpServletResponse response) throws IOException {
		String cid = request.getParameter("cid");
		boolean flag = categoryService.deleteCategory(cid);
		// 设置响应信息
		response.setContentType("text/html;charset=utf-8");
		if(flag) {
			// 删除成功
			response.getWriter().write("删除成功");
			// 删除redis中的缓存
			Jedis j = JedisUtils.getJedis();
			j.del("categories");
		}
		else {
			// 删除失败
			response.getWriter().write("删除失败，该分类下还有商品");
		}
		// ajax处理返回的信息
		return null;
	}
	
	// 获取分类，以json格式传给前端
	public String getCategoriesWithJson(HttpServletRequest request, HttpServletResponse response) throws IOException {
		List<Category> categories = categoryService.getCategories();
		String jsonStr = JSON.toJSONString(categories);
		response.setContentType("application/json;charset=utf-8");
		response.getWriter().write(jsonStr);
		return null;
	}

}
