package v1ch03.lotteryDrawing;

import java.util.Scanner;
import java.math.*;

/**
 * 功能：随机从n个数中抽取出k个不重复的数，并输出
 */
public class LotteryDrawing {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		//询问从多少个数字
		System.out.println("How many numbers you need?");
		int n = in.nextInt();
		//抽取多少个数字
		System.out.println("How long the Lottery is?");
		int k = in.nextInt();
		
		//将数字存入nums数组，从nums数组中抽取数字
		int[] nums = new int[n];
		//将结果存入result数组
		int[] result = new int[k];
		
		//对nums数组初始化
		for(int i = 0; i < n; i++) {
			nums[i] = i + 1;
		}
		
		//随机选出k个数字存入result数组，数字不重复
		int index = n - 1;//选择范围的下标
		for(int i = 0; i < k; i++) {
			int rand = (int)(Math.random() * (index + 1));
			result[i] = nums[rand];
			//交换选中数字和数组尾部的数字，以保证不再选择重复的数字。
			int temp = nums[index];
			nums[index] = nums[rand];
			nums[rand] = temp;
			index--;
		}
		//Array.sort(result);
		//输出选中的数字
		for(int i = 0; i < k; i++) {
			System.out.println(result[i]);
		}
	}
}
