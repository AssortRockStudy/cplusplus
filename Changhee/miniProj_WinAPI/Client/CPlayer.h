#pragma once
#include "CObj.h"
class CPlayer :
    public CObj
{
private:
    Vec2    m_vDir;
    float   m_fSpeed;



public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;


public:
    CPlayer();
    ~CPlayer();

};

