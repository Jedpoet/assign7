#include "StarGameObject.h"
#include "environment.h"
#include <iostream>

Player::Player() {
	_icon = *iconFactory.create_icon(PLAYER);
}

bool Player::intersect(ICollider *other) {
	auto *otherObj = dynamic_cast<GameObject *>(other);
	if ( !otherObj ) {
		return false;
	}

	bool dx = std::abs(_pos.x() == otherObj->getPosition().x());
	bool dy = std::abs(_pos.y() == otherObj->getPosition().y());

	return dx && dy;
}

void Player::onCollision(ICollider *other) {

	life--;
	auto *otherObj = dynamic_cast<Enemy *>(other);
	otherObj->be_touched();
}

void Player::init() {
	_dir = STOP;
	life = 5;
	_pos.x() = 2;
	_pos.y() = 2;
}

int Player::getLife() const {
	return life;
}

void Player::update() {
	int nextX = _pos.x();
	int nextY = _pos.y();

	switch ( _dir ) {
	case UP:
		nextY -= 1;
		break;
	case LEFT:
		nextX -= 1;
		break;
	case RIGHT:
		nextX += 1;
		break;
	case DOWN:
		nextY += 1;
		break;
	default:
		break;
	}

	_dir = STOP;

	if ( nextX >= 0 && nextX < GAME_WINDOW_WIDTH && nextY >= 0 &&
	     nextY < GAME_WINDOW_HEIGHT ) {
		_pos.x() = nextX;
		_pos.y() = nextY;
	}
}

void Player::setDirection(Direction dir) {
	_dir = dir;
}

Enemy::Enemy() {
	_icon = *iconFactory.create_icon(ENEMY);
	is_alive = false;
	_pos.x() = -1;
	_pos.y() = -1;
}

void Enemy::init() {
	_pos.x() = GAME_WINDOW_WIDTH - 1;
	_pos.y() = rng.getInt(0, GAME_WINDOW_HEIGHT - 1);
}

void Enemy::be_touched() {
	is_alive = false;
	_pos.x() = -1;
	_pos.y() = -1;
}

void Enemy::update() {
	if ( is_alive ) {
		_pos.x()--;
		if ( _pos.x() <= 0 ) {
			be_touched();
		}
	}
	else {
		if ( rng.getInt(0, 100) > 70 ) {
			is_alive = true;
			_icon = *iconFactory.create_icon(ENEMY);
			this->init();
		}
	}
}

void Enemy::onCollision(ICollider *other) {
}

bool Enemy::intersect(ICollider *other) {
	return true;
}
