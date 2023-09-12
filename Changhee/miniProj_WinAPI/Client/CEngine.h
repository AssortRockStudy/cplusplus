#pragma once


class CEngine
{
	SINGLETON(CEngine);

private:
	HWND		m_hWnd;				// ���� ������ �ڵ�
	POINT		m_ptResloution;		// ������ �ػ� ����
	HDC			m_hDC;				// ���� DC
	
	HDC			m_hSubDC;			// BackBuffer DC
	HBITMAP		m_hSubBitMap;		// BackBuffer BitMap

	// ���� ����� pen, brush
	HPEN	m_arrPen[(UINT)PEN_TYPE::END];
	HBRUSH	m_arrBrush[(UINT)BRUSH_TYPE::END];

private:
	void CreatePenBrush();
	void CopyBackBuffer();


public:
	HWND GetMainWind() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResloution; }

	HPEN GetPEN(PEN_TYPE _ePenType) { return m_arrPen[(UINT)_ePenType]; }
	HBRUSH GetBRUSH(BRUSH_TYPE _eBrushType) { return m_arrBrush[(UINT)_eBrushType]; }

public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();
};

