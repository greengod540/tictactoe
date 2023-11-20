
#include <SDL.h>
#include <fstream>
#include <iostream>
#include <map>
#include "main.h"

#undef main

using namespace std;

int turn = 1;

SDL_Window* mainWindow = SDL_CreateWindow("Title",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	1366, 768, 0);


SDL_Rect square1 = { 326, 198, 200, 200 };
SDL_Rect square2 = { 866, 270, 200, 200 };
SDL_Rect square3 = { 1411, 310, 200, 200 };
SDL_Rect square4 = { 343, 563, 200, 200 };
SDL_Rect square5 = { 883, 618, 200, 200 };
SDL_Rect square6 = { 1383, 638, 200, 200 };
SDL_Rect square7 = { 346, 887, 200, 200 };
SDL_Rect square8 = { 863, 903, 200, 200 };
SDL_Rect square9 = { 1381, 895, 200, 200 };

std::map <int, SDL_Rect> squarets;
std::map<int, bool> square;
std::map <int, string> squaret;

bool mouseButtonPressed(SDL_MouseButtonEvent& b, int mouseButton) {
	if (b.button == mouseButton) {

		return true;


	}
	else {
		return false;
	}
}

bool isHorizontal(SDL_Renderer* renderer) {
	if (squaret[1] == "O" && squaret[4] == "O" && squaret[7] == "O") {
		SDL_RenderClear(renderer);
		return true;

	}
	if (squaret[7] == "O" && squaret[4] == "O" && squaret[1] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[2] == "O" && squaret[5] == "O" && squaret[8] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[8] == "O" && squaret[5] == "O" && squaret[2] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[3] == "O" && squaret[6] == "O" && squaret[9] == "O") {
		SDL_RenderClear(renderer);
	}
	if (squaret[9] == "O" && squaret[6] == "O" && squaret[3] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}																					//uzhasno otvratitlen kod


	if (squaret[1] == "X" && squaret[4] == "X" && squaret[7] == "X") {
		SDL_RenderClear(renderer);
		return true;

	}
	if (squaret[7] == "X" && squaret[4] == "X" && squaret[1] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[2] == "X" && squaret[5] == "X" && squaret[8] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[8] == "X" && squaret[5] == "X" && squaret[2] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[3] == "X" && squaret[6] == "X" && squaret[9] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[9] == "X" && squaret[6] == "X" && squaret[2] == "X") {
		SDL_RenderClear(renderer);
		return true;


	}
	




}


bool isVertical(SDL_Renderer* renderer) {
	if (squaret[1] == "O" && squaret[2] == "O" && squaret[3] == "O") {
		SDL_RenderClear(renderer);
		return true;
		
	}
	if (squaret[3] == "O" && squaret[2] == "O" && squaret[1] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[4] == "O" && squaret[5] == "O" && squaret[6] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[6] == "O" && squaret[5] == "O" && squaret[4] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}																				//uzhasno otvratitlen kod
	if (squaret[7] == "O" && squaret[8] == "O" && squaret[9] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[9] == "O" && squaret[8] == "O" && squaret[7] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}


	if (squaret[1] == "X" && squaret[2] == "X" && squaret[3] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[3] == "X" && squaret[2] == "X" && squaret[1] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[4] == "X" && squaret[5] == "X" && squaret[6] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[6] == "X" && squaret[5] == "X" && squaret[4] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[7] == "X" && squaret[8] == "X" && squaret[9] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[9] == "X" && squaret[8] == "X" && squaret[7] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}


}




bool isDiagonal(SDL_Renderer* renderer) {
	if (squaret[1] == "X" && squaret[5] == "X" && squaret[9] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[9] == "X" && squaret[5] == "X" && squaret[1] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[3] == "X" && squaret[5] == "X" && squaret[7] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[7] == "X" && squaret[5] == "X" && squaret[3] == "X") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[1] == "O" && squaret[5] == "O" && squaret[9] == "O") { //uzhasno otvratitlen kod
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[9] == "O" && squaret[5] == "O" && squaret[1] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[3] == "O" && squaret[5] == "O" && squaret[7] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}
	if (squaret[7] == "O" && squaret[5] == "O" && squaret[3] == "O") {
		SDL_RenderClear(renderer);
		return true;
	}




}




	










SDL_Renderer* mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);

void improveRenderer() {

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);

	auto desktopWidth = DM.w;
	auto desktopHeight = DM.h;

	if (SDL_SetWindowFullscreen(mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP) < 0)
	{
		cout << "SDL Renderer improve failed!" << SDL_GetError();
	}

	SDL_RenderSetLogicalSize(mainRenderer, 1920, 1080);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	


}




SDL_Texture* loadTexture(string imgPath) {

	string temImg = "img\\" + imgPath;


	SDL_Surface* loadingSurface = SDL_LoadBMP(temImg.c_str());

	SDL_Texture* texture = SDL_CreateTextureFromSurface(mainRenderer, loadingSurface);

	if (texture == nullptr) {

		temImg = "img\\";

		loadingSurface = SDL_LoadBMP(temImg.c_str());

		texture = SDL_CreateTextureFromSurface(mainRenderer, loadingSurface);

	}

	SDL_FreeSurface(loadingSurface);

	return texture;

}

int isMouseInRect(int mouseX, int mouseY, SDL_Rect rect) {

	return false;


}

bool mousePosCheck(SDL_Rect rect, int mx, int my, int offsetx, int offsety) {



	if (mx >= rect.x && mx <= rect.x + rect.w + offsetx && my >= rect.y && my <= rect.y + rect.h + offsety) {
		return true;

	}

	return false;
}

bool colliding(SDL_Rect objectRect, SDL_Rect targetRect, int offsetx, int offsety) {

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

int main(int argc, char* argv[]) {
	squarets[1] = square1;
	squarets[2] = square2;
	squarets[3] = square3;
	squarets[4] = square4;
	squarets[5] = square5;
	squarets[6] = square6;
	squarets[7] = square7;
	squarets[8] = square8;
	squarets[9] = square9;

	SDL_Init(SDL_INIT_EVERYTHING);

	improveRenderer();

	SDL_Texture* grid = loadTexture("grid.bmp.bmp");
	SDL_Texture* X = loadTexture("X.bmp.bmp");
	SDL_Texture* O = loadTexture("O.bmp.bmp");

	SDL_Event sdlEvent;

	SDL_Rect msdstRect = { 0, 0, 200, 200 };

	bool isRunning = true;
	bool isGameOver = false;

	while (isRunning) {
		while (SDL_PollEvent(&sdlEvent)) {
			switch (sdlEvent.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					// Handle escape key
				}
				break;
			case SDL_MOUSEMOTION:
				// Handle mouse motion
				std::cout << sdlEvent.motion.x << " " << sdlEvent.motion.y << std::endl;
				if (sdlEvent.motion.x == 500 && sdlEvent.motion.y == 500) {
					std::cout << "good";
				}
				break;
			default:
				break;
			}
		}

		SDL_MouseButtonEvent mb = sdlEvent.button;

		if (mouseButtonPressed(mb, 1) && !isGameOver) {
			msdstRect.x = sdlEvent.motion.x;
			msdstRect.y = sdlEvent.motion.y;

			for (int x = 1; x <= 9; x++) {
				if (mousePosCheck(squarets[x], msdstRect.x, msdstRect.y, 100, 0)) {
					if (!square[x]) {
						if (turn == 1) {
							SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
							turn = 2;
							square[x] = true;
							squaret[x] = "X";
						}
						else {
							SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
							turn = 1;
							square[x] = true;
							squaret[x] = "O"; //dobur shto gode kod
						}
						if (isHorizontal(mainRenderer) || isVertical(mainRenderer) || isDiagonal(mainRenderer)) {
							isGameOver = true;
						}
					}
				}
			}
		}

		if (isGameOver) {
			for (int y = 1; y <= 9; y++) {
				square[y] = false;
				squaret[y] = ""; //dobur shto gode
			}
			turn = 1;
			isGameOver = false;
		}

		SDL_RenderCopy(mainRenderer, grid, NULL, NULL);
		SDL_RenderPresent(mainRenderer);
		SDL_Delay(100);
	}

	SDL_Quit();
	return 0;
}
