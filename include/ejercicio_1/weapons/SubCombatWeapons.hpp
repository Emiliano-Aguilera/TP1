#pragma once

#include "CombatWeapon.hpp"

class Spear : public CombatWeapon {
    public:
        Spear() : CombatWeapon(weaponType::SPEAR, 20, 30, 20, 0.2, 300, 3, 6) {}
        // Efectua un ataque en circulo, muy util en defensa, mejora el daño de defensa.
        void circleAttack();
        ~Spear() = default;
};

class SimpleAxe : public CombatWeapon {
    public:
        SimpleAxe() : CombatWeapon(weaponType::SIMPLE_AXE, 10, 25, 7, 0.4, 150, 2, 4) {}
        // Tira el hacha, y vuelve, mejora su daño rapido
        void throwAxe();
        ~SimpleAxe() = default;
};

class DoubleAxe : public CombatWeapon {
    public:
        DoubleAxe() : CombatWeapon(weaponType::DOUBLE_AXE, 20, 50, 14, 0.25, 300, 4, 8) {}
        // Golpea las hachas entre si, a modo de intimidacion. Aumenta el daño rapido
        void clapAxes();
        ~DoubleAxe() = default;
};

class Club : public CombatWeapon {
    public:
        Club() : CombatWeapon(weaponType::CLUB, 13, 19, 20, 0.3, 500, 2, 10) {}
        // Juggle es como jugar con el garrote. Aumenta el daño de defensa
        void juggleClub();
        ~Club() = default;
};

class Sword : public CombatWeapon {
    public:
        Sword() : CombatWeapon(weaponType::SWORD, 20, 25, 10, 0.4, 225, 3, 1) {}
        // Levanta la espada para hacer un saludo o rezar. Aumenta el daño fuerte
        void riseSword();
        ~Sword() = default;
};