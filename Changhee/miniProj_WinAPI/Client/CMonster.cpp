#include "pch.h"
#include "CMonster.h"

#include "CKeyMgr.h"


CMonster::CMonster()
	: m_fSpeed(100.f)
	, m_fAcc(0.f)
	, m_iDir(1)
{
}

CMonster::~CMonster()
{
}



void CMonster::tick(float _DT)
{
	Vec2 vPos = GetPos();

	m_fAcc += _DT;

	if (m_fAcc > 2.f)
	{
		m_iDir *= -1;
		m_fAcc = 0.f;
	}
	
	vPos.x += m_iDir * m_fSpeed * _DT;

	SetPos(vPos);

}

void CMonster::render(HDC _dc)
{
	CPalette RedBrush(_dc, BRUSH_TYPE::RED);
	CPalette RedPen(_dc, PEN_TYPE::RED);

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc 
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}

