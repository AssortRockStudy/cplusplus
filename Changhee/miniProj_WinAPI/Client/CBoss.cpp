#include "pch.h"
#include "CBoss.h"

#include "CPalette.h"

CBoss::CBoss()
{
}

CBoss::~CBoss()
{
}


void CBoss::tick(float _DT)
{
}

void CBoss::render(HDC _dc)
{
	CPalette RedBrush(_dc, BRUSH_TYPE::RED);

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
	

}

