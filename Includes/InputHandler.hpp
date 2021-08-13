//
// Created by VictorHamon on 08/08/2021.
//

#ifndef INC_2048_INPUTHANDLER_HPP
#define INC_2048_INPUTHANDLER_HPP

#include <string>
#include <functional>
#include <algorithm>
#include <SFML/Window/Event.hpp>
#include <map>

class Board;

struct KeyboardInput {
    std::function<int(std::shared_ptr<Board>)> _callback;
    sf::Keyboard::Key _key;
};

namespace InputCallbacks {
    int InputFunction_Move_UP(std::shared_ptr<Board> boardInstance);
}

class InputHandler {
    private:
    std::map<sf::Keyboard::Key, std::pair<std::function<int(std::shared_ptr<Board>)>, const std::string>> _inputs = {
            {sf::Keyboard::Key::Up, std::make_pair(InputCallbacks::InputFunction_Move_UP, "Move_UP")},
            {sf::Keyboard::Key::Down, std::make_pair(InputCallbacks::InputFunction_Move_UP, "Move_UP")},
            {sf::Keyboard::Key::Left, std::make_pair(InputCallbacks::InputFunction_Move_UP, "Move_UP")},
            {sf::Keyboard::Key::Right, std::make_pair(InputCallbacks::InputFunction_Move_UP, "Move_UP")}
    };

public:
};


#endif //INC_2048_INPUTHANDLER_HPP
