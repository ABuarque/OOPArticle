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

typedef struct {
	Shape super;
	int width;
	int height;
} Rectangle;

void newRectangle(Rectangle* this, int x, int y,
				  int width, int height);


void newRectangle(Rectangle* this, int x, int y,
				  int width, int height) {
	newShape(&(this->super), x, y);
	this->width = width;
	this->height = height;
}

void printRect(Rectangle* r) {
	printf("x: %d, y: %d, width: %d, height: %d \n", 
			(r->super).x, (r->super).y, r->width, r->height);
}

int main() {
	Rectangle r;
	newRectangle(&r, 0, 0, 20, 10);
	printRect(&r);
	moveBy(&(r.super), 9, -1);
	printRect(&r);
	return 0;
} 
