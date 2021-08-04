//
// Created by Victor Hamon on 02/08/2021.
//

#include <iostream>
#include "../Includes/Board.hpp"
#include "../Includes/BoardSquare.hpp"

Board::Board() {
    InitWindow();
}

void Board::StartGame() {
    while (_window->isOpen()) {
        sf::Event event;

        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window->close();
        }
        _window->clear(sf::Color::White);
        DisplayBackground();
        DisplayGameObjects();
        _window->display();
    }
}

void Board::InitWindow() {
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_W, WINDOW_H), "2048", sf::Style::Close);
    _window->setFramerateLimit(30);
    InitSquares();
}


void Board::DisplayBackground() {
    _boardBackground.setSize({static_cast<float>(_window->getSize().x), static_cast<float>(_window->getSize().x)});
    _boardBackground.setOrigin(_boardBackground.getSize().x / 2, _boardBackground.getSize().y / 2);
    _boardBackground.setPosition(static_cast<float>(_window->getSize().x) / 2,
                                 static_cast<float>(_window->getSize().y) / 2);
    _boardBackground.setFillColor(sf::Color::Cyan);
    _window->draw(_boardBackground);
}

void Board::InitSquares() {
    for (int i = 0; i < BOARD_SIZE_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_SIZE_WIDTH; ++j) {
            BoardSquare newSquare(_window);
            newSquare.setRelativeX(static_cast<float>(j) / (BOARD_SIZE_WIDTH));
            newSquare.setRelativeY(static_cast<float>(i) / (BOARD_SIZE_HEIGHT));
            newSquare.setSize({static_cast<float>(_window->getSize().x) / BOARD_SIZE_WIDTH,
                               static_cast<float>(_window->getSize().y) / BOARD_SIZE_HEIGHT});
            newSquare.setSquareColor(sf::Color(217, 202, 179));
            newSquare.getShape();
            _gameObjects.push_back(std::make_unique<BoardSquare>(newSquare));
        }
    }
}

void Board::DisplayGameObjects() {
    for (auto &object : _gameObjects) {
        object->draw();
    }
}
