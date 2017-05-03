
#ifndef STATE_H
#define STATE_H

class State {
  
  public:
    State() {};
    virtual ~State();

    // Properties
    char c;
    State *transition;
    State *transition1;
    //char last_list;
};

#endif // STATE_H
