
#include "Quad.h"
#include "PianoGraphics.h"

Quad::Quad() {
    fill = {1, 1, 1};
    center = {0, 0};
    width = 50;
    height = 100;
}

Quad::Quad(color fill, point center, unsigned int width, unsigned int height) {
    this->fill = fill;
    this->center = center;
    this->width = width;
    this->height = height;
}

int Quad::getCenterX() const {
    return center.x;
}

int Quad::getLeftX() const {
    return center.x - (width / 2);
}

int Quad::getRightX() const {
    return center.x + (width / 2);
}

int Quad::getCenterY() const {
    return center.y;
}

int Quad::getTopY() const {
    return center.y - (height / 2);
}

int Quad::getBottomY() const {
    return center.y + (height / 2);
}

point Quad::getCenter() const {
    return center;
}

color Quad::getFill() const {
    return fill;
}

unsigned int Quad::getWidth() const {
    return width;
}

unsigned int Quad::getHeight() const {
    return height;
}

void Quad::setColor(double red, double green, double blue) {
    fill = {red, green, blue};
}

void Quad::setColor(color fill) {
    this->fill = fill;
}

void Quad::resize(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
}

void Quad::draw() const {
    glBegin(GL_QUADS);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(getLeftX(),getBottomY());
    glVertex2i(getLeftX(),getTopY());
    glVertex2i(getRightX(),getTopY());
    glVertex2i(getRightX(),getBottomY());
    glEnd();
}
