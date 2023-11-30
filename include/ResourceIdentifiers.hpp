#ifndef BOOK_RESOURCEIDENTIFIERS_HPP
#define BOOK_RESOURCEIDENTIFIERS_HPP


// Forward declaration of SFML classes
namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		Wood,
		Crocodile,
		Car,
		Bear,
		TrafficLight,
		River,
		Road,
		Fox,
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif // BOOK_RESOURCEIDENTIFIERS_HPP
