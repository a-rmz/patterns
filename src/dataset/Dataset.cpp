
#include <iostream>
#include <set>
#include "Dataset.h"
#include "../json/utils.hpp"

/**
 * Constructor
 */
Dataset::Dataset(std::string path) {
  this->path = path;
  this->tweets = load(path);
}

 Dataset::Dataset(std::string path, std::string regex) {
  this->path = path;
  this->tweets = load(path);
  this->set_regex(regex);
}

/**
 * Destructor
 */
Dataset::~Dataset() {}

void Dataset::set_regex(std::string regex) {
  this->regex = new Regex(regex);
  this->dfa = this->regex->compile_regex()->to_dfa();
}

/**
 * Load the dataset from a file
 * {path} -> name of the file to load
 */
tw_arr Dataset::load(std::string path) {
  return jsonutils::parse_file(path);
}

/**
 * Print the tweet set
 */
void Dataset::print_tweets() {
  for (Tweet::Tweet* t : this->tweets) {
    std::cout << *t << std::endl;
  }
}

void Dataset::find_pattern(std::string regex) {
  this->set_regex(regex);
  std::set<Tweet*> found;

  std::cout << "Searching for the pattern { " << regex << " }…" << std::endl;
  
  for (Tweet* tweet : this->tweets) {

    std::istringstream iss (tweet->get_text());
    std::vector<std::string> tokens {
      std::istream_iterator<std::string>{iss},
      std::istream_iterator<std::string>{}
    };

    for(std::string t : tokens) {
      if (this->dfa->is_word_valid(t)) {
        found.insert(tweet);
      }
    }
  }
  
  std::cout << "I found " << found.size() << " matches:\n";
  for(Tweet* t : found) {
    std::cout << *t << std::endl;
  }
}