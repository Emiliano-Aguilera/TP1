#include "Warrior.hpp"
#include "Mage.hpp"
#include "NullWeapon.hpp"
Warrior::Warrior(characterType type, double HP, int shield, int strength, int speed, std::unique_ptr<Weapon> weapon1, std::unique_ptr<Weapon> weapon2) {
    m_type = type;
    m_healthPoints = HP;
    m_weapon1 = weapon1 ? std::move(weapon1) : std::make_unique<NullWeapon>(); // Si no se da arma, se asigna NullWeapon
    m_weapon2 = weapon2 ? std::move(weapon2) : std::make_unique<NullWeapon>();
    m_shield = shield;
    m_strength = strength;
    m_speed = speed;
}

double Warrior::attack(attackType attackSent) {
    switch (attackSent) {
        case attackType::FAST_ATTACK:
            return m_weapon1->fastAttack() + m_weapon2->fastAttack() + m_speed / 5;
        case attackType::STRONG_ATTACK:
            return m_weapon1->strongAttack() + m_weapon2->strongAttack() + m_strength;
        case attackType::DEFENSE_ATTACK:
            return m_weapon1->defenseAttack() + m_weapon2->defenseAttack() + m_shield / 4;
        default:
            return 0;
    }
}

void Warrior::receiveDamage(double damageReceived) {
    if (!m_alive) {
        throw std::invalid_argument("El guerrero está muerto, no puede recibir daño.");
    }

    if (m_healthPoints > damageReceived) {
        m_healthPoints -= damageReceived - m_shield / 4;
    } else {
        kill();
    }
}

void Warrior::kill() {
    if (!m_alive) {
        throw std::invalid_argument("El guerrero clase " + getType() + " ya está muerto, no puede morir de nuevo.");
    }

    m_alive = false;
    m_healthPoints = 0;
    std::cout << "El guerrero clase " << getType() << " ha muerto." << std::endl;
}

void Warrior::setWeapon1(std::unique_ptr<Weapon> weapon) {
    m_weapon1 = weapon ? std::move(weapon) : std::make_unique<NullWeapon>();
    
}
void Warrior::setWeapon2(std::unique_ptr<Weapon> weapon) {
    m_weapon2 = weapon ? std::move(weapon) : std::make_unique<NullWeapon>();
}

void Warrior::displayWeapon1() const {
    if (m_weapon1) {
        std::cout << "Weapon 1: " << m_weapon1->getType() << std::endl;
    } else {
        std::cout << "Weapon 1: NullWeapon" << std::endl;
    }
}

void Warrior::displayWeapon2() const {
    if (m_weapon2) {
        std::cout << "Weapon 2: " << m_weapon2->getType() << std::endl;
    } else {
        std::cout << "Weapon 2 NullWeapon" << std::endl;
    }
}

bool Warrior::isAlive() const { return m_alive; }

std::string Warrior::getType() const { return s_characterTypeToString(m_type); }

double Warrior::getHealthPoints() const { return m_healthPoints; }

Warrior::~Warrior() {}
