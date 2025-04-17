#include "NullWeapon.hpp"

double NullWeapon::fastAttack() { return 0.0; }
double NullWeapon::strongAttack() { return 0.0; }
double NullWeapon::defenseAttack() { return 0.0; }
std::string NullWeapon::getType() const { return "nullweapon"; }
double NullWeapon::getCritProb() const { return 0.0; }

double NullWeapon::getFastDamage() const { return 0.0; }
double NullWeapon::getStrongDamage() const { return 0.0; }
double NullWeapon::getDefenseDamage() const { return 0.0; }
int NullWeapon::getMana() const { return 0; }
int NullWeapon::getDurability() const { return 0; }
std::string NullWeapon::getElement() const { return "nullweapon"; }
