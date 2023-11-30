#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <Entity.hpp>
#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Vehicle: public Entity {
public:
    enum Type {Car};
    Vehicle(Type type, const TextureHolder& textures);
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    bool checkCollision(Entity& other);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f center();

private:
    Type mType;
    sf::Sprite sprite;
};

#endif