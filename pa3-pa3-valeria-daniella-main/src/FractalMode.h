#pragma once

#include "ofMain.h"
class FractalMode{
    public:

        virtual void draw(int x, int y, int n, int r, int g, int b,int size) = 0;
        virtual bool getName() = 0;
        virtual void getLevel(bool activation) = 0;
};
