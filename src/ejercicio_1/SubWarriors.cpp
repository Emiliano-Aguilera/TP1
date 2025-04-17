#include "SubWarriors.hpp"

/*
Este archivo incluye las implementaciones de los metodos especificos a cada tipo de Warrior.
Se eligio este enfoque ya que es solo un metodo por Warrior y son todos de la misma clase abstracta,
lo que los relaciona entre si. 
En caso de ser muchos metodos por Warrior, o si los mismos no se relacionasen, en ese caso habria que separar en distintos archivos.
*/

// Implementacion Barbarian
void Barbarian::barbarianScream() {
    std::cout << "GRAHHGHHHH" << std::endl;
}

// Implementacion Knight
void Knight::kneel(std::string who) {
    std::cout << "The knight kneels before " << who << std::endl;
}

// Implementacion Gladiator
void Gladiator::grabSandFromFloor() {
    std::cout << "He grabs sand, smells it and the he lets it slip through his fingers." << std::endl;
}

// Implementacion Mercernary
void Mercenary::getPaid(double salary) {
    std::cout << "The mercenary got paid for his services: " << salary << " Credits" << std::endl;
}

// Implementacion Paladin
void Paladin::giveSpeech(std::string speech) {
    std::cout << "And the Paladin exclaimed: " << std::endl << speech << std::endl;
}