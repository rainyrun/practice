package rainy.web.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import rainy.web.base.BaseServlet;

/**
 * 测试BaseServlet的功能
 */
public class TestBaseServlet extends BaseServlet {
	private static final long serialVersionUID = 1L;

	public String add(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		return "add";
	}

	public String delete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		return "delete";
	}

	public String query(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		return "query";
	}

	public String update(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		return "update";
	}

}
