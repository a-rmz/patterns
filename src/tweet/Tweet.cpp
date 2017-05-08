
#include "Tweet.h"

/**
 * Constructor
 */
Tweet::Tweet(std::string user, std::string text, strvec hashtags, strvec user_mentions) {
  set_user(user);
  set_text(text);
  set_hashtags(hashtags);
  set_user_mentions(user_mentions);
}

Tweet::Tweet(json json_tw) {
  strvec hts;
  strvec user_mentions;

  for (auto ht : json_tw["entities"]["hashtags"]) {
    hts.push_back(ht["text"].str);
  }
  for (auto um: json_tw["entities"]["user_mentions"]) {
    hts.push_back(um["screen_name"].str);
  }

  set_id(json_tw["id_str"].str);
  set_user(json_tw["user"]["screen_name"].str);
  set_text(json_tw["text"].str);
  set_hashtags(hts);
  set_user_mentions(user_mentions);
}

/**
 * Destructor
 */
Tweet::~Tweet() {}

/**
 * Setters
 */
void Tweet::set_id(std::string id) {
  this->id = id;
}

void Tweet::set_user(std::string user) {
  this->user = user;
}

void Tweet::set_text(std::string text) {
  this->text = text;
}

void Tweet::set_hashtags(strvec hashtags) {
  this->hashtags = hashtags;
}

void Tweet::set_user_mentions(strvec user_mentions) {
  this->user_mentions = user_mentions;
}


/**
 * Getters
 */
std::string Tweet::get_id() {
  return this->id;
}

std::string Tweet::get_user() {
  return this->user;
}

std::string Tweet::get_text() {
  return this->text;
}

strvec Tweet::get_hashtags() {
  return this->hashtags;
}

strvec Tweet::get_user_mentions() {
  return this->user_mentions;
}
/**
 * Override to string method
 */
std::ostream& operator<<(std::ostream &strm, const Tweet &t) {
  return strm << "User: " << t.user << "\n" << "Text: " << t.text << "\n";
}
