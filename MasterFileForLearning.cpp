#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main()
{
	// Here are the stuff that are going to be in the program or stuff.
        RenderWindow window(VideoMode(800,600), "helloworld"); // this is a render window
	CircleShape shape(100); //the shape of the moving object
	shape.setFillColor(Color::White); // the colour of the moving object

	Font font;
	if(!font.loadFromFile("Roboto-Light.tff")) // Trying to load the font that i have
	{
		cout << "The font didnt load" << endl;
	}
	Text text1;
	//text1.setFont(font);
	text1.setCharacterSize(14);
	text1.setColor(Color::White);
	text1.setString("Hello World SFML!!");	

	Texture texture; // defining the texture/
	if(!texture.loadFromFile("google.png")) // loading a texture if it doesnt. it fails
	{
		cout << "it failed to load the image!" << endl;
	}
	Sprite sprite; // defining the sprite.
	sprite.setTexture(texture); //the sprite has a texture which is the google logo.
	
	while(window.isOpen()) // the game loop 
        {
                Event event; // this is going to be the event;
                while (window.pollEvent(event)) 
		{  // this is going to be the start of the game loop.

                        if (event.type == Event::Closed) window.close(); // showing that the game is running
			
				                //cout << "The program is running" << endl;
			
                        if(Keyboard::isKeyPressed(Keyboard::Q)) // The window will close.
               	        {
                                window.close(); // this is going to close the window
				                        cout << "!!!Window Closed!!!" << endl;
                        }
			
			if(Keyboard::isKeyPressed(Keyboard::Right)) 
      { // Move Right.
				shape.move(15, 0);
				cout << "Keyboard Right" << endl;
			}
				
			if(Keyboard::isKeyPressed(Keyboard::Down))
      { // Move Down.
				shape.move(0,15);
				cout << "Keyboard Down" << endl;
			}

				
			if(Keyboard::isKeyPressed(Keyboard::Left))
        { // Move Left.
				  shape.move(-15,0);
				  cout << "Keyboard Left" << endl;
			  }
				
			if(Keyboard::isKeyPressed(Keyboard::Up)) 
      { // Move Up.
				shape.move(0,-15);
				cout << "Keyboard Up!" << endl;
			}
			
			    sprite.setPosition(400,200);
			    //Texture texture;
			    //texture.loadFromFile("");
				

                }

                         window.clear();
			                   window.draw(shape);
			                   window.draw(text1);
			                   window.draw(sprite);
                         window.display();
          }
        return 0;
}


