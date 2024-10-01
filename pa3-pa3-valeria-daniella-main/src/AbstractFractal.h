#pragma once

#include "ofMain.h"

using namespace glm;

class AbstractFractal {
    protected:
    string name; 
    int level;



  public:
AbstractFractal( string name, int level)
{
    this-> name = name;
    this-> level = level;
}
string getname();
void setname(string newname){ name = newname;}
int getlevel();
void setlevel(int newlevel){ level = newlevel;};
void drawFractal() ;
};