#pragma once
#ifndef ASTROID_H
#define ASTROID_h

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<string>

using namespace sf;

class Astroid {
public:
	float Frame, speed;
	Sprite astroid;
	bool can;
	String isim = "astroid";
	float x = 0, y = 0, dx = 0, dy = 0, aci = 0, R = 0, hiz = 0;
	Astroid(Texture&, float, float, float, float, float);
	void cizim(RenderWindow&);
};

#endif // !ASTROID_H

