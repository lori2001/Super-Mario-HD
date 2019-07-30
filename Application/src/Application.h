#pragma once
#include "NGin.h"

class Application : public ngin::Client
{
public:
	Application();

	/* abstract overrides */
	virtual void setup();
	virtual void handleEvents();
	virtual void update();
	virtual void draw(sf::RenderWindow& window) const;
private:

	ngin::ui::Button button;
};

ngin::Client* createApplication() {
	return new Application;
}