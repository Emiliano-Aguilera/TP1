#include "RandomEngine.hpp"

// Devuelve la instancia
RandomEngine& RandomEngine::Instance() {
    static RandomEngine instance;
    return instance;
}

// Devuelve true o false segund la probabilidad dada
bool RandomEngine::RandomBool(double probability) {
    std::bernoulli_distribution dist(probability);
    return dist(m_mtEngine);
}

// Devuelve un int dentro del rango dado
int RandomEngine::RandomInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(m_mtEngine);
}