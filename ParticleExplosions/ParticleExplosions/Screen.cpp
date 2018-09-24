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
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "SDL Couldn't init" << std::endl;
            return false;
        }
        m_window = SDL_CreateWindow(m_name->c_str(),
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (m_window == NULL) {
            SDL_Quit();
            return false;
        }
        
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
                                      SCREEN_WIDTH, SCREEN_HEIGHT);
        if(m_renderer == NULL) {
            SDL_Quit();
            return false;
        }
        
        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        m_blur_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(m_blur_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

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
        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return;
        }
        
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
    }
    
    void Screen::clear() {
        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(m_blur_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    }
    
    bool Screen::processEvents() {
        SDL_Event event;
        
        while (SDL_PollEvent(&event)) {
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
    
    void Screen::boxBlur() {
        Uint32 * aux = m_buffer;
        m_buffer = m_blur_buffer;
        m_blur_buffer = aux;
        applyBlur();
    }
    
    void Screen::applyBlur() {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            for (int y = 0; y < SCREEN_HEIGHT; y++) {
                
                int totalRed = 0;
                int totalGreen = 0;
                int totalBlue = 0;
                for (int row = -1; row <=1; row++) {
                    for (int col = -1; col <=1; col++) {
                        int currentX = x + col;
                        int currentY = y + row;
                        if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >=0 && currentY < SCREEN_HEIGHT) {
                            Uint32 color = m_blur_buffer[currentY*SCREEN_WIDTH + currentX];
                            Uint8 red = color >> 24;
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;
                            
                            totalRed += red;
                            totalGreen += green;
                            totalBlue += blue;
                        }
                    }
                }
                
                Uint8 red = totalRed/9;
                Uint8 green = totalGreen/9;
                Uint8 blue = totalBlue/9;
                
                setPixel(x, y, red, green, blue);
            }
        }
    }
    
    Screen::~Screen() {
        delete m_name;
        delete [] m_buffer;
        delete [] m_blur_buffer;
    }
    
}
