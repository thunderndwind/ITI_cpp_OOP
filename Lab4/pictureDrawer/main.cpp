#include "picture.h"
#include "customGraphics.h"

int main()
{
    Graphics graphics("Shapes", 800, 600);
    // graphics.setColor(Color::LIGHTBLUE);

    Circle circles[2] = {Circle(200, 200, 50), Circle(400, 400, 75)};
    Rectangle rectangles[2] = {Rectangle(100, 100, 200, 200), Rectangle(300, 300, 500, 500)};
    Line lines[2] = {Line(50, 50, 200, 200), Line(400, 50, 600, 200)};

    Picture picture;
    picture.setCircles(2, circles);
    picture.setRects(2, rectangles);
    picture.setLines(2, lines);

    graphics.cleardevice();
    picture.paint(graphics);
    graphics.refresh();

    SDL_Delay(5000);
    return 0;
}
