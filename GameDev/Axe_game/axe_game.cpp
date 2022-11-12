#include "raylib.h"
int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "JK's Window");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int d_circle_y{circle_y + circle_radius};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int d_axe_y{axe_y + axe_length};

    int direction(10);

    SetTargetFPS(60);
    while(WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begins

        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

        // move the axe
        axe_y += direction;
        if(axe_y > height || axe_y < 0)
        {
            direction = -direction;
        }

        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x += 10;
        }
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }
        
        EndDrawing();
    }
}