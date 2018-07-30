#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int16_t x;
	int16_t y;
} Shape;

void newShape(Shape* this, int16_t x, int16_t y);
void moveBy(Shape* this, int16_t x, int16_t y);

void newShape(Shape* this, int16_t x, int16_t y) {
	this->x = x;
	this->y = y;
}

void moveBy(Shape* this, int16_t dx, int16_t dy) {
	this->x += dx;
	this->y += dy;
}

void printShape(Shape* shape) {
	printf("x: %d, y: %d\n", shape->x, shape->y);
}

int main() {
	Shape shape;
	newShape(&shape, 505, -505);
	printShape(&shape);
	moveBy(&shape, 1, 1);
	printShape(&shape);
} 
