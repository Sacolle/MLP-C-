#include<iostream>
#include<regex>

#include "aluno.hpp"


Aluno::Aluno(std::string nome, Data dt_nascimento, GENERO genero, NIVEL nivel, std::string matricula, Data data_matricula)
  : Pessoa(nome, dt_nascimento, genero)
{
  this->set_nivel(nivel);
  this->set_matricula(matricula);
  this->set_data_matricula(data_matricula);
  std::cout << "> [Aluno] Construtor chamado." << std::endl;
}

void Aluno::set_nivel(NIVEL nivel){
  this->nivel = nivel;
}

void Aluno::set_matricula(std::string matricula){
    const auto regex = std::regex("(\\d{8})");

    if(!std::regex_match(matricula, regex)){
      throw std::runtime_error("Matricula incorreta.");
    }

    this->matricula = matricula;
}

void Aluno::set_data_matricula(Data data){
  auto const t = data.get_full_date();
  if(t > time(0) || t < dt_nascimento.get_full_date()){
    throw std::runtime_error("data de matrícula inválida.");
  }
  this->data_matricula = data;
}

// sobrecarga do operator<< para aceitar Pessoas
std::ostream& operator<<(std::ostream& os, const Aluno& a){
  os << "Aluno (";
  os << (Pessoa&)a;
  os << ")";
  return os;
}