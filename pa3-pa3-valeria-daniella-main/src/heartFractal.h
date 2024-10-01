#pragma once

#include "FractalMode.h"

class heartFractal : public FractalMode{
    private:
        bool isActive;
        int level;

    public:
    heartFractal();
    void draw(int x, int y, int n, int r, int g, int b,int size);
    void drawHeart(int x, int y, int size, int r, int g, int b);

    bool getName();
    void getLevel(bool activation);
};