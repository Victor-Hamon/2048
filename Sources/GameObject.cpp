//
// Created by Victor Hamon on 02/08/2021.
//

#include "../Includes/GameObject.hpp"

#include <utility>

GameObject::~GameObject() = default;

void GameObject::setPosition(float x, float y) {
    setX(x);
    setX(y);
}

float GameObject::getX() const {
    return _x;
}

void GameObject::setX(float x) {
    _x = x;
    _relativeX = x / static_cast<float>(_window->getSize().x);
}

float GameObject::getY() const {
    return _y;
}

void GameObject::setY(float y) {
    _y = y;
    _relativeY = y / static_cast<float>(_window->getSize().y);
}

float GameObject::getRelativeX() const {
    return _relativeX;
}

void GameObject::setRelativeX(float relativeX) {
    _x = relativeX * static_cast<float>(_window->getSize().x);
    _relativeX = relativeX;
}

float GameObject::getRelativeY() const {
    return _relativeY;
}

void GameObject::setRelativeY(float relativeY) {
    _x = relativeY * static_cast<float>(_window->getSize().y);
    _relativeY = relativeY;
}

[[maybe_unused]] GameObject::GameObject(std::shared_ptr<sf::RenderWindow> window) {
    _window = std::move(window);
}

void GameObject::setRelativePosition(float relativeX, float relativeY) {
    setRelativeX(relativeX);
    setRelativeY(relativeY);
}

sf::Vector2<float> GameObject::getPosition() const {
    return sf::Vector2<float>(_x, _y);
}

sf::Vector2<float> GameObject::getRelativePosition() const {
    return sf::Vector2<float>(_relativeX, _relativeY);
}

[[maybe_unused]] void GameObject::draw() {
    throw std::runtime_error("Unimplemented Functions in game object");
}

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {
}
