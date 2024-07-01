//
// Created by stone on 2024-06-25.
//

#ifndef RESOURCEIDENTIFIERS_H
#define RESOURCEIDENTIFIERS_H

namespace sf {
    class Texture;
    class Font;
}

namespace Textures {
    enum ID {
        Eagle,
        Raptor,
        Desert,
    };
}
namespace Fonts {
    enum ID {
        Main,
    };
}
template<typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#endif //RESOURCEIDENTIFIERS_H
