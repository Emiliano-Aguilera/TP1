#pragma once
#include "armamagica.hpp"

// TODO cambiar ArmaCombate para que no sea igual a ArmaMagica
class ArmaCombate : public ArmaMagica {
    protected: 
        // Constructor para ArmaCombate en base a ArmaMagica
        ArmaCombate(armaType type, double lightDamage, double strongDamage, double defenseDamage,
             double critProb) : ArmaMagica(type, lightDamage, strongDamage, defenseDamage, critProb) {}
};

