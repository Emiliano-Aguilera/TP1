#include "armamagica.hpp"

ArmaMagica::ArmaMagica(armaType type, double lightDamage, double strongDamage, double defenseDamage, double critProb){
    m_type = type;
    m_lightDamage = lightDamage;
    m_strongDamage = strongDamage;
    m_defenseDamage = defenseDamage;
    m_critProbability = critProb;
}

// Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
double ArmaMagica::lightAttack() const {
    return (RandomEngine::Instance().RandomBool(m_critProbability)) ? (m_lightDamage * 2) : m_lightDamage;
}

// Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
double ArmaMagica::strongAttack() const {
    return (RandomEngine::Instance().RandomBool(m_critProbability)) ? (m_strongDamage * 2) : m_strongDamage;
}

// Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
double ArmaMagica::defenseAttack() const {
    return (RandomEngine::Instance().RandomBool(m_critProbability)) ? (m_defenseDamage * 2) : m_defenseDamage;
}

std::string ArmaMagica::getType() const {
    return s_armaTypeToString(m_type);
}

void ArmaMagica::setType(armaType newType){
    m_type = newType;
}

// Permite cambiar la probabilidad de critico, toma 0 <= double <= 1.
void ArmaMagica::setCritProb(double newProb) {
    if (newProb >= 0 && newProb <= 1) {
        m_critProbability = newProb;
    }
    else {
        throw std::invalid_argument("La probabilidad debe estar entre 0 y 1");
    }
}

// Devuelve la probabilidad de critico.
double ArmaMagica::getCritProb() const {
    return m_critProbability;
}

ArmaMagica::~ArmaMagica() {};