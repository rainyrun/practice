package v1ch03.lotteryOdds;

import java.util.*;

/**
 * 功能：计算抽奖中奖的概率
 */
public class LotteryOdds {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		//询问从多少个数字中选
		System.out.println("How many numbers you need?");
		int nums = in.nextInt();
		//中奖号码有多少个数字
		System.out.println("How long the Lottery is?");
		int len = in.nextInt();
		//计算获奖概率（假设只有一个中奖号码）
		double lotteryOdds = 1;
		for(double i = 1; i <= len; i++) {
			lotteryOdds *= i / (nums - i + 1) ;
		}
		System.out.printf("the percent you win is %.3f%%", (lotteryOdds * 100));
	}
}
/* i的类型不能为int，因为此时i / (nums - i + 1) 的结果可能为0，造成结果出错。
 */
