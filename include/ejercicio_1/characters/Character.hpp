#pragma once

#include <string>
#include <memory>
#include <map>

#include "Weapon.hpp"
#include "NullWeapon.hpp"

enum class attackType{
    FAST_ATTACK = 1,
    STRONG_ATTACK,
    DEFENSE_ATTACK
};

enum class characterType {
    SORCERER = 0,
    CONJURER,
    WITCHER,
    NECROMANCER,
    BARBARIAN,
    PALADIN,
    KNIGHT,
    MERCENARY, 
    GLADIATOR
};

class Character {
    public:
        virtual double attack(attackType attackSent) = 0;
        virtual void receiveDamage(double damageReceived) = 0;
        virtual void kill() = 0;

        virtual std::string getType() const = 0;
        virtual bool isAlive() const = 0;
        virtual double getHealthPoints() const = 0;

        virtual void setWeapon1(std::unique_ptr<Weapon> weapon) = 0;
        virtual void setWeapon2(std::unique_ptr<Weapon> weapon) = 0;
        virtual void displayWeapon1() const = 0;
        virtual void displayWeapon2() const = 0;

        // Funcion de ayuda que permite transformar characterType a string
        static std::string s_characterTypeToString(characterType type) {
            switch (type) {
                case characterType::SORCERER: return "Sorcerer";
                case characterType::CONJURER: return "Conjurer";
                case characterType::WITCHER: return "Witcher";
                case characterType::NECROMANCER: return "Necromancer";
                case characterType::BARBARIAN: return "Barbarian";
                case characterType::PALADIN: return "Paladin";
                case characterType::KNIGHT: return "Knight";
                case characterType::MERCENARY: return "Mercenary";
                case characterType::GLADIATOR: return "Gladiator";
                default: return "Unknown";
            }
        }
        
        // Destructor default
        virtual ~Character() = default;
};