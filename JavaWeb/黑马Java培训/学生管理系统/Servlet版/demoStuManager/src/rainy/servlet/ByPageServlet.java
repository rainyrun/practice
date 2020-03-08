package rainy.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import rainy.domain.Manager;
import rainy.domain.Student;
import rainy.service.StudentService;
import rainy.service.impl.StudentServiceImpl;

/**
 * Servlet implementation class ByPageServlet
 */
public class ByPageServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		int pageId = 1;
		// 获取参数
		String currentPage = request.getParameter("pageId");
		if(currentPage != null)
			pageId = Integer.parseInt(currentPage);
		// 获取学生服务
		StudentService stuService = new StudentServiceImpl();	
		Manager<Student> stuManager = stuService.queryByPage(pageId);
		// 传递结果
		request.getSession().setAttribute("stuManager", stuManager);
		// 显示页面
		request.getRequestDispatcher("listByPage.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
