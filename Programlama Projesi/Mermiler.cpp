#include "Mermiler.h"
float DEGTORADD = 0.017453f;
Mermiler::Mermiler(Texture& t, float x, float y, float aci, float yaricap)
{
	can = true;
	R = yaricap;
	Mermi.setTexture(t);
	this->x = x; this->y = y; this->aci = aci;
}
void Mermiler::kontrol()
{
	dx = cos(aci * DEGTORADD) * 10;
	dy = sin(aci * DEGTORADD) * 10;
}
void Mermiler::cizim(RenderWindow& app)
{
	x += dx;
	y += dy;
	Mermi.setPosition(x, y);
	Mermi.setOrigin(+10, +15);
	Mermi.setRotation(aci);
	app.draw(Mermi);
}