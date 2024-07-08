//
// Created by stone on 2024-07-08.
//

#ifndef LABEL_H
#define LABEL_H

#include "Component.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Text.hpp>

namespace GUI {
    class Label : public Component {
    public:
        typedef std::shared_ptr<Label> Ptr;
    public:
        Label(const std::string& text, const FontHolder& fonts);
        virtual bool isSelectable() const;
        void setText(const std::string& text);
        virtual void handleEvent(const sf::Event &event) override;
    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    private:
        sf::Text mText;
    };
}



#endif //LABEL_H
