package rainy.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import rainy.dao.UserDao;
import rainy.dao.ipml.UserDaoImpl;

/**
 * Servlet implementation class LogupServlet
 */
public class LogupServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// 获取参数
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		
		response.setContentType("text/html;charset=utf-8");
		
		// 创建数据对象
		UserDao user = new UserDaoImpl();
		// 查找用户是否存在
		if(user.findUser(username, password)) {
			response.getWriter().write("用户已存在");
		}
		else {
			user.addUser(username, password);
			response.getWriter().write("注册成功，请登录");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
