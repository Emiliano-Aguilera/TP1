#pragma once

#include <iostream>

#include <mago.hpp>
#include <map>
#include <string>
#include <memory>

//TODO Checkear que los valores que se le asignan a cada tipo tengan sentido
// Diferencias Guerrero de Mago
class Guerrero : public Mago {
protected:
    Guerrero(personajeType type, double health, std::shared_ptr<Arma> weapon1 = std::make_shared<ArmaNula>(), std::shared_ptr<Arma> weapon2 = std::make_shared<ArmaNula>())
        : Mago(type, health, weapon1, weapon2) {}
    
public:
    virtual ~Guerrero() = 0; // Pure virtual destructor
};