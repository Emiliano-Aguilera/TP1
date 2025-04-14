#pragma once

#include "arma.hpp"

class ArmaNula : public Arma {
    public:
        double lightAttack() const override;
        double strongAttack() const override;
        double defenseAttack() const override;
        void setType(armaType newType) override;
        std::string getType() const override;
        void setCritProb(double new_prob) override;
        double getCritProb() const override;
};
