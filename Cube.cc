#include "Cube.h"

void CreateCube(struct Cube* cube, const Vector3& pos, float w, float h, float l, const Color& c)
{
    cube->position = pos;
    cube->width = w;
    cube->height = h;
    cube->length = l;
    cube->color = c;
}

void CustomDrawCube(struct Cube* cube)
{
    DrawCube(cube->position, cube->width, cube->height, cube->length, cube->color);
}

void DrawRotatingCube(struct Cube* cube, float angle)
{
    rlPushMatrix();     // we save the current transformation state
    rlTranslatef(cube->position.x, cube->position.y, cube->position.z);
    rlRotatef(angle, 0.0f, 1.0f, 0.0f);     // rotate around the y axis

    // Draw the rotated cube at the origin, since we already translated it
    DrawCubeV((Vector3){0, 0, 0}, (Vector3){cube->width, cube->height, cube->length}, cube->color);

    rlPopMatrix();  // Restore the original transformation
}

void MoveCubeLeftRight(struct Cube* cube, float dt)
{
    if (IsKeyDown(KEY_A))
    {
        cube->position.x -= 2.0f * dt;
    }

    if (IsKeyDown(KEY_D))
    {
        cube->position.x += 2.0f * dt;
    }
}

void DrawCubeShadow(const Vector3& pos, float size, float angle, const Color& sc)
{
    // Offset shadow slightly based on the rotation angle
    float shadowOffsetX = sin(DEG2RAD * angle) * 0.5f;  // Small shadow movement
    float shadowOffsetZ = cos(DEG2RAD * angle) * 0.5f;

    Vector3 shadowPos = {pos.x + shadowOffsetX, 0.01f, pos.z + shadowOffsetZ};
    DrawCubeV(shadowPos, (Vector3){size, 0.01f, size}, sc);
}