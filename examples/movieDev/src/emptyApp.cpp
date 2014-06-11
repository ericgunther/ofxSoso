#include "emptyApp.h"


//--------------------------------------------------------------
void emptyApp::setup(){
  
  ofDisableSetupScreen();
  
  scene = new ofxScene(ofGetWidth(), ofGetHeight());
	scene->setBackgroundColor(30,30,30);
  
  setFilepaths(videoFilepaths);
  
  vidScale = 0.5;
  vidDimensions.set(1920*vidScale,1080*vidScale);
  curPathIndex = 0;
  
}

ofxVideoPlayerObject* emptyApp::loadMovie()
{
  ofxVideoPlayerObject *vid = new ofxVideoPlayerObject(videoFilepaths[curPathIndex]);
  vid->setTrans(0, 0, 0);
  vid->isCentered = true;
  vid->setScale(vidScale);
  videos.push_back(vid);
  scene->getRoot()->addChild(vid);
  vid->start();
  
  curPathIndex = ++curPathIndex%videoFilepaths.size();
  
  return vid;
}

void emptyApp::setFilepaths(vector<char *> &iVec)
{
  iVec.push_back("~/Documents/Sosolimited/Super Bowl/documentation/Raw footage/MVI_5509.mov");
  iVec.push_back("~/Documents/Sosolimited/Super Bowl/documentation/Raw footage/MVI_5519.mov");
  iVec.push_back("~/Documents/Sosolimited/Super Bowl/documentation/Raw footage/MVI_5511.mov");
  iVec.push_back("~/Documents/Sosolimited/Super Bowl/documentation/Raw footage/MVI_5513.mov");
  iVec.push_back("~/Documents/Sosolimited/Super Bowl/documentation/Raw footage/MVI_5521.mov");
  iVec.push_back("~/Documents/Sosolimited/Super Bowl/documentation/Raw footage/MVI_5525.mov");
  iVec.push_back("~/Documents/Sosolimited/Super Bowl/documentation/Raw footage/MVI_5553.mov");
  iVec.push_back("~/Documents/Sosolimited/Super Bowl/documentation/Raw footage/MVI_5554.mov");
  iVec.push_back("~/Documents/Sosolimited/Super Bowl/documentation/Raw footage/MVI_5555.mov");
}

//--------------------------------------------------------------
void emptyApp::update(){
  
	scene->update(ofGetElapsedTimef());
}

//--------------------------------------------------------------
void emptyApp::draw(){
  
	//Call draw on scene, which initiates the drawing of the root object.
  scene->draw();
}

//--------------------------------------------------------------
void emptyApp::keyPressed  (int key){
  if(key == 'a'){
    loadMovie();
  }
  
}

//--------------------------------------------------------------
void emptyApp::keyReleased(int key){
  
}

//--------------------------------------------------------------
void emptyApp::mouseMoved(int x, int y ){
  
}

//--------------------------------------------------------------
void emptyApp::mouseDragged(int x, int y, int button){
  
  
}

//--------------------------------------------------------------
void emptyApp::mousePressed(int x, int y, int button){
  
}

//--------------------------------------------------------------
void emptyApp::mouseReleased(int x, int y, int button){
  
  
}


//--------------------------------------------------------------
void emptyApp::windowResized(int w, int h){
  
}

//--------------------------------------------------------------
void emptyApp::gotMessage(ofMessage msg){
  
}

//--------------------------------------------------------------
void emptyApp::dragEvent(ofDragInfo dragInfo){ 
  
}


