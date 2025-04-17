#include "SubMages.hpp"
#include "SubWarriors.hpp"
#include "SubMagicWeapons.hpp"
#include "SubCombatWeapons.hpp"
#include "RandomEngine.hpp"
#include "CharacterFactory.hpp"

#include <iostream>
#include <map>

int main() {
    RandomEngine& randomEngine = RandomEngine::Instance();
    
    int mageQuantity = randomEngine.RandomInt(3, 7);
    int warriorQuantity = randomEngine.RandomInt(3, 7);

    std::cout << "Number of Mages: " << mageQuantity << std::endl;
    std::cout << "Number of Warriors: " << warriorQuantity << std::endl;
    std::cout << "=======================" << std::endl;

    for (int i = 0; i < mageQuantity; i++) {
        int weaponQuantity = randomEngine.RandomInt(0, 2);
        characterType mageType = characterType(randomEngine.RandomInt(0, 3));
        std::unique_ptr<Character> mage = CharacterFactory::createCharacter(mageType);

        std::cout << "Mage " << i << " type: " << mage->getType() << std::endl;
        std::cout << "Number of weapons for Mage " << i << ": " << weaponQuantity << std::endl << std::endl;
        std::cout << "Character's signature ability: " << std::endl;

        switch (mageType) {
            case characterType::SORCERER: {
                Sorcerer* subMage = dynamic_cast<Sorcerer*>(mage.get());
                if (subMage) {
                    subMage->castSpell();
                }
                break;
            }
            case characterType::CONJURER: {
                Conjurer* subMage = dynamic_cast<Conjurer*>(mage.get());
                if (subMage) {
                    subMage->invokeFriend("Spirit");
                }
                break;
            }
            case characterType::WITCHER: {
                Witcher* subMage = dynamic_cast<Witcher*>(mage.get());
                if (subMage) {
                    subMage->witcherVision();
                }
                break;
            }
            case characterType::NECROMANCER: {
                Necromancer* subMage = dynamic_cast<Necromancer*>(mage.get());
                if (subMage) {
                    subMage->awakeDeath("Skeleton");
                }
                break;
            }
            default: 
                std::cerr << "Unknown Mage Type!" << std::endl;
                break;
        }

        for (int j = 0; j < weaponQuantity; j++) {
            std::cout << std::endl;
            weaponType randomWeaponType = static_cast<weaponType>(randomEngine.RandomInt(0, 3));
            std::unique_ptr<Weapon> weapon;

            std::cout << "Weapon " << (j + 1) << " type: ";
            switch (randomWeaponType) {
                case weaponType::TALISMAN: {
                    std::cout << "Talisman" << std::endl;
                    Talisman talisman;
                    talisman.prayToTalisman();
                    weapon = std::make_unique<Talisman>();
                    break;
                }
                case weaponType::POTION: {
                    std::cout << "Potion" << std::endl;
                    Potion potion;
                    potion.distillPotion();
                    weapon = std::make_unique<Potion>();
                    break;
                }
                case weaponType::STAFF: {
                    std::cout << "Staff" << std::endl;
                    Staff staff;
                    staff.growTree();
                    weapon = std::make_unique<Staff>();
                    break;
                }
                case weaponType::SPELL_BOOK: {
                    std::cout << "Spell Book" << std::endl;
                    SpellBook spellBook;
                    spellBook.tellStory();
                    weapon = std::make_unique<SpellBook>();
                    break;
                }
                default: {
                    std::cerr << "Unknown Magic Weapon Type!" << std::endl;
                    weapon = std::make_unique<NullWeapon>();
                    break;
                }
            }

            if (j == 0) {
                mage->setWeapon1(std::move(weapon));
            } else if (j == 1) {
                mage->setWeapon2(std::move(weapon));
            }
        }

        // Add a separator after each Mage
        std::cout << "-----------------------------" << std::endl;
    }

    for (int i = 0; i < warriorQuantity; i++) {
        int weaponQuantity = randomEngine.RandomInt(0, 2);
        characterType warriorType = characterType(randomEngine.RandomInt(4, 8));
        std::unique_ptr<Character> character = CharacterFactory::createCharacter(warriorType);

        std::cout << "Warrior " << i << " type: " << character->getType() << std::endl;
        std::cout << "Number of weapons for Warrior " << i << ": " << weaponQuantity << std::endl << std::endl;
        std::cout << "Character's signature ability: " << std::endl;
        switch (warriorType) {
            case characterType::BARBARIAN: {
                Barbarian* subWarrior = dynamic_cast<Barbarian*>(character.get());
                if (subWarrior) {
                    subWarrior->barbarianScream();
                }
                break;
            }
            case characterType::PALADIN: {
                Paladin* subWarrior = dynamic_cast<Paladin*>(character.get());
                if (subWarrior) {
                    subWarrior->giveSpeech("For honor and justice!");
                }
                break;
            }
            case characterType::KNIGHT: {
                Knight* subWarrior = dynamic_cast<Knight*>(character.get());
                if (subWarrior) {
                    subWarrior->kneel("King");
                }
                break;
            }
            case characterType::MERCENARY: {
                Mercenary* subWarrior = dynamic_cast<Mercenary*>(character.get());
                if (subWarrior) {
                    subWarrior->getPaid(100.0);
                }
                break;
            }
            case characterType::GLADIATOR: {
                Gladiator* subWarrior = dynamic_cast<Gladiator*>(character.get());
                if (subWarrior) {
                    subWarrior->grabSandFromFloor();
                }
                break;
            }
            default:
                std::cerr << "Unknown warrior type!" << std::endl;
                break;
        }
        for (int j = 0; j < weaponQuantity; j++) {
            std::cout << std::endl;
            weaponType randomWeaponType = static_cast<weaponType>(randomEngine.RandomInt(4, 8));
            std::unique_ptr<Weapon> weapon;

            std::cout << "Weapon " << (j + 1) << " type: ";
            switch (randomWeaponType) {
                case weaponType::SPEAR: {
                    std::cout << "Spear" << std::endl;
                    Spear spear;
                    spear.circleAttack();
                    weapon = std::make_unique<Spear>();
                    break;
                }
                case weaponType::SIMPLE_AXE: {
                    std::cout << "Simple Axe" << std::endl;
                    SimpleAxe simpleAxe;
                    simpleAxe.throwAxe();
                    weapon = std::make_unique<SimpleAxe>();
                    break;
                }
                case weaponType::DOUBLE_AXE: {
                    std::cout << "Double Axe" << std::endl;
                    DoubleAxe doubleAxe;
                    doubleAxe.clapAxes();
                    weapon = std::make_unique<DoubleAxe>();
                    break;
                }
                case weaponType::CLUB: {
                    std::cout << "Club" << std::endl;
                    Club club;
                    club.juggleClub();
                    weapon = std::make_unique<Club>();
                    break;
                }
                case weaponType::SWORD: {
                    std::cout << "Sword" << std::endl;
                    Sword sword;
                    sword.riseSword();
                    weapon = std::make_unique<Sword>();
                    break;
                }
                default: {
                    std::cout << "Unknown Weapon" << std::endl;
                    weapon = std::make_unique<NullWeapon>();
                    break;
                }
            }

            if (j == 0) {
                character->setWeapon1(std::move(weapon));
            } else if (j == 1) {
                character->setWeapon2(std::move(weapon));
            }
        }

        // Add a separator after each Warrior
        std::cout << "-----------------------------" << std::endl;
    }
}
