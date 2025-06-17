#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "RNG.h"
#include "StarGameObject.h"
#include "gameObject.h"
#include "gameObjectFactory.h"
#include "view.h"
#include <termios.h>
#include <vector>

class Controller {

  public:
	Controller(View &);
	void run();

  private:
	void handleInput(int);
	void update();
	void endgame(int *);
	int timer;

	// Model
	std::vector<Enemy *> _objs;
	Player player;

	// View
	View &_view;
	RNG rng = RNG();
	GameObjectFactory factory;
};

static struct termios old_termios, new_termios;
void reset_terminal();
void configure_terminal();
int read_input();

#endif
