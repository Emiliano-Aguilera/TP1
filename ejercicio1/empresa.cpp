// filepath: /home/emiag/TP1/ejercicio1/empresa.cpp
#include "empresa.hpp"

std::shared_ptr<Departamento> Empresa::getDeptByName(std::string name) {
    for (const auto& departamento : departamentos) {
        if (departamento->getNombre() == name) {
            return departamento;
        }
    }
    return nullptr; // Return nullptr if not found
}

std::vector<std::string> Empresa::getDeptNames() {
    std::vector<std::string> names;
    for (const auto& departamento : departamentos) {
        names.push_back(departamento->getNombre());
    }
    return names;
}