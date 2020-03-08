package rainy.service;

import rainy.domain.Customer;

public interface CustomerService {
	/**
	 * 将用户注册到数据库
	 * @param cust 需要注册的用户
	 */
	void register(Customer cust);
	/**
	 * 根据uid注销用户
	 * @param uid
	 */
	void delete(String uid);
	/**
	 * 更新用户信息
	 * @param cust 用户信息
	 */
	void update(Customer cust);
	/**
	 * 查找激活码code对应的用户，并激活
	 * @param code 激活码
	 * @return 是否激活成功
	 */
	boolean active(String code);
	/**
	 * 根据用户名&昵称&手机号、密码，返回对应的用户，null表示没有此用户
	 * @param name 用户名&昵称&手机号
	 * @param password 密码
	 * @return 找到的用户
	 * @throws RuntimeException 
	 */
	Customer login(String name, String password) throws RuntimeException;

}
