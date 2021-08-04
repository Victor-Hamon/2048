//
// Created by Victor Hamon on 02/08/2021.
//

#ifndef INC_2048_BOARD_HPP
#define INC_2048_BOARD_HPP
#define BOARD_SIZE_HEIGHT 4;
#define BOARD_SIZE_WIDTH 4;
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Board {
private:
    std::shared_ptr<sf::RenderWindow> _window;
    std::vector<GameObject> _gameObjects;
public:
    Board();
    void StartGame();
    void InitWindow();
};


#endif //INC_2048_BOARD_HPP
