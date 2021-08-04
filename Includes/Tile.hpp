//
// Created by Victor Hamon on 04/08/2021.
//

#ifndef INC_2048_TILE_HPP
#define INC_2048_TILE_HPP
#include "GameObject.hpp"

class Tile : public GameObject {
protected:
    sf::RectangleShape _shape;
public:
    const sf::Color &getSquareColor() const;
    void setSquareColor(const sf::Color &squareColor);
    sf::RectangleShape &getShape();
    void setShape(const sf::RectangleShape &shape);
public:
    virtual void draw() override;
    void setPosition(float x, float y) override;
    void setRelativePosition(float relativeX, float relativeY) override;
    void setX(float x) override;
    void setY(float y) override;
    void setRelativeX(float relativeX) override;
    void setRelativeY(float relativeY) override;
    void UpdatePosition();
    void setSize(sf::Vector2<float> size);
    sf::Vector2<float> getSize() const;

public:
    Tile(const std::shared_ptr <sf::RenderWindow> &window, sf::RectangleShape shape);
    Tile(const std::shared_ptr <sf::RenderWindow> &window);
};


#endif //INC_2048_TILE_HPP
