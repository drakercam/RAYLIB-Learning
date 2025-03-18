#include <iostream>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <raymath.h>
#include <vector>

// custom headers for custom implementations
#include "Entity.h"
#include "Cube.h"

void FreePointers(std::vector<struct Entity*>& entities);
void CheckEntityCollisions(std::vector<struct Entity*>& entities);

int main(void)
{
    std::cout << "Raylib and Raygui project" << std::endl;

    InitWindow(1280, 720, "Raylib and Raygui project");
    SetTargetFPS(120);       // set the fps to 120

    float windowWidth = GetScreenWidth();
    float windowHeight = GetScreenHeight();
    Vector2 windowCenter = {windowWidth / 2.0f, windowHeight / 2.0f };

    // create an entity which will be drawn by a gradient circle
    struct Entity* circle_grad = new struct Entity;
    std::string id1 = "gradient circle 1";
    circle_grad->CreateCircle(200, 200, 100.0f, id1);

    // create another circle Entity which will be drawn by another gradient circle
    struct Entity* circle_grad2 = new struct Entity;
    std::string id2 = "gradient circle 2";
    circle_grad2->CreateCircle(600, 180, 150.0f, id2);

    // create an entity which will be drawn as a regular circle
    struct Entity* circle = new struct Entity;
    std::string id3 = "regular circle";
    circle->CreateCircle(400, 400, 100.0f, id3);

    std::vector<struct Entity*> entities;
    entities.push_back(circle_grad);
    entities.push_back(circle_grad2);
    entities.push_back(circle);

    // create a cube to draw to the screen
    struct Cube* cube1 = new struct Cube;
    Vector3 pos1 = {-4, 1, 0};
    CreateCube(cube1, pos1, 2.0f, 2.0f, 2.0f, DARKPURPLE);

    // create a cube to draw to the screen
    struct Cube* cube2 = new struct Cube;
    Vector3 pos2 = {0, 1, 0};
    CreateCube(cube2, pos2, 2.0f, 2.0f, 2.0f, DARKGREEN);

    // create another cube to draw to the screen
    struct Cube* cube3 = new struct Cube;
    Vector3 pos3 = {4, 1, 0};
    CreateCube(cube3, pos3, 2.0f, 2.0f, 2.0f, DARKBLUE);

    // setup the camera
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f }; // Move camera back
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Look at origin
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    float delta_time;
    float rotation_angle1 = 0.0f;
    float rotation_angle2 = 0.0f;
    float rotation_angle3 = 0.0f;

    // set up text to be drawn at top of screen
    const char* text = "Cube Rendering Simulation";  // Your text
    int fontSize = 32;
    int textWidth = MeasureText(text, fontSize);
    int centerX = (GetScreenWidth() - textWidth) / 2;

    SetExitKey(KEY_Q);      // set a custom program exit key to mark the window to close

    while (!WindowShouldClose())
    {
        delta_time = GetFrameTime();
        rotation_angle1 += 45.0f * delta_time;
        rotation_angle2 += 90.0f * delta_time;
        rotation_angle3 += 135.0f * delta_time;

        BeginDrawing();
        ClearBackground(MAROON);

        // // handle input
        // circle->MoveWASD(delta_time, 1000.0f);
        // circle_grad->MoveArrowKeys(delta_time, 800.0f);
        // circle_grad2->MoveUHJK(delta_time, 900.0f);

        // // check collisions
        // CheckEntityCollisions(entities);

        // // 2D rendering
        // circle->CustomDrawCircle(DARKPURPLE);
        // circle_grad->CustomDrawCircleWithGradient(RED, BLUE);
        // circle_grad2->CustomDrawCircleWithGradient(MAGENTA, PINK);

        // 3D rendering movement checks
        MoveCubeLeftRight(cube1, delta_time);
        MoveCubeLeftRight(cube2, delta_time);
        MoveCubeLeftRight(cube3, delta_time);

        // 3D rendering for a rotating cube
        BeginMode3D(camera);

        // draw the cubes shadows
        Color shadowColor = Fade(BLACK, 0.33f);

        DrawCubeShadow(cube1->position, 2.0f, rotation_angle1, shadowColor);
        DrawCubeShadow(cube2->position, 2.0f, rotation_angle2, shadowColor);
        DrawCubeShadow(cube3->position, 2.0f, rotation_angle3, shadowColor);

        // draw the rotating cubes
        DrawRotatingCube(cube1, rotation_angle1);
        DrawRotatingCube(cube2, rotation_angle2);
        DrawRotatingCube(cube3, rotation_angle3);
        EndMode3D();

        // draw the fps
        DrawFPS(0, 0);

        // draw some text
        DrawText(text, centerX, 5, fontSize, BEIGE);

        EndDrawing();
    }

    CloseWindow();      // free up any memory created by the window

    FreePointers(entities);
    delete cube1;
    delete cube2;
    delete cube3;

    return 0;
}

void FreePointers(std::vector<struct Entity*>& entities)
{
    for (auto entity : entities)
    {
        delete entity;
    }
}

void CheckEntityCollisions(std::vector<struct Entity*>& entities)
{
    if (entities.empty())
    {
        return;
    }

    for (int i = 0; i < entities.size(); ++i)
    {
        struct Entity* current = entities[i];

        for (int j = i + 1; j < entities.size(); ++j)
        {
            struct Entity* other = entities[j];

            current->CustomCheckCollisionCircles(*other);
        }
    }
}