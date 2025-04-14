#pragma once

#include <string>
#include <memory>
#include <map>

#include "arma.hpp"
#include "armanula.hpp"

enum class attackType{
    RAPIDO = 1,
    FUERTE,
    DEFENSA_ATAQUE
};

enum class personajeType {
    HECHICERO,
    CONJURADOR,
    BRUJO,
    NIGROMANTE,
    BARBARO,
    PALADIN,
    CABALLERO,
    MERCERNARIO, 
    GLADIADOR
};

class Personaje {
    public:
        // Metodos
        virtual double attack(attackType ataqueEnviado) = 0;
        // Devuelve true si el personaje sigue vivo luego del ataque
        virtual bool receiveDamage(double damage) = 0;
        // Mata al personaje
        virtual void kill() = 0;

        // Getters y setters
        
        virtual std::string getType() const = 0;

        virtual bool isAlive() const = 0;

        virtual double getHealthPoints() const = 0;

        virtual std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> getWeapons() const = 0;
        virtual void setWeapons(std::shared_ptr<Arma> arma1 = std::make_shared<ArmaNula>(), std::shared_ptr<Arma> arma2 = std::make_shared<ArmaNula>()) = 0;

        static std::string s_personajeTypeToString(personajeType type) {
            switch (type) {
                case personajeType::HECHICERO: return "Hechicero";
                case personajeType::CONJURADOR: return "Conjurador";
                case personajeType::BRUJO: return "Brujo";
                case personajeType::NIGROMANTE: return "Nigromante";
                case personajeType::BARBARO: return "Barbaro";
                case personajeType::PALADIN: return "Paladin";
                case personajeType::CABALLERO: return "Caballero";
                case personajeType::MERCERNARIO: return "Mercenario";
                case personajeType::GLADIADOR: return "Gladiador";
                default: return "Unknown";
            }
        }
        
        // Destructor
        virtual ~Personaje() = default;
};