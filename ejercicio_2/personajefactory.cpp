#include "personajefactory.hpp"
#include "subguerreros.hpp"
#include "submagos.hpp"
#include "subarmascombate.hpp"
#include "subarmasmagicas.hpp"
#include "armanula.hpp"

std::shared_ptr<Personaje> PersonajeFactory::crearPersonaje(personajeType tipoPersonaje) {
    switch (tipoPersonaje) {
        case personajeType::HECHICERO:
            return std::make_shared<Hechicero>();
        case personajeType::CONJURADOR:
            return std::make_shared<Conjurador>();
        case personajeType::BRUJO:
            return std::make_shared<Brujo>();
        case personajeType::NIGROMANTE:
            return std::make_shared<Nigromante>();
        case personajeType::BARBARO:
            return std::make_shared<Barbaro>();
        case personajeType::PALADIN:
            return std::make_shared<Paladin>();
        case personajeType::CABALLERO:
            return std::make_shared<Caballero>();
        case personajeType::MERCERNARIO:
            return std::make_shared<Mercenario>();
        case personajeType::GLADIADOR:
            return std::make_shared<Gladiador>();
        default:
            return nullptr;
    }
}

std::shared_ptr<Arma> PersonajeFactory::crearArma(armaType tipoArma) {
    switch (tipoArma) {
        case armaType::BASTON:
            return std::make_shared<Baston>();
        case armaType::ESPADA:
            return std::make_shared<Espada>();
        case armaType::GARROTE:
            return std::make_shared<Garrote>();
        case armaType::HACHA_DOBLE:
            return std::make_shared<HachaDoble>();
        case armaType::HACHA_SIMPLE:
            return std::make_shared<HachaSimple>();
        case armaType::LANZA:
            return std::make_shared<Lanza>();
        case armaType::POCION:
            return std::make_shared<Pocion>();
        case armaType::LIBRO_DE_HECHIZOS:
            return std::make_shared<LibroDeHechizos>();
        case armaType::AMULETO:
            return std::make_shared<Amuleto>();
        default:
            return nullptr;
    }
}

std::shared_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(personajeType tipoPersonaje, armaType tipoArma1) {
    std::shared_ptr<Arma> weapon1 = crearArma(tipoArma1);

    std::shared_ptr<Personaje> personaje = crearPersonaje(tipoPersonaje);

    personaje->setWeapons(weapon1);

    return personaje;
}

std::shared_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(personajeType tipoPersonaje, armaType tipoArma1, armaType tipoArma2) {
    std::shared_ptr<Arma> weapon1 = crearArma(tipoArma1);
    std::shared_ptr<Arma> weapon2 = crearArma(tipoArma2);

    std::shared_ptr<Personaje> personaje = crearPersonaje(tipoPersonaje);

    personaje->setWeapons(weapon1, weapon2);
    
    return personaje;
}