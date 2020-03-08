package v1ch05.arrays;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.math.*;

public class CopyOfTest {
	public static void main(String[] args) {
		int[] a = {1, 2, 3, 5};
		String[] b = {"a", "ab", "abc"};
		
		a = (int[]) goodCopyOf(a, 5);
		System.out.println(Arrays.toString(a));
		
		b = (String[]) goodCopyOf(b, 5);
		System.out.println(Arrays.toString(b));
	}
	/**
	 * 改变一个数组的容量
	 * @param array 一个数组
	 * @param length 数组最终的长度
	 * @return 改变长度后的数组
	 */
	public static Object goodCopyOf(Object array, int length) {
		Class cl = array.getClass();
		if(!cl.isArray()) return null;
		
		Class componentType = cl.getComponentType();
		//创建新数组
		Object newArray = Array.newInstance(componentType, length);
		
		//复制
		int oldLength = Array.getLength(array);
		System.arraycopy(array, 0, newArray, 0, Math.min(length, oldLength));
		
		return newArray;
	}
}
