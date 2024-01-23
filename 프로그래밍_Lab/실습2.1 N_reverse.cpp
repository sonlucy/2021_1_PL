/***
10진수 정수를 입력받고 거꾸로 출력하기
작성자: 정보통신공학과 22012225 손보경
작성일자: 2021- 03 - 9
***/

#include <stdio.h>

int main() {

	int N;
	printf("10자리 이내 10진수 입력: ");
	scanf_s("%d", &N);
	printf(" 역순 출력: ");

	while (N) {
		if (N > 999999999) {
			printf(" X, 10자리를 초과하였습니다.");
			break;
		}
		printf(" %d", N % 10);
		N = N / 10;

	}
	return 0;
}