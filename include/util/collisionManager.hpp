#include "event.hpp"
#include "entities.hpp"
#include <memory>
#include <vector>

namespace GameFr::Util{
	class CollisionManager{
	public:
		void Update();
		void AddEntities(const std::vector<std::shared_ptr<Entity2D>> additions);
		template<int n>
		void AddEntities(const std::array<std::shared_ptr<Entity2D>, n> additions);
		void SetCOllisionMode(bool useAABBCollision);
		CollisionManager(bool useAABBCollision);
	private:
		bool useAABB;
		std::vector<std::shared_ptr<Entity2D>> entities;
		bool CheckCollision(const std::shared_ptr<Entity2D> first, const std::shared_ptr<Entity2D> second);
	};
}
