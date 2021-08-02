//
// Created by Victor Hamon on 02/08/2021.
//

#ifndef INC_2048_GAMEOBJECT_HPP
#define INC_2048_GAMEOBJECT_HPP


#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable {
private:
    float _x;
    float _y;
    float _relativeX;
    float _relativeY;
public:
    GameObject();
    ~GameObject();
    void setPosition(const sf::RenderWindow& ref, float x, float y);
    void setX(const sf::RenderWindow& ref, float x);
    void setY(const sf::RenderWindow& ref, float y);
};


#endif //INC_2048_GAMEOBJECT_HPP
