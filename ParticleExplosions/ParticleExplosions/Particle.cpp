//
//  Particle.cpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 07/09/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include "Particle.hpp"

namespace particles {
 
    Particle::Particle(): m_y(0), m_x(0) {
        m_direction = (2 * M_PI * rand())/RAND_MAX;
        m_speed = 0.01 * rand()/RAND_MAX;
    }
    
    void Particle::updateRandomPosition() {
        m_x += m_speed * cos(m_direction);
        m_y += m_speed * sin(m_direction);
    }
    
    void Particle::roundCoordinate(double * coordinate) {
        if (*coordinate < -1.0 || *coordinate > 1.0) {
            *coordinate = -*coordinate;
        }
    }
    
    Particle::~Particle() {
        
    }

}
