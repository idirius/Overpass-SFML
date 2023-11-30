#ifndef LOG_HPP
#define LOG_HPP
#include <Entity.hpp>
#include <ResourceIdentifiers.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Log: public Entity {
public:
    enum Type {Wood, Crocodile};
    Log(Type type, const TextureHolder& textures);
	bool checkCollision(Entity& other);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f center();

private:
    Type mType;
    sf::Sprite sprite;
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif