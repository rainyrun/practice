package rainy.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import rainy.service.StudentService;
import rainy.service.impl.StudentServiceImpl;

/**
 * Servlet implementation class DelStuServlet
 */
public class DelStuServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		int sid = Integer.parseInt(request.getParameter("sid"));
		System.out.println(sid);
		StudentService stuService = new StudentServiceImpl();
		stuService.delete(sid);
		// 在回调函数内重定向
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
