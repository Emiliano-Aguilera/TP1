#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
// TODO para que sirve subentidades si es privado??, 
// Para que quiero agregar subentidades a una clase que no puede ser instanciada si sus subclases implementan un metodo igual?
class EntidadOrganizativa {
    private:
        std::vector<std::shared_ptr<EntidadOrganizativa>> subentidades;
    public:
        std::string nombre;
    public:
        void agregarSubentidad(std::shared_ptr<EntidadOrganizativa> entidad);
        int contarSubentidades() const;
        virtual ~EntidadOrganizativa() = 0;
};
