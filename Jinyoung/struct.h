#pragma once

#include <vector>
#include <string>

using namespace std;

class User
{
public:
	string			name;
	int	Age;
	unsigned char	Sex; // 1, 2
	unsigned int	ID;
};


extern vector<User> g_user;