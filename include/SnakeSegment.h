#ifndef SNAKESEGMENT_H
#define SNAKESEGMENT_H

struct SnakeSegment {
    int x, y; // Position of the segment
    SnakeSegment(int posX, int posY) : x(posX), y(posY) {}
};

#endif // SNAKESEGMENT_H


