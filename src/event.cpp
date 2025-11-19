#include "event.hpp"

namespace Gf = GameFr;

Gf::Util::EventDataPoint::EventDataPoint(const Gf::Util::EventDataPoint& dataPoint) : position(dataPoint.position), additionalData(dataPoint.additionalData) {}

Gf::Util::EventDataPoint::EventDataPoint(const Vector2& pos, const std::array<int, 10>& data) : additionalData(data), position(pos){}

Gf::Event::Event(const Types t, const std::shared_ptr<const Entity2D> s, const std::shared_ptr<const Entity2D> r, const Util::EventDataPoint d) : type(t), sender(s), receiver(r), dataPoint(d){}

void Gf::EventQueue::CreateEvent(std::shared_ptr<const Event> event){
	qp++;
	queue.push_back(event);
}

std::shared_ptr<const Gf::Event> Gf::EventInterface::Listen(const std::shared_ptr<const Entity2D> parent){
	for(; localQp <= *qp; localQp++){
		if (queue->queue[localQp]->receiver == parent) return queue->queue[localQp];
	}
	return nullptr;
}

Gf::EventInterface::EventInterface(const EventInterface& other) : queue(other.queue), qp(other.qp), localQp(other.localQp) {}
Gf::EventInterface::EventInterface(){}
void Gf::EventInterface::AssignQueue(const std::shared_ptr<EventQueue> q){
	queue = q;
}
