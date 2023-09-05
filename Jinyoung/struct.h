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
	unsigned int	Group;

	bool operator == (const User& _other) 
	{
		return name == _other.name &&
			Age == _other.Age &&
			Sex == _other.Sex &&
			Group == _other.Group;
	}

};

 


extern vector<User> g_user;