#include <Vehicle.hpp>

Textures::ID toTextureID(Vehicle::Type type)
{
	switch (type)
	{
		case Vehicle::Car:
			return Textures::Car;

	}
	return Textures::Car;
}

Vehicle::Vehicle(Type type, const TextureHolder& textures): 
mType(type), 
sprite(textures.get(toTextureID(type))) {
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Vehicle::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite, states);
}

bool Vehicle::checkCollision(Entity& other) {
   return sprite.getGlobalBounds().intersects(other.getGlobalBounds());
}

sf::FloatRect Vehicle::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

sf::Vector2f Vehicle::center() {
    return sf::Vector2f(sprite.getGlobalBounds().getSize().x/2, sprite.getGlobalBounds().getSize().y/2);
}