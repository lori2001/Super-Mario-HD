#include "SFML/Graphics.hpp"
#include "NGin/Base.h"
#include "NGin/UserInterface.h"

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1366, 768), "My Application");

	ngin::Console::setFontStyle({ 18, 18 }, true);
	ngin::Console::setSize({ 1280, 600 });
	ngin::Timer::measureSysTime();

	ngin::Resources::setLocation("assets/");
	ngin::ui::Cursor::setBuffer(*ngin::Resources::AcquireSoundBuffer("click.wav"));

	ngin::ui::Switcher switcher;
	switcher.setTexture(*ngin::Resources::AcquireTexture("switcher.png"));

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
	
			ngin::ui::Cursor::followMouse(window);
			switcher.handleEvents(event, ngin::ui::Cursor::getPosition());
		}
		
		window.clear();

		switcher.draw(window);

		window.display();
	}

	return 0;
}