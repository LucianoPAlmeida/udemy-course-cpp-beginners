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
#include <math.h>

namespace particles {
    
    struct Particle {
        double m_x;
        double m_y;
    private:
        double m_speed;
        double m_direction;
        void roundCoordinate(double * coordinate);
    public:
        Particle();
        void updateRandomPosition();
        virtual ~Particle();
    };
}

#endif /* Particle_hpp */
