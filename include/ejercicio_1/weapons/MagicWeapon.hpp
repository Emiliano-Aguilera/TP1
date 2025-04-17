#pragma once

#include "Weapon.hpp"
#include "RandomEngine.hpp" // Para randomBool

#include <string>
#include <stdexcept>
#include <iostream>


class MagicWeapon : public Weapon {      
    protected:
        // Potencia de ataque del ataque ligero.
        double m_fastDamage;
        // Potencia de ataque del ataque fuerte o pesado.
        double m_strongDamage;
        // Defensa y golpe
        double m_defenseDamage;
        // Probabilidad de infligir el doble de danio
        double m_critProbability;
        
        // Tipo de arma
        weaponType m_type;
        int m_durability;
        
        // Atributos de magicWeapon
        int m_mana;
        std::string m_element;

        // Constructor protected para que solo personaje factory pueda instanciar armas
        MagicWeapon(weaponType type,
            int fastDamage,
            int strongDamage,
            int defenseDamage,
            double critProb,
            int mana,
            int durability,
            std::string element);


    private:
        friend double calcDamage(const MagicWeapon& weapon, double damage);


    public:        
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        double fastAttack() override;
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        double strongAttack() override;
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        double defenseAttack() override;
        
        // Devuelve el tipo de arma como string en base a la funcion helper declarada en weapon.
        std::string getType() const override;

        int getDurability() const override;
        double getCritProb() const override;
        double getFastDamage() const override;
        double getStrongDamage() const override;
        double getDefenseDamage() const override;

        // Metodos de magicWeapon
        int getMana() const;
        std::string getElement() const;

        // Destructor puro para que sea clase abstracta
        virtual ~MagicWeapon() = 0;
};

