#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0,0,0);
    //ofSetBackgroundAuto(false);
    cellSize = ofGetWidth()/12;
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableAlphaBlending();
    
    	
    //we can now get back a list of devices.
	vector<ofVideoDevice> devices = vidGrabber.listDevices();
	
    for(int i = 0; i < devices.size(); i++){
		cout << devices[i].id << ": " << devices[i].deviceName;
        if( devices[i].bAvailable ){
            cout << endl;
        }else{
            cout << " - unavailable " << endl;
        }
	}
    
	vidGrabber.setDeviceID(0);
    vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(12, 8);
    //img.allocate(camWidth, camHeight, OF_IMAGE_GRAYSCALE);
	
	ofSetVerticalSync(true);
    //ofSetFrameRate(60);
    
    noiseScale= 0.03;
    noiseIncrement = 0.01;


}

//--------------------------------------------------------------
void testApp::update(){
        
    
	vidGrabber.update();                                 //update the vidGrabber
    if(vidGrabber.isFrameNew())
    {
        ofPixels pix = vidGrabber.getPixelsRef();
        for(int i = 0; i < 12; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                br[i+(i*j)] = (pix.getColor(i,j).getLightness())*0.7;
                
                noiseVal = renderNoise(i,j);
                
                br[i+(i*j)] = br[i+(i*j)] + noiseVal;
                
            }
        }
        
    }
    noiseIncrement += noiseIncrement;

}


//--------------------------------------------------------------
float testApp::renderNoise(int x, int y)
{
    float tempVal = ofNoise((x+1)*noiseScale*noiseIncrement, (y+1)*noiseScale*noiseIncrement);
    tempVal = ofMap(tempVal, 0.0, 1.0, 0.0, 155.0);
    return tempVal;
    
}


//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            ofPushMatrix();
                ofSetColor(br[i+(i*j)]);
                ofTranslate(i*cellSize, j*cellSize);
                // Rotation formula based on brightness
                //rotate((2 * PI * brightness(c) / 255.0));
                //rectMode(CENTER);
                ofFill();
                // Rects are larger than the cell for some overlap
                ofRect(0, 0, cellSize, cellSize);
            ofPopMatrix();
        }
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
