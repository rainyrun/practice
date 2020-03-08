package rainy.service;

public interface UserService {
	/**
	 * 查找用户是否存在
	 * @param username 用户名
	 * @param password 密码
	 * @return 返回是否存在
	 */
	boolean findUser(String username, String password);

}
