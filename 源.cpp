#include<stdio.h> 
#include<conio.h>
#include<string.h>
#define day_org 0//1899 12.31 ������ 
void Show(int y, int m, int d);
int  IsLeap(int y); //�Ƿ�������  
int SpaceN; //1��ǰ �ո��� 
int main()
{

	char s[11]; //�洢ʱ���ַ��� 
	//1999-04-05
	int  i = 0;
	printf_s("����������:��2000-04-28\n");
	scanf_s("%s", s,11);//��֤��Խ���������һ��������¼���С
	printf_s("\033[32m%s\033[0m", s);
	int year = 1899;
	int month = 12;
	int day = 31;
	int week = 0; int day_pass = 0;
	//**********************************************************�ַ������� 
	year = 1000 * (s[0] - 48) + 100 * (s[1] - 48) + 10 * (s[2] - 48) + (s[3] - 48);
	month = 10 * (s[5] - 48) + (s[6] - 48);
	day = 10 * (s[8] - 48) + (s[9] - 48);
	//**************************************************************�ַ�ת�������� 
	for (int i = 1900; i < year; i++)
	{
		day_pass += 365;
		if (IsLeap(i)) day_pass++;
	}//�����ȥ�������  
	switch (month) //���ϱ����Ѿ���ȥ������ 
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

	week = (day_pass) % 7; //������������ڼ�  
	SpaceN = (day_pass - day + 1) % 7;


	printf_s("\n����ǣ�%d", year);
	printf_s("\n�·��ǣ�%d", month);
	printf_s("\n�����ǣ�%d", day);
	printf_s("\n�����ǣ�%d", week);

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

	//��ͷ��ӡ 
	printf_s("\n\033[48;5;9m%s\033[0m                            \033[48;5;9m%d\033[0m\n\n", Months[m - 1], y); //15���ո� 
	printf_s("\033[48;5;19mSUN   MON   TUE   WED   THU   FRI   SAT   \033[0m\n\n"); //3+4
	//����ӡ
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
	//����֮���пո�  
}
int  IsLeap(int y)
{
	if (y % 400 == 0) return 1;
	if (y % 4 == 0 && y % 100 != 0) return 1;
	return 0;
}