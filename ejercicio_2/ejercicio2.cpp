#include "arma.hpp"
#include "personaje.hpp"
#include "randomengine.hpp"
#include "personajefactory.hpp"

#include <iostream>
#include <map>

// TODO Pensar un poco mas los metodos y atributos de las armas

int main() {
    // Ejercicio 2:
    // Con el punto anterior, obtenga dos valores entre 3 y 7 para indicar la cantidad
    // de personajes tipo Mago y la cantidad de personajes tipo Guerrero. Luego, para
    // cada uno de estos personajes, obtenga un nuevo valor aleatorio entre 0 y 2 que
    // indique cuantas armas tendrá cada uno de estos personajes.

    // Motor que tiene metodos para generar numeros aleatorios
    RandomEngine& randomEngine = RandomEngine::Instance();
    
    int cantMagos = randomEngine.RandomInt(3, 7);
    int cantGuerreros = randomEngine.RandomInt(3, 7);

    std::cout << "Cantidad de Magos: " << cantMagos << std::endl;
    std::cout << "Cantidad de Guerreros: " << cantGuerreros << std::endl;

    std::vector<std::shared_ptr<Personaje>> personajes{};

    for (int i = 0; i < cantMagos; i++) {
        int cantArmas = randomEngine.RandomInt(0, 2);

        std::cout << "Cantidad de armas Mago_" << i + 1 << ": " << cantArmas << std::endl;

        std::shared_ptr<Personaje> personaje = PersonajeFactory::crearPersonaje(personajeType::BRUJO);

        personajes.push_back(personaje);
    }

    for (int i = 0; i < cantGuerreros; i++) {
        int cantArmas = randomEngine.RandomInt(0, 2);

        std::cout << "Cantidad de armas Guerrero_" << i + 1 << ": " << cantArmas << std::endl;

        std::shared_ptr<Personaje> personaje = PersonajeFactory::crearPersonaje(personajeType::CABALLERO);

        personajes.push_back(personaje);
    }

    for (auto p : personajes) {
        std::cout << "Personaje tipo: " << p->getType() << std::endl;
    }
}
