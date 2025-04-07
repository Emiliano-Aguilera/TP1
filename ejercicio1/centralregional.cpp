// filepath: /home/emiag/TP1/ejercicio1/centralregional.cpp
#include "centralregional.hpp"

int CentralRegional::getCantEmpleados() const {
    return cantEmpleados;
}

std::vector<std::string> CentralRegional::getEmpNames() const {
    std::vector<std::string> empNames;
    for (const auto& empresa : empresas) {
        empNames.push_back(empresa.first); // Assuming the key is the name of the empresa
    }
    return empNames;
}

std::vector<GerenteAlto> CentralRegional::getGerentesAlto() const {
    std::vector<GerenteAlto> gerentesAltoVec(gerentesAlto, gerentesAlto + sizeof(gerentesAlto) / sizeof(GerenteAlto));
    return gerentesAltoVec;
}

std::vector<GerenteMedio> CentralRegional::getGerentesMedio() const {
    std::vector<GerenteMedio> gerentesMedioVec(gerentesMedio, gerentesMedio + sizeof(gerentesMedio) / sizeof(GerenteMedio));
    return gerentesMedioVec;
}