#include "JuliaSet.h"

JuliaSet::JuliaSet() {
    isActive = false;
}

void JuliaSet::draw(int x, int y, int n, int r, int g, int b, int size) {
   if(n == 0) return;
   

   
    for (int i = 0; i < ofGetWidth(); ++i) {
        for (int j = 0; j < ofGetHeight(); ++j) {
           
            float a = ofMap(i, 0, ofGetWidth(), -2.0, 2.0); 
            float b = ofMap(j, 0, ofGetHeight(), -2.0, 2.0); // Map y to the range -2 to 2
            int level = n; 
           
            float ca = a;
            float cb = b;

          
            int n = 0;
            int maxIterations = level;
            while (n < maxIterations) {
                float aa = a * a - b * b;
                float bb = 2 * a * b;
                a = aa + ca;
                b = bb + cb;

               
                if (a * a + b * b > 16) {
                    break; 
                }
                ++n;
            }

        

            ofSetColor((int)((n * 150) % 256), (int)((n * 150 + 85) % 256), (int)((n * 150 + 170) % 256),(int)((n * 150 + 200) % 256));
            ofDrawRectangle(i, j, 1, 1); // Draw a pixel
            ofSetColor(ofColor::white);
             level +=1;
        }
    }
}

bool JuliaSet::getName() {
    return isActive;
}

void JuliaSet::getLevel(bool activation) {
    isActive = activation;
}
