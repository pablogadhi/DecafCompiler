#include "ui_controller.h"
#include <gtkmm.h>
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "me.gadhi.decaf");
  auto ui_contr = UIController();

  app->run(*ui_contr.main());

  return 0;
}
