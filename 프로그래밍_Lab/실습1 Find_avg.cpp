/*
입력받은 데이터들의 최댓값,최솟값,평균값 찾기
작성자: 손보경
작성일자: 2021-03-04
*/
#include <stdio.h>

int main() {

	int a;  //데이터 입력
	int max, min;  //최댓값, 최솟값
	int avg;  //평균값
	int sum = 0;  //입력데이터의 합
	int count = 0;  //

	while (count < 5)
	{
		printf("데이터 입력:");
		scanf_s("%d", &a);
		count++;

		if (count == 1)
		{
			max = a;
			min = a;
		}

		if (min > a)min = a;
		if (max < a)max = a;

		sum += a;
		avg = sum / 5;

	}
	printf("\n최솟값: %d", min);
	printf("최댓값: %d", max);
	printf("평균값: %d", avg);
}