package rainy.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import rainy.dao.StudentDao;
import rainy.dao.UserDao;
import rainy.dao.ipml.StudentDaoImpl;
import rainy.dao.ipml.UserDaoImpl;
import rainy.domain.Student;
import rainy.service.StudentService;
import rainy.service.UserService;
import rainy.service.impl.StudentServiceImpl;
import rainy.service.impl.UserServiceImpl;

/**
 * Servlet implementation class LoginServlet
 */
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// 获取参数
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		// 设置响应内容的编码方式
		response.setContentType("text/html;charset=utf-8");
		// 创建用户服务对象
		UserService userService = new UserServiceImpl();
		boolean result = userService.findUser(username, password);
		if(result) {
			response.sendRedirect("byPage");
		}
		else {
			// 提示登录失败
			response.getWriter().write("登录失败，请重试");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
