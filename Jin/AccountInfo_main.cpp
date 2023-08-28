#include <iostream>
#include <stdlib.h>
#include "member.h"



//회원 등록은 이름, 성별(남1, 여2), 나이를 입력받고 추가로 입력 받을 것인지를 물어보고 추가입력과 메인화면 분기


void AddMembers(Members * ms);
void OutputMember(Members* ms);

int main()
{
	Members members = {};
	initM(&members);

	int sel = 0;
	while (sel != 3)
	{
		printf(" ================================ \n");
		printf(" < 회원 정보 시스템 >\n");
		printf(" 1. 회원 등록 \n");
		printf(" 2. 회원 정보 출력 \n");
		printf(" 3. 끝내기\n");
		printf(" 기능 선택  : ");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1:
			AddMembers(&members);
			break;
		case 2:
			OutputMember(&members);
			break;
		case 3:
			break;
		default:
			printf(" 올바른 숫자를 입력해주세요. \n");
			break;
		}
	}
	freeM(&members);
	return 0;
}

//회원 등록은 이름, 성별(남1, 여2), 나이를 입력받고 추가로 입력 받을 것인지를 물어보고 추가입력과 메인화면 분기
void AddMembers(Members* ms)
{
	system("cls");
	printf(" ================================ \n");
	if (ms->curCnt >= ms->maxCnt)
	{
		//resize();
		exit(0);
	}
	else
	{
		printf(" 회원 성명 : ");
		scanf_s("%s", ms->member[ms->curCnt].name, 10);
		printf(" \n 회원 성별 (남성 1, 여성 2)  : ");
		scanf_s("%d", ms->member[ms->curCnt].gender);
		printf(" \n 회원 나이 : ");
		scanf_s("%d", ms->member[ms->curCnt].age);
		++ms->curCnt;
	}

	printf(" \n 회원을 더 입력하시겠습니까 ? (Yes : 1, No : 2) : ");
	int yn = 0;
	scanf_s("%d", yn);
	if (yn == 1)
	{
		return AddMembers(ms);
	}
	printf(" ================================ \n");
}

//회원 전부 출력은 여태 입력받은 회원을 모두 출력하면 메인화면으로
void OutputMember(Members *ms)
{
	system("cls");
	printf(" ================================ \n");
	for (int i = 0; i >= ms->curCnt; ++i)
	{
		printf(" 회원 성명 :%s\n", ms->member[i].name);
		if ((ms->member[i].age) == 1) { printf(" 회원 성별 : 남성\n "); }
		else { printf("회원 성별 : 여성\n"); }
		printf(" 회원 나이 :%s세\n", ms->member[i].age);
	}
	printf(" ================================ \n");
}