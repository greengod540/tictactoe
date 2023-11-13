
#include <SDL.h>
#include <fstream>
#include <iostream>

#undef main

using namespace std;


SDL_Window* mainWindow = SDL_CreateWindow("Title",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	1366, 768, 0);


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

		temImg = "img\\Null.bmp";

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

	SDL_Event sdlEvent;

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
					SDL_Quit();
				}
				break;

			case SDL_MOUSEMOTION:

				cout << sdlEvent.motion.x << " " << sdlEvent.motion.y << endl;

				SDL_SetRenderDrawColor(mainRenderer, sdlEvent.motion.x, sdlEvent.motion.y, 100, 255);

			default:
				break;

			}



		}

		SDL_RenderClear(mainRenderer);
		SDL_RenderPresent(mainRenderer);


	}

	while (true)
	{
		SDL_RenderCopy(mainRenderer, vikingTexture, &srcRect, &dstRect);

		SDL_RenderPresent(mainRenderer); // Draw the render


		SDL_RenderClear(mainRenderer); // Clear what you have drawn
		SDL_Delay(100); // Slow the program
	}

	return 0;
}