#include "emptyApp.h"


//--------------------------------------------------------------
void emptyApp::setup(){
  
  ofDisableSetupScreen();
  
  scene = new ofxScene(ofGetWidth(), ofGetHeight());
	scene->setBackgroundColor(0, 221, 255);
  
  vidScale = 0.15;
  vidDimensions.set(1920*vidScale,1080*vidScale);
  gap = 10;
  origin.set(-0.4*ofGetWidth(), 0.48*ofGetHeight() - vidDimensions[1]);
  curRow = 0;
  curX = origin[0];
  
  curPathIndex = 0;
  curMovieIndex = 0;
  
  
  setupFilepaths(videoFilepaths);
  
  for(int i=0; i < videoFilepaths.size(); i++){
    loadMovie();
  }
  
  cout << "*******\nvideos has " << videos.size() << " movies.\n";
  

  // MEMORY OBSERVATIONS
  
  // For each 1920x1080 movie load, there is a 2-6 Mb increase in memory.

  // During play, memory climbed 140Mb / 100Mb / 80Mb /
  // very quickly, then held. At finish, somtimes dipped back down 10Mb.

  // The memory does not increase on a replay of the same movie.
  
  // Calling close and reload releases a significant chunk, but not all of it! (WTF?)
  
}

ofxVideoPlayerObject* emptyApp::loadMovie()
{
  ofxVideoPlayerObject *vid = new ofxVideoPlayerObject(videoFilepaths[curPathIndex]);
  vid->setTrans(curX, origin[1] - curRow*(vidDimensions[1]+gap), 0);
  vid->setScale(vidScale);
  videos.push_back(vid);
  scene->getRoot()->addChild(vid);
  //vid->start();

  if(curX > (origin[0]+0.6*ofGetWidth()-vidDimensions[0])){
    curRow++;
    curX = origin[0];
  }else{
    curX += (vidDimensions[0]+gap);
  }
  
  curPathIndex = ++curPathIndex%videoFilepaths.size();
  
  return vid;
}

void emptyApp::playCurMovie()
{
  if(curMovieIndex < videos.size()){
    videos[curMovieIndex]->player->setPosition(0);
    videos[curMovieIndex]->start();
  }
}

void emptyApp::stopCurMovie()
{
  if(curMovieIndex < videos.size()){
    videos[curMovieIndex]->stop();
  }
}

void emptyApp::stopAllMovies()
{
  for(auto vid : videos){
    vid->stop();
  }
}

void emptyApp::closeCurMovie()
{
  if(curMovieIndex < videos.size()){
    videos[curMovieIndex]->player->closeMovie();
  }
}

void emptyApp::reloadCurMovie()
{
  if(curMovieIndex < videos.size()){
    videos[curMovieIndex]->reload();
  }
}

void emptyApp::setupFilepaths(vector<char *> &iFilepaths)
{
  iFilepaths.push_back("~/Documents/Sosolimited/Dev/Dev Media/csis_1080p.mp4");
  iFilepaths.push_back("~/Documents/Sosolimited/Dev/Dev Media/healthcare_solutions_gma-gb_B.mov");
  iFilepaths.push_back("~/Documents/Sosolimited/Dev/Dev Media/healthcare_solutions_gma-gb.mov");
  iFilepaths.push_back("~/Documents/Sosolimited/Dev/Dev Media/mercy_health_beyond_the_digital_hospital_1920x1080_B.mov");
  iFilepaths.push_back("~/Documents/Sosolimited/Dev/Dev Media/mercy_health_beyond_the_digital_hospital_1920x1080.mov");
  iFilepaths.push_back("~/Documents/Sosolimited/Dev/Dev Media/region_skane_gma-gb.mov");
  iFilepaths.push_back("~/Documents/Sosolimited/Dev/Dev Media/sxw4hc_whiteboard_gma-gb_1_B.mov");
  iFilepaths.push_back("~/Documents/Sosolimited/Dev/Dev Media/sxw4hc_whiteboard_gma-gb_1.mov");

  
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

  // Set cur movie index.
  if(key>=49 && key<=57){
    curMovieIndex = key-49;
    curMovieIndex = min(curMovieIndex, (int)videos.size());
    cout << "curMovieIndex = " << curMovieIndex;
  }

  
  if(key == 'a'){
    loadMovie();
  }
  else if(key == 'p'){
    playCurMovie();
  }
  else if(key == 's'){
    stopCurMovie();
  }
  else if(key == 'S'){
    stopAllMovies();
  }
  else if(key == 'c'){
    closeCurMovie();
  }
  else if(key == 'r'){
    reloadCurMovie();
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


