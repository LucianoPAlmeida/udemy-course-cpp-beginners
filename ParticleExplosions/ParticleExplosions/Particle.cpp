//
//  Particle.cpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 07/09/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include "Particle.hpp"

namespace particles {
 
    Particle::Particle() {
        m_x = ((2.0 * rand())/RAND_MAX) - 1;
        m_y = ((2.0 * rand())/RAND_MAX) - 1;
        m_xspeed = Particle::PARTICLE_SPEED * (((2.0 * rand())/RAND_MAX) - 1);
        m_yspeed = Particle::PARTICLE_SPEED * (((2.0 * rand())/RAND_MAX) - 1);
    }
    
    void Particle::updateRandomPosition() {
        m_x += m_xspeed;
        m_y += m_yspeed;
        
        roundCoordinate(&m_x);
        roundCoordinate(&m_y);
    }
    
    void Particle::roundCoordinate(double * coordinate) {
        if (*coordinate < -1.0 || *coordinate > 1.0) {
            *coordinate = -*coordinate;
        }
    }
    
    Particle::~Particle() {
        
    }
    
    
}
