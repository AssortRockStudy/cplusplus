#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <map>
#include <string>

#include "UserFunc.h"
#include "User.h"

using namespace std;

map<string, User> userMap;

enum USER_FUNC
{
	INIT = 1,
	PRINT,
	EDIT,
	RETURN
}; 

enum OUTPUT
{
	SEARCH = 1,
	SORT,
	BREAK,
};

enum SEX
{
	MALE = 1,
	FEMALE
};


void initUser()
{
	while (true)
	{
		system("cls");
		cout << "+++++ 회원 등록" << endl;	
		cout << "지금까지" << userMap.size() << "명의 회원을 등록했습니다." << endl;

		User newUser;

		map<string, User>::iterator isValidName;
		do // 이름 입력
		{
			cout << "이름 입력(영문): ";
			cin >> newUser.m_Name;
			isValidName = userMap.find(newUser.m_Name);
			if (isValidName != userMap.end())
				cout << "중복된 이름입니다. 다시 입력해주세요." << endl;
		} while (isValidName != userMap.end());

		do // 성별 입력
		{
			cout << "성별 입력(남성-> 1, 여성-> 2): ";
			cin >> newUser.m_Sex;
			if (newUser.m_Sex != MALE && newUser.m_Sex != FEMALE)
				cout << "잘못된 값입니다. 다시 입력해주세요." << endl;
		} while (newUser.m_Sex != MALE && newUser.m_Sex != FEMALE);

		// 나이 입력
		cout << "나이 입력: ";
		cin >> newUser.m_Age;

		// 데이터 삽입
		userMap.insert(make_pair(newUser.m_Name, newUser));
		cout << endl << endl
			<< "회원 등록이 완료되었습니다." << endl;


		int answer = 0;
		do // 재실행 체크
		{
			cout << "회원 등록을 한 번 더 진행할까요? (yes-> 1, no-> 2): ";
			cin >> answer;

		} while (answer != 1 && answer != 2);

		if (answer == 2) break;
	}
}

void outputSort_Name(int isReverse)
{
	if (isReverse == 1)
	{
		for (auto iter = userMap.begin(); iter != userMap.end(); ++iter)
		{
			User data = iter->second;
			cout << "----- " << data.m_Name << "님" << endl;
			cout << "나이: " << data.m_Age << endl;
			cout << "성별: ";
			if (data.m_Sex == MALE)
				cout << "남성" << endl;
			else
				cout << "여성" << endl;
			cout << "그룹: " << data.m_Group << endl;
		}
	}
	else
	{
		for (auto riter = userMap.rbegin(); riter != userMap.rend(); ++riter)
		{
			User data = riter->second;
			cout << "----- " << data.m_Name << "님" << endl;
			cout << "나이: " << data.m_Age << endl;
			cout << "성별: ";
			if (data.m_Sex == MALE)
				cout << "남성" << endl;
			else
				cout << "여성" << endl;
			cout << "그룹: " << data.m_Group << endl;
		}
	}
}
void outputSort_Sex(int Sex)
{
	for (auto iter = userMap.begin(); iter != userMap.end(); ++iter)
	{
		User data = iter->second;
		if (Sex != data.m_Sex) continue;
		cout << "----- " << data.m_Name << "님" << endl;
		cout << "나이: " << data.m_Age << endl;
		cout << "성별: ";
		if (data.m_Sex == MALE)
			cout << "남성" << endl;
		else
			cout << "여성" << endl;
		cout << "그룹: " << data.m_Group << endl;
	}
}

void outputSort() // 정렬 후 출력
{
	system("cls");
	cout << "1. 이름 순 출력" << endl;
	cout << "2. 이름 역순 출력" << endl;
	cout << "3. 모든 남성 출력" << endl;
	cout << "4. 모든 여성 출력" << endl;
	cout << "5. 나이대 별 출력" << endl;
	cout << "원하는 기능을 입력하세요: ";
	
	int answer = 0;
	cin >> answer;
	switch (answer)
	{
	case 1:
	case 2:
		outputSort_Name(answer);
		break;
	case 3:
	case 4:
		outputSort_Sex(answer - 2);
		break;
	case 5:

		break;
	}
	return;
}

void outputSearch() // 탐색 후 유저 출력
{
	system("cls");

	// 유저 탐색
	string nameBuffer = "";
	cout << "찾고자 하는 이름 입력: ";
	cin >> nameBuffer;

	map<string, User>::iterator dataIter = userMap.find(nameBuffer);

	if (dataIter == userMap.end())
	{
		cout << "해당 이름의 회원은 저장되어있지 않습니다." << endl;
		return;
	}

	// 유저 출력
	User data = dataIter->second;
	cout << "----- " << data.m_Name << "님" << endl;
	cout << "나이: " << data.m_Age << endl;
	cout << "성별: ";
	if (data.m_Sex == MALE)
		cout << "남성" << endl;
	else
		cout << "여성" << endl;
	cout << "그룹: " << data.m_Group << endl;

	return;
}

void printUser()
{
	system("cls");
	cout << "+++++ 회원 출력" << endl;
	cout << "현재 " << userMap.size() << "명의 회원이 저장되어 있습니다.";
	cout << "1. 유저 검색 후 출력" << endl;
	cout << "2. 유저 전체 출력" << endl; 
	cout << "3. 돌아가기" << endl << endl << endl;
	cout << "원하는 기능을 입력하세요: ";

	int answer = 0;
	cin >> answer;
	
	switch (answer) // 연속된 구조의 case면 jump table을 사용
	{
	case OUTPUT::SEARCH:
		outputSearch();
		break;
	case OUTPUT::SORT:
		outputSort();
		break;
	case OUTPUT::BREAK:
		break;	
	default:
		break;
	}
	
	cout << "회원을 출력했습니다. 아무 키를 누르면 메인 화면으로 복귀합니다..." << endl;
	_getwch();
	return;
}

int RunUserInfoSystem()
{
	system("cls");
	int answer = 0;
	cout << "+++++회원정보 입출력 프로그램+++++" << endl;
	cout << "---현재 입력된 유저의 수: " << userMap.size() << endl;
	cout << "1. 회원 등록" << endl;
	cout << "2. 회원 출력" << endl;
	cout << "3. 회원 정보 수정" << endl;
	cout << "4. 끝내기" << endl << endl << endl;
	cout << "원하는 기능을 입력하세요: ";

	cin >> answer;
	switch (answer) // 연속된 구조의 case면 jump table을 사용
	{
	case INIT:
		initUser();
		break;
	case PRINT:
		printUser();
		break;
	case EDIT:
		// 회원정보수정 함수
		break;
	case RETURN:
		cout << "프로그램을 종료합니다." << endl;
		return 0;
		break;
	default:
		break;
	}

	return 1;
}