/*
�Է¹��� �����͵��� �ִ�,�ּڰ�,��հ� ã��
�ۼ���: �պ���
�ۼ�����: 2021-03-04
*/
#include <stdio.h>

int main() {

	int a;  //������ �Է�
	int max, min;  //�ִ�, �ּڰ�
	int avg;  //��հ�
	int sum = 0;  //�Էµ������� ��
	int count = 0;  //

	while (count < 5)
	{
		printf("������ �Է�:");
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
	printf("\n�ּڰ�: %d", min);
	printf("�ִ�: %d", max);
	printf("��հ�: %d", avg);
}