#include "FlowerFractal.h"

FlowerFractal::FlowerFractal(){
    isActive = false;
}

void FlowerFractal::draw(int x, int y, int n, int r, int g, int b, int size) {
    if (n <= 0) return;

    // Draw the flower
    ofSetColor((int)((n * 200) % 256), (int)((n * 150 ) % 256), (int)((n * 220) % 256),(int)((n * 248 ) % 256)); 
    ofDrawEllipse(x, y, size, size); // Draw the main flower

    // Calculate the radius of the circle
    float radius = size / 2;

    // Define the angle between branches
    float angleOffset = PI / 4;

    // Define the number of branches
    int numBranches = 8;

    // Calculate the angle increment between branches
    float angleIncrement = TWO_PI / numBranches;

    for (int i = 0; i < numBranches; ++i) {
        // Calculate the angle for this branch
        float angle = i * angleIncrement + angleOffset;

        // Calculate the position for the end of this branch
        int endX = x + cos(angle) * (radius + size * 0.4); // Start outside the circle
        int endY = y + sin(angle) * (radius + size * 0.4); // Start outside the circle

        // Draw the branch
        ofSetColor(ofColor::green); // Set color to green
        ofDrawLine(x, y, endX, endY);
        ofSetColor(ofColor::white);

        // Draw a smaller flower at the end of this branch recursively
        draw(endX, endY, n - 1, r, g, b, size * 0.5);
    }
    
}



bool FlowerFractal::getName(){return isActive;}

void FlowerFractal::getLevel(bool activation){
    isActive = activation;
}

