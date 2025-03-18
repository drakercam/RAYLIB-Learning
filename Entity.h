#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <raylib.h>

struct Entity
{
    Vector2 position;
    Vector2 center;
    Vector2 velocity;
    Vector2 acceleration;
    std::string id;
    float radius;

    // input checking
    void MoveWASD(float dt, float units);
    void MoveUHJK(float dt, float units);
    void MoveArrowKeys(float dt, float units);

    // create circle and draw
    void CreateCircle(float x, float y, float r, std::string& id);
    void CustomDrawCircle(const Color& color);
    void CustomDrawCircleWithGradient(const Color& c1, const Color& c2);

    // setters
    void SetPosition(float x, float y);
    void SetVelocity(float x, float y);
    void SetAcceleration(float x, float y);
    void SetCenter(float x, float y);
    void SetRadius(float r);
    void SetID(std::string& s);

    // moving functionality
    void MoveEntityX(float unitsX, float dt);
    void MoveEntityY(float unitsY, float dt);

    // collision
    bool CustomCheckCollisionCircles(struct Entity&);
};

#endif