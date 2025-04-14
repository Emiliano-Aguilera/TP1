#pragma once

#include <string>
#include <random>

enum class armaType {
    BASTON,
    ESPADA,
    GARROTE,
    HACHA_DOBLE,
    HACHA_SIMPLE,
    LANZA,
    POCION,
    LIBRO_DE_HECHIZOS,
    AMULETO
};

class Arma {
    public:
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        virtual double lightAttack() const = 0;
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        virtual double strongAttack() const = 0;
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        virtual double defenseAttack() const = 0;
        // Permite ponerle un nombre al arma, por defecto se llamara como su tipo.
        virtual void setType(armaType newType) = 0;
        // Devuelve el tipo de arma
        virtual std::string getType() const = 0;
        // Permite cambiar la probabilidad de critico, toma 0 <= double <= 1.
        virtual void setCritProb(double new_prob) = 0;
        // Devuelve la probabilidad de critico.
        virtual double getCritProb() const = 0;

        // Funcion estatica para pasar de armaType a string.
        static std::string s_armaTypeToString(armaType type) {
            switch (type) {
                case armaType::BASTON: return "Baston";
                case armaType::ESPADA: return "Espada";
                case armaType::GARROTE: return "Garrote";
                case armaType::HACHA_DOBLE: return "Hacha Doble";
                case armaType::HACHA_SIMPLE: return "Hacha Simple";
                case armaType::LANZA: return "Lanza";
                case armaType::POCION: return "Pocion";
                case armaType::LIBRO_DE_HECHIZOS: return "Libro de Hechizos";
                case armaType::AMULETO: return "Amuleto";
                default: return "Unknown";
            }
        }
};  