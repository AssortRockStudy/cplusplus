#include <stdio.h>
#include <stdlib.h>

#include <string>
#include "struct.h"
#include <iostream>
#include <algorithm> 


// 특정 인덱스에 해당하는 유저정보 출력
void moduser();
void deluser();
void usernamesearch(vector<User>& _outuser);
void sexfilter(vector<User>& _outuser);
void agefilter(vector<User>& _outuser);
void alluser(vector<User>& _outuser);
void OutputUserInfo(vector<User>::iterator& _iter);
bool namecmpasc(User& _A, User& _B);
bool namecmpdes(User& _A, User& _B);
bool cmpid(User& _A, User& _B);

using namespace std;

void CheckUserInfo()
{
	system("cls");
	cout << "1. 유저 정보 확인" << endl;
	cout << "2. 유저 정보수정" << endl;
	cout << "3. 유저 정보삭제" << endl;

	int input = 0;
	cin>>input;

	//출력용 유저
	vector<User> outuser = g_user;

	if (1 == input) {
		usernamesearch(outuser);
		system("pause");
	}
	else if (2 == input)
	{
		usernamesearch(outuser);
		if (outuser.size())
		{
			moduser();
		}
		system("pause");
	}
	else if (3 == input)
	{
		usernamesearch(outuser);
		if (outuser.size())
		{
			deluser();
		}
		system("pause");
	}

}


void moduser()
{
	cout << "수정할 유저를 고르시오 (아이디입력)" << endl;
	string inputstr;
	getline(cin, inputstr);
	int input = stoi(inputstr);

		vector<User>::iterator iter ;

		for (iter = g_user.begin(); g_user.end() != iter; ++iter)
		{
			if (input == iter->ID)
			{
				break;
			}
		}

		if (g_user.end() == iter)
		{
			cout << "ID를 찾을 수 없습니다." << endl;
			return;
		}

		system("cls");

		cout << "바꿀유저 정보를 입력하세요" << endl;
		cout << "이름을 입력하세요 (엔터입력시 안바꿈)" << endl;
		getline(cin, inputstr);

		if ("" != inputstr)
		{
			iter->name = inputstr;
		}


		cout << "성별을 입력하세요( 남자 : 1, 여자 2 ,엔터 그대로)" << endl;
		getline(cin, inputstr);

		if ("1" == inputstr || "2" == inputstr)
		{
			iter->Sex = inputstr[0];
		}

		cout << "나이를 입력하세요(엔터 그대로)" << endl;
		getline(cin, inputstr);
		if ("" != inputstr)
		{
			iter->Age = stoi(inputstr);
		}

		cout << "유저를 수정했습니다" << endl;
}


void deluser()
{
	cout << "삭제할 유저를 고르시오 (아이디입력)" << endl;
	string inputstr;
	getline(cin, inputstr);
	int input = stoi(inputstr);

	vector<User>::iterator iter;

	for (iter = g_user.begin(); g_user.end() != iter; ++iter)
	{
		if (input == iter->ID)
		{
			break;
		}
	}

	if (g_user.end() == iter)
	{
		cout << "ID를 찾을 수 없습니다." << endl;
		return;
	}

	system("cls");
	iter =g_user.erase(iter);

	cout << "유저를 삭제했습니다" << endl;
}


void usernamesearch(vector<User>& _outuser)
{
	// 검색할 이름을 입력받는다.
	cout << "찾을 이름을 입력하세요(엔터만 누를시 전체)" << endl;
	// 전체 유저중에 검색 입력받은 이름에 해당하는 유저의 인덱스를 찾는다.
	string inputname;
	//버퍼에서 \n제거
	cin.ignore();
	getline(cin, inputname);

	//이름을 입력햇을 경우
	if ("" == inputname)
	{
		sexfilter(_outuser);
		return;
	}

	vector<User>::iterator iter;
	for (iter = _outuser.begin(); _outuser.end() != iter;)
	{
		//순회하면서 이름이다른것 remove
		if (inputname != iter->name)
		{
			iter = _outuser.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	// 입력된 이름과 같은 유저의 인덱스로, 정보를 출력한다.
	if (_outuser.size())
	{
		alluser(_outuser);
	}
	else {
		cout << "유저를 찾을수 없습니다" << endl;
	}



}



void sexfilter(vector<User>& _outuser)
{
	// 필터할 성별을 받는다.
	cout << "성별을 제한하려면 1(남자)혹은 2(여자)를 입력하세요(엔터만 누를시 전체)" << endl;
	char inputsex;
	//버퍼에서 \n제거
	cin.get(inputsex);

	if ('1' == inputsex||'2'==inputsex) {
		vector<User>::iterator iter;
		for (iter = _outuser.begin(); _outuser.end() != iter;)
		{
			//순회하면서 성별이다른것 remove
			if (inputsex != ((iter->Sex)+48))
			{
				iter=_outuser.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	agefilter(_outuser);

}


void agefilter(vector<User>& _outuser)
{
	// 필터할 나이대을 받는다.
	cout << "나이대를 제한하려면 10단위로 입력해주세요 (ex 20->20대) 제한x=엔터 " << endl;
	string inputage;
	//버퍼에서 \n제거
	getline(cin, inputage);



	if ("" != inputage) {
		int age[2];
		age[0] = stoi(inputage);
		age[1] = stoi(inputage) + 9;
		vector<User>::iterator iter;
		for (iter = _outuser.begin(); _outuser.end() != iter;)
		{
			//순회하면서 조건에맞지않는 것제거
			if ((age[0] > iter->Age) || (age[1] < iter->Age))
			{
				iter = _outuser.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
	alluser(_outuser);
}



void OutputUserInfo(vector<User>::iterator& _iter)
{


	cout << "ID : " << _iter->ID << endl;
	cout << "이름 : " << _iter->name << endl;
	cout << "나이 : " << _iter->Age << endl;

	if (1 == _iter->Sex)
	{
		cout << "성별 : 남자" << endl << endl;;
	}
	else
	{
		cout << "성별 : 여자" << endl << endl;
	}

}



void alluser(vector<User>& _outuser) {


	if (_outuser.size())
	{
		char order;
		cout << "이름 정렬기준을 선택하세요. 1오름차순 2내림차순 엔터 기준없음" << endl;
		cin.get(order);
		if (49 == order)
		{
			sort(_outuser.begin(), _outuser.end(), namecmpasc);
		}
		if (50 == order)
		{
			sort(_outuser.begin(), _outuser.end(), namecmpdes);
		}

		vector<User>::iterator iter;
		for (iter = _outuser.begin(); _outuser.end() != iter; ++iter)
		{
			OutputUserInfo(iter);
		}
	}
	else
	{
		cout << "표시할 유저가 없습니다." << endl;
	}
}


bool namecmpasc(User& _A, User& _B)
{
	return _A.name < _B.name;
}


bool namecmpdes(User& _A, User& _B)
{
	return _A.name > _B.name;
}

bool cmpid(User& _A, User& _B)
{
	return _A.ID < _B.ID;
}