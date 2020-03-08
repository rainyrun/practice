package rainy.web.servlet;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.commons.beanutils.BeanUtils;

import rainy.domain.Customer;
import rainy.service.CustomerService;
import rainy.service.impl.CustomerServiceImpl;
import rainy.utils.MyBeanUtils;
import rainy.utils.UUIDUtils;
import rainy.web.base.BaseServlet;

/**
 * Servlet implementation class CustomerServlet
 */
public class CustomerServlet extends BaseServlet {
	private static final long serialVersionUID = 1L;
	// 用户服务对象
	private static CustomerService custService = new CustomerServiceImpl();
	private static String msg = null;
	
	/**
	 * 跳转到注册页面
	 * 
	 * @param request
	 * @param response
	 * @return 跳转路径
	 */
	public String toRegister(HttpServletRequest request, HttpServletResponse response) {
		return "/jsp/register.jsp";
	}

	/**
	 * 跳转到登录页面
	 * 
	 * @param request
	 * @param response
	 * @return 跳转路径
	 */
	public String toLogin(HttpServletRequest request, HttpServletResponse response) {
		return "/jsp/login.jsp";
	}

	/**
	 * 接收表单数据，处理注册逻辑
	 * 
	 * @param request
	 * @param response
	 * @return 跳转路径
	 */
	public String register(HttpServletRequest request, HttpServletResponse response) {
		System.out.println("调用了Customer：register方法");
		// 接收参数
		Map<String, String[]> paramsMap = request.getParameterMap();
		// 将参数转换为Customer对象
		Customer customer = new Customer();
		try {
			MyBeanUtils.populate(customer, paramsMap);
		} catch (Exception e) {
			e.printStackTrace();
		}
		// 部分数据需要手动构造
		customer.setUid(UUIDUtils.getId());
		customer.setCode(UUIDUtils.getCode());
		// 将Customer对象注册到数据库
		custService.register(customer);
		// 转发页面
		msg = "注册成功，激活码已发送到您邮箱，请激活！";
		request.setAttribute("msg", msg);
		return "/jsp/info.jsp";
	}

	public String active(HttpServletRequest request, HttpServletResponse response) {
		String code = request.getParameter("code");
		System.out.println(code);
		boolean flag = custService.active(code);
		if (flag) {
			// 激活成功
			msg = "激活成功";
		} else
			msg = "激活失败";
		request.setAttribute("msg", msg);
		return "/jsp/info.jsp";
	}

	public String login(HttpServletRequest request, HttpServletResponse response) {
		// 获取用户名&昵称&手机号
		String name = request.getParameter("name");
		// 获取密码
		String password = request.getParameter("password");
		// 查找是否有对应的用户
		Customer cust = null;
		try {
			cust = custService.login(name, password);
		} catch (Exception e) {
			// 没找到，则提示登录失败原因
			msg = e.getMessage();
			request.setAttribute("msg", msg);
			System.out.println("登录失败原因：" + msg);
		}
		// 将用户对象存入session
		if(cust != null) {
			request.getSession().setAttribute("loginCustomer", cust);
			// 设置session生存时间
			HttpSession session = request.getSession();
			session.setMaxInactiveInterval(60*60*24);
			// 将sessionid保持到cookie里
			String id = session.getId();
			Cookie cookie = new Cookie("JSESSIONID", id);
			cookie.setMaxAge(60*60*24);//1day
			response.addCookie(cookie);
			// 跳转到首页，显示用户信息
			return "/jsp/index.jsp";
		}
		return "/jsp/login.jsp";
	}
	
	public String logout(HttpServletRequest request, HttpServletResponse response) {
		// 删除loginCustomer属性
		request.getSession().invalidate();
//		Customer cust = (Customer) request.getSession().getAttribute("loginCustomer");
//		if(cust != null)
//			request.getSession().removeAttribute("loginCustomer");
		// 跳转到首页
		return "/jsp/index.jsp";
	}
}
