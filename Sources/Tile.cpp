//
// Created by Victor Hamon on 04/08/2021.
//

#include "../Includes/Tile.hpp"

#include <utility>
#include <iostream>

void Tile::draw() {
    _window->draw(_shape);
    _window->draw(_value);
}

void Tile::UpdatePosition() {
    _shape.setPosition(_x, _y);
}

void Tile::setPosition(float x, float y) {
    GameObject::setPosition(x, y);
    UpdatePosition();
}

void Tile::setRelativePosition(float relativeX, float relativeY) {
    GameObject::setRelativePosition(relativeX, relativeY);
    UpdatePosition();
}

void Tile::setX(float x) {
    GameObject::setX(x);
    UpdatePosition();
}

void Tile::setY(float y) {
    GameObject::setY(y);
    UpdatePosition();
}

void Tile::setRelativeX(float relativeX) {
    GameObject::setRelativeX(relativeX);
    UpdatePosition();
}

void Tile::setRelativeY(float relativeY) {
    GameObject::setRelativeY(relativeY);
    UpdatePosition();
}

const sf::Color &Tile::getSquareColor() const {
    return _shape.getFillColor();
}

void Tile::setSquareColor(const sf::Color &squareColor) {
    _shape.setFillColor(squareColor);
    _shape.setOutlineColor(sf::Color::Black);
    _shape.setOutlineThickness(2);
}

sf::RectangleShape &Tile::getShape() {
    return _shape;
}

void Tile::setShape(const sf::RectangleShape &shape) {
    _shape = shape;
}

Tile::Tile(const std::shared_ptr<sf::RenderWindow> &window, sf::RectangleShape shape) : GameObject(
        window), _shape(std::move(shape)) {}

Tile::Tile(const std::shared_ptr<sf::RenderWindow> &window): GameObject(
        window) {

}

void Tile::setSize(sf::Vector2<float> size) {
    _shape.setSize(size);
}

sf::Vector2<float> Tile::getSize() const {
    return _shape.getSize();
}

void Tile::setText(const std::string& val) {
    _value.setString(val);
}
