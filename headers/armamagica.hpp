#pragma once

#include "arma.hpp"
#include "randomengine.hpp" // Para randomBool

#include <string>
#include <stdexcept>


class ArmaMagica : public Arma {
    protected:
        // Potencia de ataque del ataque ligero.
        double m_lightDamage;
        // Potencia de ataque del ataque fuerte o pesado.
        double m_strongDamage;
        // Defensa y golpe
        double m_defenseDamage;
        // Probabilidad de infligir el doble de danio
        double m_critProbability;
        // Tipo de arma
        armaType m_type;
        
        // Constructor protected para que solo personaje factory pueda instanciar armas
        ArmaMagica(armaType type,
            double lightDamage,
            double strongDamage,
            double defenseDamage,
            double critProb);
    public:
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        double lightAttack() const override;
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        double strongAttack() const override;
        // Devuelve el valor del ataque, dependiendo de si es critico(x2) o no.
        double defenseAttack() const override;

        std::string getType() const override;
        void setType(armaType newType) override;

        // Permite cambiar la probabilidad de critico, toma 0 <= double <= 1.
        void setCritProb(double new_prob) override;
        // Devuelve la probabilidad de critico.
        double getCritProb() const override;

        // Destructor puro para que sea clase abstracta
        virtual ~ArmaMagica() = 0;
};

