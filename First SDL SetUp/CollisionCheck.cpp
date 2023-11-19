#include "CollisionCheck.h"

bool CollisionCheck::colliding (SDL_Rect objectRect, SDL_Rect targetRect, int offsetx, int offsety) {

    bool checkCollision = false;
    if (objectRect.y + objectRect.h + offsety > targetRect.y && objectRect.y < targetRect.y + targetRect.h) {
        checkCollision = true;
        return checkCollision;
    }


    if (objectRect.x + objectRect.w + offsetx > targetRect.x && objectRect.x < targetRect.x + targetRect.w) {
        checkCollision = true;
        return checkCollision;
    }

    
    return checkCollision;

	


	

	
}