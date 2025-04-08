#pragma once

#include <string>
#include <vector>
#include <memory>

#include "entidadorganizativa.hpp"
#include "departamento.hpp"

class Empresa : public EntidadOrganizativa {
    private:
        std::vector<std::shared_ptr<Departamento>> departamentos;
    public:
        std::string direccion;
    public:
        void agregarDepartamento(std::shared_ptr<Departamento> nuevo_departamento);

        std::shared_ptr<Departamento> getDeptByName(std::string name);
        std::vector<std::string> getDeptNames();
        
        ~Empresa() = default;
};