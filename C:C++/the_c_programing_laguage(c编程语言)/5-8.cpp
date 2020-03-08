#include <stdio.h>
/*函数day_of_year和month_day中没有进行错误检查，请解决该问题。*/

int daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(int year, int month, int day)
{
	int leap;
	if (year < 1752 || month < 1 || day < 1 || month > 12 || day >31)
	{
		printf("please input right.");
		return -1;
	}
	leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	if (day <= daytab[leap][month])
	{
		for (int i = 1; i < month; i++)
			day += daytab[leap][i];
	}
	else
	{
		printf("please input right day.");
		return -1;
	}
	return day;
}

void month_day(int year, int day, int *pmonth, int *pday)
{
	int leap;
	if (year < 0 || day < 1 || day > 366)
	{
		printf("please input right.");
		return;
	}
	leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	if (leap == 0 && day > 365)
	{
		printf("please input right.");
		return;
	}
	int i;
	for (i = 1; daytab[leap][i] < day; i++)
		day -= daytab[leap][i];
	*pmonth = i;
	*pday = day;
}

void main()
{
	int year = 2017;
	int day1 = 19;
	int month = 15;
	int day2 = 231;
	int nmonth, nday;

	//int day_of = day_of_year(year, month, day1);
	month_day(year, day2, &nmonth, &nday);

	printf("month is %d, day is %d\n", nmonth, nday);
}
