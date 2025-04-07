// filepath: /home/emiag/TP1/ejercicio1/departamento.cpp
#include "departamento.hpp"

int Departamento::contarEmpleados() const {
    return empleados.size();
}

std::vector<std::shared_ptr<Empleado>> Departamento::getEmployees() {
    return empleados;
}

bool Departamento::contratarEmpleado(std::shared_ptr<Empleado> empleado) {
    empleados.push_back(empleado);
    return true; // Assuming the hiring process is always successful
}

bool Departamento::despedirEmpleado(std::shared_ptr<Empleado> empleado) {
    auto it = std::find(empleados.begin(), empleados.end(), empleado);
    if (it != empleados.end()) {
        empleados.erase(it);
        return true; // Employee successfully fired
    }
    return false; // Employee not found
}