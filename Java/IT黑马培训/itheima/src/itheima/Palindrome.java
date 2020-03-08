package itheima;
/**
 *需求：打印5位数中的所有回文数。如，12321，34643
 *分析：只要知道万、千、十位即可将回文数组合出来。
 */
public class Palindrome {
	public static void main(String[] args) {
		for(int i = 1; i < 10; i++)
			for(int j = 0; j < 10; j++)
				for(int k = 0; k < 10; k++)
					System.out.format("%d%d%d%d%d\n", i, j, k, j, i);
	}
}
