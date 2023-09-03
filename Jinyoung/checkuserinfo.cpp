#include <stdio.h>
#include <stdlib.h>

#include <string>
#include "struct.h"
#include <iostream>


// 특정 인덱스에 해당하는 유저정보 출력
void OutputUserInfo(vector<User>::iterator& _iter);

void CheckUserInfo()
{
	system("cls");
	cout << "1. 전체 유저 정보 확인" << endl;
	cout << "2. 유저 이름 검색" << endl;

	int input = 0;
	scanf_s("%d", &input);

	vector<User>::iterator iter;

	if (1 == input) {

		// 입력된 유저 수 만큼 반복한다.

		for (iter = g_user.begin(); g_user.end() != iter; ++iter)
		{
			OutputUserInfo(iter);
		}

		system("pause");
	}
	else if (2 == input)
	{
		// 검색할 이름을 입력받는다.
		printf("찾을 이름을 입력하세요\n");
		string inputname;
		cin >> inputname;

		// 전체 유저중에 검색 입력받은 이름에 해당하는 유저의 인덱스를 찾는다.	
		for (iter = g_user.begin(); g_user.end() != iter; ++iter)
		{
			// 전체 유저의 이름을 확인한다.
			// 입력된 이름과 유저의 이름이 같으면 이때 i 가 찾은 인덱스이다.
			if (inputname == iter->name)
			{
				break;
			}
		}

		// 입력된 이름과 같은 유저의 인덱스로, 정보를 출력한다.
		if (g_user.end() == iter)
		{
			cout << "유저를 찾을수 없습니다" << endl;
		}
		else {
			OutputUserInfo(iter);
		}

		// 대기
		system("pause");
		//}
	}
}

void OutputUserInfo(vector<User>::iterator& _iter)
{
	

	//User user = g_user.pData[_Idx];

	cout << "이름 : "<< _iter->name<<endl;
	cout << "나이 : "<< _iter->Age<<endl;

	if (1 == _iter->Sex)
	{
		cout << "성별 : 남자" << endl;
	}
	else
	{
		cout << "성별 : 여자" << endl << endl;
	}

}