#pragma once
#include <array>
#include <cstdint>
#include <memory>
#include <vector>

namespace GameFr{
class Vector2;
class Entity2D;

	namespace Util{
		struct EventDataPoint{
			const std::unique_ptr<Vector2> position;
			const std::unique_ptr<Vector2> direction;
			const std::array<int, 10> additionalData;
		};
	}

	struct Event{
		enum struct Types;
		const Types type;
		const std::shared_ptr<Entity2D> sender;
		const std::shared_ptr<Entity2D> receiver;
		const Util::EventDataPoint dataPoint;
	};

	struct EventQueue{
		void CreateEvent(std::weak_ptr<Event> event);
		uint64_t qp; //queue pointer
		std::vector<std::weak_ptr<Event>> queue;
	};

	class EventInterface{
		EventQueue& queue;
		uint64_t localQp;
		uint64_t& qp;
	public:
		EventInterface(EventQueue& q);
		std::weak_ptr<Event> Listen();
	};

	enum struct Event::Types{
		COLLISION,
		MOVEMENT,
	};

}
