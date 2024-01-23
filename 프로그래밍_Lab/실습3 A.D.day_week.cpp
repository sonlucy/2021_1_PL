/***
입력 받은 날짜가 서기 1년 1월 1일로부터 몇번째날인지, 무슨요일인지
작성자: 정보통신공학과 22012225 손보경
작성일자: 2021-03-17
***/

#include <stdio.h>
#include <conio.h>
#define WEEKDAY_AD01Jan01 MON //서기 1년 1월 1일의 요일
#define DAYS_PER_WEEK 7

enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };
enum MONTH {
	JAN = 1, FED, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT,
	NOV, DEC, NUM_MONTHS
};
const char* weekDayName[DAYS_PER_WEEK] = { "SUN", "MON",
"TUE", "WED", "THR", "FRI", "SAT" };
const char* monthName[NUM_MONTHS] = { "", "January", "February",
"March", "April","May", "June", "July", "August", "September", "October",
"November", "December" };

bool isLeapYear(int y);  //해당년도가 윤년인지 확인
int getDaysFromJan01AD01(int year, int month, int d);  //해당 연월일이 서기 1년 1월 1일부터 몇번째날인지

int main()
{
	int y, m, d;
	printf("년, 월, 일을 입력하시오.:");
	scanf_s("%d %d %d", &y, &m, &d);

	printf("입력된 %d년 %d월 %d일은 서기 1년 1월 1일부터 %d번째 날입니다. "
		, y, m, d, getDaysFromJan01AD01(y, m, d));
	printf("이 날은 %s요일입니다.\n\n", weekDayName[getDaysFromJan01AD01(y, m, d) % 7]);


	for (int i = 2011; i <= 2021; i++)  //2011년부터 22021년까지
	{
		printf("%d년 1월 1일은 서기 1년 1일로부터 %d번째 날입니다.", i, getDaysFromJan01AD01(i, 1, 1));
		printf("이 날은 %s요일입니다.\n", weekDayName[getDaysFromJan01AD01(i, 1, 1) % 7]);

	}
}

bool isLeapYear(int y)
{
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))  //윤년일 조건
		return true;
	else
		return false;
}

int getDaysFromJan01AD01(int year, int month, int d)
{
	int daysFromAD01Jan01 = 0;
	int daysInYear;
	int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = 0;  //days를 0으로 초기화
	for (int y = 1; y < year; y++)
	{
		daysInYear = isLeapYear(y) ? 366 : 365;
		days += daysInYear;  //daysInYear 값을 days에 더하기
	}
	if (isLeapYear(year))
		daysInMonth[2] = 29;  //윤년인경우 2월을 29일로 변경
	for (int m = 1; m < month; m++)
	{
		days += daysInMonth[m];  //해당 달의 일수를 days에 더하기

	}

	daysFromAD01Jan01 += days;  //앞서 더한 days값(년,월 일수)과
	daysFromAD01Jan01 += d;    //전달받은 d일 더하면 서기 1년1월1일부터의 일수
	return daysFromAD01Jan01;
}
