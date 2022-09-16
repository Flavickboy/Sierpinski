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

	RectangleShape rect1({3,3});
	RectangleShape rect2({3,3});
	RectangleShape rect3({3,3});

	Vector2f rect1pos;
	Vector2f rect2pos;
	Vector2f rect3pos;

	//main coords of the main triangle//
	vector<Vector2f> vertices;
	//the points inbetween//
	vector<Vector2f> points;

	int VERT_COUNT=0;




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
    			if ((event.mouseButton.button == sf::Mouse::Left)&& VERT_COUNT<3)
				{

				if (VERT_COUNT==0)
				{

					rect1pos.x = event.mouseButton.x;
					rect1pos.y = event.mouseButton.y;

					//changing int to float
					rect1pos.x+=0.0;
					rect1pos.y+=0.0;

					vertices.push_back({rect1pos.x,rect1pos.y});

					cout<< " Vertex 1: "<< rect1pos.x << " x , " << rect1pos.y << " y."<< endl;

					

				}


				if (VERT_COUNT==1)
				{
					rect2pos.x = event.mouseButton.x;
					rect2pos.y = event.mouseButton.y;

					rect2pos.x+=0.0;
					rect2pos.y+=0.0;

					vertices.push_back({rect2pos.x,rect2pos.y});

					cout<< " Vertex 2: "<< rect2pos.x << " x , " << rect2pos.y << " y."<< endl;

				}

				if (VERT_COUNT==2){
					rect3pos.x = event.mouseButton.x;
					rect3pos.y = event.mouseButton.y;

					rect3pos.x+=0.0;
					rect3pos.y+=0.0;

					vertices.push_back({rect3pos.x,rect3pos.y});

					cout<< " Vertex 3: "<< rect3pos.x << " x , " << rect3pos.y << " y."<< endl;
				}
				
				if (VERT_COUNT<3)
				{
					VERT_COUNT++;
				}

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

		rect1.setPosition(rect1pos.x, rect1pos.y);
		rect2.setPosition(rect2pos.x, rect2pos.y);
		rect3.setPosition(rect3pos.x, rect3pos.y);


		/*
		****************************************
		Draw the scene
		****************************************
		*/

		//loop through vectors and draw each coordinate//
		// Clear everything from the last run frame//
		// Draw our game scene here
		window.clear();
		window.draw(rect1);
		window.draw(rect2);
		window.draw(rect3);
		window.display();
    }
    return 0;
}