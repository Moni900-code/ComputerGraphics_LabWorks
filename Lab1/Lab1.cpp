#include <GL/freeglut.h>
#include <cmath>

// Function to draw a 2D Circle
void drawCircle(float radius, float x, float y) {
    glBegin(GL_TRIANGLE_FAN);  
    glVertex2f(x, y);  // Center of the circle
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

// Function to draw a 2D Square
void drawSquare(float x, float y, float size) {
    glBegin(GL_QUADS);
    glVertex2f(x - size / 2, y - size / 2);
    glVertex2f(x + size / 2, y - size / 2);
    glVertex2f(x + size / 2, y + size / 2);
    glVertex2f(x - size / 2, y + size / 2);
    glEnd();
}

// Function to draw a 2D Line
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to draw a 3D Triangle
void draw3DTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 1.0f, 0.0f); // Top vertex
    glVertex3f(-1.0f, -1.0f, 0.0f); // Bottom left vertex
    glVertex3f(1.0f, -1.0f, 0.0f); // Bottom right vertex
    glEnd();
}

// Function to draw a 3D Cylinder
void draw3DCylinder() {
    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);  // Rotate cylinder to display correctly
    glutSolidCylinder(0.5, 1.0, 32, 32);  // Draw solid cylinder
    glPopMatrix();
}

// Function to clear the window and set up transformations
void setupOpenGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear color and depth buffer
    glLoadIdentity();  // Reset transformations
}

// Display function to render the shapes
void display() {
    setupOpenGL();

    // Draw 2D Shapes
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    drawCircle(0.5f, -1.5f, 0.0f);  // Circle

    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    drawSquare(1.0f, 0.0f, 1.0f);  // Square

    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    drawLine(-1.0f, -1.0f, 1.0f, 1.0f);  // Line

    // Draw 3D Shapes
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glPushMatrix();
    glTranslatef(-1.0f, 1.5f, 0.0f);  // Move triangle
    draw3DTriangle();  // Triangle
    glPopMatrix();

    glColor3f(0.0f, 1.0f, 1.0f); // Cyan color
    glPushMatrix();
    glTranslatef(1.5f, 1.5f, 0.0f);  // Move cylinder
    draw3DCylinder();  // Cylinder
    glPopMatrix();

    glutSwapBuffers();  // Swap buffers to display rendered image
}

// Reshape function to adjust window size
void reshape(int w, int h) {
    glViewport(0, 0, w, h);  // Set viewport to window dimensions
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);  // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
}

// Main function to initialize and run GLUT
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Set display mode
    glutInitWindowSize(800, 600);  // Set window size
    glutCreateWindow("Basic 2D & 3D Shapes with GLUT");

    glEnable(GL_DEPTH_TEST);  // Enable depth testing for 3D shapes

    // Register callback functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();  // Enter GLUT event processing loop
    return 0;
}
