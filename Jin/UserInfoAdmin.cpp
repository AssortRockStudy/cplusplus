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
		cout << " 3. 끝내기" << endl;
		cout << EQUAL_PRINT << endl;
		exitProgram = Selecting();
		//	system("cls");
	}
}

bool UserInfoAdmin::Selecting( )
{
	int selectNum = 0;
	cout << " 수행할 기능의 숫자를 입력해주세요 : ";
	cin.clear();
	cin >> selectNum;

	switch (selectNum)
	{
		case 1:
			AddUserInfo();
			break;
		case 2:
			PrintUserInfo();
			break;
		case 3:
			return true;
		default :
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
	
	/*int reAdd = 0;
	cout << " 0을 입력하면 초기화면으로 돌아갑니다. " << endl;
	cout << " 추가 회원 정보 등록은 1을 입력하십시오. ";
	cin >> reAdd;

	if (1 == reAdd)
	{
		return AddUserInfo();
	}
	else if (0 == reAdd)
	{
		return;
	}
	else
	{
		while (true)
		{
			"올바른 숫자키를 입력하십시오. 재입력 !!!! : ";
			cin.clear();
			cin >> reAdd;
			if (1 == reAdd)
			{
				return AddUserInfo();
			}
			else if (0 == reAdd)
			{
				break;
			}
		}
	}*/
}

void UserInfoAdmin::PrintUserInfo()
{
	system("cls");
	cout << " 모든 회원 정보를 출력합니다. " << endl;

	for (int i = 0; i < users.size(); ++i)
	{
		cout << EQUAL_PRINT << endl;
		cout << " 회원 이름 : " << users[i]->name << endl;
		cout << " 회원 나이 : " << users[i]->age << endl;
		if(1 == users[i]->sex)
			cout << " 회원 성별 : 남성" << endl;
		else
			cout << " 회원 성별 : 여성" << endl;
	}
	cout << "아무 키를 입력하면 초기화면으로 돌아갑니다. " << endl;
	bool reAdd = true;
	cin >> reAdd;
}
