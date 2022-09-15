#pragma once
#ifndef CALISAN_H
#define CALISAN_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<string>

using namespace sf;

class Oyuncu {
public:
	Sprite oyuncu;
	bool itme, can;
	String isim = "oyuncu";
	float x = 0, y = 0, dx = 0, dy = 0, aci = 0, R = 0, hiz = 0;
	int maxHizi = 7;
	Oyuncu(Texture&, float, float, float, float, float, float);
	void kontrol();
	void cizim(RenderWindow&);
};

#endif
