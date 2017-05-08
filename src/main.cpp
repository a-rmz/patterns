
#include "./dataset/Dataset.h"

void regex_func();

int main(int argc, char const *argv[]) {
  std::string path = argv[1];

  Dataset* d = new Dataset(path);

  for(Tweet* t : d->find_pattern("(K|k)im")) {
    std::cout << *t << std::endl;
  };

  return 0;
}

void regex_func() {
  std::string regex;
  std::cout << "Enter the regex: ";
  std::cin >> regex;
  
  Regex* regex_or = new Regex(regex);
  NFA* nfa_or = regex_or->compile_regex();
  DFA* dfa = nfa_or->to_dfa();

  while (true) {
    std::cout << "\n\nEnter the word to test: ";
    std::cin >> regex;
    std::cout << regex << ": " << dfa->is_word_valid(regex);
  }
}