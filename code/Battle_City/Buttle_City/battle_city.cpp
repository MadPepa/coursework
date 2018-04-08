#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

const int H = 20;
const int W = 20;

class Player {
public:
	float x, y, w, h, dx = 0, dy = 0, speed; // параметры игрока (координаты, ширина, высота, ускорение, скорость)
	int dir = 0; // направление движени€
	String File; // файл с расширением
	Image image; // изображение
	Texture texture; // текстура
	Sprite sprite; // спрайт
	Player(String F, int X, int Y, float W, float H) {
		File = F;
		w = W; h = H;
		image.loadFromFile(File);
		image.createMaskFromColor(Color(0,0,0)); // пр€чет чЄрный фон от танка, по идее...
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect (x, y, w, h));
	}
	void update(float time) {
		switch (dir)
		{
		case 0: dx = speed; dy = 0; break; // движение вправо
		case 1: dx = -speed; dy = 0; break; // движение влево
		case 2: dx = 0; dy = -speed; break; // движение вверх
		case 3: dx = 0; dy = speed; break;// движение вниз
		}
		x += dx * time;  // новые
		y += dy * time;  // координаты
		speed = 0;
		sprite.setPosition(x, y);
	}
};

int main()
{
	RenderWindow window(VideoMode(640, 640), "Battle City by Pepa");

	Texture map;
	map.loadFromFile("sprites_texture.png");

	Sprite map_s;
	map_s.setTexture(map);

	Player pl_1("sprites_player1.png", 0,0,32,32);
	pl_1.sprite.setPosition(464,464);

	float currentFrame = 0;
	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();

		Event event;
		while (window.pollEvent(event)){
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
		
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			pl_1.dir = 2; pl_1.speed = 0.1;
			currentFrame += 0.005*time;
			if (currentFrame > 2) currentFrame = 0;
			pl_1.sprite.setTextureRect(IntRect(32 * (int)currentFrame, 0, 32, 32));
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			pl_1.dir = 1; pl_1.speed = 0.1;
			currentFrame += 0.005*time;
			if (currentFrame > 2) currentFrame = 0;
			pl_1.sprite.setTextureRect(IntRect(32 * (int)currentFrame + 64, 0, 32, 32));
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			pl_1.dir = 3; pl_1.speed = 0.1;
			currentFrame += 0.005*time;
			if (currentFrame > 2) currentFrame = 0;
			pl_1.sprite.setTextureRect(IntRect(32 * (int)currentFrame + 128, 0, 32, 32));
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			pl_1.dir = 0; pl_1.speed = 0.1;
			currentFrame += 0.005*time;
			if (currentFrame > 2) currentFrame = 0;
			pl_1.sprite.setTextureRect(IntRect(32 * (int)currentFrame + 192, 0, 32, 32));
		}
		pl_1.update(time);
		
		String TyleMap1[H] = {
			"BBBBBBBBBBBBBBBBBBBB",
			"BWBB            BBWB",
			"B   BB        BB   B",
			"B     BBWWWWBB     B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B                  B",
			"B     BBWWWWBB     B",
			"B   BB        BB   B",
			"BWBB            BBWB",
			"BBBBBBBBBBBBBBBBBBBB"
		};

		window.clear();
		for (int k = 0; k < W; k++)
			for (int i = 0; i < H; i++)
			{
				if (TyleMap1[i][k] == 'B') {
					map_s.setTextureRect(IntRect(0, 0, 32, 32));
					map_s.setPosition(32 * k, 32 * i);
				}
				if (TyleMap1[i][k] == 'W') {
					map_s.setTextureRect(IntRect(0, 64, 32, 32));
					map_s.setPosition(32 * k, 32 * i);
				}
				if (TyleMap1[i][k] == ' ') continue;
				window.draw(map_s);
			}
		window.draw(pl_1.sprite);
		window.display();
	}
	return 0;
}
// без ќќѕ
/*
if (Keyboard::isKeyPressed(Keyboard::W))
{
s.move(0, -0.1*time);
currentFrame += 0.005*time;
if (currentFrame > 2) currentFrame -= 2;
s.setTextureRect(IntRect(32 * (int)currentFrame, 0, 32, 32));
}
if (Keyboard::isKeyPressed(Keyboard::A))
{
s.move(-0.1*time, 0);
currentFrame += 0.005*time;
if (currentFrame > 2) currentFrame -= 2;
s.setTextureRect(IntRect(32 * (int)currentFrame + 64, 0, 32, 32));
}
if (Keyboard::isKeyPressed(Keyboard::S))
{
s.move(0, 0.1*time);
currentFrame += 0.005*time;
if (currentFrame > 2) currentFrame -= 2;
s.setTextureRect(IntRect(32 * (int)currentFrame + 128, 0, 32, 32));
}
if (Keyboard::isKeyPressed(Keyboard::D))
{
s.move(0.1*time, 0);
currentFrame += 0.005*time;
if (currentFrame > 2) currentFrame -= 2;
s.setTextureRect(IntRect(32 * (int)currentFrame + 192, 0, 32, 32));
}
*/