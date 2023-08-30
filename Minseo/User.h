#pragma once
#include <string>
#include <map>

class User
{
public: // 멤버 변수
	std::string	m_Name;
	std::string	m_Group;
	int		m_Sex;
	int		m_Age;
public: // 생성자, 소멸자
	User();
	//User(string	Name, string Group, int	Sex, int Age);
	~User();
};

extern std::map<std::string, User> userMap;