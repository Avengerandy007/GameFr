#include "util/collisionManager.hpp"
#include "GFmath.hpp"
#include "entities.hpp"
#include "event.hpp"

bool GameFr::Util::CollisionManager::CheckCollision(const std::shared_ptr<Entity2D>& first, const std::shared_ptr<Entity2D>& second){
	if (useAABB){
		if (first->CollidingRect(*second)) return true;
		return false;
	}
	if (first->CollidingCircle(*second, GameFr::Util::Math::Pythagorean(first->width, first->height) / 2)) return true;
	return false;
}

void GameFr::Util::CollisionManager::AddEntities(const std::vector<std::shared_ptr<Entity2D>>& additions){
	for (auto& ptr : additions){
		entities.emplace_back(ptr);
	}
	iterations = entities.size() * (entities.size() - 1) / 2;
}

void GameFr::Util::CollisionManager::AddEntities(const std::shared_ptr<Entity2D>& addition){
	entities.emplace_back(addition);
	iterations = entities.size() * (entities.size() - 1) / 2;
}

template<int n>
void GameFr::Util::CollisionManager::AddEntities(const std::array<std::shared_ptr<Entity2D>, n>& additions){
	for (auto& ptr : additions){
		entities.emplace_back(ptr);
	}
	iterations = entities.size() * (entities.size() - 1) / 2;
}

GameFr::Util::CollisionManager::CollisionManager(const bool useAABBCollision, const std::shared_ptr<EventQueue> eventQueue, const std::vector<std::shared_ptr<Entity2D>>& list){
	useAABB = useAABBCollision;
	eventInterface.AssignQueue(eventQueue);
	entities = list;
	iterations = entities.size() * (entities.size() - 1) / 2;
}

template<int n>
GameFr::Util::CollisionManager::CollisionManager(const bool useAABBCollision, const std::shared_ptr<EventQueue> eventQueue, const std::array<std::shared_ptr<Entity2D>, n>& list){
	useAABB = useAABBCollision;
	eventInterface.AssignQueue(eventQueue);
	entities = list;
	iterations = entities.size() * (entities.size() - 1) / 2;
}

void GameFr::Util::CollisionManager::Update(){
	for (uint32_t i = 0; i < (iterations % 2 == 0) ? iterations : (iterations - 1); i += 2){
		if (CheckCollision(entities[i], entities[i + 1])){
			EventDataPoint data(entities[i]->position, {});
			Event ev(Event::Types::COLLISION, entities[i], entities[i + 1], data);
			eventInterface.queue->CreateEvent(std::make_shared<const Event>(ev));
		}
	}
}
