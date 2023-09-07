#include "pch.h"
#include "CEngine.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"



CEngine::CEngine()
	: m_hWnd(nullptr)
	, m_ptResloution{}
	, m_hDC(nullptr)
	, m_hSubBitMap(nullptr)
	, m_hSubDC(nullptr)
{
	// pen, brush ����
	CreatePenBrush();
}

CEngine::~CEngine()
{
	// DC ����
	ReleaseDC(m_hWnd, m_hDC);

	// SubDC, Bitmap ����
	DeleteObject(m_hSubBitMap);
	DeleteDC(m_hSubDC);
	
	// Pen,Brush ����
	for (int i = 0; i < (UINT)PEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}

	for (int i = 0; i < (UINT)BRUSH_TYPE::END; i++)
	{
		DeleteObject(m_arrBrush[i]);
	}

}



void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	// ��� ���� �ʱ�ȭ
	m_hWnd = _hWnd;
	m_ptResloution = _ptResolution;
	m_hDC = GetDC(m_hWnd);

	// �ػ� ����
	SetWindowPos(m_hWnd, nullptr, 50, 50, m_ptResloution.x, m_ptResloution.y, 0);
	ShowWindow(m_hWnd, true);

	// �߰� ��Ʈ�� ����
	m_hSubBitMap = CreateCompatibleBitmap(m_hDC, m_ptResloution.x, m_ptResloution.y);
	m_hSubDC = CreateCompatibleDC(m_hDC);
	
	// m_SubDC�� ����Ʈ�� ����ִ� ��Ʈ���� ����
	DeleteObject((HBITMAP)SelectObject(m_hSubDC, m_hSubBitMap));

	// Manager �ʱ�ȭ
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CLevelMgr::GetInst()->init();

}

void CEngine::tick()
{
	// ------------ Manager Update ------------
	CTimeMgr::GetInst()->tick();
	CKeyMgr::GetInst()->tick();


	// ------------ update ------------
	CLevelMgr::GetInst()->tick();


	// ------------ render ------------
	CLevelMgr::GetInst()->render(m_hSubDC);



	// SubDC -> mainDC ����
	CopyBackBuffer();
	
}

void CEngine::CreatePenBrush()
{
	// red, green, blue blush ����
	m_arrBrush[(UINT)BRUSH_TYPE::RED] = CreateSolidBrush(RGB(255, 0, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::GREEN] = CreateSolidBrush(RGB(0, 255, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::BLUE] = CreateSolidBrush(RGB(0, 0, 255));
	m_arrBrush[(UINT)BRUSH_TYPE::BLACK] = CreateSolidBrush(RGB(0, 0, 0));


	// red, green, blue pen ����
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

}

void CEngine::CopyBackBuffer()
{
	// m_SubDC -> m_DC �� ����
	BitBlt(m_hDC, 0, 0, m_ptResloution.x, m_ptResloution.y, m_hSubDC, 0, 0, SRCCOPY);
}
