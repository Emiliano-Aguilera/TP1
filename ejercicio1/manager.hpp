#pragma once

#include <string>
#include <vector>
#include <memory>

#include "empleado.hpp"

class Manager : public Empleado {
    protected:
        float bono;
        std::string level;
    public: 
        bool updateBono(float new_bono);
        float getBono();
        bool setLevel(std::string new_level);
        
        ~Manager() = default;
};