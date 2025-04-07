// filepath: /home/emiag/TP1/ejercicio1/empleado.cpp
#include "empleado.hpp"

int Empleado::getAntiguedad() {
    return antiguedad;
}

bool Empleado::updateSalario(float new_salario) {
    salario = new_salario;
    return true;
}

float Empleado::getSalario() {
    return salario;
}