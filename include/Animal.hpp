#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <Entity.hpp>
#include <Animation.hpp>
#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Animal: public Entity {
public:
    Animal(const TextureHolder& textures);
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    bool checkCollision(Entity& other);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f center();

private:
    Animation animation;
    void updateCurrent(sf::Time dt);
};

#endif