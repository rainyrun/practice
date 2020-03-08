package rainy.dao.ipml;

import java.sql.SQLException;
import javax.sql.DataSource;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;
import rainy.dao.UserDao;
import rainy.domain.User;
import rainy.utils.JDBCUtils;

public class UserDaoImpl implements UserDao {

	@Override
	public boolean findUser(String username, String password) {
		// 获取资源
		DataSource dataSource = JDBCUtils.getDataSource();
		// 创建QueryRunner
		QueryRunner runner = new QueryRunner(dataSource);
		// 查询数据
		String sqlFind = "select * from user where username = ? and password = ?";
		try {
			User someone = null;
			Object[] params = { username, password };
			someone = runner.query(sqlFind, new BeanHandler<User>(User.class), params);
			// 可以查出用户
			if (someone != null)
				return true;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}

	@Override
	public void addUser(String username, String password) {
		// 前提是用户不在数据库内
		// 获取资源
		DataSource dataSource = JDBCUtils.getDataSource();
		// 创建QueryRunner
		QueryRunner runner = new QueryRunner(dataSource);
		// 查询数据
		String sqlInsert = "insert into user(uid, username, password) values(null, '" + username + "', '" + password + "');";
		try {
			runner.update(sqlInsert);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}

/*
 * 1. 先测试数据库是否能连通
 * 2. SQL语句不要忘记字符串要引起来
 */