
#include "./dataset/Dataset.h"
#include "./cli-menu/menu.h"

int main(int argc, char const *argv[]) {
  // std::string path = argv[1];

  CLIMenu m = CLIMenu();
  m.greeting();
  m.list_datasets();
  do {
    m.show_datasets();
    while(!m.select_dataset()) {
      std::cout << "Please enter a valid option (name or number)\n";
    }

    Dataset* d = new Dataset(m.get_current_dataset_path());

    m.regex_instr();
    while(!m.get_regex()) {
      std::cout << "Please enter a valid pattern.\n";
    }

    std::set<Tweet*> result = d->find_pattern(m.get_current_regex());
    std::cout << std::endl << std::endl;
    for(Tweet* t : result) {
      std::cout << *t << std::endl;
    };

    m.show_results(result.size());
  } while(m.another_query());

  return 0;
}