#pragma once

#include "armamagica.hpp"

class Amuleto : public ArmaMagica {
    public:
        Amuleto() : ArmaMagica(armaType::AMULETO, 8, 12, 15, 0.4) {}
        ~Amuleto() = default;
};

class Pocion : public ArmaMagica {
    public:
        Pocion() : ArmaMagica(armaType::POCION, 4, 30, 3, 0.6) {}
        ~Pocion() = default;
};

class Baston : public ArmaMagica {
    public:
        Baston() : ArmaMagica(armaType::BASTON, 10, 15, 7, 0.1) {}
        ~Baston() = default;
};

class LibroDeHechizos : public ArmaMagica {
    public:
        LibroDeHechizos() : ArmaMagica(armaType::LIBRO_DE_HECHIZOS, 15, 25, 5, 0.3) {}
        ~LibroDeHechizos() = default;
};