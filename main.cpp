
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

std::map <int, bool> square;
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
	}


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
	}
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
	if (squaret[1] == "O" && squaret[5] == "O" && squaret[9] == "O") {
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

bool mousePosCheck(SDL_Rect rect, int mx, int my) {



	if (mx >= rect.x && mx <= rect.x + rect.w && my >= rect.y && my <= rect.y + rect.h) {
		return true;

	}

	return false;
}



int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);



	improveRenderer();

	SDL_Rect dstRect, srcRect, imageValues;

	string imgName, temp;

	fstream stream;

	stream.open("config\\init.txt"); // Open the file

	stream >> temp >> imgName; //Read the image name
	stream >> temp >> dstRect.x >> dstRect.y >> dstRect.w >> dstRect.h; //Read the dstrect value
	stream >> temp >> srcRect.x >> srcRect.y >> srcRect.w >> srcRect.h; //Read the srcrect value
	stream >> temp >> imageValues.x >> imageValues.y >> imageValues.w >> imageValues.h; //Read the srcrect value
					//width            height           rows             cols 

	stream.close(); //Close the file

	int xMargin = imageValues.x / imageValues.h;
	int yMargin = imageValues.y / imageValues.w;

	SDL_Surface* loadingSurface = SDL_LoadBMP(imgName.c_str());

	SDL_Texture* vikingTexture = SDL_CreateTextureFromSurface(mainRenderer, loadingSurface);
	SDL_Texture* grid = loadTexture("grid.bmp.bmp");
	SDL_Texture* X = loadTexture("X.bmp.bmp");
	SDL_Texture* O = loadTexture("O.bmp.bmp");

	SDL_Event sdlEvent;

	SDL_Rect msdstRect = { 0, 0, 200, 200 };

	bool isRunning = true;



	while (isRunning) {

		while (SDL_PollEvent(&sdlEvent)) {

			switch (sdlEvent.type) {

			case SDL_QUIT:
				isRunning = false;
				break;

			case SDL_KEYDOWN:
				if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {

					//isRunning = false;
					

				}
				break;

			case SDL_MOUSEMOTION:

				cout << sdlEvent.motion.x << " " << sdlEvent.motion.y << endl;

				if (sdlEvent.motion.x == 500 && sdlEvent.motion.y == 500) {

					cout << "good";

				}


			default:
				break;

			}



		}

		SDL_MouseButtonEvent mb = sdlEvent.button;

		
		 




		int x = 0;

		if (mouseButtonPressed(mb, 1)) {
			std::cout << "okokok";
			
			msdstRect.x = sdlEvent.motion.x;
			msdstRect.y = sdlEvent.motion.y;
			if (mousePosCheck(square1, msdstRect.x, msdstRect.y)) {
				if (square[1] != true) {
					if (turn == 1) {

						SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
						turn = 2;
						square[1] = true;
						squaret[1] = "X";
					}
					else if (turn == 2) {
						SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
						turn = 1;
						square[1] = true;
						squaret[1] = "O";
					}
				}
				
				
			}
			if (mousePosCheck(square2, msdstRect.x, msdstRect.y)) {
				if (square[2] != true) {
					if (turn == 1) {

						SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
						turn = 2;
						square[2] = true;
						squaret[2] = "X";
					}
					else if (turn == 2) {
						SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
						turn = 1;
						square[2] = true;
						squaret[2] = "O";
					}
				}


			}
			if (mousePosCheck(square3, msdstRect.x, msdstRect.y)) {
				if (square[3] != true) {
					if (turn == 1) {

						SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
						turn = 2;
						square[3] = true;
						squaret[3] = "X";
					}
					else if (turn == 2) {
						SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
						turn = 1;
						square[3] = true;
						squaret[3] = "O";
					}
				}


			}
			if (mousePosCheck(square4, msdstRect.x, msdstRect.y)) {
				if (square[4] != true) {
					if (turn == 1) {

						SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
						turn = 2;
						square[4] = true;
						squaret[4] = "X";
					}
					else if (turn == 2) {
						SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
						turn = 1;
						square[4] = true;
						squaret[4] = "O";
					}
				}


			}
			if (mousePosCheck(square5, msdstRect.x, msdstRect.y)) {
				if (square[5] != true) {
					if (turn == 1) {

						SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
						turn = 2;
						square[5] = true;
						squaret[5] = "X";
					}
					else if (turn == 2) {
						SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
						turn = 1;
						square[5] = true;
						squaret[5] = "O";
					}
				}


			}
			if (mousePosCheck(square6, msdstRect.x, msdstRect.y)) {
				if (square[6] != true) {
					if (turn == 1) {

						SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
						turn = 2;
						square[6] = true;
						squaret[6] = "X";
					}
					else if (turn == 2) {
						SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
						turn = 1;
						square[6] = true;
						squaret[6] = "O";
					}
				}


			}
			if (mousePosCheck(square7, msdstRect.x, msdstRect.y)) {
				if (square[7] != true) {
					if (turn == 1) {

						SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
						turn = 2;
						square[7] = true;
						squaret[7] = "X";
					}
					else if (turn == 2) {
						SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
						turn = 1;
						square[7] = true;
						squaret[7] = "O";
					}
				}


			}
			if (mousePosCheck(square8, msdstRect.x, msdstRect.y)) {
				if (square[8] != true) {
					if (turn == 1) {

						SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
						turn = 2;
						square[8] = true;
						squaret[8] = "X";
					}
					else if (turn == 2) {
						SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
						turn = 1;
						square[8] = true;
						squaret[8] = "O";
					}
				}
				
				
			}
			if (mousePosCheck(square9, msdstRect.x, msdstRect.y)) {
				if (square[9] != true) {
					if (turn == 1) {

						SDL_RenderCopy(mainRenderer, X, NULL, &msdstRect);
						turn = 2;
						square[9] = true;
						squaret[9] = "X";
					}
					else if (turn == 2) {
						SDL_RenderCopy(mainRenderer, O, NULL, &msdstRect);
						turn = 1;
						square[9] = true;
						squaret[9] = "O";
					}
				}
				
				
			}
			isHorizontal(mainRenderer);
			isVertical(mainRenderer);
			isDiagonal(mainRenderer);

			

			
			
		}
		

		SDL_RenderCopy(mainRenderer, grid, NULL, NULL);

		SDL_RenderPresent(mainRenderer); // Draw the render


		 // Clear what you have drawn
		SDL_Delay(100); // Slow the program


	}


	return 0;
}