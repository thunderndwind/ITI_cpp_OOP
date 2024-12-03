#include <iostream>
#include "conio.h" // For getch() (on Windows or specific environments)

using namespace std;

#define EXTENDED 27        // ESC key
#define EXTENDED_ARROWS 91 // '[' character for extended keys
#define LEFT_ARROW 68      // Left arrow key code
#define RIGHT_ARROW 67     // Right arrow key code
#define UP_ARROW 65        // Up arrow key code
#define DOWN_ARROW 66      // Down arrow key code

int main()
{
    unsigned char key;

    key = getch(); // Get first keypress

    // Check if the key is ESC (ASCII 27)
    if (key == EXTENDED)
    {
        // It's an ESC key, so we need to check for extended arrow keys
        key = getch(); // Get next keypress

        if (key == EXTENDED_ARROWS)
        {
            // It's part of the extended sequence, now get the arrow key
            key = getch();

            // Now check for specific arrow keys
            if (key == UP_ARROW)
            {
                cout << "Up Arrow key pressed!" << endl;
            }
            else if (key == DOWN_ARROW)
            {
                cout << "Down Arrow key pressed!" << endl;
            }
            else if (key == LEFT_ARROW)
            {
                cout << "Left Arrow key pressed!" << endl;
            }
            else if (key == RIGHT_ARROW)
            {
                cout << "Right Arrow key pressed!" << endl;
            }
            else
            {
                cout << "Unknown extended key pressed!" << endl;
            }
        }
        else
        {
            cout << "ESC key pressed!" << endl;
        }
    }
    else
    {
        cout << "Other key pressed: " << (int)key << endl;
    }

    return 0;
}
