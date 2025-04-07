// filepath: /home/emiag/TP1/ejercicio1/entidadorganizativa.cpp
#include "entidadorganizativa.hpp"

int EntidadOrganizativa::contarSubentidades() const {  
    return subentidades.size();
}

std::string EntidadOrganizativa::getNombre() const {
    return nombre;
}

void EntidadOrganizativa::agregarSubentidad(std::shared_ptr<EntidadOrganizativa> entidad){
    subentidades.push_back(entidad);
}