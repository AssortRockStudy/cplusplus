#include <iostream>
#include <conio.h>
#include <Windows.h>

char u_Name[100][10] = {};
int u_Sex[100] = {};
int u_Age[100] = {};

int u_Count = 0;


void initUser()
{
	while (true)
	{
		system("cls");
		int answer = 0;
		if (u_Count > 99)
		{
			printf("더 이상 추가할 수 없습니다. 아무 숫를 입력하면 메인 화면으로 복귀합니다...");
			scanf_s("%d", &answer);
		}
		printf("이름 입력(공백 포함 최대 9글자, 영문): ");
		scanf_s("%9s", &u_Name[u_Count], sizeof(u_Name[u_Count] - 1));
		printf("성별 입력(남성-> 1, 여성-> 2): ");
		scanf_s("%d", &u_Sex[u_Count]);		
		printf("나이 입력: ");
		scanf_s("%d", &u_Age[u_Count]);

		++u_Count;

		printf("회원 등록을 한 번 더 진행할까요? (yes-> 1, no-> 2): ");
		scanf_s("%d", &answer);

		if (answer == 2)
		{
			break;
		}

	}
}

void printUser()
{
	system("cls");
	int i = 0;
	for (; i < u_Count; ++i)
	{
		printf("+++++유저 %d\n", i + 1);
		printf("- 유저 이름: %s\n", u_Name[i]);
		printf("- 유저 성별: %s\n", u_Sex[i] == 1 ? "남성" : "여성");
		printf("- 유저 나이: %d\n", u_Age[i]);
	}
	printf("모든 회원을 출력했습니다. 아무 숫자를 입력하면 메인 화면으로 복귀합니다...");
	_getwch();
}

int main()
{
	while (true)
	{
		system("cls");
		int answer = 0;
		printf("+++++회원정보 입출력 프로그램+++++\n");
		printf("1. 회원 등록\n");
		printf("2. 회원 전부 출력\n");
		printf("3. 끝내기\n\n\n");
		printf("원하는 기능을 입력하세요: ");

		scanf_s("%d", &answer);
		switch (answer) // 연속된 구조의 case면 jump table을 사용
		{
		case 1:
			initUser();
			break;
		case 2:
			printUser();
			break;
		case 3:
			printf("프로그램을 종료합니다.\n");
			return 0;
			break;
		default:
			break;
		}
	}
}