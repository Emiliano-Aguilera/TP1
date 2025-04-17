#pragma once

#include "Weapon.hpp"
#include "Character.hpp"

class CharacterFactory {
    public:
        static std::unique_ptr<Character> createCharacter(characterType);
        static std::unique_ptr<Weapon> createWeapon(weaponType);

        // Constructor sobrecargado que puede contener 1 o 2 armas, en el caso de contener solo una, la otra es ArmaNUla.
        static std::unique_ptr<Character> createArmedCharacter(characterType chType, weaponType wType);
        static std::unique_ptr<Character> createArmedCharacter(characterType chType, weaponType wType1, weaponType wType2);
    
    private:
        CharacterFactory() = delete;
        ~CharacterFactory() = delete;
    
        CharacterFactory(const CharacterFactory&) = delete;
        CharacterFactory& operator=(const CharacterFactory&) = delete;
};
