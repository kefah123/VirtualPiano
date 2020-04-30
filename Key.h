
#ifndef KE_FINAL_PROJECT_GRAPHICS_KEY_H
#define KE_FINAL_PROJECT_GRAPHICS_KEY_H
#include "Quad.h"

class Key : public Quad {
private:
    color fill;
    color pressFill;

public:
    Key(color fill, point center, unsigned int width, unsigned int height);
    void draw() const override;
    void pressDown();
    void release();
};


#endif //KE_FINAL_PROJECT_GRAPHICS_KEY_H
