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
#include "Particle.hpp"
#include "Swarm.hpp"

using namespace particles;

int main(int argc, const char * argv[]) {
    
    srand((unsigned int)time(NULL));
    
    Screen * screen = new Screen(new std::string("Particles Explosion"));
    
    Swarm * swarm = new Swarm();
    
    if (!screen->init()) {
        std::cout << "SDL Fail to initialize" << std::endl;
    }
    
    while (screen->processEvents()) {
        //TODO: Particle handle.
        swarm->update();
        screen->clear();
        
        int elapsed = SDL_GetTicks();
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0005)) * 128);

        const Particle * const particles = swarm->getParticles();
        for(int i = 0; i<Swarm::N_PARTICLES; i++) {
            Particle particle = particles[i];
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;
            
            screen->setPixel(x, y, red, green, blue);
        }
        
        screen->update();
        
    }
    
    screen->close();
    delete screen;
    delete swarm;
    return 0;
}
