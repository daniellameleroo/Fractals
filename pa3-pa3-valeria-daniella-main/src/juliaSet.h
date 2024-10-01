#pragma once

#include "FractalMode.h"

class JuliaSet : public FractalMode{
    private:
        bool isActive;
        int level;

    public:
    JuliaSet();
    void draw(int x, int y, int n, int r, int g, int b,int size);
    bool getName();
    void getLevel(bool activation);
};