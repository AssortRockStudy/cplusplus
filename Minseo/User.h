#pragma once
#include <string>

using namespace std;

class User
{
public: // ��� ����
	string	m_Name;
	string	m_Group;
	int		m_Sex;
	int		m_Age;
public: // ������, �Ҹ���
	User();
	User(string	Name, string Group, int	Sex, int Age);
	~User();
};

extern map<string, User> userMap;