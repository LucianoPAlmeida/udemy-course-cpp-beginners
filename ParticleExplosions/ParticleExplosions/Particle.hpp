//
//  Particle.hpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 07/09/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include <stdlib.h>

namespace particles {
    
    struct Particle {
        double m_x;
        double m_y;
    private:
        double m_xspeed;
        double m_yspeed;
        void roundCoordinate(double * coordinate);
    public:
        constexpr const static double PARTICLE_SPEED = 0.01;
    public:
        Particle();
        void updateRandomPosition();
        virtual ~Particle();
    };
}

#endif /* Particle_hpp */
