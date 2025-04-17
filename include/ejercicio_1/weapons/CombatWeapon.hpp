#pragma once

#include "Weapon.hpp"
#include "RandomEngine.hpp" // Para randomBool

#include <string>
#include <stdexcept>
#include <iostream>

class CombatWeapon : public Weapon {
    protected:
        // Potencia de ataque del ataque ligero.
        double m_fastDamage;
        // Potencia de ataque del ataque fuerte o pesado.
        double m_strongDamage;
        // Defensa y golpe
        double m_defenseDamage;
        // Probabilidad de infligir el doble de danio
        double m_critProbability;

        weaponType m_type;
        int m_durability;

        int m_weight;
        int m_concussion;
        
        // Constructor protected para que solo personaje factory pueda instanciar armas
        CombatWeapon(weaponType type,
                     int fastDamage,
                     int strongDamage,
                     int defenseDamage,
                     double critProb,
                     int durability,
                     int weight,
                     int concussion);

    private:
        friend double calcDamage(const CombatWeapon& weapon, double damage);
        
    public:        
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        double fastAttack() override;

        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        double strongAttack() override;

        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        double defenseAttack() override;
        
        std::string getType() const override;
        double getCritProb() const override;
        double getFastDamage() const override;
        double getStrongDamage() const override;
        double getDefenseDamage() const override;
        int getDurability() const override;

        int getWeight() const;
        int getConcussion() const;
        
        // Destructor puro para que sea clase abstracta
        virtual ~CombatWeapon() = 0;
};

