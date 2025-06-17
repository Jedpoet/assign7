#include "iconFactory.h"
#include "icon.h"
#include <vector>

Icon *IconFactory::create_icon(TYPE type) const {
	Icon *icon = new Icon;

	if ( type == PLAYER ) {
		std::vector<Cell> temp(1, Cell(BLUE, " "));
		icon->push_back(temp);
		// icon->push_back(temp);
	}
	else if ( type == ENEMY ) {
		std::vector<Cell> temp(1, Cell(RED, " "));
		icon->push_back(temp);
		// icon->push_back(temp);
	}
	else {
	}

	return icon;
}
