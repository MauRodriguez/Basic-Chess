#include "mbutton.h"
#define BUTTON_HEIGHT 125
#define BUTTON_WIDTH 125

MButton::MButton(int currentSprite, int mXPosition, int mYPosition) :
	mXPosition(mXPosition),
	mYPosition(mYPosition),
	currentSprite(currentSprite)
{}

MButton::~MButton(){

}

void MButton::handleEvent( SDL_Event* e )
{
	//If mouse event happened
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if(x < mXPosition){
			inside = false;
		}
		//Mouse is right of the button
		else if(x > mXPosition + BUTTON_WIDTH){
			inside = false;
		}
		//Mouse above the button
		else if(y < mYPosition){
			inside = false;
		}
		//Mouse below the button
		else if(y > mYPosition + BUTTON_HEIGHT){
			inside = false;
		}

		//Mouse is inside button
		if(inside){			
			//Set mouse over sprite
			switch( e->type )
			{
				case SDL_MOUSEMOTION:
				//mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;
			
				case SDL_MOUSEBUTTONDOWN:
				//mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;
				
				case SDL_MOUSEBUTTONUP:
				//mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}
	
