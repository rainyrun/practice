package demo.login;

import java.io.*;

import javax.servlet.*;
import javax.servlet.http.*;

public class HomeServlet extends HttpServlet{
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		//获取ServletContext中的count字段
		ServletContext ctx = getServletContext();
		Object value = ctx.getAttribute("count");
		resp.setContentType("text/html");
		PrintWriter out = resp.getWriter();
		out.write("<h1>Welcome</h1><p>you are the " + value + " people login.</p>");
	}

}
