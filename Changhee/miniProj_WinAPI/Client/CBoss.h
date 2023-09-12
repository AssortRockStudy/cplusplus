#pragma once
#include "CObj.h"

class CBoss :
    public CObj
{

private:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;


public:
    CBoss();
    ~CBoss();

};
