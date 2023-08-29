#include "User.h"

User::User()
	:m_Name(nullptr)
	, m_Group(nullptr)
	,m_Age(0)
	,m_Sex(0)
{
}

User::User(string Name, string Group, int Sex, int Age)
	:m_Name(Name)
	, m_Group(Group)
	,m_Sex(Sex)
	,m_Age(Age)
{
}

User::~User()
{
}
