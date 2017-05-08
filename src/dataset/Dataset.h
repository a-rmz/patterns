
#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <vector>
#include "../tweet/Tweet.h"
#include "../automaton/dfa/dfa.h"
#include "../automaton/regex/regex.h"

class Dataset {
  
  public:
    Dataset(std::string path);
    Dataset(std::string path, std::string regex);
    virtual ~Dataset();
    void print_tweets();
    void set_regex(std::string regex);
    void find_word(std::string word);
    void find_pattern(std::string regex);

  private:
    std::string path;
    DFA* dfa;
    Regex* regex; 
    tw_arr tweets;

    // Methods
    tw_arr load(std::string path);

};

#endif // DATASET_H
