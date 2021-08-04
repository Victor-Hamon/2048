//
// Created by Victor Hamon on 02/08/2021.
//

#ifndef INC_2048_GAMEOBJECT_HPP
#define INC_2048_GAMEOBJECT_HPP


#include <SFML/Graphics.hpp>

class GameObject : sf::Drawable {
protected:
    float _x{};
    float _y{};
    float _relativeX{};
    float _relativeY{};
    std::shared_ptr<sf::RenderWindow> _window;

    /// Getters and setters
public:
    void setPosition(float x, float y);
    void setRelativePosition(float relativeX, float relativeY);
    sf::Vector2<float> getPosition() const;
    sf::Vector2<float> getRelativePosition() const;
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
    float getRelativeX() const;
    void setRelativeX(float relativeX);
    float getRelativeY() const;
    void setRelativeY(float relativeY);

    /// Graphic functions
public:
    [[maybe_unused]] void draw();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    /// Constructors and destructors
public:
    [[maybe_unused]] GameObject(std::shared_ptr<sf::RenderWindow> window);
    ~GameObject();
};


#endif //INC_2048_GAMEOBJECT_HPP
