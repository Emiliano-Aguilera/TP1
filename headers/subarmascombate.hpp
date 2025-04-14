#pragma once

#include "armacombate.hpp"

class Lanza : public ArmaCombate {
    public:
        Lanza() : ArmaCombate(armaType::LANZA, 10, 15, 14, 0.2) {}
        ~Lanza() = default;
};

class HachaSimple : public ArmaCombate {
    public:
        HachaSimple() : ArmaCombate(armaType::HACHA_SIMPLE, 5, 12, 9, 0.4) {}
        ~HachaSimple() = default;
};

class HachaDoble : public ArmaCombate {
    public:
        HachaDoble() : ArmaCombate(armaType::HACHA_DOBLE, 5, 12, 9, 0.8) {}
        ~HachaDoble() = default;
};

class Garrote : public ArmaCombate {
    public:
        Garrote() : ArmaCombate(armaType::GARROTE, 4, 20, 12, 0.3) {}
        ~Garrote() = default;
};

class Espada : public ArmaCombate {
    public:
        Espada() : ArmaCombate(armaType::ESPADA, 9, 16, 11, 0.2) {}
        ~Espada() = default;
};