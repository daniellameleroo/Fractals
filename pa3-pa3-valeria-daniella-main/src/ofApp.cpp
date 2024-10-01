#include "ofApp.h"
#include "Fractal3D.h"
#include "heartFractal.h"


//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",30);
    dataText.load("Fonts/fractalFont.otf",15);
    fractal3d = new Fractal3D(&cam); // 3D FRACTAL Spec
    frames = 60;
    animate = false;
}

//--------------------------------------------------------------
void ofApp::update() {
    if( animate == true)
{

if( mode == '1') 
{
    
    if(ofGetFrameNum() % frames ==  0)
    {

        if( CircleDepth < 5)
        {
        CircleDepth++;
        }
        else
        CircleDepth = 1;

    }
}
else if( mode == '2')
{
   
    if(ofGetFrameNum() % frames ==  0)
    {
        if( TreeDepth < 15)
        {
        TreeDepth++;
        }
        else
        TreeDepth = 1;
    }
}

else if( mode == '3')
{
    if(ofGetFrameNum() % frames ==  0)
    {
        if( SierpinskiDepth < 10)
        {
        SierpinskiDepth++;
        }
        else
        SierpinskiDepth = 1;
    }
}


else if( mode == '4')
{
    if(ofGetFrameNum() % frames ==  0)
    {
        if( BarnsleyDepth < 50)
        {
        BarnsleyDepth++;
        }
        else
        BarnsleyDepth = 5;
    }
}

else if( mode == '5')
{
    if(ofGetFrameNum() % frames ==  0)
    {
        if(  SnowflakeDepth > 1)
        {
        snowflakefix++;
        SnowflakeDepth--;
        }
        else{
        snowflakefix = 1;
        SnowflakeDepth = 6;}
    }
}
else if( mode == '6')
{
    if( ofGetFrameNum() % frames == 0)
    {
        if(fractalLevel < 9 )
        {

            fractalLevel++;
        }
        else
        fractalLevel = 0;


    }


}

else if( mode == '7')
{
    if( ofGetFrameNum() % frames == 0)
    {
        if(FlowerLevel < 9 )
        {

            FlowerLevel++;
        }
        else
        FlowerLevel = 0;


    }


}
else if ( mode == '8'){
 if( ofGetFrameNum() % frames == 0)
 {
    if(juliaDepth < 9)
    {
        juliaDepth++;
    }
    else
    juliaDepth = 0;
 }
}
else if( mode == '9')
{
    if( ofGetFrameNum() % frames == 0)
    {
        if(heartbreak < 9 )
        {

            heartbreak++;
        }
        else
        heartbreak = 0;


    }


}
}
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);
       
       
    
    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        text.drawString("Circle",25,60);

        float r = (0.31 * ofGetHeight());
        angle += 0.01;
        drawMode1((ofGetWidth() / 2), ofGetHeight() / 2, r, CircleDepth);
    } break;
    case '2': {
        // Tree
        text.drawString("Tree",25,60);
        float r2 = 1.5 *PI;
        float length = 0.31 * ofGetHeight();
        float HalfLength = 0.10* ofGetHeight();

        drawMode2(ofGetWidth() / 2, ofGetHeight() - 40, TreeDepth, length, r2);

        drawMode2(ofGetWidth() / 2 - 1.82 * length, ofGetHeight()-15, TreeDepth, HalfLength, r2);

        drawMode2(ofGetWidth() / 2 + 1.82 * length, ofGetHeight() - 15, TreeDepth, HalfLength, r2);

        
    } break;
    case '3': {
        // Sierpinski Triangle
        text.drawString("Sierpinski Triangle",25,60);

        float size = 0.88 * ofGetHeight();
{
}        drawMode3((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, SierpinskiDepth);
    } break;
    case '4': {
        // Barnsley Fern
        text.drawString("Barnsley Fern",25,60);

        drawMode4(0, 0, BarnsleyDepth*1000);
    }    break;
    case '5': {
        // Koch SnowFlake
        text.drawString("Koch SnowFlake",25,60);

        DrawedSnowflake->setSnowflakeDepth(SnowflakeDepth);
        DrawedSnowflake->draw();
    }   break;
    case '6': {
        //3d Fractal
        text.drawString("3D Fractal",25,60);

           Fractal3D(&cam).draw(map<string, float> {{"n", fractalLevel}, {"scale", 100}});
    }   break;
    case '7': {

        text.drawString("Flower Fractal",25,60);


           flowerfractal->draw(ofGetWidth()/ 2,ofGetHeight()/ 2,FlowerLevel,ofRandom( 0, 255 ),ofRandom( 128, 255 ),ofRandom( 0, 255 ),200);
    }   break;

    case '8': {
        
        text.drawString("GOTCHA",500,500);
        text.drawString("Give me bonus plis", 500, 1000);
       

           juliaFractal->draw(ofGetWidth()/ 2,ofGetHeight()/ 2,juliaDepth,ofRandom( 0, 255 ),ofRandom( 128, 255 ),ofRandom( 0, 255 ),200);
    }   break;// 3D FRACTAL Spec
    case '9': {
        
        text.drawString("Heart Fractal",25,60);
       
         heartdepth->draw(ofGetWidth()/ 2,ofGetHeight()/ 2,heartbreak,ofRandom( 0, 255 ),ofRandom( 128, 255 ),ofRandom( 0, 255 ),200);
    }   break;
    }


    if(debugInfo==true){
    text.drawString("1. Circle Level:",15,180);
    text.drawString(to_string(CircleDepth),300,180);

    text.drawString("2. Tree Level:",15,280);
    text.drawString(to_string(TreeDepth),300,280);

    text.drawString("3. Triangle Level:",15,380);
    text.drawString(to_string(SierpinskiDepth),350,380);

    text.drawString("4. Barnsley Level:",15,480);
    text.drawString(to_string(BarnsleyDepth),340,480);

    text.drawString("5. SnowFlake Level:",15,580);
    text.drawString(to_string(SnowflakeDepth),380,580);

    text.drawString("6. 3D Fractal Level:",15,680);
    text.drawString(to_string(fractalLevel),400,680);

    text.drawString("7. Flower Fractal:",15,780);
    text.drawString(to_string(FlowerLevel),400,780);

    text.drawString("8. Julia Set:",15,880);
    text.drawString(to_string(juliaDepth),400,880);

    text.drawString("9. Heart Fractal:",1000,300);
    text.drawString(to_string(heartbreak),1250,300);

    text.drawString("Right Key To Level Up",1000,60);
    text.drawString("Left Key To Level Down",1000,130);
    }
}

void ofApp::drawMode1(float x, float y, float r, int n) {
    if (n == 0) return;

    int delta = r * 0.35;
    ofSetColor((int)((n * 150) % 256), (int)((n * 150 + 85) % 256), (int)((n * 150 + 170) % 256),(int)((n * 150 + 200) % 256));    
    ofDrawCircle(x, y, r);
    //ofSetColor( ofColor(ofRandom( 0, 255 ), ofRandom( 0, 255 ), ofRandom( 0, 255 )));
    ofSetColor(255,255,255);

    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    drawMode1(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1);
    drawMode1(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1);
    drawMode1(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1);
    drawMode1(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1);
    drawMode1(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1);
    drawMode1(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1);
}


void ofApp::drawMode2(float x, float y, int n, float length, float rad) {
    if (n == 0) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofSetColor((int)((n * 100) % 256), (int)((n * 85 ) % 256), (int)((n * 220) % 256),(int)((n * 248 ) % 256));     
    ofDrawLine(x, y, x2, y2);
    ofSetColor(255,255,255);

    drawMode2(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI);
    drawMode2(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI);
}

void ofApp::drawMode3(float x, float y, float size, int n) {
    if (n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofSetColor((int)((n * 85) % 256), (int)((n * 100 + 85) % 256), (int)((n * 90 + 85) % 256));
    ofDrawTriangle(a, b, c);
    ofSetColor(ofColor::white);


    drawMode3(x, y, size / 2, n - 1);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    drawMode3((c.x + a.x)/2, (c.y + a.y)/2 , size/2 , n - 1); // Sirpisnki triangle fixed 
    ofSetColor((int)((n * 150) % 256), (int)((n * 150 + 85) % 256), (int)((n * 150 + 170) % 256));
    ofDrawTriangle(a, b, c);
    ofSetColor(ofColor::white);
}

void ofApp::drawMode4(float x, float y, float n) {
    if (n == 0) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    //ofFill();
    ofSetColor((int)((int(n) * 150) % 256), (int)((int(n) * 150 + 85) % 256), (int)((int(n) * 150 + 170) % 256));
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);
    

    if (r < 0.01)
        drawMode4(0, 0.16 * y, n - 1);

    else if (r < 0.86)
        drawMode4(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (r < 0.93)
        drawMode4(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        drawMode4(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '9'){
        mode = key;
    }

    if( key == OF_KEY_RIGHT)
    {
     
     if(mode == '1' && CircleDepth < 5)
     {

        CircleDepth++;
     }
     else if( mode == '2'  && TreeDepth < 15)
     {

        TreeDepth++;
     }
     else if( mode == '3' &&  SierpinskiDepth < 10)
     {

        SierpinskiDepth++;
     }
     else if( mode == '4' && BarnsleyDepth < 50)
     {

        BarnsleyDepth++;
     }
else if( mode == '5' && SnowflakeDepth < 6 )
     {

    //    snowflakefix ++;
       SnowflakeDepth+=1;
     }
else if( mode == '6' && fractalLevel< 9)
{

    fractalLevel +=1;
} // 3D FRACTAL Spec
else if( mode == '7' && FlowerLevel< 5)
{

    FlowerLevel +=1;
}

else if(mode == '8' && juliaDepth < 100)
{
    juliaDepth +=1;
}

else if(mode == '9' && heartbreak < 4)
{
    heartbreak +=1;
}
    }
     if( key == OF_KEY_LEFT)
    {

    if(mode == '1' && CircleDepth > 1)
     {

        CircleDepth--;
     }
     else if( mode == '2' && TreeDepth > 1)
     {

        TreeDepth--;
     }
     else if( mode == '3' && SierpinskiDepth > 1)
     {

        SierpinskiDepth--;
     }
     else if( mode == '4' && BarnsleyDepth > 5 )
     {

        BarnsleyDepth--;
     }
else if( mode == '5' && SnowflakeDepth >=1  )
     {
        //snowflakefix--;
        SnowflakeDepth-=1;
     }
else if( mode == '6' && fractalLevel > 0)
{

    fractalLevel-=1;
}
else if( mode == '7' && FlowerLevel > 0)
{

    FlowerLevel-=1;
} 
else if ( mode == '8' && juliaDepth > 0 )
{
    juliaDepth-=1;
}  

else if ( mode == '9' && heartbreak > 0 )
{
    heartbreak-=1;
} 
    }
if(key == 'd'){
    debugInfo = !debugInfo ;
 }
if( key == 32)
{

    animate = !animate;
}

};

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}