#include <stdio.h>
/*用指针方式代替组下标方式，重写函数day_of_year和month_day。*/

int daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(int year, int month, int day)
{
	int leap;
	int *p;
	if (year < 1752 || month < 1 || day < 1 || month > 12 || day >31)
	{
		printf("please input right.");
		return -1;
	}
	leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	p = &daytab[leap][1];
	if (day <= *(p+month-1))
	{
		for (int i = 1; i < month; i++)
			day += *p++;
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
	int *p;
	if (year < 0 || day < 1 || day > 366)
	{
		printf("please input right.");
		return;
	}
	leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	p = &daytab[leap][1];
	if (leap == 0 && day > 365)
	{
		printf("please input right.");
		return;
	}
	int i;
	for (i = 1; *p < day; i++)
		day -= *p++;
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
