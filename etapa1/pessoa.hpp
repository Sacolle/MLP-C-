#pragma once

#include "data.hpp"

#include<string>
#include<iostream>

class Pessoa{
   public:
      enum GENERO { INDEFINIDO, HOMEM_CIS, MULHER_CIS, NAO_BINARIO, TRANSGENERO };

      Pessoa(std::string="INDEFINIDO", Data=Data(), GENERO=INDEFINIDO);  // construtor com valores-default
      Pessoa(const Pessoa&);  // construtor de cópia

      // sobrecarga de atribuição
      virtual Pessoa& operator=(const Pessoa&);

      // getters:
      std::string get_nome() const;
      Data get_dt_nascimento() const ;
      GENERO get_genero() const;

      // setters:
      void set_nome(const std::string);
      void set_dt_nascimento(const Data);
      void set_genero(const GENERO);

   protected:
      std::string nome;
      Data dt_nascimento;
      GENERO genero;
};

// sobrecarga do operator<< para atuar com Pessoa::Genero
std::ostream& operator<<(std::ostream&, const Pessoa::GENERO);
std::ostream& operator<<(std::ostream&, const Pessoa&);