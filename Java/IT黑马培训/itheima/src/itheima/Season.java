package itheima;
import java.util.*;
/**
 需求：键盘录入一个月份，输出该月份对应的季节。
	一年有4季
	3， 4， 5	春
	6， 7， 8	夏
	9，10，11	秋
	12，1， 2	冬
测试数据：
1. 1-12月份
2. 0，13
 */
public class Season {
	public static void main(String[] args) {
		String[] season = {"winter", "spring", "summer", "autumn", "winter"};
		int mounth;
		System.out.println("Please input a mounth:");
		Scanner in = new Scanner(System.in);
		mounth = in.nextInt();
		if(mounth < 1 || mounth > 12) {
			System.out.println("Please input the right mounth.");
		}
		System.out.println("The season is " + season[mounth/3]);
	}
}
