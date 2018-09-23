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
    }
    
    Particle::~Particle() {
        
    }
}
