#include "entities.hpp"
#include "camera.hpp"
#include "event.hpp"
#include "util/vectors.hpp"
#include <cstdint>
#include <memory>
namespace GameFr{

	Entity2D::Entity2D(){}

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

	    if (rightA < leftB)  return false;
	    if (rightB < leftA)  return false;

	    if (bottomA < topB)   return false;
	    if (bottomB < topA)   return false;

	    return true;
	}

	std::shared_ptr<const Entity2D> Entity2D::GetPtr() const{
		return shared_from_this();
	}

	bool Entity2D::CollidingCircle(const Entity2D& other, const uint32_t desiredDistance) const{
		Vector2 pos(position.X + (float)width / 2, position.Y + (float)height / 2);
		Vector2 otherPos(other.position.X + (float)other.width / 2, other.position.Y + (float)other.height / 2);
		if (Vector2::GetDistance(pos, other.position) < (float)desiredDistance){
			return true;
		}
		else return false;
	}

	void Entity2D::GetRenderingPosition(const Camera2D& camera){
		renderingPosition = Vector2(position.X - camera.position.X, position.Y - camera.position.Y);
		if (renderingPosition.X + width < 0 || renderingPosition.Y + height < 0){
			onScreen = false;
			return;
		}
		if (renderingPosition.X > camera.resolutionX || renderingPosition.Y > camera.resolutionY){
			onScreen = false;
			return;
		}
		onScreen = true;
	}
}
