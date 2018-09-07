//
//  main.cpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 30/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <SDL.h>
#include "Screen.hpp"

using namespace particles;

int main(int argc, const char * argv[]) {
    
    Screen * screen = new Screen(new std::string("Particles Explosion"));
    
    if (!screen->init()) {
        std::cout << "SDL Fail to initialize" << std::endl;
    }
    
    while (true) {
        //TODO: Particle handle.
        for(int y=0; y < Screen::SCREEN_HEIGHT; y++) {
            for(int x=0; x < Screen::SCREEN_WIDTH; x++) {
                screen->setPixel(x, y, 128, 0, 255);
            }
        }
        screen->update();
//        screen->setPixel(300, 400, 255, 255, 255);
        if(!screen->processEvents()) {
            break;
        }
    }
    
    screen->close();
    delete screen;
    
    return 0;
}
