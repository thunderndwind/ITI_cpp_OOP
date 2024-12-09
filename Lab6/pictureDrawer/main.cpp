#include "picture.h"
#include "customGraphics.h"

int main()
{
    Graphics graphics("Shapes", 800, 600);

    Picture picture(2);
    Shape *s = new Circle(200, 200, 50, Color::RED);
    picture.addShape(s);
    picture.addShape(new Rectangle(100, 100, 200, 200, Color::BLUE));

    graphics.cleardevice();
    picture.paint(graphics);
    graphics.refresh();

    SDL_Delay(2000);
    return 0;
}
