#include "entities.hpp"

void Entity2D::Push(const Vector2& direction, const float& speed){
	position.X += direction.X * speed;
	position.Y += direction.Y * speed;
}
