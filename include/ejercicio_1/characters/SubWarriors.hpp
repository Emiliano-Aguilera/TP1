#pragma once

#include "Warrior.hpp"

class Barbarian : public Warrior {
    public:
        Barbarian() : Warrior(characterType::BARBARIAN, 400, 1, 9, 7) {}
        // Grito barbaro
        void barbarianScream();
        ~Barbarian() = default;
};

class Knight : public Warrior {
    public:
        Knight() : Warrior(characterType::KNIGHT, 300, 8, 7, 4) {}
        // El caballero se arrodilla
        void kneel(std::string who);
        ~Knight() = default;
};

class Gladiator : public Warrior {
    public:
        Gladiator() : Warrior(characterType::GLADIATOR, 315, 4, 10, 7) {}
        // El gladiador agarra arena del suelo. (pelicula gladiador)
        void grabSandFromFloor();
        ~Gladiator() = default;
};

class Mercenary : public Warrior {
    public:
        Mercenary() : Warrior(characterType::MERCENARY, 250, 6, 5, 7) {}
        // El mercenario recibe una paga
        void getPaid(double salary);
        ~Mercenary() = default;
};

class Paladin : public Warrior {
    public:
        Paladin() : Warrior(characterType::PALADIN, 300, 8, 4, 8) {}
        // El paladin da un discurso.
        void giveSpeech(std::string speech);
        ~Paladin() = default;
};