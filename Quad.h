
#ifndef KE_FINAL_PROJECT_GRAPHICS_QUAD_H
#define KE_FINAL_PROJECT_GRAPHICS_QUAD_H

struct color {
    double red;
    double green;
    double blue;
};


struct point {
    int x;
    int y;
};

class Quad {
protected:
    color fill;
    point center;
    unsigned int width;
    unsigned int height;

public:
    Quad();
    Quad(color fill, point center, unsigned int width, unsigned int height);
    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;
    point getCenter() const;

    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;
};


#endif //KE_FINAL_PROJECT_GRAPHICS_QUAD_H
