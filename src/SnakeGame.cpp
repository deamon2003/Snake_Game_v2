#include "../include/SnakeGame.h"
#include <cstdlib> // For rand()

const int blockSize = 20; // Size of each grid block
const int width = 30;     // Grid width
const int height = 20;    // Grid height

SnakeGame::SnakeGame() 
    : window(sf::VideoMode(width * blockSize, height * blockSize), "Snake Game"),
      dirX(1), dirY(0), gameOver(false), delay(0.1f) {
    snake.push_back(SnakeSegment(width / 2, height / 2));
    spawnFruit();
}

void SnakeGame::spawnFruit() {
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void SnakeGame::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dirY != 1) {
        dirX = 0;
        dirY = -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dirY != -1) {
        dirX = 0;
        dirY = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dirX != 1) {
        dirX = -1;
        dirY = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dirX != -1) {
        dirX = 1;
        dirY = 0;
    }
}

void SnakeGame::update() {
    if (clock.getElapsedTime().asSeconds() < delay) return;

    int newX = snake[0].x + dirX;
    int newY = snake[0].y + dirY;

    if (newX >= width) newX = 0; else if (newX < 0) newX = width - 1;
    if (newY >= height) newY = 0; else if (newY < 0) newY = height - 1;

    for (size_t i = 0; i < snake.size(); i++) {
        if (snake[i].x == newX && snake[i].y == newY) {
            gameOver = true;
            return;
        }
    }

    snake.insert(snake.begin(), SnakeSegment(newX, newY));

    if (newX == fruitX && newY == fruitY) {
        spawnFruit();
    } else {
        snake.pop_back();
    }

    clock.restart();
}

void SnakeGame::render() {
    window.clear(sf::Color::Black);

    sf::RectangleShape rectangle(sf::Vector2f(blockSize - 2, blockSize - 2));
    rectangle.setFillColor(sf::Color::Green);
    for (const auto &segment : snake) {
        rectangle.setPosition(segment.x * blockSize, segment.y * blockSize);
        window.draw(rectangle);
    }

    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(fruitX * blockSize, fruitY * blockSize);
    window.draw(rectangle);

    window.display();
}

void SnakeGame::run() {
    while (window.isOpen() && !gameOver) {
        processInput();
        update();
        render();
    }
}

