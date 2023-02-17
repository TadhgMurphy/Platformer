#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
class Game
{
public:
	//create Window
	sf::RenderWindow window;
	sf::View view;
	float randomNum;


	sf::RectangleShape playerShape;


	float velocityX = 0, velocityY = 0, gravity = 0.3;




	static const int numRows = 45;
	static const int numCols = 20;
	int levelData[numRows][numCols] =
	{
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,2,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,0,0,0,2,4,4,4,1,0,0,0,0,2,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,5,1,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,5,1,0,0,0,0,0,2,0 },
	{ 0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,2,1,2,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,2,1,2,0,1 },
	{ 0,0,0,0,0,0,0,0,0,4,6,0,0,0,0,2,1,2,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,1 },
	{ 0,0,0,0,0,0,0,0,5,1,0,0,0,0,0,0,0,1,6,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,5,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,3,3,3,3,3,1,0,0,0,0,0 } };

	sf::RectangleShape level[numRows][numCols];
	sf::Font m_font;  
	sf::Text m_message;

	Game()
	{
		window.create(sf::VideoMode(800, 600), "Endless Runner Game");
	}
	void init()
	{
		view = window.getDefaultView();
		playerShape.setSize(sf::Vector2f(20, 20));
		playerShape.setPosition(160, 500);

		for (int row = 0; row < numRows; row++)
		{
			for (int col = 0; col < numCols; col++)
			{
				if (levelData[row][col] == 1)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);
					level[row][col].setFillColor(sf::Color::Red);
				}
				if (levelData[row][col] == 0)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);
					level[row][col].setFillColor(sf::Color::Black);
				}
				if (levelData[row][col] == 2)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);

					level[row][col].setFillColor(sf::Color::Blue);
				}
				if (levelData[row][col] == 3)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);

					level[row][col].setFillColor(sf::Color::Green);
				}
				if (levelData[row][col] == 4)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);

					level[row][col].setFillColor(sf::Color::Blue);
				}
				if (levelData[row][col] == 5)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);

					level[row][col].setFillColor(sf::Color::Magenta);
				}
				if (levelData[row][col] == 6)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);

					level[row][col].setFillColor(sf::Color::Red);
				}
			}
			std::cout << std::endl;
		}
	}
	void run()
	{
		sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
		sf::Time timeSinceLastUpdate = sf::Time::Zero;
		sf::Clock clock;
		int death = 0;
		sf::Text m_deaths;
		sf::Text m_message;
		sf::Text m_win;
		sf::Font m_font;
		if (!m_font.loadFromFile("FONTS/BebasNeue.otf"))
		{
			std::cout << "error with font file file";
		}
		m_message.setFont(m_font);  
		m_message.setCharacterSize(24); 
		m_message.setFillColor(sf::Color::White); 
		m_message.setPosition(20, 10);  
		m_deaths.setFont(m_font);
		m_deaths.setCharacterSize(24);
		m_deaths.setFillColor(sf::Color::White);
		m_deaths.setPosition(20, 40);
		m_win.setFont(m_font);
		m_win.setCharacterSize(34);
		m_win.setFillColor(sf::Color::White);
		m_win.setPosition(275, 300);

		clock.restart();

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && velocityY == 0)
			{
					velocityY = -12;
			}

			timeSinceLastUpdate += clock.restart();

			if (timeSinceLastUpdate > timePerFrame)
			{
				for (int row = 0; row < numRows; row++)
				{
					for (int col = 0; col < numCols; col++)
					{
						level[row][col].move(-3.7, 0);
					}
				}

				velocityY = velocityY + gravity;
				playerShape.move(0, velocityY);

				gravity = 0.6;

				for (int row = 0; row < numRows; row++)
				{
					for (int col = 0; col < numCols; col++)
					{
						if (velocityY >= 0)
						{
							if (levelData[row][col] == 1)
							{
								if (playerShape.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
								{
									if (playerShape.getPosition().y < level[row][col].getPosition().y)
									{
										gravity = 0;
										velocityY = 0;
										playerShape.setPosition(playerShape.getPosition().x, level[row][col].getPosition().y);
										playerShape.move(0, -playerShape.getGlobalBounds().height);
										break;
									}
									else {
										death++;
										init();
									}
								}
							}
						}
						if (velocityY < 0)
						{
							if (levelData[row][col] == 1)
							{
								if (playerShape.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
								{
									death++;
									init();
								}
							}
						}
						if (levelData[row][col] == 2)
						{
							if (playerShape.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
							{
								death++;
								init();
							}
						}
						//Win Rectangle
						if (levelData[row][col] == 3)
						{
							if (playerShape.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
							{
								death = 0;
								window.clear();
								window.draw(m_win);
								window.display();
								for (int i = 0; i < 30; i++)
								{
									init();
								}
								/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
								{
									init();
								}*/
							}
						}
						//Fake Blue
						if (levelData[row][col] == 4)
						{
							
						}
						//Launch Block
						if (levelData[row][col] == 5)
						{
							if (playerShape.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
							{
								if (velocityY == -12)
								{
									velocityY = -18;
								}
							}
						}
						// Hidden Win
						if (levelData[row][col] == 6)
						{
							if (playerShape.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
							{
								death = 0;
								window.clear();
								window.draw(m_win);
								window.display();
								for (int i = 0; i < 30; i++)
								{
									init();
								}
								/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
								{
									init();
								}*/
							}
						}
					}
				}

				if (playerShape.getPosition().y > 600)
				{
					death++;
					init();
				}

				window.clear();

				for (int row = 0; row < numRows; row++)
				{
					for (int col = 0; col < numCols; col++)
					{
						window.draw(level[row][col]);
					}
				}
				m_message.setString("Deaths: ");
				m_deaths.setString(std::to_string(death));
				window.draw(m_message);
				window.draw(m_deaths);
				window.draw(playerShape);
				m_win.setString("Congrats You Won Now Go Again");
				window.display();

				timeSinceLastUpdate = sf::Time::Zero;
			}
		}
	}
};


int main()
{
	Game game;
	game.init();
	game.run();
	return 0;
}
