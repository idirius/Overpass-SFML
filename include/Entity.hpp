#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SceneNode.hpp>

class Entity : public SceneNode {
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
	virtual bool checkCollision(Entity& other) = 0;
	virtual sf::FloatRect getGlobalBounds() = 0;
	virtual sf::Vector2f center() = 0;

protected: 
	virtual void updateCurrent(sf::Time dt);

private:
	sf::Vector2f mVelocity;
};

#endif
