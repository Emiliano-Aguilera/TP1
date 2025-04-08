#include <iostream>
#include <memory>
#include "centralregional.hpp"
#include "empresa.hpp"
#include "departamento.hpp"
#include "gerentealto.hpp"
#include "gerentemedio.hpp"
#include "gerentebajo.hpp"
#include "liderequipo.hpp"

int main() {
    // Crear empleados de distintos tipos
    auto empleado1 = std::make_shared<Empleado>();
    empleado1->nombre = "Juan Perez";
    empleado1->puesto = "Analista";
    empleado1->updateSalario(50000);

    auto gerenteMedio1 = std::make_shared<GerenteMedio>();
    gerenteMedio1->nombre = "Maria Lopez";
    gerenteMedio1->puesto = "Gerente Medio";
    gerenteMedio1->updateSalario(80000);

    auto gerenteAlto1 = std::make_shared<GerenteAlto>();
    gerenteAlto1->nombre = "Carlos Gomez";
    gerenteAlto1->puesto = "Gerente Alto";
    gerenteAlto1->updateSalario(120000);

    auto liderEquipo1 = std::make_shared<LiderEquipo>();
    liderEquipo1->nombre = "Ana Torres";
    liderEquipo1->puesto = "Líder de Equipo";
    liderEquipo1->updateSalario(70000);

    // Crear departamentos
    auto departamento1 = std::make_shared<Departamento>();
    departamento1->nombre = "Recursos Humanos";
    departamento1->ubicacion = "Edificio A";
    departamento1->contratarEmpleado(empleado1);
    departamento1->contratarEmpleado(liderEquipo1);

    auto departamento2 = std::make_shared<Departamento>();
    departamento2->nombre = "Finanzas";
    departamento2->ubicacion = "Edificio B";
    departamento2->contratarEmpleado(gerenteMedio1);

    // Crear empresas
    auto empresa1 = std::make_shared<Empresa>();
    empresa1->nombre = "Empresa Alpha";
    empresa1->direccion = "Calle Principal 123";
    empresa1->agregarDepartamento(departamento1);
    empresa1->agregarDepartamento(departamento2);

    // Crear una central regional
    auto centralRegional1 = std::make_shared<CentralRegional>();
    centralRegional1->nombre = "Central Regional Norte";
    centralRegional1->paises.insert("Argentina");
    centralRegional1->paises.insert("Chile");
    centralRegional1->agregarEmpresa(empresa1);
    centralRegional1->agregarGerenteAlto(gerenteAlto1);
    centralRegional1->agregarGerenteMedio(gerenteMedio1);

    // Mostrar información
    std::cout << "Central Regional: " << centralRegional1->nombre << std::endl;
    std::cout << "Países: ";
    for (const auto& pais : centralRegional1->paises) {
        std::cout << pais << " ";
    }
    std::cout << std::endl;

    std::cout << "Empresas en la central: " << std::endl;
    for (const auto& empName : centralRegional1->getEmpNames()) {
        std::cout << "- " << empName << std::endl;
    }

    std::cout << "Cantidad de empleados en departamentos: " 
              << departamento1->contarEmpleados() + departamento2->contarEmpleados() 
              << std::endl;

    return 0;
}