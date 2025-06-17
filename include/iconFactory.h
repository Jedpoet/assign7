// TODO
// Finish the declaration of IconFactory that
// 1. offers some methods to create an Icon.
// 2. encapsulates the constructor from the caller.

#ifndef ICONF_H
#define ICONF_H

#include "icon.h"

enum TYPE { PLAYER, ENEMY, DEAD };

class IconFactory : public Icon {
  public:
	IconFactory(){};
	Icon *create_icon(TYPE) const;
};

#endif
