package rainy.utils;

import java.sql.Connection;
import java.sql.SQLException;

public class JDBCUtils {
	// 开启事务
	public static void startTrasaction(Connection conn) {
		try {
			// 关闭自动提交
			conn.setAutoCommit(false);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	// 关闭连接
	public static void closeConn(Connection conn) {
		try {
			if(conn != null)
				conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		conn = null;
	}
	// 回滚
	public static void rollBack(Connection conn) {
		try {
			conn.rollback();
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}
	// 提交事务
	public static void commit(Connection conn) {
		try {
			conn.commit();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
