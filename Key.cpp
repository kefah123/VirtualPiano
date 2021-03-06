
#include "Key.h"
#include "PianoGraphics.h"

Key::Key(color fill, point center, unsigned int width, unsigned int height) : Quad(fill, center, width, height) {
    this->fill = fill;
    pressFill = {0.5, 0.5, 0.5};
}

void Key::draw() const {
    Quad::draw();
    glColor3f(1, 1, 1);
}

void Key::pressDown() {
    setColor(pressFill);
}

void Key::release() {
    setColor(fill);
}
