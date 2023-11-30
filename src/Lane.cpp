#include <Lane.hpp>

Lane::Lane(const TextureHolder& textures): laneTexture() {
	sf::IntRect textureRect(0, 0, 1400, 150);
    sprite.setTexture(textures.get(Textures::Road));
    sprite.setTextureRect(textureRect);
    loadTextures();
    buildLane();
}

void Lane::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite, states);
}

void Lane::updateCurrent(sf::Time dt) {
    TrafficLight::Color curColor = trafficlight->getCurrentColor();
    if(curColor == TrafficLight::Color::Red)
        for(auto& x : cars)
            x->setVelocity(0, 0);
    else if (curColor == TrafficLight::Color::Green)
        for(auto& x : cars)
			x->setVelocity(300.f, 0.f);
    else
        for(auto& x : cars)
			x->setVelocity(100.f, 0.f);
    
	// for(auto& x : cars) {
	// 	sf::Vector2f position = x->getPosition();
	// 	if (position.x > mWorldBounds.left + mWorldBounds.width + 200) {
	// 		x->setPosition(-200, position.y);
	// 	}
	// }
}

void Lane::loadTextures() {
    laneTexture.load(Textures::Car, "../Media/Textures/Car.png");
	laneTexture.load(Textures::TrafficLight, "../Media/Textures/TrafficLight.png");
	laneTexture.load(Textures::Fox, "../Media/Textures/Fox.png");
}

void Lane::buildLane() {
    std::unique_ptr<Vehicle> car(new Vehicle(Vehicle::Car, laneTexture));
    cars.push_back(car.get());
    car->setPosition(0.f, 75.f);
    car->setVelocity(300.f, 0.f);
    std::unique_ptr<TrafficLight> traffic(new TrafficLight(laneTexture));
    traffic->setPosition(500.f, 75.f);
    traffic->setVelocity(0.f, 0.f);
    traffic->setScale(0.8, 0.8);
    trafficlight = traffic.get();
    std::unique_ptr<Animal> fox(new Animal(laneTexture));
    fox->setVelocity(100.f, 0.f);
    fox->setPosition(50.f, 75.f);
    fox->setScale(0.7, 0.7);
    this->attachChild(std::move(car));
    this->attachChild(std::move(fox));
    this->attachChild(std::move(traffic));
}