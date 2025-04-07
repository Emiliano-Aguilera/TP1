// filepath: /home/emiag/TP1/ejercicio1/empleado.cpp
#include "empleado.hpp"

int Empleado::getAntiguedad() {
    return antiguedad;
}

bool Empleado::updateSalario(float new_salario) {
    salario = new_salario;
    return true; // Assuming the update is always successful
}

float Empleado::getSalario() {
    return salario;
}