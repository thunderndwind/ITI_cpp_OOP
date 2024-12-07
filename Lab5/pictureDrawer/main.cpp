#include "picture.h"
#include "customGraphics.h"

int main()
{
    Graphics graphics("Shapes", 800, 600);

    Circle circles[4] = {Circle(200, 200, 50, Color::RED), Circle(400, 400, 75, Color::GREEN), Circle(300, 300, 50, Color::YELLOW), Circle(600, 400, 75, Color::BROWN)};
    Rectangle rectangles[2] = {Rectangle(100, 100, 200, 200, Color::BLUE), Rectangle(300, 300, 500, 500, Color::YELLOW)};
    Line lines[2] = {Line(50, 50, 200, 200, Color::MAGENTA), Line(400, 50, 600, 200, Color::CYAN)};

    Picture picture;
    picture.setCircles(4, circles);
    picture.setRects(2, rectangles);
    picture.setLines(2, lines);

    graphics.cleardevice();
    picture.paint(graphics);
    graphics.refresh();

    SDL_Delay(5000);
    return 0;
}
