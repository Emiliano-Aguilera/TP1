#include "armanula.hpp"

double ArmaNula::lightAttack() const {
    return 0.0;
}

double ArmaNula::strongAttack() const {
    return 0.0;
}

double ArmaNula::defenseAttack() const {
    return 0.0;
}

void ArmaNula::setType(armaType newType) {
    if(newType == armaType::AMULETO) {

    }
}

std::string ArmaNula::getType() const {
    return "Sin arma";
}

void ArmaNula::setCritProb(double newProb) {
    if(newProb == 0.0) {
    }
}

double ArmaNula::getCritProb() const {
    return 0.0;
}
