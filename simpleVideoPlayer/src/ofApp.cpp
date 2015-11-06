#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(55);
	video.load("test.mp4");
	video.play();

	
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	video.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key)
	{

		case '1':	
			{
				video.load("test.mp4");
				video.play();
				break;
			}
		case '2':	
			{
				video.load("test2.mp4");
				video.play();
				break;
			}
		
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
