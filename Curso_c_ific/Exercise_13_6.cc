#include <iostream>   // cout, cin, endl
#include <algorithm>  // generate
#include <string>     // string
#include <vector>     // vector
#include <functional> // function

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::function;


class MenuItem {
public:
  MenuItem(string l, function<void()> a) : label(l), action(a) {}
  string get_label() const { return label; }
  void doit() const { action(); }
  void display() const { cout << label << endl; }
private:
  string label;
  function<void()> action;
};

class Menu {
public:

  void display() {
    int count = 0;
    for (auto item:items) {
      cout << ++count << ". ";
      item.display();
    }
  }

  void add_item(string l, function<void()> a) { items.push_back(MenuItem(l, a)); }

  void select(unsigned int choice) {
    if (1 <= choice && choice <= items.size())
      items[choice-1].doit();
    else
      cout << "Invalid choice " << choice << endl;
  }

private:
  std::vector<MenuItem> items;
};

class Lift {
public:
  Lift(unsigned int id_) : id(id_), level(0) {}
  void up()           { ++level; }
  void down()         { --level; }
  void report() const { cout << "Lift " << id << " is on level " << level << endl; }
private:
  unsigned int id;
  int level;
};

// Don't change the code above this line
////////////////////////////////////////////////////////////////////////////////
// Simplify the code below, by replacing functors with lambda expressions

int main() {
  std::vector<Lift> lifts{Lift(1), Lift(2)};

  Menu menu;
  menu.add_item("Lift 1 up",   [&] { lifts[0].up();   });
  menu.add_item("Lift 1 down", [&] { lifts[0].down(); });
  menu.add_item("Lift 2 up",   [&] { lifts[1].up();   });
  menu.add_item("Lift 2 down", [&] { lifts[1].down(); });
  menu.add_item("Report", [&] { for (auto lift:lifts) lift.report(); });

  bool quit = false;
  menu.add_item("QUIT", [&] { quit = true; });

  while (!quit) {
    menu.display();
    int choice;
    cin >> choice;
    menu.select(choice);
  }

}