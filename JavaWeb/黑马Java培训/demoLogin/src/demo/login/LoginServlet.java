package demo.login;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

/**
 * 进入登录页面，输入用户名和密码。在数据库内查找是否有对应的用户名和密码
 *  有，重定向到主页。在ServletContext里添加属性count（表示登录人数）。
 *  没有，提示登录失败
 */
public class LoginServlet extends HttpServlet {
	static final String url = "jdbc:mysql://localhost/demoLogin";
	static final String name = "root";
	static final String psword = "bejavaer";

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		// 获取参数
		String username = req.getParameter("username");
		String password = req.getParameter("password");
		// 查询数据库
		Connection conn = null;
		Statement stmt = null;
		ResultSet rs = null;
		try {
			// 加载默认驱动
			Class.forName("com.mysql.cj.jdbc.Driver");
			// 建立连接
			conn = DriverManager.getConnection(url, name, psword);
			// 创建Statement
			stmt = conn.createStatement();
			// 创建查询语句
			String sql_check = "select * from user where username='" + username + "' and password='" + password + "';";
			// 获得结果
			rs = stmt.executeQuery(sql_check);
			if (rs.next()) {
				// 数据库内有对应的用户名和密码，登录成功，跳转到主页
				resp.sendRedirect("home");
				//添加count属性
				//注1
				ServletContext ctx = getServletContext();
				Object value = ctx.getAttribute("count");
				ctx.setAttribute("count", 1);
				if(value != null) {
					int temp = (int) value;
					ctx.setAttribute("count", temp + 1);
				}
			} else {
				// 登录失败
				resp.setContentType("text/html;charset=UTF-8");
				PrintWriter out = resp.getWriter();
				out.write("登录失败，如果未注册，请先注册");
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			// 关闭文件
			closeConn(conn);
			closeRs(rs);
			closeStmt(stmt);
		}
	}

	private void closeConn(Connection conn) {
		try {
			if (conn != null)
				conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			conn = null;
		}
	}
	
	private void closeStmt(Statement stmt) {
		try {
			if (stmt != null)
				stmt.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			stmt = null;
		}
	}
	
	private void closeRs(ResultSet rs) {
		try {
			if (rs != null)
				rs.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			rs = null;
		}
	}
}
/* 注1：web项目初始化后，就不能再添加ServletContext参数了，只能添加属性。
 */