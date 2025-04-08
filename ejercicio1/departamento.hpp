#pragma once

#include <string>
#include <vector>
#include <memory>

#include "empleado.hpp"

class Departamento{
    private:
        std::vector<std::shared_ptr<Empleado>> empleados;
        int cantEmpleadosDept;
    public:
        std::string nombre;
        std::string ubicacion;
    public:
        int contarEmpleados();
        std::vector<std::shared_ptr<Empleado>> getEmpleados();
        bool contratarEmpleado(std::shared_ptr<Empleado> empleado);
        bool despedirEmpleado(std::shared_ptr<Empleado> empleado);

        ~Departamento() = default;
};