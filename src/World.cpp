#include <World.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
, mTextures() 
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f)
{
	loadTextures();
	buildScene();

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	// Scroll the world
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());	

	for(auto& x : logs) {
		sf::Vector2f position = x->getPosition();
		if (position.x > mWorldBounds.left + mWorldBounds.width + 200) {
			x->setPosition(-200, position.y);
		}
	}



	// Move the player sidewards (plane scouts follow the main aircraft)
	// sf::Vector2f position = mPlayerAircraft->getPosition();
	// sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	// // If player touches borders, flip its X velocity
	// if (position.x <= mWorldBounds.left + 150.f
	//  || position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
	// {
	// 	velocity.x = -velocity.x;
	// 	mPlayerAircraft->setVelocity(velocity);
	// }

	// Apply movements
	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextures.load(Textures::Wood, "../Media/Textures/Wood.jpg");
	mTextures.load(Textures::River, "../Media/Textures/River.jpg");
	mTextures.load(Textures::Road, "../Media/Textures/Road.png");
}

void World::buildScene()
{
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}
	sf::IntRect textureRect(0, 0, mWorldView.getSize().x, 150);
	mTextures.get(Textures::Road).setRepeated(true);
	mTextures.get(Textures::River).setRepeated(true);

	srand(time(NULL));
    int randnum = rand() % 3;
	// int numOfLanes = 1400/150;
	int numOfLanes = 50;
	for (int i = 0; i < numOfLanes; ++i) {
		if (randnum != 2) {
			std::unique_ptr<SceneNode> road(new Lane(mTextures));
			road->setPosition(mWorldBounds.left, mWorldBounds.top + mWorldBounds.height - 150*i);
			mSceneLayers[Background]->attachChild(std::move(road));
			// mSceneLayers[Background]->attachChild(std::move(traffic));
		}
		else {
			std::unique_ptr<Ground> river(new Ground(Ground::River, mTextures, textureRect));
			river->setPosition(mWorldBounds.left, mWorldBounds.top + mWorldBounds.height - 150*i);
			std::unique_ptr<Log> log(new Log(Log::Wood, mTextures));
			logs.push_back(log.get());
			log->setPosition(0.f, 75.f);
			log->setVelocity(500.f, 0.f);
			river->attachChild(std::move(log));
			mSceneLayers[Background]->attachChild(std::move(river));
		}
		randnum = rand() % 3;	
	}

}
