//
// Created by Victor Hamon on 02/08/2021.
//

#include "../Includes/Board.hpp"

Board::Board() {
    InitWindow();
}

void Board::StartGame() {
    while(_window->isOpen()) {
        sf::Event event;

        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window->close();
        }
        _window->clear(sf::Color::White);
        _window->display();
    }
}

void Board::InitWindow() {
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "2048");
    _gameObjects.emplace_back(_window);

    _gameObjects[0].draw();
}
