#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../include/SnakeSegment.h"

class SnakeGame {
private:
    sf::RenderWindow window;
    std::vector<SnakeSegment> snake;
    int fruitX, fruitY;
    int dirX, dirY;
    bool gameOver;
    sf::Clock clock;
    float delay;

    void spawnFruit();    // Spawns a new fruit
    void processInput();  // Handles keyboard input
    void update();        // Updates game logic
    void render();        // Renders the game on the window

public:
    SnakeGame();          // Constructor
    void run();           // Main game loop
};

#endif // SNAKEGAME_H


