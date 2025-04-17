#pragma once

#include "Character.hpp"

#include <iostream> 
#include <map> 
#include <string> 
#include <memory> 

class Warrior : public Character {
    protected:
        // Atributos de personaje

        // Tipo de personaje, se usa para poder imprimirlo facilmente
        characterType m_type;
        // Puntos de vida
        double m_healthPoints;
        // Arma 1, es shared pointer para simplificar get y set weapons.
        std::unique_ptr<Weapon> m_weapon1;
        std::unique_ptr<Weapon> m_weapon2;
        // Determina si el personaje esta vivo, no se puede setear y el constructor no lo toma. Solo puede ser modificado por kill
        bool m_alive = true;
        // Atributos especificos de Warrior
        
        // Se usa para disminuir el daño recibido y para aumentar el daño del ataque de defensa.
        int m_shield;
        // Se usa para modificar el daño del ataque fuerte.
        int m_strength;
        // Se usa para modificar el daño del ataque rapido.
        int m_speed;

        // Las armas son nullptr por default, asi se puede identificar cuando no se las provee y establecerla como NullWeapon.
        // Es protected para que solo pueda instanciarlo CharacterFactory.
        Warrior(characterType type,
                double HP,
                int shield,
                int strength,
                int speed,
                std::unique_ptr<Weapon> weapon1 = nullptr,
                std::unique_ptr<Weapon> weapon2 = nullptr);

                
    public:
        // Devuelve el daño efectuado en base al tipo de ataque, shield, strength y speed.
        double attack(attackType attackSent) override;
        // Recibe daño, si el daño resulta en la muerte del personaje, lo mata y muestra un mensaje.
        void receiveDamage(double damageReceived) override;
        // Setea isAlive en false, la vida en 0 e imprime que el personaje murio.
        void kill() override;

        // Setea cada arma, por defecto es nullptr, lo que deriva en NullWeapon
        void setWeapon1(std::unique_ptr<Weapon> weapon = nullptr) override;
        void setWeapon2(std::unique_ptr<Weapon> weapon = nullptr) override;
        void displayWeapon1() const override;
        void displayWeapon2() const override;
        
        std::string getType() const override;
        bool isAlive() const override;
        double getHealthPoints() const override;

        // Destructor virtual puro para que sea una clase abstracta.
        virtual ~Warrior() = 0;
};