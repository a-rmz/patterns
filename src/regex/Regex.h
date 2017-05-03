
#ifndef REGEX_H
#define REGEX_H

#include <string>

class Regex {
  
  public:
    Regex(std::string raw);
    virtual ~Regex();

  private:
    std::string raw;

};

#endif // REGEX_H
