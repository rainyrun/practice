package rainy.utils;

import java.lang.reflect.InvocationTargetException;
import java.util.Date;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.beanutils.ConvertUtils;
import org.apache.commons.beanutils.Converter;
import org.apache.commons.beanutils.converters.DateConverter;
import org.apache.commons.beanutils.converters.DateTimeConverter;
import org.apache.commons.beanutils.locale.converters.DateLocaleConverter;

import rainy.domain.Customer;

public class MyBeanUtils {

	/**
	 * 由于BeanUtils将字符串"1992-3-3"向Customer对象的setBirthday()方法传递参数有问题，需要手动向BeanUtils注册一个时间类型转换器
	 * 本方法自定义了一个转化器
	 * 
	 * @param obj
	 * @param map
	 */
	public static void myPopulate(Object obj, Map<String, String[]> map) {
		try {
			// 注册自定义的转换器
			ConvertUtils.register(new Converter() {
				@Override
				public Object convert(Class type, Object value) {
					Object result = null;
					// 参数合法性判断
					if (type != java.util.Date.class) {
						return result;
					}
					if (value == null || "".equals(value.toString().trim())) {
						return result;
					}
					// 字符串转换为日期
					SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
					try {
						result = sdf.parse(value.toString());
					} catch (ParseException e) {
						e.printStackTrace();
					}
					return result;
				}
			}, java.util.Date.class);
			// 将参数填充到obj对象
			BeanUtils.populate(obj, map);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * 由于BeanUtils将字符串"1992-3-3"向Customer对象的setBirthday()方法传递参数有问题，需要手动向BeanUtils注册一个时间类型转换器
	 * 使用BeanUtils自带的时间转换器
	 * @param <T>
	 * @param obj
	 * @param map
	 */
	public static <T> void populate(Object obj, Map<String, T> map) {
		try {
			// 1_创建时间类型的转换器
			DateConverter dt = new DateConverter();
			// 2_设置转换的格式
			dt.setPattern("yyyy-MM-dd");
			// 3_注册转换器
			ConvertUtils.register(dt, java.util.Date.class);
			// 将参数填充到obj对象
			BeanUtils.populate(obj, map);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		Customer day = new Customer();
		String date = "1992-07-13";

		Map<String, String[]> map = new HashMap<String, String[]>();
		map.put("birthday", new String[] { date });
		try {
			MyBeanUtils.populate(day, map);
		} catch (Exception e) {
			e.printStackTrace();
		}
		// 拷贝日期到对象中
		System.out.println(day.getBirthday());
	}
}
