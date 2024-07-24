#include<string>
#include<iostream>

#include "aluno.hpp"


int main(void){
  Aluno* a1 = new Aluno("Jose mauricio", Data(), Pessoa::GENERO::HOMEM_CIS, Aluno::NIVEL::GRADUACAO, "00333916");
 // Pessoa* p1 = new Aluno();

  Pessoa p("man amn");
  Pessoa p2 = p;
  Pessoa p3("man nam");
  p3 = p;

  std::cout << *a1 << std::endl;
 // std::cout << *p1 << std::endl;

  return 0;
}