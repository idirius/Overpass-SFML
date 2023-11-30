#include <Log.hpp>
#include <ResourceHolder.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Textures::ID toTextureID(Log::Type type)
{
	switch (type)
	{
		case Log::Wood:
			return Textures::Wood;

		case Log::Crocodile:
			return Textures::Crocodile;
	}
	return Textures::Wood;
}

Log::Log(Type type, const TextureHolder& textures)
: mType(type)
, sprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Log::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

bool Log::checkCollision(Entity& other) {
   return sprite.getGlobalBounds().intersects(other.getGlobalBounds());
}

sf::FloatRect Log::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

sf::Vector2f Log::center() {
    return sf::Vector2f(sprite.getGlobalBounds().getSize().x/2, sprite.getGlobalBounds().getSize().y/2);
}