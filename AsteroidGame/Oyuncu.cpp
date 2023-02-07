#include "Oyuncu.h"
const int W = 1200;
const int H = 800;
float DEGTORAD = 0.017453f;
Oyuncu::Oyuncu(Texture& t, float x, float y, float dx, float dy, float aci, float yaricap)
{
	can = true;
	this->oyuncu.setTexture(t); //Oyuncu texture geçirme
	this->x = x; this->y = y; this->dx = dx; // atamalar
	this->dy = dy; this->aci = aci; this->R = yaricap; // atamalar
}
void Oyuncu::kontrol()
{
	if (itme == true)
	{
		dx += cos(aci * DEGTORAD) * 0.1;
		dy += sin(aci * DEGTORAD) * 0.1;
	}
	else
	{
		dx *= 0.99;
		dy *= 0.99;
	}

	hiz = sqrt(pow(dx, 2) + pow(dy, 2));

	if (hiz > maxHizi)
	{
		dx *= maxHizi / hiz;
		dy *= maxHizi / hiz;
	}

	x += dx;
	y += dy;

	if (x > W) x = 0; if (x < 0) x = W;
	if (y > H) y = 0; if (y < 0) y = H;
}
void Oyuncu::cizim(RenderWindow& app)
{
	oyuncu.setPosition(x, y);
	oyuncu.setOrigin(75, 35);
	oyuncu.setRotation(aci);
	app.draw(oyuncu);
}