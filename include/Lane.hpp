#ifndef LANE_HPP
#define LANE_HPP
#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <SceneNode.hpp>
#include <TrafficLight.hpp>
#include <Animal.hpp>
#include <Vehicle.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Lane: public SceneNode {
public:
    Lane(const TextureHolder& textures);

private:
    sf::Sprite sprite;
    TextureHolder laneTexture;
	std::vector<Vehicle *> cars;
    TrafficLight* trafficlight;

    void updateCurrent(sf::Time dt);
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void loadTextures();
    void buildLane();
};

#endif