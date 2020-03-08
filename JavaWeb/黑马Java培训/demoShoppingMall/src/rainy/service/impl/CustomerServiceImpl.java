package rainy.service.impl;

import java.io.UnsupportedEncodingException;

import javax.mail.MessagingException;
import javax.mail.internet.AddressException;

import rainy.dao.CustomerDao;
import rainy.dao.impl.CustomerDaoImpl;
import rainy.domain.Customer;
import rainy.service.CustomerService;
import rainy.utils.MailUtils;

public class CustomerServiceImpl implements CustomerService {
	
	private static CustomerDao custDao = new CustomerDaoImpl();

	@Override
	public void update(Customer cust) {
		custDao.update(cust);
	}

	@Override
	public boolean active(String code) {
		Customer cust = custDao.queryByCode(code);
		if(cust == null) return false;
		// 设置用户状态为“已激活”
		cust.setState(1);
		cust.setCode("");
		// 更新用户信息
		custDao.update(cust);
		return true;
	}

	@Override
	public void register(Customer cust) {
		// 发送邮件到用户注册的邮箱
		try {
			MailUtils.sendMail(cust.getEmail(), cust.getCode());
		} catch (Exception e) {
			e.printStackTrace();
		} 
		// 注册用户到数据库
		custDao.add(cust);
	}

	@Override
	public void delete(String uid) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public Customer login(String name, String password) throws RuntimeException {
		Customer cust = custDao.queryByPassword(password);
		if(cust == null) {
			throw new RuntimeException("密码或用户名错误！");
		}
		if(cust != null && (cust.getUsername().equals(name) || cust.getNickname().equals(name) || cust.getPhone().equals(name))) 
			return cust;
		else {
			throw new RuntimeException("用户名错误！");
		}
			
	}

}
