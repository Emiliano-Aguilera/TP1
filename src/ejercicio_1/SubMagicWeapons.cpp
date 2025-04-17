#include "SubMagicWeapons.hpp"

/*
Implementa los metodos especificos de cada MagicWeapon.
*/

// Implementacion Talisman
void Talisman::prayToTalisman(){
    std::cout << "Grabs the Talisman, prays something to it...And something shines trough his eyes..." << std::endl;
    m_fastDamage = 20;
    m_strongDamage = 35;
    m_defenseDamage = 20;
}

// Implementacion Potion
void Potion::distillPotion() {
    std::cout << "After 2 hours, the potion is ready!... Where is everyone?" << std::endl;
    m_fastDamage = 40;
    m_strongDamage = 50;
}

// Implementacion Staff
void Staff::growTree() {
    std::cout << "A tree appears out of nowhere protecting the allies!" << std::endl;
    m_defenseDamage = 60;
}

// Implementacion SpellBook
void SpellBook::tellStory() {
    std::cout << "Once upon a time... ZZZ..." << std::endl;
    m_fastDamage = 50;
}