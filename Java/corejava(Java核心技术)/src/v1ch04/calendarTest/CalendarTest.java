package v1ch04.calendarTest;

import java.time.*;

/**
 * 显示本月日历，并在当天的日期后标*。日历格式如下
 * Mon Tue Wed Thu Fri Sat Sun
 *                          1
 *  2   3   4   5   6   7   8
 *  9  10  11  12  13  14  15
 * 16  17  18  19  20  21* 22
 * 23  24  25  26  27  28  29
 * 30
 */
public class CalendarTest {
	public static void main(String[] args) {
		//获取当天的日期
		LocalDate today = LocalDate.now();
		//今天是本月的第几天
		int day = today.getDayOfMonth();
		int month = today.getMonthValue();
		//获取本月第一天的日期
		LocalDate firstDay = today.minusDays(day - 1);
		//取得第一天的星期
		DayOfWeek weekday = firstDay.getDayOfWeek();
		int week = weekday.getValue();
		//打印表头
		System.out.println(" Mon Tue Wed Thu Fri Sat Sun");
		//打印第一行的空格
		int count = 1;
		LocalDate countDate = firstDay;
		for(int i = 1; i < week; i++) {
			System.out.print("    ");
		}
		//循环打印表体，当星期=7时换行，当到下月时，结束循环，当日期=今天时，打印*。
		while(countDate.getMonthValue() == month) {
			//打印日期
			if(week > 7) {
				week = week % 7;
				System.out.println();
			}
			System.out.printf("%3d", count);
			//注1
			if(countDate.equals(today))
				System.out.print("*");
			else
				System.out.print(" ");
			count++;
			//注2
			countDate = countDate.plusDays(1);
			week++;
		}
	}
}
/* 注1: 不能使用countDate == today。countDay和today指向对象的引用，两个变量引用的对象不同，所以不相等
 * 注2: countDate.plusDays(1)不会改变countDate的值。
 * 注3: 灵活使用countDay里的getDayOfWeek、getDayOfMonth方法，week、count变量可以省略。
 */

