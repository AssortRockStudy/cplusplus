#pragma once
#include <vector>
#include "UserInfo.h"
using std:: vector;
class UserInfoAdmin
{
private:
	vector<UserInfo*> users;
public:
	void StartProgram();
private:
	bool Selecting();
	void AddUserInfo();
	void PrintUserInfo();
	void AlwaysLast();
};


