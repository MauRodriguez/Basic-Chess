#include "mbutton.h"
#define BUTTON_HEIGHT 125
#define BUTTON_WIDTH 125

MButton::MButton(int currentTexture, int XPosition, int YPosition, int empty) :
	XPosition(XPosition),
	YPosition(YPosition),
	currentTexture(currentTexture),
	empty(empty)
{}

MButton::~MButton(){

}

int MButton::getXPosition(){
	return XPosition;
}

void MButton::setTextureType(int i){
	currentTexture = i;
}

int MButton::getYPosition(){
	return YPosition;
}

int MButton::getTextureType(){
	return currentTexture;
}
	
