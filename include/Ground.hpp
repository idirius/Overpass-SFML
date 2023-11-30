#ifndef GROUND_HPP
#define GROUND_HPP
#include <Entity.hpp>
#include <ResourceIdentifiers.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Ground: public Entity {
public:
    enum Type {Road, River};
    Ground(Type type, const TextureHolder& textures, const sf::IntRect& textureRect);
    bool checkCollision(Entity& other);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f center();

private:
    Type mType;
    sf::Sprite sprite;
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif