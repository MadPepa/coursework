#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(300, 300), "Battle City(By Pepa)");

	float currentFrame = 0;

	Texture t;
	t.loadFromFile("t_sprite.png");

	Sprite s;
	s.setTexture(t);
	s.setTextureRect( IntRect (0,0,15,15));
	s.setPosition(50, 50);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			s.move(0, -0.1);
			currentFrame += 0.005;
			if (currentFrame > 2) currentFrame -= 2;
			s.setTextureRect(IntRect(16 * (int)currentFrame, 0, 15, 15));
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			s.move(-0.1, 0);
			currentFrame += 0.005;
			if (currentFrame > 2) currentFrame -= 2;
			s.setTextureRect(IntRect(16 * (int)currentFrame + 32, 0, 15, 15));
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			s.move(0, 0.1);
			currentFrame += 0.005;
			if (currentFrame > 2) currentFrame -= 2;
			s.setTextureRect(IntRect(16 * (int)currentFrame +64, 0, 15, 15));
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			s.move(0.1, 0);
			currentFrame += 0.005;
			if (currentFrame > 2) currentFrame -= 2;
			s.setTextureRect(IntRect(16 * (int)currentFrame + 96, 0, 15, 15));
		}

		window.clear();
		window.draw(s);
		window.display();
	}
	return 0;
}