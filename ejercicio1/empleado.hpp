#pragma once

#include <string>

class Empleado {
    protected:
        int antiguedad;
        float salario;
    public:
        std::string nombre;
        std::string puesto;
    public:
        int getAntiguedad();
        bool updateSalario(float new_salario);
        float getSalario();
        
        ~Empleado() = default;
};