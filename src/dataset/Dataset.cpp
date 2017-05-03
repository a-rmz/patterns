
#include <iostream>
#include "Dataset.h"
#include "../json/utils.hpp"

/**
 * Constructor
 */
Dataset::Dataset(std::string path) {
  this->path = path;
  this->tweets = load(path);
  this->dfa = new DFA::DFA();
  this->regex = new Regex::Regex("ab+");
}


/**
 * Destructor
 */
Dataset::~Dataset() {}

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
