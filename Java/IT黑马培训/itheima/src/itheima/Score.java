package itheima;
import java.util.*;
/**
 * 需求
 * 1. 在编程竞赛中，有6个评委为参赛的选手打分，分数为0-100的整数分。
 * 2. 选手最后得分为：去掉一个最高分和一个最低分后的4个评委的平均值
 * 3. 求选手的分数
 * 分析
 * 1. 6个评委的分数从控制台输入
 * 2. 输入同时记录最低分、最高分、和
 * 3. 计算最终分数
 * 测试
 * 1. 输入102分或-1分
 * 2. 输入字符串
 */
public class Score {
	public static void main(String[] args) {
		double sum = 0;
		int max = 0;
		int min = 100;
		System.out.println("input 6 scores:");
		for(int i = 0; i < 6; i++) {
			Scanner in = new Scanner(System.in);
			int temp = in.nextInt();
			if(temp < 0 || temp > 100) {
				System.out.println("the score is between 0 and 100, please input again");
				i--;
				continue;
			}
			if(temp > max)
				max = temp;
			if(temp < min)
				min = temp;
			sum += temp;
		}
		System.out.println("final score is " + (sum - max - min) / 4);
	}
}
