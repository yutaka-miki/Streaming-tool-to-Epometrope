#include "ofApp.h"

ofTrueTypeFont font;

// float e = 0.0;

ofEasyCam cam;

int Width = 1600;
int Height = 960;

float camDeg = 0.0;
float camRad = 0.0;
int camDis = 1500;

float t = 0.0;
float tDeg = 0.0;

// int StartPoint = 300;
// int BoxSize = 50;

ofLight PointLight2;
ofLight PointLight3;

ofPoint LightPoint4 = ofPoint(-1000,250,-500); 
ofPoint LightPoint5 = ofPoint(-1000,250,500); 

float brightness2 = -0.3;
float brightness3 = -0.3;

bool text = 1;

float pos = 0;
int PosTotal = 16;
int W = 4;
int H = 4;

ofFbo fbo1;
ofFbo fbo2;
ofTexture tex;	
ofPixels pixels;
ofImage image;

int a = 0;


//--------------------------------------------------------------
void ofApp::setup(){

    MyClass m;
    // m.set

    font.load("RictyDiminished-Regular.ttf",12);
    ofSetFrameRate(60);

    ofEnableDepthTest();
    cam.setDistance(camDis); //EasyCam
    cam.setFov(10.0f);

    fbo1.allocate(400, 240);

    ofSetBackgroundAuto(false);
    ofBackground(50);

}

//--------------------------------------------------------------
void ofApp::update(){

    pos = 0; 
    ofClear(50); 
    
    // if( pos >= PosTotal ){ pos = 0; }
    // if( pos >= PosTotal ){ 
    //     pos = 0; 
    //     // ofClear(50); 
    //     // ofClear()
    // }

    // if(0 <= pos < H){
    //     ofRect(0, (H-1-int(pos))*Height/H, Width/W , Height/H);
    // }else if(H <= pos && pos < 2*H){
    //     ofRect(Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
    // }else if(2*H <= pos && pos < 3*H){
    //     ofRect(2*Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
    // }else if(3*H <= pos && pos < 4*H){
    //     ofRect(3*Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
    // }

    

    // nomBoxes = 1;


}

//--------------------------------------------------------------
void ofApp::draw(){ 

    // ofSleepMillis(100);

    // int i = 0;

    for(int i = 0; i <= PosTotal; i++){

    camDeg = 360*pos/PosTotal;
    cam.orbitDeg(0,camDeg,camDis,{-260,0,0});
    cam.rotate(-10.0,0.0,cos(camDeg*PI/180),sin(camDeg*PI/180));

    fbo1.begin();
    ofBackground(0);
    cam.begin();
  
        // ofSetColor(1300,1300,900);
        // ofDrawSphere(ofPoint(0,0,0),50);   

        //Boxes(Top)---------------------------------------------------
        
        ofSetColor(255);

        t += 0.03;
        if(t >= 360 * 2 ){ t = 0; }
        tDeg = t * PI/180;

        // if(nomBoxes == 1){
        PointLight2.setAmbientColor(ofFloatColor(brightness2));
        PointLight2.setAmbientColor(ofFloatColor(-0.1));
        PointLight2.setPosition(LightPoint4);
        PointLight2.enable(); 
        
        PointLight3.setAmbientColor(ofFloatColor(brightness2));
        PointLight3.setAmbientColor(ofFloatColor(0.0));
        PointLight3.setPosition(LightPoint5);
        PointLight3.enable(); 

        int BoxRotate = t/2;

        ofPushMatrix();
            ofTranslate(140*cos(-tDeg-0.3*PI),-30,-20);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),50);    
        ofPopMatrix();
        ofPushMatrix();
            ofTranslate(140*cos(-tDeg),30,0);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),60);    
        ofPopMatrix();
        ofPushMatrix();
            ofTranslate(130*cos(-tDeg+0.1*PI),70,10);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),40);    
        ofPopMatrix();

        ofPushMatrix();
            ofTranslate(60*cos(-tDeg-0.8*PI),-50,0);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),60);    
        ofPopMatrix();
        ofPushMatrix();
            ofTranslate(60*cos(-tDeg-0.6*PI),-10,-40);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),70);    
        ofPopMatrix();
        ofPushMatrix();
            ofTranslate(70*cos(-tDeg-0.2*PI),20,20);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),80);    
        ofPopMatrix();

        ofPushMatrix();
            ofTranslate(90*cos(-tDeg+0.9*PI),-10,-20);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),45);    
        ofPopMatrix();

        //中心点
        // ofPushMatrix();
        //     ofSetColor(255,0,0);
        //     ofDrawSphere(ofPoint(0,0,0),1);   
        // ofPopMatrix();

        //中心線
        // ofDrawLine(-ofGetWidth()/2, 0, 0, ofGetWidth()/2, 0, 0);
            
        PointLight3.disable();
        PointLight2.disable();
        // }
        
        //Boxes(Bottom)---------------------------------------------------

    cam.end();
    fbo1.end();

    // ofPixels pixels;
	fbo1.readToPixels(pixels);
    image.setFromPixels(pixels);

    ofSetColor(1000);
  
    if(pos < H){
        // ofSetColor(50);
        // ofRect(0, (H-1-int(pos))*Height/H, Width/W , Height/H);
        // ofSetColor(1000);
        // fbo1.draw(0, (H-1-int(pos))*Height/H, Width/W , Height/H);
        image.draw(0, (H-1-int(pos))*Height/H, Width/W , Height/H);
    }else if(H <= pos && pos < 2*H){
        // ofSetColor(50);
        // ofRect(Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
        // ofSetColor(1000);
        // fbo1.draw(Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
        image.draw(Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
    }else if(2*H <= pos && pos < 3*H){
        // ofSetColor(50);
        // ofRect(2*Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
        // ofSetColor(1000);
        // fbo1.draw(2*Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
        image.draw(2*Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
    }else if(3*H <= pos && pos < 4*H){
        // ofSetColor(50);
        // ofRect(3*Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
        // ofSetColor(1000);
        // fbo1.draw(3*Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
        image.draw(3*Width/W, (H-1-int(pos)%H)*Height/H, Width/W , Height/H);
    }

    pos++;

    }//for(int i = 0; i <= PosTotal; i++)

    

    cout << "pos: " << pos << endl;
    cout << "t " << t << endl;

    // ofSetColor(255);
    if(text == 1){

        // ofSetColor(0);
        // ofRect(0,0,1000,1000);

        ofSetColor(255);
        // ofSetColor(1000);
        // font.drawString(ofToString(fingerMovie.getCurrentFrame()) + " / "  + ofToString(TotalFrame), 10, 20);   
        // font.drawString("gpioMode: " + ofToString(gpioMode) , 10, 40);
        // font.drawString("keypressed : " + ofToString(keypressed) , 10, 60);
        // font.drawString("Framerate: " + ofToString(ofGetFrameRate()) , 10, 20);
        font.drawString("camDeg: " + ofToString(camDeg) , 10, 40);
        // font.drawString("brightness1: " + ofToString(brightness1) , 10, 60);
        // font.drawString("brightness2: " + ofToString(brightness2) , 10, 80);
        // font.drawString("t: " + ofToString(t) , 10, 100);
        // font.drawString("camRotateSpeed: " + ofToString(camRotateSpeed) , 10, 120);
        // font.drawString("i: " + ofToString(i) , 10, 120);
        // font.drawString("flatMoon: " + ofToString(flatMoon) , 10, 140);
        font.drawString("pos: " + ofToString(pos) , 10, 80);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'a'){ pos++; }

    if (key == 't'){ 
        if(text == 0){
            text = 1;
        }else{
            text = 0;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}