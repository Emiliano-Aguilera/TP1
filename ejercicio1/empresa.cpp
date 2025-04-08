#include "empresa.hpp"


void Empresa::agregarDepartamento(std::shared_ptr<Departamento> nuevo_departamento) {
    departamentos.push_back(nuevo_departamento);
}


std::shared_ptr<Departamento> Empresa::getDeptByName(std::string name){
    for (auto i = departamentos.begin(); i != departamentos.end(); i++) {
        if ((*i)->nombre == name) {
            return *i;
        }
    }
    return nullptr;
}

std::vector<std::string> Empresa::getDeptNames() {
    std::vector<std::string> deptNames{};

    for (auto i : departamentos) {
        deptNames.push_back(i->nombre);
    }

    return deptNames;
}