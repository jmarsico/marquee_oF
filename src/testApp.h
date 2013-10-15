#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    float renderNoise(int x, int y);
   
    
    int cellSize;
    // Number of columns and rows in our system
    int cols, rows;
    float noiseScale;
    float noiseVal;
    float noiseIncrement;
    float x[12];
    float y[8];

    ofColor br[96];
    ofVideoGrabber vidGrabber;
    



};
