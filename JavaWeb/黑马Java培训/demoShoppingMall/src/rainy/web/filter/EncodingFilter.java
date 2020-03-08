package rainy.web.filter;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletRequestWrapper;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet Filter implementation class EncodingFilter
 */
public class EncodingFilter implements Filter {

	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
			throws IOException, ServletException {
		// 将request、response转成HttpServletRequest、HttpServletResponse
		HttpServletRequest req = (HttpServletRequest) request;
		HttpServletResponse resp = (HttpServletResponse) response;
		// pass the request along the filter chain
		chain.doFilter(new MyRequest(req), resp);
	}

	@Override
	public void destroy() {
		// TODO Auto-generated method stub

	}

	@Override
	public void init(FilterConfig arg0) throws ServletException {
		// TODO Auto-generated method stub

	}
}

/**
 * 对请求做包装，改写获取参数的方法
 * @author runlei
 */
class MyRequest extends HttpServletRequestWrapper {
	HttpServletRequest request;
	public MyRequest(HttpServletRequest request) {
		super(request);
		this.request = request;
	}

	@Override
	public String getParameter(String name) {
		if(name == null || name.equals("") || name.trim().equals(""))
			return null;
		String[] values = getParameterValues(name);
		// 注1
		if(values == null || values.length == 0)
			return null;
		return values[0];
	}

	@Override
	public String[] getParameterValues(String name) {
		if(name == null || name.equals("") || name.trim().equals(""))
			return null;
		Map<String, String[]> map = getParameterMap();
		if(map == null || map.size() == 0)
			return null;
		return map.get(name);
	}

	@Override
	public Map<String, String[]> getParameterMap() {
		// 判断提交的方法是post还是get
		String method = request.getMethod();
		// 注2
		if("post".equalsIgnoreCase(method)) {
			try {
				// 设置编码方式
				request.setCharacterEncoding("utf-8");
				return request.getParameterMap();
			} catch (UnsupportedEncodingException e) {
				e.printStackTrace();
			}
		}
		else if("get".equalsIgnoreCase(method)) {
			// 获取所有参数
			Map<String, String[]> map = request.getParameterMap();
			if (map == null) return null;
			// 存储处理后的参数
			Map<String, String[]> result = new HashMap<String, String[]>();
			// 获取默认的编码
			String charset = Charset.defaultCharset().name();
			// 对每个参数进行编码
			Set<String> keySet = map.keySet();
			// 注3
			for (String key : keySet) {
				String[] values = map.get(key);
				for (int i = 0; i < values.length; i++) {
					try {
						values[i] = new String(values[i].getBytes(charset), "utf-8");
					} catch (UnsupportedEncodingException e) {
						e.printStackTrace();
					}
				}
			}
			return map;
		}
		return super.getParameterMap();
	}
}

/* 
 * 注1：注意判断参数的合法性
 * 注2: equalsIgnoreCase()比equals()方法更严谨
 * 注3: 直接修改map里的valuse数组里的成员即可，不需要再重新创建map对象存储处理后的参数。
 * 测试：
 * 1. get方法，但是没有传递参数。request.getParameterMap()返回的内容是什么？
 */
