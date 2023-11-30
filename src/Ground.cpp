#include <Ground.hpp>
#include <ResourceHolder.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Textures::ID toTextureID(Ground::Type type) {
	if (type == Ground::River)
		return Textures::River;
	return Textures::Road;
}

Ground::Ground(Type type, const TextureHolder& textures, const sf::IntRect& textureRect)
: mType(type),
sprite(textures.get(toTextureID(type)), textureRect)
{
	// sf::FloatRect bounds = sprite.getLocalBounds();
	// sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Ground::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite, states);
}

bool Ground::checkCollision(Entity& other) {
   return sprite.getGlobalBounds().intersects(other.getGlobalBounds());
}

sf::FloatRect Ground::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

sf::Vector2f Ground::center() {
    return sf::Vector2f(sprite.getGlobalBounds().getSize().x/2, sprite.getGlobalBounds().getSize().y/2);
}