#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <list>
#include <time.h>
#include <sstream>
#include "Mermiler.h"
#include "Oyuncu.h"
#include "Astroid.h"

const int W = 1200;
const int H = 800;

using namespace std;
using namespace sf;

bool CarpismaTesi(Astroid* a, Mermiler* b)
{
	if (pow((b->x - a->x), 2) + pow((b->y - a->y), 2) < pow((a->R + b->R), 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CarpismaTesit2(Astroid* a, Oyuncu* o)
{
	if (pow((o->x - a->x), 2) + pow((o->y - a->y), 2) < pow((a->R + o->R), 2))
		return true;
	else
		return false;
}

int main()
{
	RenderWindow pencere(VideoMode(W, H), "ASTROID OYUNU", Style::Default);
	pencere.setFramerateLimit(60);
	int oyuncuPuani = 0;

	Font font;
	if (!font.loadFromFile("Literata TTF/literata-bold.ttf"))
		cout << "Yüklenmedi";

	stringstream ssPuan;
	ssPuan << "Puan: " << oyuncuPuani;

	Text puan;
	puan.setCharacterSize(30);
	puan.setPosition({ 1010,10 });
	puan.setFont(font);
	puan.setString(ssPuan.str());
	puan.setFillColor(Color::White);


	Texture t1, t2, t3, t4;

	t1.loadFromFile("spaceship3.png");
	t2.loadFromFile("space1.jpg");
	t3.loadFromFile("astroid.png");
	t4.loadFromFile("mermi.png");



	Sprite background(t2);

	list<Oyuncu*> oyuncular;
	list<Astroid*> astroidler;
	list<Mermiler*> mermiler;

	Oyuncu* o = new Oyuncu(t1, 600, 400, 0, 0, 0, 20);
	oyuncular.push_back(o);

	for (int i = 0; i < 15; ++i)
	{
		Astroid* a = new Astroid(t3, rand() % W, rand() % H, rand() % 360, 20, 25);
		astroidler.push_back(a);
	}

	while (pencere.isOpen())
	{
		Event event;

		while (pencere.pollEvent(event))
		{
			if (event.type == Event::Closed)
				pencere.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Space)
				{
					Mermiler* m = new Mermiler(t4, o->x, o->y, o->aci, 10);
					mermiler.push_back(m);
					m->Mermi.setColor(Color::White);
					m->kontrol();
				}
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) o->aci += 2;
		if (Keyboard::isKeyPressed(Keyboard::A)) o->aci -= 2;
		if (Keyboard::isKeyPressed(Keyboard::W)) { o->itme = true; }
		else { o->itme = false; }
		o->kontrol();

		for (auto a : astroidler)
			for (auto b : mermiler)
			{
				if ((a->isim == "astroid") && (b->isim == "mermi"))
					if (CarpismaTesi(a, b))
					{
						a->can = false;
						b->can = false;
						oyuncuPuani += 50;
						ssPuan.str("");
						ssPuan << "Puan: " << oyuncuPuani;
						puan.setString(ssPuan.str());
					}
			}
		for (auto o : oyuncular)
			for (auto a : astroidler)
			{
				if ((o->isim == "oyuncu") && (a->isim == "astroid"))
					if (CarpismaTesit2(a, o))
					{
						o->can = false;
						a->can = false;
						o->oyuncu.setTexture(t1);
						o->x = 600;
						o->y = 400;
						o->R = 20;
						o->aci = 0;
						oyuncuPuani -= 150;
						ssPuan.str("");
						ssPuan << "Puan: " << oyuncuPuani;
						puan.setString(ssPuan.str());
					}
			}

		for (auto i = astroidler.begin(); i != astroidler.end();)
		{
			Astroid* e = *i;

			if (e->can == false) { i = astroidler.erase(i); delete e; }
			else i++;
		}
		for (auto i = mermiler.begin(); i != mermiler.end();)
		{
			Mermiler* m = *i;
			if (m->can == false) { i = mermiler.erase(i); delete m; }
			else i++;
		}

		if (rand() % 150 == 0)
		{
			Astroid* a = new Astroid(t3, rand() % W, rand() % H, rand() % 360, 20, 25);
			astroidler.push_back(a);
		}


		//sPlayer.setPosition(600, 400);
		//draw//
		pencere.clear();
		pencere.draw(background);
		for (auto i : oyuncular) i->cizim(pencere);
		for (auto i : astroidler) i->cizim(pencere);
		for (auto i : mermiler) i->cizim(pencere);
		pencere.draw(puan);
		pencere.display();
	}
}