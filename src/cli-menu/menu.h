
#ifndef CLIMENU_H
#define CLIMENU_H

#include <iostream>
#include <string>
#include <vector>

class CLIMenu {
  
  public:
    CLIMenu();
    ~CLIMenu() {};

    void greeting();
    void list_datasets();
    void show_datasets();
    bool select_dataset();
    std::string get_current_dataset_path();
    void regex_instr();
    bool get_regex();
    std::string get_current_regex();
    void show_results(int qty);
    bool another_query();

  private:
    std::string cwd;
    std::string dataset_dir;
    std::vector<std::string> datasets;
    std::string current_dataset;
    std::string current_regex;

};

#endif // CLIMENU_H
