
#include <iostream>
#include "automaton/dfa.h"
#include "dataset/Dataset.h"

void automaton();

int main(int argc, char *argv[]) {
  std::string path =  "/Users/a-rmz/Documents/LP/patterns/datasets/korea.json";

  Dataset::Dataset* d = new Dataset::Dataset(path);
  d->print_tweets();

  automaton();

  return 0;
}

void automaton() {
  DFA::DFA *dfa = new DFA::DFA();

  std::vector<std::string> states;
  states  = {"q0", "q1", "q2"};

  std::vector<std::string> final_states;
  final_states  = {"q2"};

  std::vector<std::string> alphabet;
  alphabet = {"0", "1"};

  dfa->set_states(states);
  dfa->set_final_states(final_states);
  dfa->set_alphabet(alphabet);

  dfa->add_transition("q0", "0", "q0");
  dfa->add_transition("q0", "1", "q1");

  dfa->add_transition("q1", "0", "q2");
  dfa->add_transition("q1", "1", "q1");
  
  dfa->add_transition("q2", "0", "q2");
  dfa->add_transition("q2", "1", "q1");

  std::cout << dfa->is_word_valid("0110") << std::endl;
}
