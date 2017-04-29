
#include <iostream>
#include "./automaton/dfa.h"

int main(int argc, char *argv[]) {
  std::cout << argv[1] << std::endl;
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

  std::cout << dfa->is_word_valid(argv[1]) << std::endl;
  return 0;
}
