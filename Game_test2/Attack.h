#pragma once

#include "Collider.h"

class Attack
{
public:

	virtual void Update();

	virtual void Draw();

	virtual int getDamage() = 0;

	virtual Collider getCollider();
	

private:



};

