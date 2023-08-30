#pragma once
#include <string>
#include <map>

class User
{
public: // ��� ����
	std::string	m_Name;
	std::string	m_Group;
	int		m_Sex;
	int		m_Age;
public: // ������, �Ҹ���
	User();
	//User(string	Name, string Group, int	Sex, int Age);
	~User();
};

extern std::map<std::string, User> userMap;