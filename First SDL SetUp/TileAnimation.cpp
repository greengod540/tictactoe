#include "TileAnimation.h"

TileAnimation tileAnim;
TileAnimation::Rects rect;


int frames = tileAnim.frame;
int row = tileAnim.row;


TileAnimation::Rects TileAnimation::getFrames(int framesToPlay, std::string configFilePath, int row1) {
    std::filesystem::path path = configFilePath;

    SDL_Rect srcRect1{ 0, 0, 0, 0 };
    SDL_Rect dstRect1{ 0, 0, 0, 0 };
    SDL_Rect imageValues;

    std::string imgName, temp;
    std::fstream stream;

    stream.open(path); // open the file
    stream >> temp >> imgName; // read image name
    stream >> temp >> dstRect1.x >> dstRect1.y >> dstRect1.w >> dstRect1.h;
    stream >> temp >> srcRect1.x >> srcRect1.y >> srcRect1.w >> srcRect1.h; // read the x, y, w, h coordinates
    stream >> temp >> imageValues.x >> imageValues.y >> imageValues.w >> imageValues.h;
    stream.close();

    int xMargin = imageValues.x / imageValues.h;
    int yMargin = imageValues.y / imageValues.w;






    rect.dstRect = dstRect1;
    rect.srcRect = srcRect1;
    rect.xMargin = xMargin;
    rect.yMargin = yMargin;




    rect.srcRect.x = rect.xMargin * frame;
    rect.srcRect.y = rect.yMargin * row1;

    return rect;
}

void TileAnimation::UpdateFrame(std::string configFilePath, int framesToPlay, bool repeat) {

    if (frame <= framesToPlay) {
        frame++;
        if (repeat == true && frame >= framesToPlay) {

            frame = 0;
            frame++;
        }
        else if (repeat == false && frame >= framesToPlay) {
            frame = 0;
            
        }
    }

    
    

}

SDL_Rect TileAnimation::returnSrcRect(int framesToPlay, std::string configFilePath, int row1) {
    rect = getFrames(framesToPlay, configFilePath, row1);

    return rect.srcRect;
}



int TileAnimation::getCurrentFrame() {
    return frame;
}


