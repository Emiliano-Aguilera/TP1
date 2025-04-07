// filepath: /home/emiag/TP1/ejercicio1/manager.cpp
#include "manager.hpp"

bool Manager::updateBono(float valor) {
    bono = valor;
    return true;
}

float Manager::getBono() {
    return bono;
}

bool Manager::setLevel(std::string new_level) {
    level = new_level;
    return true;
}