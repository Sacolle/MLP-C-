#pragma once 

#include<iostream>

#include "pessoa.hpp"


// define uma classe filha de Pessoa (tendo acesso publico a ela)
class Aluno: public Pessoa{
  public:
   enum NIVEL {INDEFINIDO, GRADUACAO, ESPECIALIZACAO, MESTRADO, DOUTORADO};
    //vt_nascimento, GENERO genero, NIVEL nivel, std::string 
    Aluno(std::string nome="INDEFINIDO", 
      Data dt_nascimento = Data(), 
      GENERO genero = Pessoa::INDEFINIDO, 
      NIVEL nivel=INDEFINIDO, 
      std::string matricula="INDEFINIDO",
      Data data_matricula = Data()  
    );


   void set_nivel(NIVEL);
   void set_matricula(std::string);
   void set_data_matricula(Data data);

  private:
    NIVEL nivel;
    std::string matricula;
    Data data_matricula;
};

// sobrecarga do operator<<
std::ostream& operator<<(std::ostream&, const Aluno&);