#include "SubCombatWeapons.hpp"

/*
Este archivo contiene las implementaciones de los metodos especificos a las armas de combate.
Como es un metodo por clase y todas se relacionan, me parece correcto unificarlos en un solo archivo.
*/

// Implementacion Spear
void Spear::circleAttack() {
    std::cout << "Circular Attack!" << std::endl;
    // Sube 10 al valor por defecto, no suma porque sino se podria abusar.
    m_defenseDamage = 30; 
}

// Implementacion SimpleAxe
void SimpleAxe::throwAxe() {
    std::cout << "The Axe has been thrown!...Here it comes!" << std::endl;

    m_fastDamage = 20;
}

// Implementacion DoubleAxe
void DoubleAxe::clapAxes() {
    std::cout << "Clang...Clang...Clang" << std::endl;
    m_fastDamage = 30;
}

// Implementacion Club
void Club::juggleClub() {
    std::cout << "\\ " << " | " << " / " << " -- " << " \\ " << std::endl;
    m_defenseDamage = 30;
}

// Implementacion Sword
void Sword::riseSword() {
    std::cout << "Levanta su espada, ganando confianza y fuerza..." << std::endl;
    m_strongDamage = 40;
}