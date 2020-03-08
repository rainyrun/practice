package rainy.service.impl;

import rainy.dao.UserDao;
import rainy.dao.ipml.UserDaoImpl;
import rainy.service.UserService;

public class UserServiceImpl implements UserService {

	@Override
	public boolean findUser(String username, String password) {
		// 创建数据对象
		UserDao user = new UserDaoImpl();
		// 查询结果
		return user.findUser(username, password);
	}

}
