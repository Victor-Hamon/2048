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
    virtual void setPosition(float x, float y);
    virtual void setRelativePosition(float relativeX, float relativeY);
    virtual sf::Vector2<float> getPosition() const;
    virtual sf::Vector2<float> getRelativePosition() const;
    virtual float getX() const;
    virtual void setX(float x);
    virtual float getY() const;
    virtual void setY(float y);
    virtual float getRelativeX() const;
    virtual void setRelativeX(float relativeX);
    virtual float getRelativeY() const;
    virtual void setRelativeY(float relativeY);

    /// Graphic functions
public:
    virtual void draw();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    /// Constructors and destructors
public:
    [[maybe_unused]] GameObject(std::shared_ptr<sf::RenderWindow> window);
    ~GameObject();
};


#endif //INC_2048_GAMEOBJECT_HPP
