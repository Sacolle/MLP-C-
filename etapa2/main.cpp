#include "classes.hpp"

#include <vector>


time_t make_data(int year, int month, int day, int hour, int min);

int main(void){
   Pessoa *p1 = new Aluno("Carlos Silva", time(0), Pessoa::Genero::HOMEM_CIS, Aluno::Nivel::GRADUACAO);
   Pessoa *p2 = new Pessoa("Roberto Carlos", time(0), Pessoa::Genero::HOMEM_CIS);

   Pessoa *p3 = new Aluno("Carlos Silveira", time(0), Pessoa::Genero::HOMEM_CIS, Aluno::Nivel::GRADUACAO);
   Pessoa *p4 = new Funcionario("Carlos Santana", make_data(1978, 9, 11, 0, 0), Pessoa::Genero::HOMEM_CIS, make_data(2001, 9, 11, 4, 20), Funcionario::Cargo::ANALISTA);
   Pessoa *p5 = new Pessoa("Joana Carlos", time(0), Pessoa::Genero::HOMEM_CIS);
   Pessoa *p6 = new Aluno("João Carlos", time(0), Pessoa::Genero::HOMEM_CIS, Aluno::Nivel::MESTRADO);

   std::vector<Pessoa*> v{p1, p2, p3, p4, p5, p6};


   for(auto pessoa: v){
      std::cout << *pessoa << std::endl;
   }

   return 0;
}


time_t make_data(int year, int month, int day, int hour, int min){
   struct tm tm;
   tm.tm_year = year - 1900;
   tm.tm_mon = month - 1;
   tm.tm_mday = day;
   tm.tm_hour = hour;
   tm.tm_min = min;
   tm.tm_isdst = -1;
   return mktime(&tm);
}