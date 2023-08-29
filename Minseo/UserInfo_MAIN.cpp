#include <iostream>
#include <map>

#include "User.h"
#include "UserFunc.h"

using namespace std;

map<string, User> userMap;



void printUser()
{
	system("cls");
	int i = 0;
	//for (; i < u_Count; ++i)
	//{
	//	printf("+++++유저 %d\n", i + 1);
	//	printf("- 유저 이름: %s\n", u_Name[i]);
	//	printf("- 유저 성별: %s\n", u_Sex[i] == 1 ? "남성" : "여성");
	//	printf("- 유저 나이: %d\n", u_Age[i]);
	//}
	printf("모든 회원을 출력했습니다. 아무 숫자를 입력하면 메인 화면으로 복귀합니다...");
	_getwch();
}

int main()
{
	while (true)
	{
		system("cls");
		int answer = 0;
		cout << "+++++회원정보 입출력 프로그램+++++" << endl;
		cout << "---현재 입력된 유저의 수: " << userMap.size() << endl;
		cout << "1. 회원 등록" << endl;
		cout << "2. 회원 전부 출력" << endl;
		cout << "3. 끝내기" << endl << endl << endl;
		cout << "원하는 기능을 입력하세요: " << endl;

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