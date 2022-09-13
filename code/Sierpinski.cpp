#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Sierpinski!!", Style::Default);

	RectangleShape rect({100,100});
	//main coords of the main triangle//
	vector<Vector2f> vertices;
	//the points inbetween//
	vector<Vector2f> points;

	//what is clicked
	Vector2f clicked;


	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
    			if (event.mouseButton.button == sf::Mouse::Left)
				{
       		 	std::cout << "the Left Mouse button was pressed" << std::endl;
        		std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        		std::cout << "mouse y: " << event.mouseButton.y << std::endl;

				clicked.x =event.mouseButton.x;
				clicked.y=event.mouseButton.y;
    			}
			}
		}
        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/
		rect.setPosition(clicked.x, clicked.y);


		/*
		****************************************
		Draw the scene
		****************************************
		*/

		//loop through vectors and draw each coordinate//
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		window.draw(rect);
		window.display();
    }
    return 0;
}