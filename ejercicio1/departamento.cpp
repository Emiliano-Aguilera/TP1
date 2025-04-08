#include "departamento.hpp"

int Departamento::contarEmpleados() {
    return empleados.size();
}
std::vector<std::shared_ptr<Empleado>> Departamento::getEmpleados() {
    return empleados;
}
bool Departamento::contratarEmpleado(std::shared_ptr<Empleado> empleado) {
    empleados.push_back(empleado);
    return true;
}

bool Departamento::despedirEmpleado(std::shared_ptr<Empleado> empleado) {
    for (auto i = empleados.begin(); i != empleados.end(); i++) {
        if (*i == empleado) {
            empleados.erase(i);
            return true;
        }
    }
    return false;
}