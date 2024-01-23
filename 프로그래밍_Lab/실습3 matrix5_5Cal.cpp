/***
5x5행렬의 덧셈,뺄셈,곱셈
작성자: 정보통신공학과 22012225 손보경
작성일자: 2021-03-17
***/

#include <stdio.h>
#include <iostream>
#include <iomanip>
#define SIZE 5 //행렬의 크기

void printMtrx(double mA[][SIZE], int size);
void addMtrx(double mA[][SIZE], double mB[][SIZE], double mX[][SIZE], int size);
void subtractMtrx(double mA[][SIZE], double mB[][SIZE], double mX[][SIZE], int size);
void multiplyMtrx(double mA[][SIZE], double mB[][SIZE], double mX[][SIZE], int size);

int main()
{
	double mA[5][5] = { {5.00, 4.00, 3.00, 2.00, 1.00},
	{6.00, 7.00, 8.00, 9.00, 10.00},
	{11.00, 12.00, 13.00, 14.00, 15.00},
	{16.00, 17.00, 18.00, 19.00, 20.00},
	{21.00, 22.00, 23.00, 24.00, 25.00}
	};
	double mB[5][5] = { {1.00, 0.00, 0.00, 0.00, 0.00},
	{0.00, 1.00, 0.00, 0.00, 0.00},
	{0.00, 0.00, 1.00, 0.00, 0.00},
	{0.00, 0.00, 0.00, 1.00, 0.00},
	{0.00, 0.00, 0.00, 0.00, 1.00}
	};
	double mC[5][5];
	double mD[5][5];
	double mE[5][5];
	printf("\n Matrix mA:\n");
	printMtrx(mA, 5);
	printf("\n Matrix mB:\n");
	printMtrx(mB, 5);
	addMtrx(mA, mB, mC, 5);
	printf("\n Matrix mC = mA + mB:\n");
	printMtrx(mC, 5);
	subtractMtrx(mA, mB, mD, 5);
	printf("\n Matrix mD = mA - mB:\n");
	printMtrx(mD, 5);
	multiplyMtrx(mA, mB, mE, 5);
	printf("\n Matrix mE = mA x mB:\n");
	printMtrx(mE, 5);
	printf("\n");
	return 0;
}

void printMtrx(double mA[][SIZE], int size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;    //확장완성형코드사용
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if ((i == 0) && (j == 0))
				printf("%c%c%8.2lf", a6, a3, mA[i][j]); //왼쪽 위
			else if ((i == 0) && j == (size - 1))
				printf("%8.2lf%c%c", mA[i][j], a6, a4);  //오른쪽 위
			else if ((i > 0) && (i < size - 1) && (j == 0))
				printf("%c%c%8.2lf", a6, a2, mA[i][j]);
			else if ((i > 0) && (i < size - 1) && (j == (size - 1)))
				printf("%8.2lf%c%c", mA[i][j], a6, a2);
			else if ((i == (size - 1)) && (j == 0))
				printf("%c%c%8.2lf", a6, a6, mA[i][j]);  //왼쪽 아래
			else if ((i == (size - 1)) && (j == (size - 1)))
				printf("%8.2lf%c%c", mA[i][j], a6, a5);  //오른쪽 아래
			else
				printf("%8.2lf", mA[i][j]);
		}
		printf("\n");
	}
}

void addMtrx(double mA[][SIZE], double mB[][SIZE], double mX[][SIZE], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mX[i][j] = mA[i][j] + mB[i][j];
}
void subtractMtrx(double mA[][SIZE], double mB[][SIZE], double mX[][SIZE], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mX[i][j] = mA[i][j] - mB[i][j];
}
void multiplyMtrx(double mA[][SIZE], double mB[][SIZE], double mX[][SIZE], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			mX[i][j] = 0;
			for (int k = 0; k < size; k++)  //행렬 곱셈 위해 3중 for-loop 구성
				mX[i][j] += mA[i][k] * mB[k][j];  
		}
}