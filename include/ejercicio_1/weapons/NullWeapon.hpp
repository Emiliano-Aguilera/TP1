#pragma once

#include "Weapon.hpp"

class NullWeapon : public Weapon {
    public:
        NullWeapon() = default;
        ~NullWeapon() = default;

        double fastAttack() override;
        double strongAttack() override;
        double defenseAttack() override;
        std::string getType() const override;
        double getCritProb() const override;

        double getFastDamage() const;
        double getStrongDamage() const;
        double getDefenseDamage() const;
        int getMana() const;
        int getDurability() const;
        std::string getElement() const;
};
