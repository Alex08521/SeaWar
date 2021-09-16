#include "SFML/Graphics.hpp"
#include <iostream>
#include "AIPlayer.h"
#include "HPlayer.h"
using namespace sf;

int main()
{

	AIPlayer aiplayer;
	HPlayer player;

	LightRand random;

	Font font;
	if (!font.loadFromFile("19168.ttf"))
	{
		return 0;
	}

	int timeAi = 0;
	for (int i = 0; i < 200; i++)
	{
		std::cout << random.getRandVolume() << "\n";
	}


	if (random.getRandVolume() < 51)
	{
		aiplayer.giveTurn();
	}
	else
	{
		player.giveTurn();
	}

	bool shipstanding = true;
	bool done = false;


	RenderWindow window(VideoMode(990, 720), "Sea War", Style::Default);
	window.setFramerateLimit(60);

	bool fourd = false;
	bool threed = false;
	bool twod = false;
	bool oned= false;

	int fourde = 0;
	int threede = 0;
	int twode = 0;
	int onede = 0;

	int bloom = 0;

	int X = 0;
	int Y = 0;
	while (window.isOpen())
	{
		Event event;
		Mouse mouse;
		Vector2i pixelPos = mouse.getPosition(window);

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
	
				window.close();
		}

		Text text("", font, 30);
		text.setFillColor(Color(240, 240, 240));
		text.setStyle(Text::Bold);
		window.clear();

		text.setCharacterSize(50);
		text.setString(L"Морской Бой");
		text.setPosition(340, 10);

		window.draw(text);

		if (player.turnIsGiven() && !shipstanding)
		{
			text.setFillColor(Color(240, 240, 240));
			if (bloom > 10)
			{
				text.setFillColor(Color(255, 255, 255));
			}
			else if (bloom < 5)
			{
				text.setFillColor(Color(185, 185, 185));
			}
			text.setCharacterSize(30);
			text.setString(L"Ваш Ход");
			text.setPosition(430, 600);
		}
		else if (aiplayer.turnIsGiven() && !shipstanding)
		{
			text.setFillColor(Color(213, 9, 45));
			if (bloom > 10)
			{
				text.setFillColor(Color(255, 9, 45));
			}
			else if (bloom < 50)
			{
				text.setFillColor(Color(185, 9, 45));
			}
			text.setCharacterSize(30);
			text.setString(L"Ход Противника");
			text.setPosition(330, 600);
		}

		window.draw(text);

		text.setFillColor(Color(240, 240, 240));
		text.setCharacterSize(20);
		text.setString(L"1АПпб-00-21зп");
		text.setPosition(20, 10);

		window.draw(text);

		text.setString(L"Плужинский А.С.");
		text.setPosition(20, 40);

		window.draw(text);

		text.setString(L"Курсовой проект");
		text.setPosition(20, 70);

		window.draw(text);

		text.setString(L"Ваши корабли");
		text.setPosition(70, 580);

		window.draw(text);

		text.setString(L"четырёхпалубников = ");
		text.setPosition(50, 600);

		window.draw(text);

		wchar_t a = L'0';

		a = player.howManyFourdeck() + L'0';
		text.setString(a);
		text.setPosition(270, 600);

		window.draw(text);

		text.setString(L"трёхпалубников = ");
		text.setPosition(50, 620);

		window.draw(text);

		a = player.howManyThreedeck() + L'0';
		text.setString(a);
		text.setPosition(270, 620);

		window.draw(text);

		text.setString(L"двухпалубников = ");
		text.setPosition(50, 640);

		window.draw(text);

		a = player.howManyTwodeck() + L'0';
		text.setString(a);
		text.setPosition(270, 640);

		window.draw(text);

		text.setString(L"однопалубников = ");
		text.setPosition(50, 660);

		window.draw(text);

		a = player.howManyOnedeck() + L'1';
		text.setString(a);
		text.setPosition(270, 660);

		window.draw(text);

		text.setFillColor(Color(213, 9, 45));
		text.setString(L"Корабли противника");
		text.setPosition(700, 580);

		window.draw(text);

		text.setString(L"четырёхпалубников = ");
		text.setPosition(700, 600);

		window.draw(text);

		a = aiplayer.howManyFourdeck() + L'0';
		text.setString(a);
		text.setPosition(920, 600);

		window.draw(text);

		text.setString(L"трёхпалубников = ");
		text.setPosition(700, 620);

		window.draw(text);

		a = aiplayer.howManyThreedeck() + L'0';
		text.setString(a);
		text.setPosition(920, 620);

		window.draw(text);

		text.setString(L"двухпалубников = ");
		text.setPosition(700, 640);

		window.draw(text);

		a = aiplayer.howManyTwodeck() + L'0';
		text.setString(a);
		text.setPosition(920, 640);

		window.draw(text);

		text.setString(L"однопалубников = ");
		text.setPosition(700, 660);

		window.draw(text);

		text.setFillColor(Color(213, 9, 45));
		a = aiplayer.howManyOnedeck() + L'1';
		text.setString(a);
		text.setPosition(920, 660);

		window.draw(text);

		text.setFillColor(Color(240, 240, 240));

		if (bloom > 10)
		{
			text.setFillColor(Color(255, 255, 255));
		}
		else if (bloom < 5)
		{
			text.setFillColor(Color(185, 185, 185));
		}

		if (!fourd)
		{
			text.setString(L"Поставь четырёхпалубник");
			text.setPosition(360, 540);
		}
		else if (!threed)
		{
			text.setString(L"Поставь 2 трёхпалубника");
			text.setPosition(360, 540);
		}
		else if (!twod)
		{
			text.setString(L"Поставь 3 двухпалубника");
			text.setPosition(350, 540);
		}
		else if (!oned)
		{
			text.setString(L"Поставь 4 однопалубника");
			text.setPosition(350, 540);
		}

		window.draw(text);

		text.setCharacterSize(30);
		text.setFillColor(Color(240, 240, 240));
		
		if (pixelPos.x > 50 && pixelPos.x < 450 && pixelPos.y > 140 && pixelPos.y < 540)
		{
			if (pixelPos.x > 50) X = 1;
			if (pixelPos.x > 90) X = 2;
			if (pixelPos.x > 130) X = 3;
			if (pixelPos.x > 170) X = 4;
			if (pixelPos.x > 210) X = 5;
			if (pixelPos.x > 250) X = 6;
			if (pixelPos.x > 290) X = 7;
			if (pixelPos.x > 330) X = 8;
			if (pixelPos.x > 370) X = 9;
			if (pixelPos.x > 410) X = 10;

			if (pixelPos.y > 140) Y = 1;
			if (pixelPos.y > 180) Y = 2;
			if (pixelPos.y > 220) Y = 3;
			if (pixelPos.y > 260) Y = 4;
			if (pixelPos.y > 300) Y = 5;
			if (pixelPos.y > 340) Y = 6;
			if (pixelPos.y > 380) Y = 7;
			if (pixelPos.y > 420) Y = 8;
			if (pixelPos.y > 460) Y = 9;
			if (pixelPos.y > 500) Y = 10;

			//std::cout << pixelPos.x << std::endl;
			//std::cout << pixelPos.y << std::endl;
			//std::cout << X << std::endl;
			//std::cout << Y << std::endl;
		}

		if (pixelPos.x > 550 && pixelPos.x < 950 && pixelPos.y > 140 && pixelPos.y < 540)
		{
			if (pixelPos.x > 550) X = 1;
			if (pixelPos.x > 590) X = 2;
			if (pixelPos.x > 630) X = 3;
			if (pixelPos.x > 670) X = 4;
			if (pixelPos.x > 710) X = 5;
			if (pixelPos.x > 750) X = 6;
			if (pixelPos.x > 790) X = 7;
			if (pixelPos.x > 830) X = 8;
			if (pixelPos.x > 870) X = 9;
			if (pixelPos.x > 910) X = 10;

			if (pixelPos.y > 140) Y = 1;
			if (pixelPos.y > 180) Y = 2;
			if (pixelPos.y > 220) Y = 3;
			if (pixelPos.y > 260) Y = 4;
			if (pixelPos.y > 300) Y = 5;
			if (pixelPos.y > 340) Y = 6;
			if (pixelPos.y > 380) Y = 7;
			if (pixelPos.y > 420) Y = 8;
			if (pixelPos.y > 460) Y = 9;
			if (pixelPos.y > 500) Y = 10;

			//std::cout << X << std::endl;
			//std::cout << Y << std::endl;
		}

		int x = 55;

		while (x < 450)
		{
			if (x < 60)
			{
				text.setString("A");
			}
			else if (x < 100)
			{
				text.setString("B");
			}
			else if (x < 140)
			{
				text.setString("C");
			}
			else if (x < 180)
			{
				text.setString("D");
			}
			else if (x < 220)
			{
				text.setString("E");
			}
			else if (x < 260)
			{
				text.setString("F");
			}
			else if (x < 300)
			{
				text.setString("G");
			}
			else if (x < 340)
			{
				text.setString("H");
			}
			else if (x < 380)
			{
				text.setString("I");
			}
			else if (x < 420)
			{
				text.setString("J");
			}

			text.setPosition(x, 100);
			window.draw(text);

			text.setPosition(x + 500, 100);
			window.draw(text);

			x += 40;
		}

		int y = 135;

		while (y < 500)
		{
			if (y < 140)
			{
				text.setString("1");
			}
			else if (y < 180)
			{
				text.setString("2");
			}
			else if (y < 220)
			{
				text.setString("3");
			}
			else if (y < 260)
			{
				text.setString("4");
			}
			else if (y < 300)
			{
				text.setString("5");
			}
			else if (y < 340)
			{
				text.setString("6");
			}
			else if (y < 380)
			{
				text.setString("7");
			}
			else if (y < 420)
			{
				text.setString("8");
			}
			else if (y < 460)
			{
				text.setString("9");
			}
			else if (y < 500)
			{
				text.setString("10");
			}

			if (y > 470)
			{
				text.setPosition(10, y);
				window.draw(text);

				text.setPosition(510, y);
				window.draw(text);
			}
			else
			{
				text.setPosition(20, y);
				window.draw(text);

				text.setPosition(520, y);
				window.draw(text);
			}

			y += 40;
		}

		CircleShape circle;

		RectangleShape rectangle;
		rectangle.setSize(Vector2f(35.f, 35.f));

		if (aiplayer.turnIsGiven())
		{
			if (timeAi > 60)
			{
				std::cout << "enemy turn" << std::endl;
				bool chosen = false;
				twoPoints vxy;
				while (!chosen)
				{
					chosen = aiplayer.doChoise();
					if (chosen)
					{
						std::cout << "choise complete" << std::endl;
						vxy = aiplayer.shooting();
					}
				}
				std::cout << "shoting at x = " << vxy.get_pnt1() << " y = " << vxy.get_pnt2() << std::endl;
				if ((aiplayer.isIMissed(player.underFire(vxy.get_pnt1(), vxy.get_pnt2()))))
				{
					player.SetShipFieldElement(vxy.get_pnt1(), vxy.get_pnt2(), player.miss);
					player.giveTurn();
					aiplayer.passTurn();
					std::cout << "enemy pass" << std::endl;
				}
				else
				{
					player.SetShipFieldElement(vxy.get_pnt1(), vxy.get_pnt2(), player.wreckeddeck);
				}
				std::cout << "turn done" << std::endl;
				timeAi = 0;
			}
			else
			{
				timeAi++;
			}
		}

		x = 50;
		y = 140;
		int XX = 0;
		int YY = 0;
		bool chek = false;

//########SHIPFIELD#########################################

		while (y < 510)
		{
			if (chek)
			{
				rectangle.setFillColor(Color(41, 192, 231));
				chek = false;
			}
			else if (!chek)
			{
				rectangle.setFillColor(Color(21, 152, 185));
				chek = true;
			}

			XX = (x - 10) / 40;
			YY = (y - 100) / 40;
			if (shipstanding)
			{
				if (pixelPos.x < x + 40 && pixelPos.y < y + 40 && pixelPos.x > x && pixelPos.y > y
					&& (player.GetShipFieldElement(XX,YY) != player.fourdeck || player.GetShipFieldElement(XX, YY) != player.threedeck || 
						player.GetShipFieldElement(XX, YY) != player.twodeck || player.GetShipFieldElement(XX, YY) != player.onedeck))
						
				{
					rectangle.setFillColor(Color(91, 222, 255));

					if (mouse.isButtonPressed(mouse.Left))
					{
						if (X > 0 && X < 11 && Y > 0 && Y < 11)
						{
							std::cout << X << std::endl;
							std::cout << Y << std::endl;
							std::cout << player.GetShipFieldElement(X, Y) << std::endl;
							
							if (player.GetShipFieldElement(X,Y) == 0)
							{
								if (!fourd)
								{
									if (player.SetShipFieldElement(X, Y, player.fourdeck))
									{
										fourde++;
										Time t3 = sf::seconds(0.01f);
									}
									else
									{
										std::cout << "SetShip Error!" << std::endl;
									}
									if (fourde == 4)
									{
										fourd = true;
									}
								}
								else if (!threed)
								{
									if (player.SetShipFieldElement(X, Y, player.threedeck))
									{
										threede++;
										Time t3 = sf::seconds(0.01f);
									}
									else
									{
										std::cout << "SetShip Error!" << std::endl;
									}
									if (threede == 6)
									{
										threed = true;
									}
								}
								else if (!twod)
								{
									if (player.SetShipFieldElement(X, Y, player.twodeck))
									{
										twode++;
										Time t3 = sf::seconds(0.01f);
									}
									else
									{
										std::cout << "SetShip Error!" << std::endl;
									}
									if (twode == 6)
									{
										twod = true;
									}
								}
								else if (!oned)
								{
									if (player.SetShipFieldElement(X, Y, player.onedeck))
									{
										onede++;
										Time t3 = sf::seconds(0.01f);
									}
									else
									{
										std::cout << "SetShip Error!" << std::endl;
									}
									if (onede == 4)
									{
										oned = true;
									}
								}
							}
						}
					}
				}
			}

			if (player.GetShipFieldElement(XX, YY) == player.fourdeck || player.GetShipFieldElement(XX, YY) == player.threedeck 
				|| player.GetShipFieldElement(XX, YY) == player.twodeck || player.GetShipFieldElement(XX, YY) == player.onedeck)
			{
				rectangle.setFillColor(Color(13, 200, 45));
			}
			if (player.GetShipFieldElement(XX, YY) == player.wreckeddeck)
			{
				rectangle.setFillColor(Color(213, 9, 45));
			}
			if (player.GetShipFieldElement(XX, YY) == player.miss)
			{
				circle.setRadius(10.f);
				circle.setFillColor(Color(255, 255, 0));
				circle.setPosition(x + 8, y + 8);
			}

			rectangle.setPosition(x, y);

			window.draw(rectangle);

			window.draw(circle);

			if (x > 409)
			{
				if (chek)
				{
					chek = false;
				}
				else
				{
					chek = true;
				}
				y += 40;
				x = 10;
			}
			x += 40;

			XX = (x - 10) / 40;
			YY = (y - 100) / 40;
		}

		if (fourd && threed && twod && oned)
		{
			shipstanding = false;
		}

		x = 550;
		y = 140;
		chek = false;
		XX = (x - 510) / 40;
		YY = (y - 100) / 40;

//########PLAYFIELD#########################################

		while (y < 510)
		{
			if (chek)
			{
				rectangle.setFillColor(Color(41, 192, 231));
				chek = false;
			}
			else
			{
				rectangle.setFillColor(Color(21, 152, 185));
				chek = true;
			}
			if (!shipstanding && player.turnIsGiven() && !aiplayer.turnIsGiven())
			{
				if (pixelPos.x < x + 40 && pixelPos.y < y + 40 && pixelPos.x > x && pixelPos.y > y)
				{
					rectangle.setFillColor(Color(91, 222, 255));

					if (mouse.isButtonPressed(mouse.Left))
					{
						rectangle.setFillColor(Color(213, 9, 45));
						
						std::cout << X << std::endl;
						std::cout << Y << std::endl;
						std::cout << player.GetPlayFieldElement(X, Y) << std::endl;

						if (player.GetPlayFieldElement(XX, YY) != player.miss && player.GetPlayFieldElement(XX, YY) != player.wreckeddeck)
						{
							if (aiplayer.underFire(XX, YY))
							{
								player.SetPlayFieldElement(XX, YY, player.wreckeddeck);
								std::cout << "strike" << std::endl;
							}

							else if (!aiplayer.underFire(XX, YY))
							{
								player.SetPlayFieldElement(XX, YY, player.miss);
								std::cout << "miss" << std::endl;
								aiplayer.giveTurn();
								player.passTurn();
							}
						}
					}
				}
			}

			if (player.GetPlayFieldElement(XX, YY) == player.wreckeddeck)
			{
				rectangle.setFillColor(Color(213, 9, 45));
			}

			if (player.GetPlayFieldElement(XX, YY) == player.miss)
			{
				circle.setFillColor(Color(255, 255, 0));
				circle.setRadius(10.f);
				circle.setPosition(x + 8, y + 8);
			}
			rectangle.setSize(Vector2f(35.f, 35.f));
			rectangle.setPosition(x, y);
	
			window.draw(rectangle);
			window.draw(circle);

			if (x > 909)
			{
				if (chek)
				{
					chek = false;
				}
				else
				{
					chek = true;
				}
				y += 40;
				x = 510;
			}
			x += 40;
			XX = (x - 510) / 40;
			YY = (y - 100) / 40;
		}

		if (bloom > 15)
		{
			bloom = 0;
		}
		bloom++;
		// Отрисовка окна
		window.display();
	}
	return 0;
}