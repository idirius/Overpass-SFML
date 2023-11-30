#include <Animal.hpp>

Animal::Animal(const TextureHolder &textures): animation(textures.get(Textures::Fox)) {
    animation.setFrameSize(sf::Vector2i(890/5, 308));
    animation.setNumFrames(5);
    animation.setDuration(sf::seconds(1));
	sf::FloatRect bounds = animation.getLocalBounds();
	animation.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Animal::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(animation, states);
}

void Animal::updateCurrent(sf::Time dt) {
    Entity::updateCurrent(dt);
    animation.update(dt);
    animation.setRepeating(true);
}

bool Animal::checkCollision(Entity& other) {
   return animation.getGlobalBounds().intersects(other.getGlobalBounds());
}

sf::FloatRect Animal::getGlobalBounds() {
    return animation.getGlobalBounds();
}

sf::Vector2f Animal::center() {
    return sf::Vector2f(animation.getGlobalBounds().getSize().x/2, animation.getGlobalBounds().getSize().y/2);
}