#pragma once

#include "guerrero.hpp"

class Barbaro : public Guerrero {
    public:
        Barbaro() : Guerrero(personajeType::BARBARO, 150) {}
        ~Barbaro() = default;
};

class Caballero : public Guerrero {
    public:
        Caballero() : Guerrero(personajeType::CABALLERO, 200) {}
        ~Caballero() = default;
};

class Gladiador : public Guerrero {
    public:
        Gladiador() : Guerrero(personajeType::GLADIADOR, 300) {}
        ~Gladiador() = default;
};

class Mercenario : public Guerrero {
    public:
        Mercenario() : Guerrero(personajeType::MERCERNARIO, 100) {}
        ~Mercenario() = default;
};

class Paladin : public Guerrero {
    public:
        Paladin() : Guerrero(personajeType::PALADIN, 250) {}
        ~Paladin() = default;
};