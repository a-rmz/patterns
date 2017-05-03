
#ifndef TWEET_H
#define TWEET_H

#include <string>
#include <iostream>
#include <vector>

#include "json.hpp"
using json = nlohmann::json;

#define str get<std::string>()

typedef std::vector<std::string> strvec;

class Tweet {
  
  public:
    Tweet(std::string user, std::string text, strvec hashtags, strvec user_mentions);
    Tweet(json json_tw);
    virtual ~Tweet();

    // Getters & setters
    void set_user(std::string user);
    void set_text(std::string text);
    void set_hashtags(strvec hashtags);
    void set_user_mentions(strvec user_mentions);
    std::string get_user();
    std::string get_text();
    strvec get_hashtags();
    strvec get_user_mentions();

    // Override to_string
    friend std::ostream& operator<<(std::ostream &strm, const Tweet &t);

  private:
    std::string user;
    std::string text;
    strvec hashtags;
    strvec user_mentions;
};

// Type definition for vector (array) of tweets
typedef std::vector<Tweet::Tweet*> tw_arr;

#endif // TWEET_H
