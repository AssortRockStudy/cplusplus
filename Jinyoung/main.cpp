#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

#include "struct.h"
#include <vector>
#include <iostream>

using namespace std;



// User 동적 배열
vector<User> g_user;


// 동적 할당
// 런타임 중에 메모리 할당
// 힙 영역
// 사용자(프로그래머) 가 직접 메모리를 관리해야함

void InputUserInfo();
void CheckUserInfo();
void pushtestdata();
void SaveUserInfo();
void LoadUserInfo();

int main()
{
	int i = 0;
	int* pInt = nullptr;
	int** ppInt = nullptr;
	int*** pppInt = nullptr;


	//initArray<User>(&g_user);

	while (1)
	{
		int Input = 0;

		// 콘솔창 클리어
		system("cls");
		// 테스트 데이터 입력
		pushtestdata();

		// 기능 설명
		cout<<"1. 회원 등록"<<endl;
		cout << "2. 회원 정보" << endl;
		//printf("3. 저장\n");
		//printf("4. 불러오기\n");
		cout << "3. 프로그램 종료" << endl;

		cin>>Input;

		// 3번 입력 시 프로그램 종료
		if (3 == Input)
		{
			break;
		}
		else if (1 == Input)
		{
			InputUserInfo();
		}
		else if (2 == Input)
		{
			CheckUserInfo();
		}
		/*else if (3 == Input)
		{
			SaveUserInfo();
		}
		else if (4 == Input)
		{
			LoadUserInfo();
		}*/
	}



	//delArray<User>(&g_user);

	return 0;
}



void pushtestdata()
{

	User user;

	user.name="aaa";
	user.Sex=1;
	user.Age=111;
	g_user.push_back(user);

	user.name = "bbb";
	user.Sex = 2;
	user.Age = 222;
	g_user.push_back(user);

	user.name = "ccc";
	user.Sex = 2;
	user.Age = 333;
	g_user.push_back(user);


}

