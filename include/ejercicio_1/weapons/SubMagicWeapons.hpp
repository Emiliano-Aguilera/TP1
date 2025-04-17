#pragma once

#include "MagicWeapon.hpp"

class Talisman : public MagicWeapon {
    public:
        Talisman() : MagicWeapon(weaponType::TALISMAN, 10, 30, 15, 0.2, 50, 200, "Fire") {}
        // Le reza al talisman para mejorar sus poderes
        void prayToTalisman();
        ~Talisman() = default;
};

class Potion : public MagicWeapon {
    public:
        Potion() : MagicWeapon(weaponType::POTION, 20, 25, 2, 0.5, 100, 150, "Water") {}
        // Destila la pocima, concentrando sus poderes, se traduce en un aumento de daño fuerte y rapido.
        void distillPotion();
        ~Potion() = default;
};

class Staff : public MagicWeapon {
    public:
        Staff() : MagicWeapon(weaponType::STAFF, 15, 50, 10, 0.1, 45, 100, "Earth") {}
        // Hace crecer un arbol que aumenta el daño de defensa
        void growTree();
        ~Staff() = default;
};

class SpellBook : public MagicWeapon {
    public:
        SpellBook() : MagicWeapon(weaponType::SPELL_BOOK, 30, 40, 5, 0.01, 100, 400, "Wind") {}
        // Cuenta una historia, lo que podria distraer a los enemigos, se traduce en un aumento de daño rapido
        void tellStory();
        ~SpellBook() = default;
};