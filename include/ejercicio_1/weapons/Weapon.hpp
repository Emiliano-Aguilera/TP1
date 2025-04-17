#pragma once

#include <string>
#include <random>

enum class weaponType {
    STAFF = 0,
    POTION,
    SPELL_BOOK,
    TALISMAN,
    SWORD,
    CLUB,
    DOUBLE_AXE,
    SIMPLE_AXE,
    SPEAR
};

class Weapon {
    public:
        virtual double fastAttack() = 0;
        virtual double strongAttack() = 0;
        virtual double defenseAttack() = 0;
        virtual std::string getType() const = 0;
        virtual double getCritProb() const = 0;
        virtual double getFastDamage() const = 0;
        virtual double getStrongDamage() const = 0;
        virtual double getDefenseDamage() const = 0;
        virtual int getDurability() const = 0;

        // Funcion estatica para pasar de weaponType a string.
        static std::string s_armaTypeToString(weaponType type) {
            switch (type) {
            case weaponType::STAFF: return "Staff";
            case weaponType::SWORD: return "Sword";
            case weaponType::CLUB: return "Club";
            case weaponType::DOUBLE_AXE: return "Double Axe";
            case weaponType::SIMPLE_AXE: return "Simple Axe";
            case weaponType::SPEAR: return "Spear";
            case weaponType::POTION: return "Potion";
            case weaponType::SPELL_BOOK: return "Spell Book";
            case weaponType::TALISMAN: return "Talisman";
            default: return "Unknown";
            }
        }

        virtual ~Weapon() = default;
};  