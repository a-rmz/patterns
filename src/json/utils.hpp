
#include "json.hpp"
#include "../tweet/Tweet.h"

#include <iostream>
#include <fstream>

#define str get<std::string>()

using json = nlohmann::json;

namespace jsonutils {
  tw_arr parse_file(std::string path) {
    std::ifstream file (path);
    tw_arr tweets;
    json j;

    file >> j;
    
    for (auto json_tw : j) {
      tweets.push_back(new Tweet(json_tw));
    }

    return tweets;
  }
}