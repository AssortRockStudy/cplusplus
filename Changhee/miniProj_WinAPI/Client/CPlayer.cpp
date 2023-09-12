#include "pch.h"
#include "CPlayer.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"

#include "CLevel.h"

#include "CProjectile.h"

CPlayer::CPlayer()
	: m_fSpeed(100.f)
	, m_vDir{0.f,0.f}
{
}

CPlayer::~CPlayer()
{
}



void CPlayer::tick(float _DT)
{
	Vec2 vPos = GetPos();

	m_vDir = {0.f, 0.f};
	
	if (KEY_PRESSED(KEY::W))
	{
		m_vDir.y -= 1.f;
	}

	if (KEY_PRESSED(KEY::S))
	{
		m_vDir.y += 1.f;
	}
	
	if (KEY_PRESSED(KEY::A))
	{
		m_vDir.x -= 1.f;
	}
	
	if (KEY_PRESSED(KEY::D))
	{
		m_vDir.x += 1.f;
	}

	if (m_vDir.Length() != 0.f)
	{
		vPos = vPos + (m_vDir.Normalize() * m_fSpeed *_DT);
	}



	if (KEY_TAP(KEY::SPACE))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CProjectile* pProjectile = new CProjectile;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(1000.f);
		pProjectile->SetDir(PI / 2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));

		pCurLevel->AddObject(pProjectile);
	}

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	CPalette BlackBrush(_dc, BRUSH_TYPE::BLACK);

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}


