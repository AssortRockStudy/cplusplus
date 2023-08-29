#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <map>
#include <string>
#include "User.h"

using namespace std;

map<string, User> userMap;

void initUser()
{
	while (true)
	{
		system("cls");
		User newUser;

		map<string, User>::iterator isValidName;
		do // 이름 입력
		{
			cout << "이름 입력(영문): ";
			cin >> newUser.m_Name;
			isValidName = userMap.find(newUser.m_Name);
			if (isValidName == userMap.end())
				cout << "중복된 이름입니다. 다시 입력해주세요." << endl;
		} while (isValidName == userMap.end());

		do // 성별 입력
		{
			cout << "성별 입력(남성-> 1, 여성-> 2): ";
			cin >> newUser.m_Sex;
			if (newUser.m_Sex == 1 || newUser.m_Sex == 2)
				cout << "잘못된 값입니다. 다시 입력해주세요." << endl;
		} while (newUser.m_Sex == 1 || newUser.m_Sex == 2);

		// 나이 입력
		cout << "나이 입력: ";
		cin >> newUser.m_Age;

		// 데이터 삽입
		userMap.insert(make_pair(newUser.m_Name, newUser));
		cout << endl << endl
			 << "회원 등록이 완료되었습니다." << endl;


		int answer = 0;
		do
		{
			cout << "회원 등록을 한 번 더 진행할까요? (yes-> 1, no-> 2): ";
			cin >> answer;

		} while (answer == 1 || answer == 2);
		
		if (answer == 2) break;
	}
}

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