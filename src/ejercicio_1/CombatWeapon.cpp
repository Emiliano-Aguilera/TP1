#include "CombatWeapon.hpp"

CombatWeapon::CombatWeapon(weaponType type, int fastDamage, int strongDamage, int defenseDamage, double critProb, int durability, int weight, int concussion) {
    m_type = type;
    m_fastDamage = fastDamage;
    m_strongDamage = strongDamage;
    m_defenseDamage = defenseDamage;
    m_critProbability = critProb;
    m_durability = durability;
    m_weight = weight;
    m_concussion = concussion;
}

double calcDamage(const CombatWeapon& weapon, double damage) {
    double totalDamage = damage + weapon.m_concussion;
    totalDamage -= weapon.m_weight;

    return totalDamage;
}

// Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
double CombatWeapon::fastAttack() {
    double totalDamage = calcDamage(*this, m_fastDamage);

    bool isCritic = RandomEngine::Instance().RandomBool(m_critProbability);
    if (isCritic) { 
        std::cout << "Critic!" << std::endl;
        totalDamage *= 2;
    }

    // durability no se tiene en cuenta, pero se pone de ejemplo de uso.
    m_durability = (m_durability - 1 < 1) ? 1 : m_durability - 1;
    return totalDamage;
}

// Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
double CombatWeapon::strongAttack() {
    double totalDamage = calcDamage(*this, m_strongDamage);

    bool isCritic = RandomEngine::Instance().RandomBool(m_critProbability);
    if (isCritic) { 
        std::cout << "Critic!" << std::endl;
        totalDamage *= 2;
    }

    // durability no se tiene en cuenta, pero se pone de ejemplo de uso.
    m_durability = (m_durability - 2 < 1) ? 1 : m_durability - 2;
    return totalDamage;
}

// Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
double CombatWeapon::defenseAttack() {
    double totalDamage = calcDamage(*this, m_defenseDamage);

    // durability no se tiene en cuenta, pero se pone de ejemplo de uso.
    m_durability = (m_durability - 3 < 1) ? 1 : m_durability - 3;
    return totalDamage;
}

// Implements getType from CombatWeapon
std::string CombatWeapon::getType() const {
    return s_armaTypeToString(m_type);
}

// Devuelve la probabilidad de critico.
double CombatWeapon::getCritProb() const {
    return m_critProbability;
}


double CombatWeapon::getFastDamage() const {
    return m_fastDamage;
}

double CombatWeapon::getStrongDamage() const {
    return m_strongDamage;
}

double CombatWeapon::getDefenseDamage() const {
    return m_defenseDamage;
}

int CombatWeapon::getDurability() const {
    return m_durability;
}

int CombatWeapon::getWeight() const {
    return m_weight;
}

int CombatWeapon::getConcussion() const {
    return m_concussion;
}

CombatWeapon::~CombatWeapon() {};
