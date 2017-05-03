
#ifndef FRAG_H
#define FRAG_H

#include "State.h"

class Frag {
  
  public:
    Frag() {};
    virtual ~Frag();

    // Properties
    State *start;
    Ptrlist *transitions;
};

#endif // FRAG_H
