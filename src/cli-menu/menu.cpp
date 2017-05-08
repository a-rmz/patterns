
#include "menu.h"
#include <algorithm>
#include <dirent.h>
#include <locale>
#include <sstream>

// #define WINDOWS  /* uncomment this line to use it for windows.*/ 
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
 
std::string GetCurrentWorkingDir() {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

CLIMenu::CLIMenu() {
  this->cwd = GetCurrentWorkingDir();
  this->dataset_dir = this->cwd + "/datasets";
}

void CLIMenu::greeting() {
  std::cout << "**********************************\n";
  std::cout << "*    Twitter dataset patterns    *\n";
  std::cout << "**********************************\n\n";
  std::cout << "The directory for the datasets is: " << this->dataset_dir << "\n\n";
  std::cout << "Please select one of the following datasets: \n";
}

void CLIMenu::list_datasets() {
  DIR *dir;
  struct dirent *ent;
  dir = opendir (this->dataset_dir.c_str());

  if (dir != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL) {
      if(ent->d_name[0] == '.') continue;
      std::string name = ent->d_name;
      // To remove the .json
      name = name.substr(0, name.length() - 5);
      this->datasets.push_back(name);
    }
    closedir (dir);
  } else {
    /* could not open directory */
    perror ("Could not open directory. Please try again.");
  }
}

void CLIMenu::show_datasets() {
   for(int i = 0; i < this->datasets.size(); i++) {
    std::cout << i << ": " << this->datasets.at(i) << "\n";
  }
}

bool CLIMenu::select_dataset() {
  std::string in;
  std::cin >> in;

  int index;
  // This code converts from string to number safely.
  std::stringstream stream(in);
  if (stream >> index && index < this->datasets.size()) {
    this->current_dataset = this->datasets.at(index);
    return true;
  } else {
    auto val = std::find(
      this->datasets.begin(),
      this->datasets.end(),
      in
    );
    if (val != this->datasets.end()) {
      this->current_dataset = *val;
      return true;
    }
  }    

  return false;
}

std::string CLIMenu::get_current_dataset_path() {
  return this->dataset_dir + "/" + this->current_dataset + ".json";
}

void CLIMenu::regex_instr() {
  std::cout << "\n\n\n\n";
  std::cout << "The text pattern must be in the following format:\n";
  std::cout << "\t- Surronund every concatenation or union with parentheses\n";
  std::cout << "\t\t* E.g. (a|b), ((0*).(1|0))\n";
  std::cout << "\n";
  std::cout << "The operators are as follows:\n";
  std::cout << "\t- { . } -> concatenation\n";
  std::cout << "\t- { | } -> union (or, selection)\n";
  std::cout << "\t- { * } -> Kleene's star (closure or operator)\n";
};

bool CLIMenu::get_regex() {
  std::string regex;
  std::cin >> regex;
  this->current_regex = regex;
  return regex.length() > 0;
}

std::string CLIMenu::get_current_regex() {
  return this->current_regex;
}

void CLIMenu::show_results(int qty) {
  std::cout << std::endl << std::endl;
  std::cout << "==================================\n";
  std::cout << "||           Results            ||\n";
  std::cout << "==================================\n\n";
  std::cout << qty << " tweets found matching the pattern " << this->current_regex << "\n\n";
}

bool CLIMenu::another_query() {
  std::string in;
  std::cout << "\nDo you want to try another query? [y|n]: ";
  std::cin >> in;
  return (in == "y" || in == "Y" || in == "yes");
}