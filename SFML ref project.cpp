#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cmath>
#include <random>

using namespace sf;
using namespace std;

bool checking_corner(float x, float y)
{
	if (x < 0 || x + 20 > 800 || y < 0 || y + 150 > 600)
	{
		return false;
	}
	return true; 
}

bool cheking_hitting(const CircleShape& round, const RectangleShape& rect)
{
	FloatRect temp = round.getGlobalBounds();
	FloatRect test = rect.getGlobalBounds();

	return temp.intersects(test);
}

int main()
{
	RenderWindow window(VideoMode(800, 600), "Pong");

	Font font;
	font.loadFromFile("tested.ttf");

	Text message;
	message.setFont(font);
	message.setFillColor(Color::Blue);
	message.setCharacterSize(40);
	message.setStyle(Text::Bold | Text::Underlined);

	Text instruction;
	instruction.setFont(font);
	instruction.setFillColor(Color::Blue);
	instruction.setCharacterSize(35);
	instruction.setStyle(Text::Bold);

	instruction.setString("H - start new game\nR - restart game\nC - faster game\nV - slower game\nQ - quit game");
	instruction.setPosition(290.f, 200.f);

	RectangleShape menu(Vector2f(300.f, 200.f));
	menu.setFillColor(Color::Green);
	menu.setPosition(250.f, 200.f);

	SoundBuffer buffer;
	buffer.loadFromFile("sound1.wav");
	Sound sound;
	sound.setBuffer(buffer);

	RectangleShape rect1(Vector2f(20.f, 150.f));
	rect1.setFillColor(Color::Green);
	rect1.setPosition(700.f, 230.f);

	RectangleShape rect2(Vector2f(20.f, 150.f));
	rect2.setFillColor(Color::Green);
	rect2.setPosition(100.f, 230.f);

	RectangleShape speedrect(Vector2f(80.f, 40.f));
	speedrect.setFillColor(Color::Green);

	CircleShape round(10.f);
	round.setFillColor(Color::Green);
	round.setPosition(400.f, 300.f);

	float spdX = 0.1f;
	float spdY = 0.1f;
	float speed = 0.1f;

	int counter_player1 = 0;
	int counter_player2 = 0;

	int is_started = 0;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Q))
			{
				window.close();
			}
		}

		if (is_started)
		{
			round.move(spdX, spdY);

			if (round.getPosition().x < 0 || round.getPosition().x > 800)
			{
				spdX = -spdX;

				if (round.getPosition().x < 0)
				{
					counter_player1++;
				}
				if (round.getPosition().x > 800)
				{
					counter_player2++;
				}

				sound.play();

			}
			if (round.getPosition().y < 0 || round.getPosition().y > 600)
			{
				spdY = -spdY;

				sound.play();

			}
			if (cheking_hitting(round, rect1) || cheking_hitting(round, rect2))
			{
				spdX = -spdX;

				sound.play();

			}

			if (Keyboard::isKeyPressed(Keyboard::C))
			{
				speed = speed + 0.0005;
				spdX = fabs(spdX) + 0.00005;
				spdY = fabs(spdY) + 0.00005;
			}
			if (Keyboard::isKeyPressed(Keyboard::V))
			{
				speed = speed - 0.0005;
				spdX = fabs(spdX) - 0.00005;
				spdY = fabs(spdY) - 0.00005;
			}

			if (Keyboard::isKeyPressed(Keyboard::R))
			{
				is_started = 0;
				round.setPosition(400.f, 300.f);
				rect1.setPosition(700.f, 230.f);
				rect2.setPosition(100.f, 230.f);
				counter_player1 = 0;
				counter_player2 = 0;
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				if (checking_corner(rect2.getPosition().x, rect2.getPosition().y - speed))
				{
					rect2.move(0.f, -speed);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				if (checking_corner(rect2.getPosition().x, rect2.getPosition().y + speed))
				{
					rect2.move(0.f, speed);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::I))
			{
				if (checking_corner(rect1.getPosition().x, rect1.getPosition().y - speed))
				{
					rect1.move(0.f, -speed);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::K))
			{
				if (checking_corner(rect1.getPosition().x, rect1.getPosition().y + speed))
				{
					rect1.move(0.f, speed);
				}
			}

			message.setString("Player1: " + to_string(counter_player1) + " | Player2 : " + to_string(counter_player2));
			message.setPosition(285.f, 500.f);
		}
		else
		{
			if (Keyboard::isKeyPressed(Keyboard::H))
			{
				is_started = 1;

				round.move(spdX, spdY);

				if (round.getPosition().x < 0 || round.getPosition().x > 800)
				{
					spdX = -spdX;

					if (round.getPosition().x < 0)
					{
						counter_player1++;
					}
					if (round.getPosition().x > 800)
					{
						counter_player2++;
					}

					sound.play();

				}
				if (round.getPosition().y < 0 || round.getPosition().y > 600)
				{
					spdY = -spdY;

					sound.play();

				}
				if (cheking_hitting(round, rect1) || cheking_hitting(round, rect2))
				{
					spdX = -spdX;

					sound.play();

				}

				if (Keyboard::isKeyPressed(Keyboard::C))
				{
					speed = speed + 0.0005;
					spdX = fabs(spdX) + 0.00005;
					spdY = fabs(spdY) + 0.00005;
				}
				if (Keyboard::isKeyPressed(Keyboard::V))
				{
					speed = speed - 0.0005;
					spdX = fabs(spdX) - 0.00005;
					spdY = fabs(spdY) - 0.00005;
				}

				if (Keyboard::isKeyPressed(Keyboard::R))
				{
					is_started = 0;
					round.setPosition(400.f, 300.f);
					rect1.setPosition(700.f, 230.f);
					rect2.setPosition(100.f, 230.f);
					counter_player1 = 0;
					counter_player2 = 0;
				}

				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					if (checking_corner(rect2.getPosition().x, rect2.getPosition().y - speed))
					{
						rect2.move(0.f, -speed - 0.1);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					if (checking_corner(rect2.getPosition().x, rect2.getPosition().y + speed))
					{
						rect2.move(0.f, speed + 0.1);
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::I))
				{
					if (checking_corner(rect1.getPosition().x, rect1.getPosition().y - speed))
					{
						rect1.move(0.f, -speed - 0.1);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::K))
				{
					if (checking_corner(rect1.getPosition().x, rect1.getPosition().y + speed))
					{
						rect1.move(0.f, speed + 0.1);
					}
				}

				message.setString("Player1: " + to_string(counter_player1) + " | Player2 : " + to_string(counter_player2));
				message.setPosition(285.f, 500.f);
			}
		}

		window.clear();

		if (is_started)
		{
			window.draw(message);
			window.draw(rect2);
			window.draw(rect1);
			window.draw(round);
		}
		else
		{
			window.draw(menu);
			window.draw(instruction);
		}

		window.display();
	}

	return 0;
}