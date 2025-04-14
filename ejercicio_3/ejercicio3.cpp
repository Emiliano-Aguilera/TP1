#include "personajefactory.hpp"
#include "randomengine.hpp"

#include <iostream>
#include <iomanip> // Para std::setprecision

bool compareAttacks(attackType ataque1, attackType ataque2);
int getInt();
int getInt(int max, int min);
void ignoreLine();

const std::string nombresAtaques[] = {"Rapido", "Fuerte", "Ataque y Defensa"};

int main() {
    RandomEngine& randomEngine = RandomEngine::Instance();
    std::shared_ptr<Personaje> personaje1 = PersonajeFactory::crearPersonajeArmado(personajeType::NIGROMANTE, armaType::LIBRO_DE_HECHIZOS, armaType::BASTON);
    std::shared_ptr<Personaje> personaje2 = PersonajeFactory::crearPersonajeArmado(personajeType::GLADIADOR, armaType::ESPADA, armaType::ESPADA);

    // Mostrar información inicial
    std::cout << "Personaje 1: " << Personaje::s_personajeTypeToString(personajeType::NIGROMANTE) 
              << " con armas: " 
              << Arma::s_armaTypeToString(armaType::LIBRO_DE_HECHIZOS) << " y " 
              << Arma::s_armaTypeToString(armaType::BASTON) 
              << ". Vida inicial: " << personaje1->getHealthPoints() << std::endl;

    std::cout << "Personaje 2: " << Personaje::s_personajeTypeToString(personajeType::GLADIADOR) 
              << " con armas: " 
              << Arma::s_armaTypeToString(armaType::ESPADA) << " y " 
              << Arma::s_armaTypeToString(armaType::ESPADA) 
              << ". Vida inicial: " << personaje2->getHealthPoints() << std::endl;

    while (personaje1->isAlive() && personaje2->isAlive()) {
        std::cout << "Elija ataque [1]Rapido, [2]Fuerte, [3]Ataque y Defensa: ";
        attackType ataqueJugador = attackType(getInt(3, 1));

        attackType ataqueAleatorio = attackType(randomEngine.RandomInt(1,  3));

        std::cout << "Tipo de ataque del Jugador: " << nombresAtaques[int(ataqueJugador) - 1] << std::endl;
        std::cout << "Tipo de ataque de la computadora: " << nombresAtaques[int(ataqueAleatorio) - 1] << std::endl;

        if (ataqueJugador == ataqueAleatorio) {
            std::cout << "Los ataques son iguales! Nadie recibe daño" << std::endl;
            continue;
        } 
        else {
            bool ganador = compareAttacks(ataqueJugador, ataqueAleatorio);
            if (ganador) {
                double damage = personaje1->attack(ataqueJugador);
                personaje2->receiveDamage(damage);
                auto armas = personaje1->getWeapons();
                std::cout << "El jugador ataca con " 
                          << armas.first->getType() 
                          << " y causa " << damage 
                          << " puntos de daño al personaje " 
                          << personaje2->getType() << "." << std::endl;
                std::cout << "Vida restante del personaje " << personaje2->getType() 
                          << ": " << personaje2->getHealthPoints() << std::endl;
            } else {
                double damage = personaje2->attack(ataqueAleatorio);
                personaje1->receiveDamage(damage);
                auto armas = personaje2->getWeapons();
                std::cout << "La computadora ataca con " 
                          << armas.first->getType() 
                          << " y causa " << damage 
                          << " puntos de daño al personaje " 
                          << personaje1->getType() << "." << std::endl;
                std::cout << "Vida restante del personaje " << personaje1->getType() 
                          << ": " << personaje1->getHealthPoints() << std::endl;
            }
        }
    }

    // Determinar y mostrar el ganador
    if (personaje1->isAlive()) {
        std::cout << "\nEl ganador es el personaje " << Personaje::s_personajeTypeToString(personajeType::NIGROMANTE) 
                  << " con vida restante: " << personaje1->getHealthPoints() 
                  << " y armas: " << Arma::s_armaTypeToString(armaType::LIBRO_DE_HECHIZOS) 
                  << " y " << Arma::s_armaTypeToString(armaType::BASTON) << "." << std::endl;
    } else {
        std::cout << "\nEl ganador es el personaje " << Personaje::s_personajeTypeToString(personajeType::GLADIADOR) 
                  << " con vida restante: " << personaje2->getHealthPoints() 
                  << " y armas: " << Arma::s_armaTypeToString(armaType::ESPADA) 
                  << " y " << Arma::s_armaTypeToString(armaType::ESPADA) << "." << std::endl;
    }

    return 0;
}

// Devuelve true si el ataque 1 gana, y false si gana el segundo.
bool compareAttacks(attackType ataque1, attackType ataque2) {
    switch (ataque1){
        case attackType::FUERTE: return (ataque2 == attackType::RAPIDO) ? true : false;
        case attackType::RAPIDO: return (ataque2 == attackType::DEFENSA_ATAQUE) ? true : false;
        case attackType::DEFENSA_ATAQUE: return (ataque2 == attackType::FUERTE) ? true : false;
        default : return false;
    }
}

int getInt() {
    while (true) {
        int input {};
        std::cin >> input;

        // Si std::cin no recibe input invalido, std::cin es true.
        bool success {std::cin};

        // Devuelve std::cin a un estado no fail() y limpia el resto del input para evitar errores
        std::cin.clear();
        ignoreLine();

        // Si todo salio bien, se devuelve el valor, sino se muestra un error y se pide de nuevo.
        if (success) {
            return input;
        }
        else {
            std::cerr << "ERROR: El valor ingresado no es valido." << std::endl;
            std::cout << ": ";
        }
    }
}

int getInt(int max, int min = 0) {
    while (true) {
        int input {};
        std::cin >> input;

        // success determina si se devuelve o no el input, lo determina que este dentro del rango y que std::cin no haya fallado.
        bool success { std::cin && input <= max && input >= min};

        // Devuelve std::cin a un estado no fail() y limpia el resto del input para evitar errores
        std::cin.clear();
        ignoreLine();

        // Si todo salio bien, se devuelve el valor, sino se muestra un error y se pide de nuevo.
        if (success) {
            return input;
        }
        else {
            std::cerr << "ERROR: El valor ingresado no es valido debe ser mayor o igual a " << min << " y menor o igual a " << max << std::endl;
            std::cout << ": ";
        }
    }
}

void ignoreLine() {
    if (std::cin.fail()) {
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}