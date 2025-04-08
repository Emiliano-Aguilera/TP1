#include "manager.hpp"

bool Manager::updateBono(float new_bono) {
    if (new_bono >= 0) {
        bono = new_bono;
        return true;
    }
    else {
        return false;
    }
}

float Manager::getBono() {
    return bono;
}
bool Manager::setLevel(std::string new_level) {
    // TODO verificar que estos sean en efecto los niveles correctos.
    std::string valid_levels[] {"alto", "medio", "bajo", "lider equipo"};

    for (int i = 0; i < 4; i++) {
        if (valid_levels[i] == new_level) {
            level = new_level;
            return true;
        }
    }

    return false;
}