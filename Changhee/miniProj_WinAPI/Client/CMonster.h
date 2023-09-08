#pragma once
#include "CObj.h"
class CMonster :
    public CObj
{
private:
    float       m_fSpeed;
    float       m_fAcc;
    int         m_iDir;

private:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;


public:
    CMonster();
    ~CMonster();

};

