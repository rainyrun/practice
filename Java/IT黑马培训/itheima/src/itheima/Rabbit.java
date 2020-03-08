package itheima;
import java.util.*;
/**
 * 需求：
 * 有一对兔子，从出生后第3个月起，每个月都生一对兔子，小兔子长到第三个月后又生一对兔子.
 * 假如兔子都不死，问第n个月的兔子对数为多少？
 * 
 * 分析：
 * 1. 一对兔子有年龄属性，年龄>=3的兔子，每生一对兔子，就把它加到兔子数组里。
 * 2. 每过一月更新兔子数组里的兔子，到月份后，计算兔子数组里的兔子对总数
 * 
 * 测试：


| 1
| 2
| 3 1
| 4 2 1 
| 5 3 2 1 1
| 6 4 3 2 2 1 1 1
| 7 5 4 3 3 2 2 2 1 1 1 1 1
| 8 6 5 4 4 3 3 3 2 2 2 2 2 1 1 1 1 1 1 1 1
---------------------------->兔子数
月份
*/
public class Rabbit {
	int age = 1;//这对兔子的年龄，按月计算
	
	public int getAge() {
		return age;
	}
	
	public void addAge() {
		age += 1;
	}
	
	public static void main(String[] args) {
		ArrayList<Rabbit> rabbits = new ArrayList<>();//兔子数组
		int mounth = 1;//过了n个月
		rabbits.add(new Rabbit());//初始的那对兔子
		System.out.println("Input mounth:");
		Scanner in = new Scanner(System.in);
		mounth = in.nextInt();
		for(int i = 1; i < mounth; i++) {
			int rabbitNum = rabbits.size();
			for(int j = 0; j < rabbitNum; j++) {
				Rabbit e = rabbits.get(j);
				e.addAge();
				if(e.getAge() >= 3){
					rabbits.add(new Rabbit());//生一对小兔子
				}
			}
		}
		System.out.println(rabbits.size());
	}
}
/*问题记录：
 *1. 在使用for each循环遍历兔子数组时，在循环体内为数组增加新兔子，导致数组无法被遍历完，产生concurentModifcationException
 */
