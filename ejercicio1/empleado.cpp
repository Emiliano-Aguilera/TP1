#include "empleado.hpp"

int Empleado::getAntiguedad() {
    return antiguedad;
}
bool Empleado::updateSalario(float new_salario) {
    if (new_salario >= 0) {
        salario = new_salario;
        return true;
    } else {
        return false;
    }
}
float Empleado::getSalario() {
    return salario;
}