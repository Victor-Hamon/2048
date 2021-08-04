//
// Created by Victor Hamon on 04/08/2021.
//

#include "../Includes/BoardSquare.hpp"

#include <utility>
#include <iostream>

void BoardSquare::draw() {
    _window->draw(_shape);
}

void BoardSquare::UpdatePosition() {
    _shape.setPosition(_x, _y);
}

void BoardSquare::setPosition(float x, float y) {
    GameObject::setPosition(x, y);
    UpdatePosition();
}

void BoardSquare::setRelativePosition(float relativeX, float relativeY) {
    GameObject::setRelativePosition(relativeX, relativeY);
    UpdatePosition();
}

void BoardSquare::setX(float x) {
    GameObject::setX(x);
    UpdatePosition();
}

void BoardSquare::setY(float y) {
    GameObject::setY(y);
    UpdatePosition();
}

void BoardSquare::setRelativeX(float relativeX) {
    GameObject::setRelativeX(relativeX);
    UpdatePosition();
}

void BoardSquare::setRelativeY(float relativeY) {
    GameObject::setRelativeY(relativeY);
    UpdatePosition();
}

const sf::Color &BoardSquare::getSquareColor() const {
    return _shape.getFillColor();
}

void BoardSquare::setSquareColor(const sf::Color &squareColor) {
    _shape.setFillColor(squareColor);
    _shape.setOutlineColor(sf::Color::Black);
    _shape.setOutlineThickness(2);
}

sf::RectangleShape &BoardSquare::getShape() {
    return _shape;
}

void BoardSquare::setShape(const sf::RectangleShape &shape) {
    _shape = shape;
}

BoardSquare::BoardSquare(const std::shared_ptr<sf::RenderWindow> &window, sf::RectangleShape shape) : GameObject(
        window), _shape(std::move(shape)) {}

BoardSquare::BoardSquare(const std::shared_ptr<sf::RenderWindow> &window): GameObject(
        window) {

}

void BoardSquare::setSize(sf::Vector2<float> size) {
    _shape.setSize(size);
}

sf::Vector2<float> BoardSquare::getSize() const {
    return _shape.getSize();
}
