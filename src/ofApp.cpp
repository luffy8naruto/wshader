#include "ofApp.h"

//--------------------------------------------------------------
const int nmax = 500;
ofVec3f a[nmax];
ofShader shader;
float z = 0.0f;

void ofApp::setup(){
	shader.load("", "shader.frag");
	srand(time(NULL));
	for (int i = 0; i < nmax; i++)
	{
		a[i] = { float(rand() % ofGetScreenWidth()), float(rand() % ofGetScreenHeight()), float(rand() % 400) };
		//cout << a[i].x << '\t' << a[i].y << '\n';
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetWindowTitle(to_string(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0, 0, 0);

	z += 1; if (z > 400) z = 0;

	shader.begin();
	shader.setUniform1f("u_z", z);
	shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	shader.setUniform3fv("u_p", (float*)&a[0].x, nmax);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
