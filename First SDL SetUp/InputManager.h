#pragma once
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

class InputManager
{

	

	

public:
	int xMouseCords = 0;
	int yMouseCords = 0;
	std::map < std::string, SDL_Scancode> actionMapKeyboard;
	std::map <std::string, int> actionMapMouse;
	
	
	std::map<std::string, SDL_Scancode> mapControlsKeyBoard(const char* inputKey, std::string nameOfAction);

	std::map<std::string, int> mapControlsMouse(std::string name, std::string button);

	bool mouseButtonPressed(SDL_MouseButtonEvent& b, int mouseButton);

	bool keyboardButtonPressed(SDL_Event e, SDL_Scancode scancode);
	
	
	int getXMouseCoordinates(int xMouse);

	int getYMouseCoordinates(int yMouse);

	



};

