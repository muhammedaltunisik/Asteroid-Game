#pragma once
#ifndef MERMILER_H
#define MERMILER_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<string>

using namespace sf;

class Mermiler {
public:
	Sprite Mermi;
	bool can;
	String isim = "mermi";
	float x, y, dx, dy, aci, R;
	Mermiler(Texture&, float, float, float, float);
	void kontrol();
	void cizim(RenderWindow&);
};

#endif // !MERMILER_H

