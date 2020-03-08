package rainy.servlet;

import java.io.IOException;
import java.util.Arrays;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import rainy.domain.Student;
import rainy.service.StudentService;
import rainy.service.impl.StudentServiceImpl;

/**
 * Servlet implementation class AddStuServlet
 */
public class UpdateStuServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		Student stu = new Student();
		request.setCharacterEncoding("utf-8");
		// 设置学生信息
		stu.setSid(Integer.parseInt(request.getParameter("sid")));
		stu.setSname(request.getParameter("sname"));
		stu.setSex(request.getParameter("sex"));
		stu.setPhone(request.getParameter("phone"));
		stu.setDescript(request.getParameter("descript"));
		// 处理hobby
		String[] hobbys = request.getParameterValues("hobby");
		String hobby = Arrays.toString(hobbys);
		stu.setHobby(hobby.substring(1, hobby.length() - 1));
		// 创建学生服务对象
		StudentService stuService = new StudentServiceImpl();
		stuService.update(stu);
		// 跳转到首页
		response.sendRedirect("byPage");
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
