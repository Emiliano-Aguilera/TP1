#include "centralregional.hpp"

int CentralRegional::getCantEmpleados() {
    return cantEmpleados;
}

std::vector<std::string> CentralRegional::getEmpNames() {
    std::vector<std::string> nombres_empleados{};

    for (auto eA : gerentesAlto) {
        // Como son std::array y no std::vector, hay que verificar que el puntero sea valid
        if (eA) {
            nombres_empleados.push_back(eA->nombre);
        }
        else {
            break;
        }
    }

    for (auto eM : gerentesMedio) {
        if (eM) {
            nombres_empleados.push_back(eM->nombre);
        }
        else {
            break;
        }
    }

    return nombres_empleados;
}

bool CentralRegional::agregarEmpresa(std::shared_ptr<Empresa> nueva_empresa) {
    return empresas.emplace(nueva_empresa->nombre, nueva_empresa).second;
}

void CentralRegional::agregarGerenteAlto(std::shared_ptr<GerenteAlto> nuevo_gerente) {
    if (iGerentesAlto < 5){
        gerentesAlto.at(iGerentesAlto) = nuevo_gerente;
        iGerentesAlto++;
    } 
    else {
        throw std::invalid_argument("Ya no se pueden agregar gerentes altos, maximo 5.");
    }
}

void CentralRegional::agregarGerenteMedio(std::shared_ptr<GerenteMedio> nuevo_gerente) {
    if (iGerentesMedio < 20) {
        gerentesMedio.at(iGerentesMedio) = nuevo_gerente;
        iGerentesMedio++;
    }
    else {
        throw std::invalid_argument("Ya no se pueden agregar gerentes medios, maximo 20");
    }
}

bool CentralRegional::eliminarEmpresa(std::shared_ptr<Empresa> nueva_empresa) {
    return empresas.erase(nueva_empresa->nombre);
}

void CentralRegional::eliminarGerenteAlto(std::shared_ptr<GerenteAlto> nuevo_gerente) {
    if (iGerentesAlto > 0) {
        gerentesAlto.at(iGerentesAlto) = nullptr;
        iGerentesAlto--;
    } 
    else {
        throw std::invalid_argument("No hay gerentes altos que eliminar.");
    }
}

void CentralRegional::eliminarGerenteMedio(std::shared_ptr<GerenteMedio> nuevo_gerente) {
    if (iGerentesMedio > 0) {
        gerentesMedio.at(iGerentesMedio) = nullptr;
        iGerentesMedio--;
    }
    else {
        throw std::invalid_argument("Ya no se pueden agregar gerentes medios, maximo 20");
    }
}

std::array<std::shared_ptr<GerenteAlto>, 5> CentralRegional::getGerentesAlto() {
    return gerentesAlto;
}

std::array<std::shared_ptr<GerenteMedio>, 20> CentralRegional::getGerentesMedio() {
    return gerentesMedio;
}