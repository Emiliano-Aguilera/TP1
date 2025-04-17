#include "CharacterFactory.hpp"
#include "RandomEngine.hpp"

#include <iostream>
#include <iomanip> // Para setprecision
#include <string>
#include <vector>
#include <array>
#include <memory>

using namespace std;

// Array de nombres para poder pasarlos a string. Se mantiene el nombre en español porque los nombres que guarda están en español.
const string nombresAtaques[] = {"Rapido", "Fuerte", "Ataque y Defensa"};

// Si bien characterType y weaponType pueden cambiar, esta me parece la forma mas clara de manejar el input para cada tipo de personaje y arma.
const array mageTypesArray = {
    characterType::SORCERER,
    characterType::CONJURER,
    characterType::WITCHER,
    characterType::NECROMANCER
};

const array warriorTypesArray = {
    characterType::BARBARIAN,
    characterType::PALADIN,
    characterType::KNIGHT,
    characterType::MERCENARY,
    characterType::GLADIATOR
};

const array combatWeaponTypesArray = {
    weaponType::SPEAR,
    weaponType::SIMPLE_AXE,
    weaponType::DOUBLE_AXE,
    weaponType::CLUB,
    weaponType::SWORD
};

const array magicWeaponTypesArray = {
    weaponType::STAFF,
    weaponType::POTION,
    weaponType::SPELL_BOOK,
    weaponType::TALISMAN
};

// Funciones para entrada de datos
int getInt(int max, int min);
void ignoreLine();
bool compareAttacks(attackType ataque1, attackType ataque2);

// Menús interactivos
void displayCharacterMenu();
void displayMageTypes();
void displayWarriorTypes();
void displayWeaponTypes();
void displayCombatWeapons();
void displayMagicWeapons();

int main() {
    // Instancia de randomEngine, singleton, se usa para randomInt i randomBool
    RandomEngine& randomEngine = RandomEngine::Instance();

    unique_ptr<Character> personaje = CharacterFactory::createCharacter(characterType::BARBARIAN);

    // Selección del personaje del jugador
    cout << "Seleccione el tipo de personaje:" << endl;
    displayCharacterMenu();

    int characterTypeChoice = getInt(2, 1);

    characterType playerCharacterType;
    if (characterTypeChoice == 1) {
        displayMageTypes();
        int mageTypeChoice = getInt(int(mageTypesArray.size()), 0);
        playerCharacterType = mageTypesArray[mageTypeChoice]; 
    } 
    else {
        displayWarriorTypes();
        int warriorTypeChoice = getInt(int(warriorTypesArray.size()), 0);
        playerCharacterType = warriorTypesArray[warriorTypeChoice];
    }

    // Selección de armas del jugador
    cout << "Ingrese la cantidad de armas (1 o 2): ";
    int weaponCount = getInt(2, 1);

    array<weaponType, 2> playerWeapons{};
    for (int i = 0; i < weaponCount; ++i) {
        cout << "Seleccione el tipo del arma " << i + 1 << ":" << endl;
        displayWeaponTypes();
        int weaponTypeChoice = getInt(2, 1);

        if (weaponTypeChoice == 1) {
            displayMagicWeapons();
            int magicWeaponChoice = getInt(int(magicWeaponTypesArray.size()) - 1, 0);
            playerWeapons[i] = magicWeaponTypesArray[magicWeaponChoice];
            cout << "Arma magica seleccionada: " << Weapon::s_armaTypeToString(playerWeapons[i]) << endl;
        }
        else {
            displayCombatWeapons();
            int combatWeaponChoice = getInt(int(combatWeaponTypesArray.size()) - 1, 0);
            playerWeapons[i] = combatWeaponTypesArray[combatWeaponChoice];
            cout << "Arma de combate seleccionada: " << Weapon::s_armaTypeToString(playerWeapons[i]) << endl;
        }
    }

    // Crear el personaje del jugador
    unique_ptr<Character> playableCharacter;
    if (weaponCount == 1) {
        playableCharacter = CharacterFactory::createArmedCharacter(playerCharacterType, playerWeapons[0]);
    } 
    else {
        playableCharacter = CharacterFactory::createArmedCharacter(playerCharacterType, playerWeapons[0], playerWeapons[1]);
    }

    // Crear un personaje aleatorio para la computadora
    characterType randomCharacterType = static_cast<characterType>(randomEngine.RandomInt(0, 8)); 
    weaponType randomWeapon1 = static_cast<weaponType>(randomEngine.RandomInt(0, 8));
    weaponType randomWeapon2 = static_cast<weaponType>(randomEngine.RandomInt(0, 8));

    unique_ptr<Character> randomCharacter = CharacterFactory::createArmedCharacter(randomCharacterType, randomWeapon1, randomWeapon2);
    
    cout << endl << endl;

    // Mostrar información inicial
    cout << "El Jugador lucha con personaje tipo: " << Character::s_characterTypeToString(playerCharacterType) << endl; 
    cout << "Armas: " << endl;
    for (const auto& weapon : playerWeapons) {
        cout << "- " << Weapon::s_armaTypeToString(weapon) << endl;
    }
    cout << "Vida inicial: " << playableCharacter->getHealthPoints() << endl;

    cout << endl << endl;

    cout << "Computadora con personaje tipo: " << Character::s_characterTypeToString(randomCharacterType) << endl;
    cout << "Armas: " << endl;
    cout << "- " << Weapon::s_armaTypeToString(randomWeapon1) << endl;
    cout << "- " << Weapon::s_armaTypeToString(randomWeapon2) << endl;
    cout << "Vida inicial: " << randomCharacter->getHealthPoints() << endl;

    cout << endl;
    
    // Bucle Jugable
    while (playableCharacter->isAlive() && randomCharacter->isAlive()) {
        cout << "Elija ataque [1]Rapido, [2]Fuerte, [3]Ataque y Defensa: ";
        attackType playerAttackChoice = attackType(getInt(3, 1));
        cout << "El jugador usa el ataque: " << nombresAtaques[int(playerAttackChoice) - 1] << endl;

        attackType randomAttackChoice = attackType(randomEngine.RandomInt(1, 3));
        cout << "La computadora usa el ataque: " << nombresAtaques[int(randomAttackChoice) - 1] << endl;

        if (playerAttackChoice == randomAttackChoice) {
            cout << "Los ataques son iguales! Nadie recibe daño" << endl;
        } else {
            bool playerAttacks = compareAttacks(playerAttackChoice, randomAttackChoice);

            if (playerAttacks) {
                double damageEffectuated = playableCharacter->attack(playerAttackChoice);
                cout << "El jugador ataca y causa " << damageEffectuated << " puntos de daño a la computadora" << endl;
                randomCharacter->receiveDamage(damageEffectuated);
            } else {
                double damageEffectuated = randomCharacter->attack(randomAttackChoice);
                cout << "La computadora ataca y causa " << damageEffectuated << " puntos de daño al jugador" << endl;
                playableCharacter->receiveDamage(damageEffectuated);
            }
        }

        cout << endl;
        // Mostrar la vida restante de ambos personajes después de cada ataque
        cout << "Vida restante del jugador (" << playableCharacter->getType() << "): " << playableCharacter->getHealthPoints() << endl;
        cout << "Vida restante de la computadora (" << randomCharacter->getType() << "): " << randomCharacter->getHealthPoints() << endl << endl;
    }

    if (playableCharacter->isAlive()) {
        cout << endl << "El ganador es el jugador con vida restante: " << playableCharacter->getHealthPoints() << endl;
    } else {
        cout << endl << "El ganador es la computadora con vida restante: " << randomCharacter->getHealthPoints() << endl;
    }

    return 0;
}

void displayCharacterMenu() {
    cout << "1. Mage" << endl;
    cout << "2. Warrior" << endl;
}

void displayMageTypes() {
    for (int i = 0; i < int(mageTypesArray.size()); i++) {
        cout << i << ". " << Character::s_characterTypeToString(mageTypesArray[i]) << endl;
    }
}

void displayWarriorTypes() {
    for (int i = 0; i < int(warriorTypesArray.size()); i++) {
        cout << i << ". " << Character::s_characterTypeToString(warriorTypesArray[i]) << endl;
    }
}

void displayWeaponTypes() {
    cout << "1. Magic Weapon" << endl;
    cout << "2. Combat Weapon" << endl;
}

void displayMagicWeapons() {
    for (int i = 0; i < int(magicWeaponTypesArray.size()); i++) {
        cout << i << ". " << Weapon::s_armaTypeToString(magicWeaponTypesArray[i]) << endl;
    }
}

void displayCombatWeapons() {
    for (int i = 0; i < int(combatWeaponTypesArray.size()); i++) {
        cout << i << ". " << Weapon::s_armaTypeToString(combatWeaponTypesArray[i]) << endl;
    }
}


// Devuelve true si el ataque 1 gana, y false si gana el segundo.
bool compareAttacks(attackType ataque1, attackType ataque2) {
    switch (ataque1){
        case attackType::STRONG_ATTACK: return (ataque2 == attackType::FAST_ATTACK) ? true : false;
        case attackType::FAST_ATTACK: return (ataque2 == attackType::DEFENSE_ATTACK) ? true : false;
        case attackType::DEFENSE_ATTACK: return (ataque2 == attackType::STRONG_ATTACK) ? true : false;
        default : return false;
    }
}

int getInt(int max, int min = 0) {
    while (true) {
        int input {};
        cout << "> ";
        cin >> input;

        // success determina si se devuelve o no el input, lo determina que este dentro del rango y que cin no haya fallado.
        bool success { cin && input <= max && input >= min};

        // Devuelve cin a un estado no fail() y limpia el resto del input para evitar errores
        cin.clear();
        ignoreLine();

        // Si todo salio bien, se devuelve el valor, sino se muestra un error y se pide de nuevo.
        if (success) {
            cout << endl;
            return input;
        }
        else {
            cerr << "ERROR: El valor ingresado no es valido debe ser mayor o igual a " << min << " y menor o igual a " << max << endl;
            cout << "> ";
        }
    }
}

void ignoreLine() {
    if (cin.fail()) {
        cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
