#include "MagicWeapon.hpp"

MagicWeapon::MagicWeapon(weaponType type, int fastDamage, int strongDamage, int defenseDamage, double critProb, int mana, int durability, std::string element) {
    m_type = type;
    m_fastDamage = fastDamage;
    m_strongDamage = strongDamage;
    m_defenseDamage = defenseDamage;
    m_critProbability = critProb;
    m_mana = mana;
    m_durability = durability;
    m_element = element;
}

double calcDamage(const MagicWeapon& weapon, double damage) {
    double totalDamage = damage + (weapon.m_mana / 50) - (100 / weapon.m_durability);
    return totalDamage;
}

// Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
double MagicWeapon::fastAttack() {
    double totalDamage = calcDamage(*this, m_fastDamage);

    bool isCritic = RandomEngine::Instance().RandomBool(m_critProbability);
    if (isCritic) {
        totalDamage *= 2;
        std::cout << "Critic " << m_element << " attack!" << std::endl;
    }

    (m_durability-1 <= 0) ? m_durability = 1 : m_durability--;

    return totalDamage;
}

// Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
double MagicWeapon::strongAttack() {
    double totalDamage = calcDamage(*this, m_strongDamage);

    bool isCritic = RandomEngine::Instance().RandomBool(m_critProbability);
    if (isCritic) {
        totalDamage *= 2;
        std::cout << "Critic " << m_element << " attack!" << std::endl;
    }

    (m_durability -10 / m_mana <= 0) ? m_durability = 1 : m_durability -= (10 / m_mana);

    return totalDamage;
}

// Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
double MagicWeapon::defenseAttack() {
    double totalDamage = calcDamage(*this, m_defenseDamage);

    bool isCritic = RandomEngine::Instance().RandomBool(m_critProbability);

    if (isCritic) {
        totalDamage *= 2;
        std::cout << "Critic " << m_element << " attack!" << std::endl;
    }

    (m_durability -50 / m_mana <= 0) ? m_durability = 1 : m_durability -= (50 / m_mana);

    return totalDamage;
}

std::string MagicWeapon::getType() const {
    return s_armaTypeToString(m_type);
}

// Devuelve la probabilidad de critico.
double MagicWeapon::getCritProb() const {
    return m_critProbability;
}

double MagicWeapon::getFastDamage() const {
    return m_fastDamage;
}

double MagicWeapon::getStrongDamage() const {
    return m_strongDamage;
}

double MagicWeapon::getDefenseDamage() const {
    return m_defenseDamage;
}

int MagicWeapon::getMana() const {
    return m_mana;
}

int MagicWeapon::getDurability() const {
    return m_durability;
}

std::string MagicWeapon::getElement() const {
    return m_element;
}

MagicWeapon::~MagicWeapon() {};