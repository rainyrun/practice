package rainy.web.base;

import java.io.IOException;
import java.lang.reflect.Method;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * 本项目所有servlet的父类。 1.
 * BaseServlet解析跳转链接内的method参数，并调用指定的方法执行。（method参数，指定要使用的方法名） 2.
 * 方法处理后，返回跳转路径，BaseServlet对跳转路径进行转发。
 */
public class BaseServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	// 跳转路径
	public String jspPath = null;

	@Override
	public void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// 获取参数
		String methodName = request.getParameter("method");
		// 处理参数
		if (methodName == null || methodName.equals("") || methodName.trim().equals(""))
			methodName = "execute";
		// 获取当前对象的class
		Class clazz = this.getClass();
		try {
			// 获取当前对象的mehodName指定的方法
			Method method = clazz.getMethod(methodName, HttpServletRequest.class, HttpServletResponse.class);
			// 有mehodName对应的方法
			jspPath = (String) method.invoke(this, request, response);
			System.out.println(method.getName() + ": path=" + jspPath);
		} catch (Exception e) {
			// 没有mehodName对应的方法
			jspPath = execute(request, response);
			System.out.println("execute: path=" + jspPath);
			e.printStackTrace();
		} finally {
			// 转发路径
			if (jspPath != null) {
				request.getRequestDispatcher(jspPath).forward(request, response);
			}
		}
	}

	public String execute(HttpServletRequest request, HttpServletResponse response) {
		String msg = "跳转路径错误";
		request.setAttribute("msg", msg);
		return "jsp/info.jsp";
	}
}

/*
 * method参数为空时，可以有2种处理方法：1. 指定方法为execute；2. 指定跳转路径为null。选择方法1比较合适，越早处理越好。
 */
