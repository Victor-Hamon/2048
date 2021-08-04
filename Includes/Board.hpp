//
// Created by Victor Hamon on 02/08/2021.
//

#ifndef INC_2048_BOARD_HPP
#define INC_2048_BOARD_HPP

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

#define BOARD_SIZE_HEIGHT 4
#define BOARD_SIZE_WIDTH 4
#define WINDOW_W 640
#define WINDOW_H 640



class Board {
private:
    std::shared_ptr<sf::RenderWindow> _window;
    std::vector<std::unique_ptr<GameObject>> _gameObjects;

    sf::RectangleShape _boardBackground;
public:
    Board();
    void StartGame();
    void InitWindow();
    void DisplayBackground();
    void InitSquares();
    void DisplayGameObjects();
};


#endif //INC_2048_BOARD_HPP
