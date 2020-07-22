#ifndef UI_BUILDER_H
#define UI_BUILDER_H

#include <gtkmm.h>

class UIBuilder {
private:
  Glib::RefPtr<Gtk::Builder> builder;

public:
  UIBuilder(string &filename);
};

#endif