package v1ch03.bigIntegerTest;

import java.util.Scanner;
import java.math.*;

/**
 * 功能：对LotteryOdds的改进，可以使用大数值进行运算。如从 490 个可能的数值中抽取 60 个。
 */
public class BigIntegerTest {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		//询问从多少个数字中选
		System.out.println("How many numbers you need?");
		int nums = in.nextInt();
		//中奖号码有多少个数字
		System.out.println("How long the Lottery is?");
		int len = in.nextInt();
		//计算获奖概率（假设只有一个中奖号码）
		BigInteger lotteryOdds = BigInteger.valueOf(1);
		for(int i = 1; i <= len; i++) {
			lotteryOdds = lotteryOdds.multiply(BigInteger.valueOf(nums - i + 1)).divide(BigInteger.valueOf(i));
		}
		System.out.println("Your odds is 1 in " + lotteryOdds);
	}
}
