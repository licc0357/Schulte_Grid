#pragma once
#include <afxwin.h>
class CCaption :
    public CStatic
{
public:
    HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    //    HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    void Init(int nX, int nY, int nW, int nH);
};

