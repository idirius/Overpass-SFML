#ifndef TRAFFICLIGHT_HPP
#define TRAFFICLIGHT_HPP
#include <Entity.hpp>
#include <Vehicle.hpp>

namespace Duration {
    const sf::Time Red = sf::seconds(1);
    const sf::Time Yellow = sf::seconds(1);
    const sf::Time Green = sf::seconds(1);
};

class TrafficLight: public Entity {
public:
    enum Color{Red, Yellow, Green};
    TrafficLight(const TextureHolder& textures);
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	bool checkCollision(Entity& other);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f center();
    Color getCurrentColor();

private:
    sf::Sprite sprite;
    sf::IntRect rect;
    Color current;
    sf::Time red;
    sf::Time yellow;
    sf::Time green;
    sf::Time elapsed;
    void updateCurrent(sf::Time dt);
    void updateCurrentColor(sf::Time dt);
};

#endif