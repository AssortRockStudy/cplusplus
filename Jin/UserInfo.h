#pragma once
#include <string>
using std::string;
class UserInfo
{
public:
	string name;
	int age;
	int sex;

public:
	UserInfo()
		: name(""), age(0), sex(-1)
	{}
	UserInfo(string _name, int _age, int _sex)
		: name(_name), age(_age), sex(_sex)
	{}
	~UserInfo() {}
};

