#pragma once

#include "arma.hpp"
#include "personaje.hpp"

class PersonajeFactory {
    public:
        static std::shared_ptr<Personaje> crearPersonaje(personajeType);
        static std::shared_ptr<Arma> crearArma(armaType);

        // Constructor sobrecargado que puede contener 1 o 2 armas, en el caso de contener solo una, la otra es ArmaNUla.
        static std::shared_ptr<Personaje> crearPersonajeArmado(personajeType tipoPersonaje, armaType tipoArma1);
        static std::shared_ptr<Personaje> crearPersonajeArmado(personajeType tipoPersonaje, armaType tipoArma1, armaType tipoArma2);
    
    private:
        // Private constructor to prevent instantiation
        PersonajeFactory() = delete;
        ~PersonajeFactory() = delete;
    
        // Optionally delete copy/move constructors too
        PersonajeFactory(const PersonajeFactory&) = delete;
        PersonajeFactory& operator=(const PersonajeFactory&) = delete;
};
