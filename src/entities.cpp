#include "entities.hpp"
#include <cstdint>

void Entity2D::Push(const Vector2& direction, const float& speed){
	position.X += direction.X * speed;
	position.Y += direction.Y * speed;
}


bool Entity2D::CollidingRect(const Entity2D& other) const {
    int leftA   = position.X;
    int rightA  = position.X + width;
    int topA    = position.Y;
    int bottomA = position.Y + height;

    int leftB   = other.position.X;
    int rightB  = other.position.X + other.width;
    int topB    = other.position.Y;
    int bottomB = other.position.Y + other.height;

    // If one rectangle is to the left of the other -> no collision
    if (rightA < leftB)  return false;
    if (rightB < leftA)  return false;

    // If one rectangle is above the other -> no collision
    if (bottomA < topB)   return false;
    if (bottomB < topA)   return false;

    // Otherwise there is an intersection
    return true;
}

bool Entity2D::CollidingCircle(const Entity2D& other, const uint32_t desiredDistance) const{
	Vector2 pos(position.X + (float)width / 2, position.Y + (float)height / 2);
	Vector2 otherPos(other.position.X + (float)other.width / 2, other.position.Y + (float)other.height / 2);
	if (Vector2::GetDistance(pos, other.position) < (float)desiredDistance) return true;
	else return false;
}
