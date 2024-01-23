/*
프로젝트 이름: 8,10,16,2진수 표현과 비트 연산
작성자: 정보통신공학과 22012225 손보경
작성일자: 2021- 03- 10
*/
#include <stdio.h>
#define BIT_MASK 0x01
#define NUM_BITS_INT 32

enum BinOp_Type {
	INT_ADD, INT_SUB, BIT_AND,BIT_OR, BIT_XOR, BIT_NOT, SHIFT_LEFT, SHIFT_RIGHT
};
const char* bop_sign[] = { "+", "-","&", "|", "^", "~", "<<", ">>" };

void printInt_Bits(int d);
void printIntOper_Bits(BinOp_Type bop, int x, int y, int z);

void main()
{
	int x, y, z;
	int k = 3;
	printf("(0x0000 ~ 0xFFFF)사이의 16진수를 입력하시오: ");
	scanf_s("%x %x", &x, &y);
	printf("Input hexadecimal numbers: \n");

	printf(" x = %#010X(16진수) = %8d(10진수) = %8o(8진수)\n = ", x, x, x);
	printInt_Bits(x); printf("(비트)\n");  
	printf(" y = %#010X(16진수) = %8d(10진수) = %8o(8진수)\n = ", y, y, y); 
	printInt_Bits(y); printf("(비트)\n"); 

	z = x + y;
	printf("\nInteger Addition : %#010X + %#010X => %#010X\n", x, y, z);
	printIntOper_Bits(INT_ADD, x, y, z);
	z = x - y;
	printf("\nInteger Subtraction : %#010X - %#010X => %#010X\n", x, y, z);
	printIntOper_Bits(INT_SUB, x, y, z);
	
	z = x & y;
	printf("\nBitwise AND : %#010X & %#010X => %#010X\n", x, y, z);
	printIntOper_Bits(BIT_AND, x, y, z);
	z = x | y;
	printf("\nBitwise OR : %#010X | %#010X => %#010X\n", x, y, z);
	printIntOper_Bits(BIT_OR, x, y, z);
	z = x ^ y;
	printf("\nBitwise XOR : %#X ^ %#X => %#X\n", x, y, z);
	printIntOper_Bits(BIT_XOR, x, y, z);
	z = x << k;
	printf("\nBitwise Shift Left : %#X << %#X => %#X\n", x, k, z);
	printIntOper_Bits(SHIFT_LEFT, x, k, z);
	z = y >> k;
	printf("\nBitwise Shift Right : %#X >> %#X => %#X\n", y, k, z);
	printIntOper_Bits(SHIFT_RIGHT, y, k, z);
	z = ~y;
	printf("\nBitwise NOT : ~%#X => %#X\n", y, y );
	printIntOper_Bits(BIT_NOT, y, y ,z);
}


void printInt_Bits(int d)
{
	unsigned long L1, L2, msk; // 32-bits
	for (int n = (NUM_BITS_INT - 1); n >= 0; n--)
	{
		msk = BIT_MASK << n;
		L1 = d & msk;
		L2 = L1 >> n;
		printf("%d", L2);
		if ((n % 8) == 0) // insert a space at each 8-bits
			printf(" ");
	}
}
	void printIntOper_Bits(BinOp_Type bop, int x, int y, int z)
	{
		if (bop != BIT_NOT)
		{
			printf("    "); printInt_Bits(x); printf("\n");
			printf("    "); printInt_Bits(y); printf("\n");
			printf("    ----------------------------------------------\n");
			printf("    "); printInt_Bits(z); printf("\n");
		}
		else
		{
			printf("    "); printInt_Bits(y); printf("\n");
			printf("    ----------------------------------------------\n");
			printf("    "); printInt_Bits(z); printf("\n");
		}

	}
