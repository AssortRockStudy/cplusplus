#pragma once
#include <string>

using namespace std;

class User
{
public: // 멤버 변수
	string	m_Name;
	string	m_Group;
	int		m_Sex;
	int		m_Age;
public: // 생성자, 소멸자
	User();
	User(string	Name, string Group, int	Sex, int Age);
	~User();
};

extern map<string, User> userMap;