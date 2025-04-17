#pragma once

#include "Mage.hpp"
#include <memory>

class Sorcerer : public Mage {
    public:
        Sorcerer() : Mage(characterType::SORCERER, 200, 8, 8, 9){}
        // El Hechicero lanza un hechizo
        void castSpell();
        ~Sorcerer() = default;
};

class Conjurer : public Mage {
    public:
        Conjurer() : Mage(characterType::CONJURER, 215, 7, 6, 8){}
        // El conjurador invoca a un amigo
        void invokeFriend(std::string friendName);
        ~Conjurer() = default;
};

class Witcher : public Mage {
    public:
        Witcher() : Mage(characterType::WITCHER, 210, 10, 5, 8){}
        // Permite al brujo ver pistas, le da vision sobrehumana
        void witcherVision();
        ~Witcher() = default;
};

class Necromancer : public Mage {
    public:
        Necromancer() : Mage(characterType::NECROMANCER, 250, 7, 7, 10){}
        // Revive a un muerto
        void awakeDeath(std::string deathName);
        ~Necromancer() = default;
};