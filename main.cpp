#include "SFML/Graphics.hpp"
#include"const.h"
using namespace sf;
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "SFML Works!");
	window.setFramerateLimit(60);
	//
	float r = 20.f;
	CircleShape circle(r,100);

	circle.setPosition(400.f - r,300.f - r);
	float speedx = 2.5f;
	float speedy = 3.5f;

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// 1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//2 update (изменение игровых обьектов
		circle.move(speedx, speedy);
		if (circle.getPosition().x + 2 * r >= WINDOW_WIDTH) {
			speedx = -speedx;

		}
		if (circle.getPosition().x <= 0) {
			speedx = -speedx;

		}
		if (circle.getPosition().y + 2*r >= WINDOW_HIGHT) {
			speedy = -speedy;

		}
		if (circle.getPosition().y <= 0) {
			speedy = -speedy;

		}

		// 3  Отрисовка окна
		//3.1 очистка окна
		window.clear(Color(50, 50, 50, 0));
		// 3.2рисуем игровые обьекты (в памяти)
		window.draw(circle);
		// 3.3отображение на экране
		window.display();
	}
	return 0;
} 