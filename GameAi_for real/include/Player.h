#pragma once
#include "GameObject.h"


class Player : public GameObject
{


public:
	Player();
	virtual ~Player();

	virtual void Update(float deltaTime);
	virtual void Draw();
protected:

private:

};
