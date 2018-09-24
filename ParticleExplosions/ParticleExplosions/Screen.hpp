//
//  Screen.hpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 06/09/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <SDL.h>
#include <stdio.h>
#include <iostream>
namespace particles {
    class Screen {
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;
        Uint32 *m_blur_buffer;
        std::string * m_name;
        void applyBlur();
    public:
        Screen(std::string * name);
        bool init();
        bool processEvents();
        void clear();
        void close();
        void update();
        void boxBlur();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        ~Screen();
    };
}
#endif /* Screen_hpp */

