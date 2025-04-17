#include "SubMages.hpp"

/*
En este archivo se implementan los metodos especificos de cada clase de submago.
Se eligio esta estructura ya que son pocos metodos y los mismos son de clases que estan muy relacionadas entre si.
En un caso en el que hubiese que implementar muchos metodos lo ideal es hacer un archivo por mago.
*/

// Implementacion de Sorcercer
void Sorcerer::castSpell() {
    std::cout << "Wingardium Leviosa!" << std::endl;
}


// Implementacion de Conjurer
void Conjurer::invokeFriend(std::string friendName) {
    std::cout << "The conjurer invokes its friend: " << friendName << std::endl;
}

// Implementacion Witcher
void Witcher::witcherVision() {
    std::cout << "--Witcher: I can see everything..." << std::endl;
}

// Implementacion Necromancer
void Necromancer::awakeDeath(std::string deathName) {
    std::cout << deathName << " rises from Hell!" << std::endl;
}

