package rainy.dao;

public interface UserDao {
	/**
	 * 查找系统内是否有该用户
	 * @param username 用户名
	 * @param password 密码
	 * @return 是否存在此用户
	 */
	boolean findUser(String username, String password);
	/**
	 * 注册用户
	 * @param username 注册用户的用户名
	 * @param password 注册用户的密码
	 * @return 返回是否注册成功
	 */
	void addUser(String username, String password);
}
