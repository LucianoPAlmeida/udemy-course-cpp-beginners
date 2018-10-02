//
//  Swarm.hpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 07/09/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include <stdio.h>
#include "Particle.hpp"

namespace particles {
    class Swarm {
    public:
        const static int N_PARTICLES = 1000;
    private:
        Particle * const m_particles;
    public:
        Swarm();
        Particle * getParticles() { return m_particles; }
        void moveParticles();
        virtual ~Swarm();
    };
}

#endif /* Swarm_hpp */
