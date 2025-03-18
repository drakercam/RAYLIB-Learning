#include "Entity.h"

void Entity::MoveWASD(float dt, float units)
{
    if (IsKeyDown(KEY_W)) 
    { 
        std::cout << "W pressed" << std::endl; 
        MoveEntityY(-units, dt);
        std::cout << "Circle y: " << position.y << std::endl;
    }
    if (IsKeyDown(KEY_S)) 
    { 
        std::cout << "S pressed" << std::endl;
        MoveEntityY(units, dt);
        std::cout << "Circle y: " << position.y << std::endl;
    }
    if (IsKeyDown(KEY_A)) 
    { 
        std::cout << "A pressed" << std::endl;
        MoveEntityX(-units, dt);
        std::cout << "Circle x: " << position.x << std::endl;
    }
    if (IsKeyDown(KEY_D)) 
    { 
        std::cout << "D pressed" << std::endl;
        MoveEntityX(units, dt);
        std::cout << "Circle x: " << position.x << std::endl;
    }
}

void Entity::MoveArrowKeys(float dt, float units)
{
    if (IsKeyDown(KEY_UP)) 
    { 
        std::cout << "W pressed" << std::endl; 
        MoveEntityY(-units, dt);
        std::cout << "Circle y: " << position.y << std::endl;
    }
    if (IsKeyDown(KEY_DOWN)) 
    { 
        std::cout << "S pressed" << std::endl;
        MoveEntityY(units, dt);
        std::cout << "Circle y: " << position.y << std::endl;
    }
    if (IsKeyDown(KEY_LEFT)) 
    { 
        std::cout << "A pressed" << std::endl;
        MoveEntityX(-units, dt);
        std::cout << "Circle x: " << position.x << std::endl;
    }
    if (IsKeyDown(KEY_RIGHT)) 
    { 
        std::cout << "D pressed" << std::endl;
        MoveEntityX(units, dt);
        std::cout << "Circle x: " << position.x << std::endl;
    }
}

void Entity::MoveUHJK(float dt, float units)
{
    if (IsKeyDown(KEY_U)) 
    { 
        std::cout << "W pressed" << std::endl; 
        MoveEntityY(-units, dt);
        std::cout << "Circle y: " << position.y << std::endl;
    }
    if (IsKeyDown(KEY_J)) 
    { 
        std::cout << "S pressed" << std::endl;
        MoveEntityY(units, dt);
        std::cout << "Circle y: " << position.y << std::endl;
    }
    if (IsKeyDown(KEY_H)) 
    { 
        std::cout << "A pressed" << std::endl;
        MoveEntityX(-units, dt);
        std::cout << "Circle x: " << position.x << std::endl;
    }
    if (IsKeyDown(KEY_K)) 
    { 
        std::cout << "D pressed" << std::endl;
        MoveEntityX(units, dt);
        std::cout << "Circle x: " << position.x << std::endl;
    }
}

// takes the entity, and the entitys position
void Entity::CreateCircle(float x, float y, float r, std::string& id)
{
    SetPosition(x, y);
    SetCenter(x, y);
    SetAcceleration(0, 0);
    SetVelocity(0, 0);
    SetRadius(r);
    SetID(id);
}

void Entity::CustomDrawCircle(const Color& color)
{
    DrawCircle(position.x, position.y, radius, color);
    SetCenter(position.x, position.y);
}

void Entity::CustomDrawCircleWithGradient(const Color& c1, const Color& c2)
{
    DrawCircleGradient(position.x, position.y, radius, c1, c2);
    SetCenter(position.x, position.y);
}

void Entity::SetPosition(float x, float y) 
{ 
    position.x = x;
    position.y = y;
}

void Entity::SetVelocity(float x, float y)
{
    velocity.x = x;
    velocity.y = y;
}

void Entity::SetAcceleration(float x, float y)
{
    acceleration.x = x;
    acceleration.y = y;
}

void Entity::SetCenter(float x, float y)
{
    center.x = x;
    center.y = y;
}

void Entity::SetRadius(float r)
{
    radius = r;
}

void Entity::SetID(std::string& s)
{
    id = s;
}

void Entity::MoveEntityX(float unitsX, float dt)
{
    position.x += unitsX * dt;
}

void Entity::MoveEntityY(float unitsY, float dt)
{
    position.y += unitsY * dt;
}

bool Entity::CustomCheckCollisionCircles(struct Entity& e)
{
    if (CheckCollisionCircles(center, radius, e.center, e.radius))
    {
        std::cout << "Circle: " << id << " collided with Circle: " << e.id << std::endl;

        return true;
    }

    return false;
}