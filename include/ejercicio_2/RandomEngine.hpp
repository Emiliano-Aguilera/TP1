#pragma once

#include <random>
#include <chrono>
// Ejercicio 2.1
// Clase que sigue el patron singleton para poder generar numeros y booleans aleatorios sin necesidad de instanciarlo.
class RandomEngine {
    private:
        // Motor de MerseneTwister, es lo que genera lo aleatorio.
        std::mt19937 m_mtEngine;

        // Constructor privado, se inicializa en base al motor de random, con una see en base al tiempo. Se usa steady clock para que no dependa del horario que el usuario pone en su computadora.
        RandomEngine():m_mtEngine(std::chrono::steady_clock::now().time_since_epoch().count()) {}

    public:
        // Borrar los copy and assignment constructors para que no se pueda instanciar mas de una vez.
        RandomEngine(const RandomEngine&) = delete;
        RandomEngine& operator=(const RandomEngine&) = delete;
        RandomEngine(RandomEngine&&) = delete;
        RandomEngine& operator=(RandomEngine&&) = delete;

        // Devuelve la instancia
        static RandomEngine& Instance();

        // Devuelve true o false segund la probabilidad dada
        bool RandomBool(double probability = 0.5);

        // Devuelve un int dentro del rango dado
        int RandomInt(int min, int max);
};
