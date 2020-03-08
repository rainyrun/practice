package demo.login;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

/**
 * 注册页提交表单信息后，进入注册页的servlet。
 * 该servlet判断表单信息是否符合要求（密码不少于6位）
 * 		符合要求，重定向到登录页面。并将数据写入数据库
 * 		不符合要求，提示注册失败
 */
public class SignUpServlet extends HttpServlet{
	static final String url = "jdbc:mysql://localhost/demoLogin";
	static final String user = "root";
	static final String passwd = "bejavaer";
	
	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		//获取表单数据
		String username = req.getParameter("username");
		String password = req.getParameter("password");
		System.out.println("username: " + username + "; password: " + password);
		//设置响应内容
		//指定输出到客户端时使用的编码
		resp.setContentType("text/html;charset=UTF-8");
		PrintWriter out = resp.getWriter();
		//判断密码长度
		if(password.length() < 6 || username.length() < 1) {
			out.write("注册失败，请重新尝试。密码长度需大于等于6，用户名长度需大于等于1");
		}
		else {
			//写进数据库
			ResultSet rs = null;
			Connection conn = null;
			Statement stmt = null;
			try {
				//启动默认驱动
				Class.forName("com.mysql.cj.jdbc.Driver");
				//获得连接
				conn = DriverManager.getConnection(url, user, passwd);
				//将数据插入user表
				stmt = conn.createStatement();
				String sql_check = "select * from user where username='" + username +"' and password='" + password +"';";
				rs = stmt.executeQuery(sql_check);
				System.out.println("查询结束");
				if(!rs.next()) {//数据库中没有该用户名和密码，则插入到表中
					System.out.println("开始插入");
					//注1
					String sql_insert = "insert into user(id, username, password) values(null, '" + username + "', '" + password +"');";
					int i = stmt.executeUpdate(sql_insert);
					if(i < 1)
						System.out.println("插入失败");
					else
						System.out.println("插入成功");
				}
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				closeRs(rs);
				closeStmt(stmt);
				closeConn(conn);
			}
			
			//重定向到登录页面
			resp.sendRedirect("login.html");
		}
	}
	
	private static void closeRs(ResultSet rs) {
		try {
			if (rs != null) {
				rs.close();
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			rs = null;
		}
	}
	
	private static void closeStmt(Statement stmt) {
		try {
			if (stmt != null) {
				stmt.close();
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			stmt = null;
		}
	}
	
	private static void closeConn(Connection conn) {
		try {
			if (conn != null) {
				conn.close();
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			conn = null;
		}
	}
}

/* 注1：sql语句在查询某字段时，记得加上单引号。
 */
