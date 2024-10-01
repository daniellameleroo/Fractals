#pragma once

#include "FractalMode.h"

class FlowerFractal : public FractalMode{
    private:
        bool isActive;
        int level;

    public:
    FlowerFractal();
    void draw(int x, int y, int n, int r, int g, int b,int size);
    bool getName();
    void getLevel(bool activation);


};

