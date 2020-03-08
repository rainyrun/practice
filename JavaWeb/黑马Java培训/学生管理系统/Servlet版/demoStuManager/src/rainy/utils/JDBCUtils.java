package rainy.utils;

import java.sql.*;
import javax.sql.DataSource;
import com.mchange.v2.c3p0.ComboPooledDataSource;

public class JDBCUtils {
	
	static ComboPooledDataSource dataSource = null;
	// 创建连接池，使用xml文件配置连接池
	static {
		dataSource = new ComboPooledDataSource();
	}
	
	public static Connection getConn() throws SQLException {
		Connection conn = dataSource.getConnection();
		return conn;
	}
	
	public static DataSource getDataSource() {
		return dataSource;
	}
}
