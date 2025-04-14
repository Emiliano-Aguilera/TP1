#pragma once

#include "personaje.hpp"
#include "armanula.hpp"

#include <iostream>
#include <map>
#include <string>

class Mago : public Personaje {
    protected:
        // Atributos de Personaje
        personajeType m_type;
        double m_healthPoints;
        std::shared_ptr<Arma> m_weapon1;
        std::shared_ptr<Arma> m_weapon2;
        bool m_alive = true;
        
        // Constructor protected para que solo pueda instanciarlo PersonajeFactory
        Mago(personajeType, double c_HP, std::shared_ptr<Arma> weapon1 = std::make_shared<ArmaNula>(), std::shared_ptr<Arma> weapon2 = std::make_shared<ArmaNula>());

    public:
        // Métodos
        // Devuelve el daño que va a efectuar el ataque en base al ataque elegido y el critico.
        double attack(attackType ataqueEnviado) override;
        
        // Si muere luego de recibir daño devuelve false, si sobrevive devuelve true.
        bool receiveDamage(double damage) override;

        // Setea isAlive en false, la vida en 0 e imprime que el personaje murio.
        void kill() override;

        // Getters y setters
        std::string getType() const override;

        bool isAlive() const override;
        
        double getHealthPoints() const override;

        std::pair<std::shared_ptr<Arma>, std::shared_ptr<Arma>> getWeapons() const override;
        void setWeapons(std::shared_ptr<Arma> arma1, std::shared_ptr<Arma> arma2) override;

        // Destructor virtual puro para que sea clase abstracta
        virtual ~Mago() = 0;
};