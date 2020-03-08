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
 * Servlet implementation class QueryStuServlet
 */
public class QueryStuServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// 获取参数
		request.setCharacterEncoding("utf-8");
		String queryByName = request.getParameter("queryByName");
		String queryBySex = request.getParameter("queryBySex");
//		String currentPage = request.getParameter("pageId");
		// 处理参数
		if(queryBySex.equals("--请选择--")) {
			queryBySex = null;
		}
		if(queryByName.equals(""))
			queryByName = null;
//		int pageId = 1;
//		if(currentPage != null) {
//			pageId = Integer.parseInt(currentPage);
//		}
		// 获取服务对象
		StudentService stuService = new StudentServiceImpl();
		// 得到查询出的结果
		List<Student> queryStudents = stuService.queryByNameAndSex(queryByName, queryBySex);
		request.setAttribute("students", queryStudents);
//		Manager<Student> stuManager = stuService.queryByNameAndSex(queryByName, queryBySex, pageId);
//		request.setAttribute("stuManager", stuManager);
		request.getRequestDispatcher("listStu.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
