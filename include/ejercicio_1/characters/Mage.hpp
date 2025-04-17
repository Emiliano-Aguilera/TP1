#pragma once

#include "Character.hpp"
#include "NullWeapon.hpp"

#include <iostream>
#include <map>
#include <string>

class Mage : public Character {
    protected:
        // Atributos de Personaje

        // Tipo de personaje
        characterType m_type;
        // Puntos de vida
        double m_healthPoints;
        // Arma, NullWeapon por defecto
        std::unique_ptr<Weapon> m_weapon1;
        // Arma, NullWeapon por defecto
        std::unique_ptr<Weapon> m_weapon2;
        // Determina si esta vivo, no puede ser seteado a menos que se use kill()
        bool m_alive = true;

        // Atributos de Mago

        // Se usa para disminuir el daño recibido y aumentar el daño de defensa
        int m_magicResistance;
        // Se usa de forma simple para aumentar el daño de los ataques
        int m_magicPower;
        double m_intelligence;
        
        // Constructor protected para que solo pueda instanciarlo CharacterFactory
        Mage(characterType type,
             double hp,
             int magicResistance,
             int magicPower,
             int intelligence,
             std::unique_ptr<Weapon> weapon1 = nullptr,
             std::unique_ptr<Weapon> weapon2 = nullptr);
             

    public:
        // Devuelve el daño que va a efectuar el ataque en base al ataque elegido, la probabilidad de critico, magicResistance, magicPower, intelligence
        double attack(attackType attackSent) override;
        
        // Permite al personaje recibir daño siempre que este vivo, si el daño recibido lo mata, llama a kill() y muestra el mensaje de muerte.
        void receiveDamage(double damageReceived) override;

        // Setea isAlive en false, la vida en 0 e imprime que el personaje murio.
        void kill() override;
        
        // Setea un arma, por defecto es nullptr, lo que deriva en NullWeapon
        void setWeapon1(std::unique_ptr<Weapon> weapon = nullptr) override;
        // Setea un arma, por defecto es nullptr, lo que deriva en NullWeapon
        void setWeapon2(std::unique_ptr<Weapon> weapon = nullptr) override;
        void displayWeapon1() const override;
        void displayWeapon2() const override;

        std::string getType() const override;
        bool isAlive() const override;
        double getHealthPoints() const override;

        // Destructor virtual puro para que sea clase abstracta
        virtual ~Mage() = 0;
};