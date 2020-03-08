package v1ch06.proxy;

import java.lang.reflect.*;
import java.util.*;

/**
 * 创建一个数组，使用二分查找从数组中找出某个值（由随机数产生），使用代理记录查找过程。
 * 代理输出的信息为：当前对象的值.调用方法(参数)
 *
 */
public class ProxyTest {
	public static void main(String[] args) {
		// 创建数组
		Object[] array = new Object[1000];
		// 初始化数组，使用代理对象
		for(int i = 0; i < array.length; i++) {
			Integer value = i + 1;
			InvocationHandler handler = new TraceHandler(value);
			Object proxy = Proxy.newProxyInstance(null, new Class[] {Comparable.class}, handler);
			array[i] = proxy;
		}
		// 产生目标数值
		Integer key = new Random().nextInt(array.length) + 1;
		// 使用二分查找找出目标数值
		int result = Arrays.binarySearch(array, key);
		// 打印目标数值
		if(result >= 0)
			System.out.println(array[result]);
	}
}

class TraceHandler implements InvocationHandler{
	// 要代理的对象
	private Object target;

	public TraceHandler(Object t) {
		target = t;
	}

	@Override
	public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
		// 打印当前对象
		System.out.print(target);
		// 打印调用的方法
		System.out.print("." + method.getName() + "(");
		// 打印方法的参数
		if(args != null) {
			for(int i = 0; i < args.length; i++) {
				System.out.print(args[i]);
				if(i < args.length - 1)
					System.out.print(", ");
			}
		}
		System.out.println(")");
		return method.invoke(target, args);
	}
	
}
