#pragma once

#include <ctime>
#include <string>
#include <iostream>

using namespace std;

class Pessoa{
   public:
      enum Genero { INDEFINIDO, HOMEM_CIS, MULHER_CIS, NAO_BINARIO, TRANSGENERO };

      Pessoa(std::string="INDEFINIDO", time_t=time(0), Genero=INDEFINIDO);
      Pessoa(const Pessoa&);

      virtual Pessoa& operator=(const Pessoa&);

      std::string get_nome() const;
      time_t get_dt_nascimento() const ;
      Genero get_genero() const;

      void set_nome(const std::string);
      void set_dt_nascimento(const time_t);
      void set_genero(const Genero);


      virtual void print(std::ostream&) const;

      friend std::ostream& operator<<(std::ostream&, const Pessoa&);            // sobrecarga do operator<< para atuar com Pessoa
      friend std::ostream& operator<<(std::ostream&, const Pessoa::Genero);     // sobrecarga do operator<< para atuar com Pessoa::Genero

   protected:
      std::string nome;
      time_t dt_nascimento;
      Genero genero;
};

class Aluno: public Pessoa{
  public:
   enum Nivel {INDEFINIDO, GRADUACAO, ESPECIALIZACAO, MESTRADO, DOUTORADO};

   Aluno(std::string="INDEFINIDO", time_t=time(0), Genero=Pessoa::INDEFINIDO, Nivel=INDEFINIDO, std::string="INDEFINIDO");

   void set_nivel(Nivel);
   void set_matricula(std::string);

   void print(std::ostream&) const override; 

   friend std::ostream& operator<<(std::ostream&, const Aluno&);
   friend std::ostream& operator<<(std::ostream&, Nivel);

  private:
    Nivel nivel;
    std::string matricula;
};


class Funcionario: public Pessoa {
    public: 
        enum Cargo { ESTAGIARIO, PROGRAMADOR_JUNIOR, PROGRAMADOR_PLENO, ANALISTA, GERENTE };

        Funcionario(std::string="INDEFINIDO", time_t=time(0), Genero=INDEFINIDO, time_t=time(0), Cargo=ESTAGIARIO);

        void print(std::ostream&) const override;

        inline void set_cargo(Cargo g){ cargo = g; }
        void set_dt_ingresso(time_t dt);

        friend std::ostream& operator<<(std::ostream&, const Funcionario&);
        friend std::ostream& operator<<(std::ostream&, Cargo);
    
    private:
        time_t dt_ingresso;
        Cargo cargo;

};