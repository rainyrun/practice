package itheima;

/**
 * 需求 
 * 1. 定义一个int类型的一维数组，内容为{171, 72, 19, 16, 118, 51, 210, 7, 18} 
 * 求出数组中满足要求的元素的和。要求，求和的元素的个位和十位不能包括7，并且只能为偶数。 
 * 分析 
 * 1. 遍历数组，依次求和，将满足要求的元素依次相加
 */
public class GetSum {
	private static boolean isCertified(int a) {
		boolean flag = true;
		if (a % 2 == 1 || a % 10 == 7 || a / 10 % 10 == 7)
			flag = false;
		return flag;
	}

	public static void main(String[] args) {
		int[] array = { 171, 72, 19, 16, 118, 51, 210, 7, 18 };
		int sum = 0;
		for (int i = 0; i < array.length; i++)
			if (isCertified(array[i])) {
				sum += array[i];
			}
		System.out.println(sum);
	}
}
