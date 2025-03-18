#ifndef CUBE_H
#define CUBE_H

#include <raylib.h>
#include <rlgl.h>
#include <iostream>
#include <cmath>

void CreateCube(struct Cube* cube, const Vector3& pos, float w, float h, float l, const Color& c);
void CustomDrawCube(struct Cube* cube);
void DrawRotatingCube(struct Cube* cube, float angle);
void MoveCubeLeftRight(struct Cube* cube, float dt);
void DrawCubeShadow(const Vector3& pos, float size, float angle, const Color& sc);

struct Cube
{
    Vector3 position;
    float width;
    float height;
    float length;
    Color color;
};

#endif