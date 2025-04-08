#pragma once

#include <memory>
#include <string>
#include <array>
#include <map>
#include <set>
#include <iostream>

#include "entidadorganizativa.hpp"
#include "gerentealto.hpp"
#include "gerentemedio.hpp"
#include "empresa.hpp"

class CentralRegional : public EntidadOrganizativa {
    private:
        int cantEmpleados;
        int iGerentesAlto;
        int iGerentesMedio;
        
        std::array<std::shared_ptr<GerenteAlto>, 5> gerentesAlto;
        std::array<std::shared_ptr<GerenteMedio>, 20> gerentesMedio;
        std::map<std::string, std::shared_ptr<Empresa>> empresas;
    public:
        std::set<std::string> paises;
    public:
        int getCantEmpleados();
        std::vector<std::string> getEmpNames();
        std::array<std::shared_ptr<GerenteAlto>, 5> getGerentesAlto();
        std::array<std::shared_ptr<GerenteMedio>, 20> getGerentesMedio();
        
        bool agregarEmpresa(std::shared_ptr<Empresa> nueva_empresa);
        void agregarGerenteAlto(std::shared_ptr<GerenteAlto> nuevo_gerente);
        void agregarGerenteMedio(std::shared_ptr<GerenteMedio> nuevo_gerente);

        bool eliminarEmpresa(std::shared_ptr<Empresa> nueva_empresa);
        void eliminarGerenteAlto(std::shared_ptr<GerenteAlto> nuevo_gerente);
        void eliminarGerenteMedio(std::shared_ptr<GerenteMedio> nuevo_gerente);

        ~CentralRegional() = default;
};