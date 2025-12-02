#include "util/collisionManager.hpp"
#include "GFmath.hpp"

bool GameFr::Util::CollisionManager::CheckCollision(const std::shared_ptr<Entity2D> first, const std::shared_ptr<Entity2D> second){
	if (useAABB){
		if (first->CollidingRect(*second)) return true;
		return false;
	}
	if (first->CollidingCircle(*second, GameFr::Util::Math::Pythagorean(first->width, first->height) / 2)) return true;
	return false;
}

void GameFr::Util::CollisionManager::Update(){
	
}
