#pragma once

#include "ofMain.h"
#include "ofxScene.h"
#include "ofxSosoRenderer.h"
#include "ofxVideoPlayerObject.h"

class emptyApp : public ofBaseApp{
  
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
  
  ofxVideoPlayerObject* loadMovie();
  void setFilepaths(vector<char *> &iVec);
  
public:
  ofxScene						*scene;

  vector<ofxVideoPlayerObject *>  videos;
  vector<char *> videoFilepaths;

  ofVec2f vidDimensions;
  ofVec3f origin;
  float vidScale;
  float gap;
  float curX;
  int curRow;
  int curPathIndex;
  
};

