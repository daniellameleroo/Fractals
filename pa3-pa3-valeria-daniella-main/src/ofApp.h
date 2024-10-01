#pragma once

#include <cmath>
#include "SnowFlake.h"
#include "Fractal3D.h"
#include "FlowerFractal.h"
#include "juliaSet.h"
#include "heartFractal.h"


#include "ofMain.h"

class ofApp : public ofBaseApp {
  private:
  map<char, int> Levels;
    char mode = '1';
    float angle = 0;
bool debugInfo = false;
map<char, string> fractalNames = {
  {'1', "Circle"},
  {'2', "Tree"}, 
  {'3', "Sierpinski Triangle"},
  {'4', "Barnsley"}, 
  {'5', "SnowFlake"}, 
  {'6', "3D Fractal"},
  {'7',"Flower Fractal"},
  {'8', "Julia Set"},
  {'9', "Heart Fractal"}
};
    int CircleDepth = 3;
    int TreeDepth = 10;
    int SierpinskiDepth =7;
    int BarnsleyDepth = 10 ;
    int SnowflakeDepth = 1;
    int fractalLevel = 1;
    int FlowerLevel = 1;
    int juliaDepth = 1; 
    int heartbreak = 1; 
  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void drawMode1(float x, float y, float r, int n);
    void drawMode2(float x, float y, int n, float length, float rad);
    void drawMode3(float x, float y, float size, int n);
    void drawMode4(float x, float y, float n);

    FlowerFractal* flowerfractal = new FlowerFractal();
    JuliaSet* juliaFractal = new JuliaSet();
    SnowFlake* DrawedSnowflake = new SnowFlake();
    heartFractal* heartdepth = new heartFractal();
    int snowflakefix = 1;
    ofEasyCam cam;
    Fractal3D* fractal3d = new Fractal3D(); // 3D FRACTAL SEPCE
    ofTrueTypeFont text;
    ofTrueTypeFont dataText;
    bool animate = false;
    int frames = 60;
};
