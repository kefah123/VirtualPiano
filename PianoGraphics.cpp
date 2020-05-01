
#include <irrKlang.h>
#include "PianoGraphics.h"
#include "Key.h"
#include <iostream>

using namespace std;
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
GLdouble width, height;
int wd;
color whiteKeyFill = {1,1,1};
color blackKeyFill = {0,0,0};
Key C(whiteKeyFill,{300,100},70,200);
Key D(whiteKeyFill,{375,100},70,200);
Key E(whiteKeyFill,{450,100},70,200);
Key F(whiteKeyFill,{525,100},70,200);
Key G(whiteKeyFill,{600,100},70,200);
Key A(whiteKeyFill,{675,100},70,200);
Key B(whiteKeyFill,{750,100},70,200);
Key cSharp(blackKeyFill,{337,50},35,130);
Key dSharp(blackKeyFill,{412,50},35,130);
Key fSharp(blackKeyFill,{562,50},35,130);
Key gSharp(blackKeyFill,{637,50},35,130);
Key aSharp(blackKeyFill,{712,50},35,130);
Quad pianoBase(blackKeyFill,{525,100},600,300);
ISoundEngine* engine = createIrrKlangDevice();
void init() {
    width = 900;
    height = 550;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.45f, 0.6f, 1.0f, 1.0f);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

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
    pianoBase.draw();
    C.draw();
    D.draw();
    E.draw();
    F.draw();
    G.draw();
    A.draw();
    B.draw();
    cSharp.draw();
    dSharp.draw();
    fSharp.draw();
    gSharp.draw();
    aSharp.draw();

    glFlush();

}


void keyButtonDown(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            glutDestroyWindow(wd);
            exit(0);
        case 'd':
            C.pressDown();
            engine->play2D("piano_sounds/448549__tedagame__c4.ogg",false);
            break;
        case 'f':
            D.pressDown();
            break;
        case 'g':
            E.pressDown();
            break;
        case 'h':
            F.pressDown();
            break;
        case 'j':
            G.pressDown();
            break;
        case 'k':
            A.pressDown();
            break;
        case 'l':
            B.pressDown();
            break;
        case 'r':
            cSharp.pressDown();
            break;
        case 't':
            dSharp.pressDown();
            break;
        case 'y':
            fSharp.pressDown();
            break;
        case 'u':
            gSharp.pressDown();
            break;
        case 'i':
            aSharp.pressDown();
            break;
    }
    glutPostRedisplay();
}
void keyButtonUp(unsigned char key, int x, int y) {
    switch(key) {
        case 'd':
            C.release();
        case 'f':
            D.release();
        case 'g':
            E.release();
        case 'h':
            F.release();
        case 'j':
            G.release();
        case 'k':
            A.release();
        case 'l':
            B.release();
        case 'r':
            cSharp.release();
        case 't':
            dSharp.release();
        case 'y':
            fSharp.release();
        case 'u':
            gSharp.release();
        case 'i':
            aSharp.release();
    }
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
    glutKeyboardFunc(keyButtonDown);

    //register keyboard release event
    glutKeyboardUpFunc(keyButtonUp);
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
