#include "Mage.hpp"
#include "NullWeapon.hpp"

Mage::Mage(characterType type, double hp, int magicResistance, int magicPower, int intelligence, std::unique_ptr<Weapon> weapon1, std::unique_ptr<Weapon> weapon2) {
    m_type = type;
    m_healthPoints = hp;
    m_weapon1 = weapon1 ? std::move(weapon1) : std::make_unique<NullWeapon>();
    m_weapon2 = weapon2 ? std::move(weapon2) : std::make_unique<NullWeapon>();
    m_magicResistance = magicResistance;
    m_magicPower = magicPower;
    m_intelligence = intelligence;
}

double Mage::attack(attackType attackSent) {
    switch (attackSent) {
        case attackType::FAST_ATTACK:
            return m_weapon1->fastAttack() + m_weapon2->fastAttack() + m_magicPower / 5;
        case attackType::STRONG_ATTACK:
            return m_weapon1->strongAttack() + m_weapon2->strongAttack() + m_magicPower / 3;
        case attackType::DEFENSE_ATTACK:
            return m_weapon1->defenseAttack() + m_weapon2->defenseAttack() + m_magicResistance / 6;
        default:
            return 0;
    }
}

void Mage::receiveDamage(double damageReceived) {
    if (!m_alive) {
        throw std::invalid_argument("El mago esta muerto, no puede recibir daño.");
    }

    if (m_healthPoints > damageReceived) {
        m_healthPoints -= damageReceived - m_magicResistance / 6;
    }
    else {
        kill();
    }
}

void Mage::kill() {
    if (!m_alive) {
        throw std::invalid_argument("El mago clase " + getType() + " ya esta muerto, no puede morir de nuevo.");
    }

    m_alive = false;
    m_healthPoints = 0;
    std::cout << "El mago clase " << getType() << " ha muerto." << std::endl;
}

void Mage::setWeapon1(std::unique_ptr<Weapon> weapon) {
    m_weapon1 = weapon ? std::move(weapon) : std::make_unique<NullWeapon>();
    
}
void Mage::setWeapon2(std::unique_ptr<Weapon> weapon) {
    m_weapon2 = weapon ? std::move(weapon) : std::make_unique<NullWeapon>();
}

void Mage::displayWeapon1() const {
    if (m_weapon1) {
        std::cout << "Weapon 1: " << m_weapon1->getType() << std::endl;
    } else {
        std::cout << "Weapon 1: NullWeapon" << std::endl;
    }
}

void Mage::displayWeapon2() const {
    if (m_weapon2) {
        std::cout << "Weapon 2: " << m_weapon2->getType() << std::endl;
    } else {
        std::cout << "Weapon 2: NullWeapon" << std::endl;
    }
}


bool Mage::isAlive() const { return  m_alive; }

std::string Mage::getType() const { return s_characterTypeToString(m_type); }

double Mage::getHealthPoints() const { return m_healthPoints; }

Mage::~Mage() {};