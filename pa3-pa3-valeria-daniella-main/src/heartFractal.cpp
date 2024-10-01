#include "heartFractal.h"

heartFractal::heartFractal() {
    isActive = false;
}

void heartFractal::draw(int x, int y, int n, int r, int g, int b, int size) {
     if(n == 0) return;
   
    for (int i = 0; i < ofGetWidth(); ++i) {
        for (int j = 0; j < ofGetHeight(); ++j) {
          
            float a = ofMap(i, 0, ofGetWidth(), -2.0, 2.0); 
            float b = ofMap(j, 0, ofGetHeight(), -2.0, 2.0);
            
          
            float dist = sqrt((a * a) + (b * b));
            
           
            if (pow(a * a + b * b - 1, 3) - a * a * b * b * b < 0) {
              
                ofSetColor((int)((n * 240) % 256), (int)((n * 200) % 256), (int)((n * 200) % 256),(int)((n * 150 + 40) % 256));
                ofDrawRectangle(i, ofGetHeight() - j, 1, 1); 
                ofSetColor(ofColor::white);
                level +=1;

            }
        }
    }
}

bool heartFractal::getName() {
    return isActive;
}

void heartFractal::getLevel(bool activation) {
    isActive = activation;
}
