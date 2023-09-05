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
	enum menu
	{
		None, AddUser, PrintAllUser, SearchUser, Exit
	};
	bool Selecting();
	void AddUserInfo();
	void PrintUserInfo(int _idx);
	void PrintAllUserInfo();
	void AlwaysLast();
	void SearchUserName();
	//void CommonSearch();
};


