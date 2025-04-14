#include "mago.hpp"
#include "armanula.hpp"

Mago::Mago(personajeType type, double HP, std::shared_ptr<Arma> weapon1, std::shared_ptr<Arma> weapon2) {
    m_type = type;
    m_healthPoints = HP;
    this->m_weapon1 = weapon1;
    this->m_weapon2 = weapon2;
}

double Mago::attack(attackType ataqueEnviado) {
    switch (ataqueEnviado) {
        case attackType::FUERTE:
            return m_weapon1->strongAttack() + m_weapon2->strongAttack();
        case attackType::RAPIDO:
            return m_weapon1->lightAttack() + m_weapon2->lightAttack();
        case attackType::DEFENSA_ATAQUE:
            return m_weapon1->defenseAttack() + m_weapon2->defenseAttack();
        default:
            return 0;
    }
}

bool Mago::receiveDamage(double damage) {
    if (!m_alive) {
        throw std::invalid_argument("El mago esta muerto, no puede recibir daño.");
    }

    if (m_healthPoints > damage) {
        m_healthPoints -= damage;
        return true;
    }
    else {
        kill();
        return false;
    }
}

void Mago::kill() {
    if (!m_alive) {
        throw std::invalid_argument("El mago clase " + getType() + " ya esta muerto, no puede morir de nuevo.");
    }

    m_alive = false;
    m_healthPoints = 0;
    std::cout << "El mago clase " << getType() << " ha muerto." << std::endl;
}

bool Mago::isAlive() const {
    return  m_alive;
}

std::string Mago::getType() const {
    return s_personajeTypeToString(m_type);
}

double Mago::getHealthPoints() const {
    return m_healthPoints;
}

std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> Mago::getWeapons() const {
    std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> weapons;
    weapons.first = m_weapon1;
    weapons.second = m_weapon2;

    return weapons;
}

void Mago::setWeapons(std::shared_ptr<Arma> arma1 = std::make_shared<ArmaNula>(), std::shared_ptr<Arma> arma2 = std::make_shared<ArmaNula>()) {
    m_weapon1 = arma1;
    m_weapon2 = arma2;
}

Mago::~Mago() {};