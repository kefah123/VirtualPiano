

#include "PianoGraphics.h"
#include "Key.h"
#include <iostream>
#include <vector>
using namespace std;
GLdouble width, height;
int wd;
color whiteKeyFill = {1,1,1};
Key C(whiteKeyFill,{300,100},70,200);
Key D(whiteKeyFill,{375,100},70,200);
Key E(whiteKeyFill,{450,100},70,200);
Key F(whiteKeyFill,{525,100},70,200);
Key G(whiteKeyFill,{600,100},70,200);
Key A(whiteKeyFill,{675,100},70,200);
Key B(whiteKeyFill,{750,100},70,200);

void init() {
    width = 900;
    height = 550;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.45f, 0.6f, 1.0f, 1.0f);
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, 1.6*width, 1.4*height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    C.draw();
    D.draw();
    E.draw();
    F.draw();
    G.draw();
    A.draw();
    B.draw();

    glFlush();

}

void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
            break;
    }
    glutPostRedisplay();
}


void cursor(int x, int y) {
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    glutPostRedisplay();
}

void timer(int dummy) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Virtual Piano");

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
