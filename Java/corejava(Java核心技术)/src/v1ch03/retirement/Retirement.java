package v1ch03.retirement;

import java.util.*;

/**
 * 功能：计算需要多长时间才能够存储一定数量的退休金。假定每年存入相同数量的金额，而且利率是固定的。
 */
public class Retirement {
	public static void main(String[] args) {
		double goal = 0;//退休金总额
		double payment = 0;//每年存入金额
		double interestRate = 0;//年利率
		int year = 0;//退休需要的年数
		
		Scanner in = new Scanner(System.in);
		//输入退休金总额
		System.out.println("How much money do you need to retire?");
		goal = in.nextDouble();
		//输入每年存入金额
		System.out.println("How much money will you store every year?");
		payment = in.nextDouble();
		//输入年利率
		System.out.println("What the Interest Rate is (%) ?");
		interestRate = in.nextDouble();
		
		//计算需要的年数
		double temp = 0;
		while(temp < goal) {
			temp += payment;
			temp *= (1 + interestRate/100);
			year++;
		}
		System.out.println("You need " + year + " years to retire.");
	}
}
