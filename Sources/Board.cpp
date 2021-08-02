//
// Created by Victor Hamon on 02/08/2021.
//

#include "../Includes/Board.hpp"

Board::Board() {
    InitWindow();
}

void Board::StartGame() {
    while(window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.display();
    }
}

void Board::InitWindow() {
    window.create(sf::VideoMode(1920, 1080), "2048");
}
