package rainy.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import rainy.domain.Student;
import rainy.service.StudentService;
import rainy.service.impl.StudentServiceImpl;

/**
 * Servlet implementation class UpdateStuServlet
 */
public class GetStuServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// 获取参数
		String sid = request.getParameter("sid");
		StudentService stuService = new StudentServiceImpl();
		Student stu = stuService.queryById(Integer.parseInt(sid));
		request.setAttribute("stu", stu);
		request.getRequestDispatcher("updateStu.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
/*
 * 注意选择合适的作用域，stu适合放在request作用域
 */