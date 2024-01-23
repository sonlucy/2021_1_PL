/***
Beep()함수 사용 전자피아노 만들기
작성자: 정보통신공학과 22012225 손보경
작성일자: 2021-03-24
최종수정일자: 2021-03-25
***/
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#define ESC 0x1B  ///아스키코드

int freq;
int mappingKey_to_Freq(char key, char alt_on); 
void freq_octave(char key);
void freq_scale(char key);

void main()
{
	char ch, alt_on = 0;
	int duration = 100; //100msec
	int freq;

	printf("\n===*★♪*♩♬♭* ELECTRIC PIANO ♪*♩♬♭*★=== \n");
	printf("'A'~'J': 8octave C D E F G A B\n");
	printf("'Z'~'M': 7octave C D E F G A B\n");
	printf("'q'~'u': 6octave C D E F G A B\n");
	printf("'a'~'j': 5octave C D E F G A B\n");
	printf("'z'~'m': 4octave C D E F G A B\n");
	printf("Input next key:\n");

	while ((ch = _getch()) != ESC) //키보드 ESC키 누르면 종료
	{
		alt_on = 0;
		if (GetAsyncKeyState(VK_MENU) && 0x8000) //alt키가 눌려졌으면
			alt_on = 1;
		freq = mappingKey_to_Freq(ch, alt_on);
		if (freq != -1) //주파수가 -1이 아닐경우
		{
			printf(" input key %c  → freq %5d", ch, freq); //주파수 출력
			freq_octave(ch); //옥타브 출력
			freq_scale(ch); //음계 출력
			Beep(freq, duration); //Beep함수 호출
		}
		else  //주파수가 -1일 경우
		{
			printf(" input key %c is wrong key.\n", ch);
		}
	}
}

int mappingKey_to_Freq(char key, char alt_on)
{
	int index = 25;
	int shiftFlag;
	int altFlag;
	int o = 0;

	int Key_to_Freq[2][2][26] = ///키보드문자-피아노음계 매핑 테이블 3차원 배열 사용
	{
		{
			{523, 392, 330, 660, 1323, 698, 784, 880, -1,988, -1,-1, 494, 440,
			-1,-1,1048, 1396, 588, 1568, 1976, 349, 1176, 294, 1760, 262}, //shift키 안 누름

			{ 4186, 3136, 2637, 5274, -1, 5588, 6272, 7040, -1,7902, -1, -1, 3951,
			3520, -1, -1, -1, -1, 4699, -1, -1, 2794, -1, 2349, -1, 2093} //shift키  누름
		} ,//alt=0 (안누름

		{
			{554, 415, 330, 660, 1323, 740, 830, 932, -1, 988, -1, -1, 494,
			 466, -1, -1, 1109, 1480, 622, 1661, 1976, 370, 1245, 311, 1865, 277 },

			{ 4435, 3322, 2637, 5274, -1, 5920, 6645, 7459, -1, 7902, -1, -1, 3951,
			 3729, -1, -1, -1, -1, 4978, -1, -1, 2960, -1, 2489, -1, 2217 }
		} //alt=1 ( 누름
	};

	if ((key >= 'a') && (key <= 'z')) //shift키 안 누름
	{
		shiftFlag = 0;
		index = key - 'a';

		if (GetAsyncKeyState(VK_MENU) & 0x8000) //alt 누름
			altFlag = 1;
		else
			altFlag = 0; //alt 안 누름

	}
	else if ((key >= 'A') && (key <= 'Z')) //shift키 누름
	{
		shiftFlag = 1;
		index = key - 'A';

		if (GetAsyncKeyState(VK_MENU) & 0x8000) //alt 누름
			altFlag = 0;
		else
			altFlag = 1;  //alt 안 누름

	}
	else
	{
		index = -1;  //잘못된 입력
	}

	int altFrag = alt_on;
	if (index == -1) freq = -1; //잘못된 입력일 경우 주파수= -1 (키사용x)
	else
		freq = Key_to_Freq[altFrag][shiftFlag][index];  

	return freq; //주파수 반환

}

void freq_octave(char key) //주파수 범위에 따른 옥타브
{
	if ((freq >= 261) && (freq <= 494))
		printf(" (4 octave)");
	else if ((freq >= 522) && (freq <= 988))
		printf(" (5 octave)");
	else if ((freq >= 1046) && (freq <= 1976))
		printf(" (6 octave)");
	else if ((freq >= 2093) && (freq <= 3952))
		printf(" (7 octave)");
	else if ((freq >= 4086) && (freq <= 7903))
		printf(" (8 octave)");
	else
		printf("\n");
}

void freq_scale(char key) //주파수에 따른 음계
{
	if ((freq == 523) || (freq == 4186) || (freq == 1048) || (freq == 262) || (freq == 2093))
		printf("C(도)\n");
	else if ((freq == 277) || (freq == 554) || (freq == 1109) || (freq == 2217) || (freq == 4435))
		printf("#C(도)\n");
	else if ((freq == 294) || (freq == 588) || (freq == 1176) || (freq == 2349) || (freq == 4699))
		printf("D(레)\n");
	else if ((freq == 330) || (freq == 660) || (freq == 1323) || (freq == 2637) || (freq == 5274))
		printf("E(미)\n");
	else if ((freq == 349) || (freq == 698) || (freq == 1396) || (freq == 2794) || (freq == 5588))
		printf("F(파)\n");
	else if ((freq == 392) || (freq == 784) || (freq == 1568) || (freq == 3136) || (freq == 6272))
		printf("G(솔)\n");
	else if ((freq == 440) || (freq == 880) || (freq == 1760) || (freq == 3520) || (freq == 7040))
		printf("A(라)\n");
	else if ((freq == 494) || (freq == 988) || (freq == 1976) || (freq == 3951) || (freq == 7902))
		printf("B(시)\n");
	else if ((freq == 311) || (freq == 622) || (freq == 1245) || (freq == 2489) | (freq == 4978))
		printf("D#(레)\n");
	else if ((freq == 370) || (freq == 740) || (freq == 1480) || (freq == 2960) || (freq == 5920))
		printf("F#(파)\n");
	else if ((freq == 415) || (freq == 830) || (freq == 1661) || (freq == 3322) || (freq == 6645))
		printf("G#(솔)\n");
	else if ((freq == 466) || (freq == 932) || (freq == 1865) || (freq == 3729) || (freq == 7459))
		printf("A#(라)\n");
	else
		printf("\n");
}