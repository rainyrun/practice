package rainy.dao.impl;

import java.sql.SQLException;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import rainy.dao.CustomerDao;
import rainy.domain.Customer;

public class CustomerDaoImpl implements CustomerDao {
	// 获取DataSource
	private static ComboPooledDataSource ds = new ComboPooledDataSource();
	// 创建queryRunner
	private static QueryRunner runner = new QueryRunner(ds);

	@Override
	public void add(Customer cust) {
		// 构造sql语句
		String sqlAdd = "insert into customer(uid, username, nickname, password, email, phone, birthday, sex, state, code) values(?,?,?,?,?,?,?,?,?,?);";
		// 添加到数据库
		Object[] params = { cust.getUid(), cust.getUsername(), cust.getNickname(), cust.getPassword(), cust.getEmail(),
				cust.getPhone(), cust.getBirthday(), cust.getSex(), cust.getState(), cust.getCode() };
		try {
			runner.update(sqlAdd, params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void deleteByUid(String uid) {
		// TODO Auto-generated method stub

	}

	@Override
	public void update(Customer cust) {
		// 构造sql语句
		String sqlUpdate = "update customer set username=?, nickname=?, password=?, email=?, phone=?, birthday=?, sex=?, state=?, code=? where uid=?;";
		Object[] params = { cust.getUsername(), cust.getNickname(), cust.getPassword(), cust.getEmail(),
				cust.getPhone(), cust.getBirthday(), cust.getSex(), cust.getState(), cust.getCode() ,cust.getUid() };
		// 更新数据
		try {
			runner.update(sqlUpdate,params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	@Override
	public Customer queryByCode(String code) {
		// 构造sql语句
		String sqlQueryByCode = "select * from customer where code=?;";
		// 返回查询结果
		Customer cust = null;
		try {
			Object[] params = {code};
			cust = runner.query(sqlQueryByCode, new BeanHandler<Customer>(Customer.class), params);
			return cust;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return cust;
	}

	@Override
	public Customer queryByPassword(String password) {
		// 构造sql语句
		String sqlQueryByPassword = "select * from customer where password=?";
		// 返回查询结果
		Customer cust = null;
		try {
			cust = runner.query(sqlQueryByPassword, new BeanHandler<Customer>(Customer.class), password);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return cust;
	}

}
