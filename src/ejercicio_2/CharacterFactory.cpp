#include "CharacterFactory.hpp"
#include "SubWarriors.hpp"
#include "SubMages.hpp"
#include "SubCombatWeapons.hpp"
#include "SubMagicWeapons.hpp"
#include "NullWeapon.hpp"

std::unique_ptr<Character> CharacterFactory::createCharacter(characterType chType) {
    switch (chType) {
        case characterType::SORCERER:
            return std::make_unique<Sorcerer>();
        case characterType::CONJURER:
            return std::make_unique<Conjurer>();
        case characterType::WITCHER:
            return std::make_unique<Witcher>();
        case characterType::NECROMANCER:
            return std::make_unique<Necromancer>();
        case characterType::BARBARIAN:
            return std::make_unique<Barbarian>();
        case characterType::PALADIN:
            return std::make_unique<Paladin>();
        case characterType::KNIGHT:
            return std::make_unique<Knight>();
        case characterType::MERCENARY:
            return std::make_unique<Mercenary>();
        case characterType::GLADIATOR:
            return std::make_unique<Gladiator>();
        default:
            return nullptr;
    }
}

std::unique_ptr<Weapon> CharacterFactory::createWeapon(weaponType wType) {
    switch (wType) {
        case weaponType::STAFF:
            return std::make_unique<Staff>();
        case weaponType::SWORD:
            return std::make_unique<Sword>();
        case weaponType::CLUB:
            return std::make_unique<Club>();
        case weaponType::DOUBLE_AXE:
            return std::make_unique<DoubleAxe>();
        case weaponType::SIMPLE_AXE:
            return std::make_unique<SimpleAxe>();
        case weaponType::SPEAR:
            return std::make_unique<Spear>();
        case weaponType::POTION:
            return std::make_unique<Potion>();
        case weaponType::SPELL_BOOK:
            return std::make_unique<SpellBook>();
        case weaponType::TALISMAN:
            return std::make_unique<Talisman>();
        default:
            return nullptr;
    }
}

std::unique_ptr<Character> CharacterFactory::createArmedCharacter(characterType chType, weaponType wType) {
    std::unique_ptr<Weapon> weapon1 = createWeapon(wType);
    std::unique_ptr<Character> personaje = createCharacter(chType);
    personaje->setWeapon1(std::move(weapon1));
    return personaje;
}

std::unique_ptr<Character> CharacterFactory::createArmedCharacter(characterType chType, weaponType wType1, weaponType wType2) {
    std::unique_ptr<Weapon> weapon1 = createWeapon(wType1);
    std::unique_ptr<Weapon> weapon2 = createWeapon(wType2);
    std::unique_ptr<Character> personaje = createCharacter(chType);

    personaje->setWeapon1(std::move(weapon1));
    personaje->setWeapon2(std::move(weapon2));
    
    return personaje;
}