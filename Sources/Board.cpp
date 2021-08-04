//
// Created by Victor Hamon on 02/08/2021.
//

#include <iostream>
#include <random>
#include <chrono>
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
            //TODO Proper event manager
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Key::Up) {
                    AddTile();
                }
            }
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
    _window->setKeyRepeatEnabled(false);
    InitSquares();
    InitGameBoard();
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
    //for (int i = 0; i < BOARD_SIZE_HEIGHT; ++i) {
    //    for (int j = 0; j < BOARD_SIZE_WIDTH; ++j) {
    //        BoardSquare newSquare(_window);
    //        newSquare.setRelativeX(static_cast<float>(j) / (BOARD_SIZE_WIDTH));
    //        newSquare.setRelativeY(static_cast<float>(i) / (BOARD_SIZE_HEIGHT));
    //        newSquare.setSize({static_cast<float>(_window->getSize().x) / BOARD_SIZE_WIDTH,
    //                           static_cast<float>(_window->getSize().y) / BOARD_SIZE_HEIGHT});
    //        //TODO make a proper color palette with a hashmap
    //        newSquare.setSquareColor(sf::Color(217, 202, 179));
    //        newSquare.getShape();
    //        _gameObjects.push_back(std::make_unique<BoardSquare>(newSquare));
    //    }
    //}
}

void Board::DisplayGameObjects() {
    for (auto &object : _gameObjects) {
        object->draw();
    }
}

void Board::AddTile() {
    sf::Vector2<int> coordinates = GenerateCoordinates();
    if (coordinates.x == -1 ||coordinates.y == -1)
        return;
    _board[coordinates.y][coordinates.x] += 1;
    BoardSquare newSquare(_window);
    newSquare.setRelativeX(static_cast<float>(coordinates.x) / (BOARD_SIZE_WIDTH));
    newSquare.setRelativeY(static_cast<float>(coordinates.y) / (BOARD_SIZE_HEIGHT));
    newSquare.setSize({static_cast<float>(_window->getSize().x) / BOARD_SIZE_WIDTH,
                       static_cast<float>(_window->getSize().y) / BOARD_SIZE_HEIGHT});
    //TODO make a proper color palette with a hashmap
    newSquare.setSquareColor(sf::Color(250, 235, 224));
    newSquare.getShape();
    _gameObjects.push_back(std::make_unique<BoardSquare>(newSquare));
}

sf::Vector2<int> Board::GenerateCoordinates() {
    std::vector<sf::Vector2<int>> available_positions{};

    for (int i = 0; i < BOARD_SIZE_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_SIZE_WIDTH; ++j) {
            if (_board[i][j] == 0) {
                available_positions.emplace_back(j, i);
            }
        }
    }
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
                    std::chrono::duration_cast<std::chrono::seconds>(
                            std::chrono::system_clock::now().time_since_epoch()
                    ).count() +
            (std::mt19937::result_type)
                    std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::high_resolution_clock::now().time_since_epoch()
                    ).count());
    std::mt19937 gen(seed);

    if(available_positions.empty())
        return {-1,-1};
    std::uniform_int_distribution<int> distrib(0, static_cast<int>(available_positions.size() - 1));
    auto test = distrib(gen);
    std::cout << std::to_string(test) << "===" << std::to_string(available_positions.size()) << std::endl;
    return available_positions[test];
}

void Board::InitGameBoard() {
    std::array<int, BOARD_SIZE_WIDTH> line{};
    line.fill(0);
    _board.fill(line);
}
