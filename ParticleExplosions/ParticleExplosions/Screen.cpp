//
//  Screen.cpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 06/09/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include "Screen.hpp"
namespace particles {
    
    Screen::Screen(std::string *name): m_name(name), m_window(NULL), m_texture(NULL), m_renderer(NULL), m_buffer(NULL) {
    }
    
    bool Screen::init() {
        if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            std::cout << "SDL Couldn't init" << std::endl;
            return false;
        }
        this->m_window = SDL_CreateWindow(this->m_name->c_str(),
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);

        if (m_window == NULL) {
            SDL_Quit();
            return false;
        }
        
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        
        if(m_renderer == NULL) {
            SDL_Quit();
            return false;
        }

        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
                                                  SCREEN_WIDTH, SCREEN_HEIGHT);
        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        this->update();
        
        if(m_texture == NULL) {
            SDL_DestroyRenderer(m_renderer);
            SDL_ShowWindow(m_window);
            SDL_Quit();
            return false;
        }
        
        return true;
    }
    
    void Screen::update() {
        SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }
    
    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
        const Uint8 alpha = 0xFF;
        
        Uint32 color = 0;
        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += alpha;
        
        m_buffer[(y * SCREEN_WIDTH) + x] = color;
        
        this->update();
    }
    
    bool Screen::processEvents() {
        SDL_Event event;
        
        while (SDL_WaitEvent (&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
        }
        return true;
    }
    
    void Screen::close() {
        SDL_DestroyTexture(m_texture);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
    
    Screen::~Screen() {
        delete m_name;
        delete [] m_buffer;
    }
    
}
