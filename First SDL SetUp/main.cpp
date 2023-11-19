#include <SDL.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <TileAnimation.h>
#include <TextureLoader.h>
#include <CollisionCheck.h>
#include <mutex>
#include <thread>
#include <InputManager.h>
#include <map>
#undef main

int turn = 0;


void improveRenderer(SDL_Window* mainWindow, SDL_Renderer* mainRenderer) {

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);

	auto desktopWidth = DM.w;
	auto desktopHeight = DM.h;


	if (SDL_SetWindowFullscreen(mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP) < 0)
	{
		std::cout << "sdl renderer improved failed" << SDL_GetError();

	}

	SDL_RenderSetLogicalSize(mainRenderer, 1920, 1080);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");





}

int main(int argc, char* argv[])
{

	TileAnimation tileAnim;
	TileAnimation tileAnim2;
	InputManager inputManager;




	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* mainWindow = SDL_CreateWindow("Caption", 0, 0, 1920, 1080, 0);

	SDL_Renderer* mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);

	//improved rendered
	
	improveRenderer(mainWindow, mainRenderer);

	
	

	inputManager.mapControlsMouse("left", "left");
	

	
	
	


	TextureLoader textLoader;
	
	TileAnimation::Rects rect;

	SDL_Texture* grid = textLoader.CreateTexture("grid.bmp", mainRenderer);
	
	//SDL_Texture* Gugug = textLoader.CreateTexture("gufguy.bmp", mainRenderer);


	


	//make a 3d rect vs 2019 make viking anim
	int frame = 0;

	
	int currentX = 5;
	int currentY = 5;
	int animStateY = 0;
	
	


	


	

	
	CollisionCheck colcheck;
	SDL_Rect cursorDstRect{ 0, 0, 0, 0 };
	int xMouse = 0;
	int yMouse = 0;
	bool isRunning = true;
	SDL_Rect srcRect = { 100, 100, 100, 100 };
	SDL_Rect dstRect = { xMouse, yMouse, 500, 500 };
	SDL_Texture* x = textLoader.CreateTexture("X.bmp", mainRenderer);
	
	while (isRunning)
	{
		SDL_Event Event;
		

		
		cursorDstRect.x = xMouse;
		cursorDstRect.y = yMouse;
		
		


		while (SDL_PollEvent(&Event)) {
			switch (Event.type) 
			{
				case SDL_QUIT:
					isRunning = false;
					break;

				case SDL_KEYDOWN:
					if(inputManager.keyboardButtonPressed(Event, inputManager.actionMapKeyboard["left"])) {

						SDL_Quit();
					
					
					
					
					}
					break;

				case SDL_MOUSEBUTTONDOWN:
					
				
					break;

				case SDL_MOUSEMOTION:
					xMouse = inputManager.getXMouseCoordinates(xMouse);
					yMouse = inputManager.getYMouseCoordinates(yMouse);
					std::cout << xMouse << ":" << yMouse << std::endl;
					
					
					


				default:
					break;


			}
			SDL_MouseButtonEvent mouseButtonEvent = Event.button;
			if (inputManager.mouseButtonPressed(mouseButtonEvent, inputManager.actionMapMouse["left"])) {
				dstRect.x = xMouse;
				dstRect.y = yMouse;
				turn = 1;
				std::cout << "koklkikkio";


				SDL_RenderCopy(mainRenderer, x, NULL, &dstRect);
				


			}
			SDL_RenderCopy(mainRenderer, grid, NULL, NULL);




			SDL_RenderPresent(mainRenderer);







			
			SDL_Delay(70);

			
			
			
			
			// Add more event handling as needed
		}
		



		








		
		
		
		
		
		
	

		
	}


	return 0;
}

