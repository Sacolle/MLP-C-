#include "classes.hpp"

#include <vector>
#include <gtkmm.h>



time_t make_data(int year, int month, int day, int hour, int min);

class Janela : public Gtk::Window {
   public:
      Janela(): m_button("Criar"){
         set_title("Basic application");
         set_default_size(200, 200);

         m_button.signal_clicked().connect(sigc::mem_fun(*this, &Janela::on_button_clicked));

         set_child(m_button);
//         m_button.show();
      }
   protected:
      //Signal handlers:
      void on_button_clicked(){
         std::cout << "Criado" << std::endl;
      }

      //Member widgets:
      Gtk::Button m_button;
};


int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  return app->make_window_and_run<Janela>(argc, argv);
}

/*
   std::cout << make_data(1978, 9, 11, 0, 0) << std::endl;

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

/usr/include/gtkmm-4.0 
/usr/lib64/gtkmm-4.0/include 
/usr/include/giomm-2.68 
/usr/lib64/giomm-2.68/include 
/usr/include/glib-2.0 
/usr/lib64/glib-2.0/include 
/usr/include/sysprof-4 
/usr/include/libmount 
/usr/include/blkid 
/usr/include/glibmm-2.68 
/usr/lib64/glibmm-2.68/include 
/usr/include/sigc++-3.0 
/usr/lib64/sigc++-3.0/include 
/usr/include/gtk-4.0 
/usr/include/pango-1.0 
/usr/include/harfbuzz 
/usr/include/freetype2 
/usr/include/libpng16 
/usr/include/fribidi 
/usr/include/libxml2 
/usr/include/cairo 
/usr/include/pixman-1 
/usr/include/gdk-pixbuf-2.0 
/usr/include/graphene-1.0 
/usr/lib64/graphene-1.0/include 
/usr/include/gio-unix-2.0 
/usr/include/cairomm-1.16 
/usr/lib64/cairomm-1.16/include 
/usr/include/pangomm-2.48 
/usr/lib64/pangomm-2.48/include 
/usr/include/gtk-4.0/unix-print

*/


time_t make_data(int year, int month, int day, int hour, int min){
   static struct tm tm;
   tm.tm_year = year - 1900;
   tm.tm_mon = month - 1;
   tm.tm_mday = day;
   tm.tm_hour = hour;
   tm.tm_min = min;
   tm.tm_isdst = -1;
   return mktime(&tm);
}