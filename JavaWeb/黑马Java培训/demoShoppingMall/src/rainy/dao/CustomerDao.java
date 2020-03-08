package rainy.dao;

import rainy.domain.Customer;

public interface CustomerDao {
	/**
	 * 将用户添加到数据库
	 * @param cust
	 */
	void add(Customer cust);
	/**
	 * 根据uid删除用户
	 * @param uid
	 */
	void deleteByUid(String uid);
	/**
	 * 更新用户信息
	 * @param cust
	 */
	void update(Customer cust);
	/**
	 * 根据激活码查找用户
	 * @param code 激活码
	 * @return 找到的用户，null表示没有找到
	 */
	Customer queryByCode(String code);
	/**
	 * 根据密码查找用户
	 * @param password 密码
	 * @return 找到的用户，null表示没有找到
	 */
	Customer queryByPassword(String password);

}
