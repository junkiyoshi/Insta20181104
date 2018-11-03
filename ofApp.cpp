#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39, 39, 239);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofColor color(239);
	int span = 3;
	for (int x = 0; x < ofGetWidth(); x += span) {

		for (int y = 0; y < ofGetHeight(); y += span) {

			float alpha = ofMap(ofNoise(x * 0.003, y * 0.005, ofGetFrameNum() * 0.01), 0, 1, 0, 255);
			alpha *= ofMap(y, 0, ofGetHeight() * 0.75, 1, 0);
			ofSetColor(color, alpha);
			ofDrawRectangle(ofPoint(x, y), span, span);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}