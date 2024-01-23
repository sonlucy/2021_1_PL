/***
�Է� ���� ��¥�� ���� 1�� 1�� 1�Ϸκ��� ���°������, ������������
�ۼ���: ������Ű��а� 22012225 �պ���
�ۼ�����: 2021-03-17
***/

#include <stdio.h>
#include <conio.h>
#define WEEKDAY_AD01Jan01 MON //���� 1�� 1�� 1���� ����
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

bool isLeapYear(int y);  //�ش�⵵�� �������� Ȯ��
int getDaysFromJan01AD01(int year, int month, int d);  //�ش� �������� ���� 1�� 1�� 1�Ϻ��� ���°������

int main()
{
	int y, m, d;
	printf("��, ��, ���� �Է��Ͻÿ�.:");
	scanf_s("%d %d %d", &y, &m, &d);

	printf("�Էµ� %d�� %d�� %d���� ���� 1�� 1�� 1�Ϻ��� %d��° ���Դϴ�. "
		, y, m, d, getDaysFromJan01AD01(y, m, d));
	printf("�� ���� %s�����Դϴ�.\n\n", weekDayName[getDaysFromJan01AD01(y, m, d) % 7]);


	for (int i = 2011; i <= 2021; i++)  //2011����� 22021�����
	{
		printf("%d�� 1�� 1���� ���� 1�� 1�Ϸκ��� %d��° ���Դϴ�.", i, getDaysFromJan01AD01(i, 1, 1));
		printf("�� ���� %s�����Դϴ�.\n", weekDayName[getDaysFromJan01AD01(i, 1, 1) % 7]);

	}
}

bool isLeapYear(int y)
{
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))  //������ ����
		return true;
	else
		return false;
}

int getDaysFromJan01AD01(int year, int month, int d)
{
	int daysFromAD01Jan01 = 0;
	int daysInYear;
	int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = 0;  //days�� 0���� �ʱ�ȭ
	for (int y = 1; y < year; y++)
	{
		daysInYear = isLeapYear(y) ? 366 : 365;
		days += daysInYear;  //daysInYear ���� days�� ���ϱ�
	}
	if (isLeapYear(year))
		daysInMonth[2] = 29;  //�����ΰ�� 2���� 29�Ϸ� ����
	for (int m = 1; m < month; m++)
	{
		days += daysInMonth[m];  //�ش� ���� �ϼ��� days�� ���ϱ�

	}

	daysFromAD01Jan01 += days;  //�ռ� ���� days��(��,�� �ϼ�)��
	daysFromAD01Jan01 += d;    //���޹��� d�� ���ϸ� ���� 1��1��1�Ϻ����� �ϼ�
	return daysFromAD01Jan01;
}
