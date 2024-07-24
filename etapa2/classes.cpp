#include "classes.hpp"

Pessoa::Pessoa(std::string nome, time_t dt_nascimento, Genero genero){
  this->set_nome(nome);
  this->set_dt_nascimento(dt_nascimento);
  this->set_genero(genero);
  std::cout << "> [Pessoa] Construtor chamado." << std::endl;
}

Pessoa::Pessoa(const Pessoa& outra){
  this->set_dt_nascimento(outra.dt_nascimento);
  this->set_genero(outra.genero);
  this->set_nome(outra.nome);
  std::cout << "> [Pessoa] Construtor de Cópia chamado." << std::endl;
}

std::string Pessoa::get_nome() const{
  return this->nome;
}

time_t Pessoa::get_dt_nascimento() const{
  // em princípio não tem problema em fazer cópia rasa (pois é um struct com literais)
  return this->dt_nascimento;
}

Pessoa::Genero Pessoa::get_genero() const{
  return this->genero;
}

void Pessoa::set_nome(const std::string nome){
  this->nome = nome;
}

void Pessoa::set_dt_nascimento(const time_t dt_nascimento){
  this->dt_nascimento = dt_nascimento;
}

void Pessoa::set_genero(const Genero genero){
  this->genero = genero;
}

Pessoa& Pessoa::operator=(const Pessoa& outra){
  std::cout << "> [Pessoa] operator= chamado." << std::endl;
  if(this != &outra){
     this->set_dt_nascimento(outra.dt_nascimento);
     this->set_genero(outra.genero);
     this->set_nome(outra.nome);
  }
  return *this;
}

// sobrecarga do operator<< para atuar com Pessoa::Genero
std::ostream& operator<<(std::ostream& os, const Pessoa::Genero g){
  switch(g){
     case Pessoa::INDEFINIDO  : os << "INDEFINIDO"; break;
     case Pessoa::HOMEM_CIS   : os << "HOMEM_CIS"; break;
     case Pessoa::MULHER_CIS  : os << "MULHER_CIS"; break;
     case Pessoa::NAO_BINARIO : os << "NAO_BINARIO"; break;
     case Pessoa::TRANSGENERO : os << "TRANSGENERO"; break;
     default                  : os.setstate(std::ios_base::failbit);
  }
  return os;
}

void Pessoa::print(std::ostream& os) const{
    tm *ltm = localtime(&dt_nascimento);
    os << "Pessoa (Nome: " << nome;   // não precisamos usar os getters pois operator<< é 'friend' de Pessoa!
    os << ", Genero: " << genero;
    os << ", Nascimento: " << ltm->tm_mday << "/" << 1+ltm->tm_mon << "/" << 1900+ltm->tm_year;
    os << ")";
}

// sobrecarga do operator<< para aceitar Pessoas
std::ostream& operator<<(std::ostream& os, const Pessoa& p){
  p.print(os);
  return os;
}

Aluno::Aluno(std::string nome, time_t dt_nascimento, Genero genero, Nivel nivel, std::string matricula){
  this->set_nome(nome);
  this->set_dt_nascimento(dt_nascimento);
  this->set_genero(genero);
  this->set_nivel(nivel);
  this->set_matricula(matricula);
  std::cout << "> [Aluno] Construtor chamado." << std::endl;
}

void Aluno::set_nivel(Nivel nivel){
  this->nivel = nivel;
}

void Aluno::set_matricula(std::string matricula){
  this->matricula = matricula;
}

void Aluno::print(std::ostream& os) const{
    tm *ltm = localtime(&dt_nascimento);

    os << "Aluno (Nome: " << nome;
    os << ", Genero: " << genero;
    os << ", Nascimento: " << ltm->tm_mday << "/" << 1+ltm->tm_mon << "/" << 1900+ltm->tm_year;
    os << ", Matrícula: " << matricula;
    os << ", Nivel: " << nivel;
    os << ")";
}

// sobrecarga do operator<< para aceitar Alunos
std::ostream& operator<<(std::ostream& os, const Aluno& a){
  a.print(os);
  return os;
}

// sobrecarga do operator<< para aceitar Níveis
std::ostream& operator<<(std::ostream& os, Aluno::Nivel n){
  switch(n) {
    case Aluno::INDEFINIDO : os << "INDEFINIDO"; break;
    case Aluno::GRADUACAO : os << "GRADUACAO"; break;
    case Aluno::ESPECIALIZACAO : os << "ESPECIALIZACAO"; break;
    case Aluno::MESTRADO : os << "MESTRADO"; break;
    case Aluno::DOUTORADO : os << "DOUTORADO"; break;
    default : os.setstate(std::ios_base::failbit);
  }
  return os;
}



void Funcionario::set_dt_ingresso(time_t dt){
    if(dt < dt_nascimento || dt > time(0)){
        throw std::runtime_error("data de ingresso inválida");
    }
    this->dt_ingresso = dt;
}


Funcionario::Funcionario(std::string nome, time_t dt_nascimento, Genero genero, time_t dt_ingresso, Cargo cargo){
  this->set_nome(nome);
  this->set_dt_nascimento(dt_nascimento);
  this->set_genero(genero);
  this->set_dt_ingresso(dt_ingresso);
  this->set_cargo(cargo);
  std::cout << "> [Funcionario] Construtor chamado." << std::endl;
}


void Funcionario::print(std::ostream& os) const{
    tm *ltm = localtime(&dt_nascimento);
    tm *ent = localtime(&dt_ingresso);

    os << "Funcionario (Nome: " << nome;
    os << ", Genero: " << genero;
    os << ", Nascimento: " << ltm->tm_mday << "/" << 1+ltm->tm_mon << "/" << 1900+ltm->tm_year;
    os << ", Data de ingresso: " << ent->tm_mday << "/" << 1+ent->tm_mon << "/" << 1900+ent->tm_year;
    os << ", Cargo: " << cargo;
    os << ")";
}

// sobrecarga do operator<< para aceitar Alunos
std::ostream& operator<<(std::ostream& os, const Funcionario& a){
  a.print(os);
  return os;
}

// sobrecarga do operator<< para aceitar Níveis
std::ostream& operator<<(std::ostream& os, Funcionario::Cargo n){
  switch(n) {
    case Funcionario::ESTAGIARIO : os << "ESTAGIARIO"; break;
    case Funcionario::PROGRAMADOR_JUNIOR : os << "PROGRAMADOR_JUNIOR"; break;
    case Funcionario::PROGRAMADOR_PLENO : os << "PROGRAMADOR_PLENO"; break;
    case Funcionario::ANALISTA : os << "ANALISTA"; break;
    case Funcionario::GERENTE : os << "GERENTE"; break;
    default : os.setstate(std::ios_base::failbit);
  }
  return os;
}