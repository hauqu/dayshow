#include<stdio.h> 
#include<conio.h>
#include<string.h>
#define day_org 0//1899 12.31 星期日 
void Show(int y, int m, int d);
int  IsLeap(int y); //是否是闰年  
int SpaceN; //1号前 空格数 
int main()
{

	char s[11]; //存储时间字符串 
	//1999-04-05
	int  i = 0;
	printf_s("请输入日期:如2000-04-28\n");
	scanf_s("%s", s,11);//保证不越界而多需求一个参数，录入大小
	printf_s("\033[32m%s\033[0m", s);
	int year = 1899;
	int month = 12;
	int day = 31;
	int week = 0; int day_pass = 0;
	//**********************************************************字符串处理 
	year = 1000 * (s[0] - 48) + 100 * (s[1] - 48) + 10 * (s[2] - 48) + (s[3] - 48);
	month = 10 * (s[5] - 48) + (s[6] - 48);
	day = 10 * (s[8] - 48) + (s[9] - 48);
	//**************************************************************字符转换成整数 
	for (int i = 1900; i < year; i++)
	{
		day_pass += 365;
		if (IsLeap(i)) day_pass++;
	}//计算过去年的天数  
	switch (month) //加上本年已经过去的天数 
	{
	case  1:day_pass += 0 + day; break;
	case  2:day_pass += 31 + day;  break;
	case  3:day_pass += 31 + 28 + day;	break;
	case  4:day_pass += 31 + 28 + 31 + day;  break;
	case  5:day_pass += 31 + 28 + 31 + 30 + day;  break;
	case  6:day_pass += 31 + 28 + 31 + 30 + 31 + day;	 break;
	case  7:day_pass += 31 + 28 + 31 + 30 + 31 + 30 + day;	break;
	case  8:day_pass += 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;  break;
	case  9:day_pass += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;  break;
	case 10:day_pass += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;	 break;
	case 11:day_pass += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;	break;
	case 12:day_pass += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;  break;
	}

	week = (day_pass) % 7; //求出这天是星期几  
	SpaceN = (day_pass - day + 1) % 7;


	printf_s("\n年份是：%d", year);
	printf_s("\n月份是：%d", month);
	printf_s("\n天数是：%d", day);
	printf_s("\n星期是：%d", week);

	printf_s("\n");
	Show(year, month, day);
	_getch();

	return 0;
}
void Show(int y, int m, int d)
{
	char Months[12][12] =
	{
		"January","February","March","April",
		"May",	"June", "July","Augest",
		"September","October","November","December"
	};
	int MonthDay = 28;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		MonthDay = 31;
	}
	else if (m == 2)
	{
		MonthDay += IsLeap(y);
	}
	else
	{
		MonthDay = 30;
	}

	//表头打印 
	printf_s("\n\033[48;5;9m%s\033[0m                            \033[48;5;9m%d\033[0m\n\n", Months[m - 1], y); //15个空格 
	printf_s("\033[48;5;19mSUN   MON   TUE   WED   THU   FRI   SAT   \033[0m\n\n"); //3+4
	//表格打印
	for (int i = 0; i < SpaceN; i++)
	{
		printf_s("      ");
	}
	int temp_day = 1;
	for (int i = SpaceN; i <= 6; i++)
	{
		printf_s("\033[48;5;22m%d     ", temp_day++);
	}

	int n = 0;
	for (int i = temp_day; i <= MonthDay; i++)
	{
		if (n++ % 7 == 0)printf_s("\n\n");
		if (i < 10)
		{
			if (i != d)	printf_s("\033[48;5;22m%d     ", i);
			else        printf_s("\033[41m%d    \033[0m ", i);
		}
		else
		{
			if (i != d)	printf_s("\033[48;5;22m%d    ", i);
			else        printf_s("\033[41m%d    \033[0m", i);
		}

	}


	printf_s("\n\n\n\n\n");
	//数字之间有空格  
}
int  IsLeap(int y)
{
	if (y % 400 == 0) return 1;
	if (y % 4 == 0 && y % 100 != 0) return 1;
	return 0;
}