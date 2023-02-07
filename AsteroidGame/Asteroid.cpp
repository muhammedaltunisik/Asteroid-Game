#include "Asteroid.h"
const int W = 1200;
const int H = 800;

Asteroid::Asteroid(Texture& t, float x, float y, float aci, float hiz, float yaricapi)
{
	can = true;
	astroid.setTexture(t);
	this->x = x;
	this->y = y;
	this->aci = aci;
	this->hiz = hiz;
	R = yaricapi;
	dx = rand() % 8 - 4;
	dy = rand() % 8 - 4;
}
void Asteroid::cizim(RenderWindow& app)
{
	x += dx;
	y += dy;

	if (x > W) x = 0;  if (x < 0) x = W;
	if (y > H) y = 0;  if (y < 0) y = H;
	astroid.setPosition(x, y);
	astroid.setRotation(aci);
	astroid.setOrigin(25, 35);
	app.draw(astroid);
}