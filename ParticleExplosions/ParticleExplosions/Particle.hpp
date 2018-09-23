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
    private:
        double m_x;
        double m_y;
    public:
        Particle();
        virtual ~Particle();
    };
}

#endif /* Particle_hpp */
