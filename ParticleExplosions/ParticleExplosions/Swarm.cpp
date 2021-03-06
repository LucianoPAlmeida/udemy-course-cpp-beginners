//
//  Swarm.cpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 07/09/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include "Swarm.hpp"

namespace particles {
    Swarm::Swarm(): m_particles(new Particle[N_PARTICLES]) {
    }
    
    Swarm::~Swarm() {
        delete [] m_particles;
    }
    
    void Swarm::moveParticles() {
        for(int i = 0; i<Swarm::N_PARTICLES; i++) {
            m_particles[i].moveToDirection();
        }
    }
}
