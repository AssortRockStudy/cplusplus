#include "UserInfoAdmin.h"
#include "UserInfo.h"

#include <iostream>
#define EQUAL_PRINT "======================"

using std::cout;
using std::endl;
using std::cin;

// Selecting 함수 실행 
void UserInfoAdmin::StartProgram()
{
	// true면 Program 종료. 
	bool exitProgram = false; 
	while (!exitProgram)
	{
		cout <<EQUAL_PRINT << endl;
		cout << " 1. 회원 정보 등록" << endl;
		cout << " 2. 모든 회원 정보 조회" << endl;
		cout << " 3. 회원 정보 검색" << endl;
		cout << " 4. 끝내기" << endl;
		cout << EQUAL_PRINT << endl;
		exitProgram = Selecting();
		//	system("cls");
	}
}

bool UserInfoAdmin::Selecting()
{
	int selectNum = 0;
	cout << " 수행할 기능의 숫자를 입력해주세요 : ";
	//cin.ignore(100, '\n');
	//cin.clear();
	cin >> selectNum;

	switch (selectNum)
	{
	case AddUser:
		AddUserInfo();
		break;
	case PrintAllUser:
		PrintAllUserInfo();
		break;
	case SearchUser:
		SearchUserName();
		break;
	case Exit:
		return true;
	default:
		cout << " 올바른 숫자를 입력하십시오. " << endl;
	}
	return false;
}

void UserInfoAdmin::AddUserInfo()
{
	system("cls");
	//cin.clear();
	UserInfo* user = new UserInfo();
	// 회원 이름, 성별, 나이 받아서 users에 저장하기 위해 하나 할당
	cout << " 등록할 회원 정보를 입력합니다. " << endl;
	cout << " 회원 이름 : ";
	cin >> user->name;
	cout << " 회원 나이 : ";
	cin >> user->age;
	cout << " 회원 성별 (남성 : 1, 여성 : 2) : ";
	cin >> user->sex;

	users.push_back(user);

	int reAdd = 0;
	cout << " 추가 회원 정보 등록은 1을 입력하십시오. " << endl;
	cout << " 1을 제외한 0이 아닌 숫자를 입력하면 초기화면으로 돌아갑니다. ";
	cin >> reAdd; // 문자를 받아버리면 0으로 치부하고 while문에 들어옴.
	cin.clear();
	cin.ignore(100, '\n');
	while (0 == reAdd || 1 == reAdd)
	{
		if (1 == reAdd) { return AddUserInfo(); }
		cout << " 잘못된 입력입니다. 올바른 숫자를 입력하십시오.";
		cin >> reAdd;
		cin.clear();
		cin.ignore(100, '\n');
	}
	system("cls");

}

void UserInfoAdmin::PrintUserInfo(int _idx)
{
	cout << EQUAL_PRINT << endl;
	cout << " 회원 이름 : " << users[_idx]->name << endl;
	cout << " 회원 나이 : " << users[_idx]->age << endl;
	if (1 == users[_idx]->sex)
		cout << " 회원 성별 : 남성" << endl;
	else
		cout << " 회원 성별 : 여성" << endl;
}

void UserInfoAdmin::PrintAllUserInfo()
{
	system("cls");
	cout << " 모든 회원 정보를 출력합니다. " << endl;

	for (int i = 0; i < users.size(); ++i)
		PrintUserInfo(i);

	AlwaysLast();
}

void UserInfoAdmin::AlwaysLast()
{
	system("pause");
	system("cls");
}

void UserInfoAdmin::SearchUserName()
{
	system("cls");
	if (!users.size())
	{
		cout << " 저장된 회원이 없습니다. 회원 등록을 해주십시오.";
		AlwaysLast();
		return;
	}
	cout << " 찾을 회원의 이름을 입력해주십시오. : ";
	string inputName;
	cin >> inputName;
	cin.clear();
	cin.ignore(100, '\n');
	
	for (int i = 0; i < users.size(); ++i)
	{
		if (users[i]->name == inputName)
		{
			PrintUserInfo(i);
			AlwaysLast();
			return;
		}
	}
	cout << " 찾으신 회원은 없는 회원입니다.";
	AlwaysLast();
}
