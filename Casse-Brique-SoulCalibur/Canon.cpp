#include "Canon.h"

Canon::Canon(float x, float y, float width, float height, sf::Color couleur) : GameObject(x, y, width, height, couleur) //Constructeur 
{
	
}

Canon::~Canon()
{

}

void Canon::setRotation(float angle)
{
	rShape.setRotation(angle);
}
