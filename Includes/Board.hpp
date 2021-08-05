//
// Created by Victor Hamon on 02/08/2021.
//

#ifndef INC_2048_BOARD_HPP
#define INC_2048_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <array>
#include "GameObject.hpp"

#define BOARD_SIZE_HEIGHT 4
#define BOARD_SIZE_WIDTH 4
#define WINDOW_W 720
#define WINDOW_H 720



class Board {
private:
    std::shared_ptr<sf::RenderWindow> _window;
    std::vector<std::unique_ptr<GameObject>> _gameObjects;
    std::array<std::array<int, BOARD_SIZE_WIDTH>, BOARD_SIZE_HEIGHT> _board;

    sf::RectangleShape _boardBackground;
public:
    Board();
    void StartGame();
    void InitWindow();
    void DisplayBackground();
    void InitSquares();
    void InitGameBoard();
    void DisplayGameObjects();
    void AddTile();
    sf::Vector2<int> GenerateCoordinates();
};


#endif //INC_2048_BOARD_HPP
