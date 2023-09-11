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
		None, AddUser, PrintAllUser, SearchUserInfo, ChangeUser, Exit
	};
	bool Selecting();
	void AddUserInfo();
	void PrintUserInfo(vector<UserInfo*>::iterator _user);
	void PrintAllUserInfo();
	void AlwaysLast();
	void SearchUser();
	void ChangeUserInfo();
	vector<UserInfo*>::iterator  SearchForName();
	//void CommonSearch();
};


