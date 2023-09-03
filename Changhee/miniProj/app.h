#pragma once

#include <string>
#include <iostream>
#include <conio.h>
#include <map>
#include <vector>
#include <assert.h>
#include <algorithm>

using std::string;
using std::vector;

using std::cout;
using std::cin;
using std::endl;
using std::map;


enum GROUP_TYPE
{
	TYPE1 = 1,
	TYPE2,
	TYPE3,

	END,
};


struct tUser
{
	string Name;
	int Age;
	int Sex;
	GROUP_TYPE Type;

	void print()
	{
		cout << "이름 : " << Name << endl;

		if (Sex == 1)
		{
			cout << "성별 : 남" << endl;
		}
		else
		{
			cout << "성별 : 여" << endl;
		}

		cout << "나이 : " << Age << endl;


		cout << "GROUP : ";
		switch (Type)
		{
		case TYPE1:
			cout << "1\n";
			break;
		case TYPE2:
			cout << "2\n";
			break;
		case TYPE3:
			cout << "3\n";
			break;
		default:
			assert(nullptr);
			break;
		}
	}
};




class app
{
private:
	vector<tUser*> m_vecUser;

public:
	void run();
	void userRegister();
	void userPrint();
	void userSearch();
	void userEdit();
	void userDel();


public:
	app()
	{}
	~app()
	{
		for (int i = 0; i < m_vecUser.size(); ++i)
		{
			delete m_vecUser[i];
			m_vecUser[i] = nullptr;
		}
		m_vecUser.clear();
	}
};

