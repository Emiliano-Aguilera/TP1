#include "entidadorganizativa.hpp"

int EntidadOrganizativa::contarSubentidades() const {
    return subentidades.size();
}

void EntidadOrganizativa::agregarSubentidad(std::shared_ptr<EntidadOrganizativa> entidad) {
    std::cerr << "Funcion no implementada, no tiene sentido." << entidad;
}

EntidadOrganizativa::~EntidadOrganizativa() {
    // TODO Implementación vacía del destructor virtual puro
}