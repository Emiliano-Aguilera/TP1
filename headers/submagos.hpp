#pragma once

#include "mago.hpp"
#include <memory>

class Hechicero : public Mago {
    public:
        Hechicero() : Mago(personajeType::HECHICERO, 85, nullptr, nullptr){}
        ~Hechicero() = default;
};

class Conjurador : public Mago {
    public:
        Conjurador() : Mago(personajeType::CONJURADOR, 75, nullptr, nullptr){}
        ~Conjurador() = default;
};

class Brujo : public Mago {
    public:
        Brujo() : Mago(personajeType::BRUJO, 150, nullptr, nullptr){}
        ~Brujo() = default;
};

class Nigromante : public Mago {
    public:
        Nigromante() : Mago(personajeType::NIGROMANTE, 150, nullptr, nullptr){}
        ~Nigromante() = default;
};