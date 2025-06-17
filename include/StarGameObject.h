#ifndef STAR_H
#define STAR_H

#include "RNG.h"
#include "collider.h"
#include "gameObject.h"
#include "iconFactory.h"

enum Direction { UP = 0, DOWN, LEFT, RIGHT, STOP };

class Player : public GameObject, public ICollider {

  public:
	Player();
	void update() override;
	void onCollision(ICollider *other) override;
	bool intersect(ICollider *other) override;
	void init();
	int getLife() const;

	// RPSType getType() const;
	// void setType(RPSType type);
	void setDirection(Direction);
	// bool isPlayer() const;
	// void playerSwitch();

  private:
	// RPSType _type;
	Direction _dir;
	RNG rng = RNG();
	int life;
	IconFactory iconFactory;
};

class Enemy : public GameObject, public ICollider {
  private:
	RNG rng = RNG();
	bool is_alive;
	IconFactory iconFactory;

  public:
	Enemy();
	void init();
	void update() override;
	void onCollision(ICollider *other) override;
	bool intersect(ICollider *other) override;
	void be_touched();
};
#endif
