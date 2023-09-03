#pragma once

#include <vector>

using namespace std;

class User
{
public:
	char			name[10];
	int	Age;
	unsigned char	Sex; // 1, 2
	unsigned int	ID;
};


extern vector<User> g_user;