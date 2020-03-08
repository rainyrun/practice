package v1ch03.lotteryArray;

import java.util.*;

/**
 * 功能odds[][]存放彩票可能的结果，odds[n][k]表示从n个数中抽k个数可能产生的结果数。
 */
public class LotteryArray {
	public static void main(String[] args) {
		final int NMAX = 10;
		int[][] odds = new int[NMAX][];
		//初始化odds数组，是个左下三角数组。
		for(int i = 0; i < NMAX; i++)
			odds[i] = new int[i + 1];
		//计算odds[n][k]的结果
		for(int n = 0; n < odds.length; n++) {
			for(int k = 0; k < odds[n].length; k++) {
				int lotteryOdds = 1;
				for(int i = 1; i <= k; i++) {
					//注1
					lotteryOdds = lotteryOdds * (n - i + 1) / i;
				}
				odds[n][k] = lotteryOdds;
			}
		}
		//打印数组
		System.out.println(Arrays.deepToString(odds));
	}
}

/* 注1：
 * lotteryOdds = lotteryOdds * (n - i + 1) / i;
 * 不能写成
 * lotteryOdds *= (n - i + 1) / i;
 * 因为表达式
 * (n - i + 1) / i
 * 结果舍入后可能为0，影响结果。而第一个式子先计算
 * lotteryOdds * (n - i + 1)
 * 避免了这种可能
 * 
 */
