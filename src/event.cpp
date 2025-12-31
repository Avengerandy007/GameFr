#include "event.hpp"
#include <iostream>

namespace Gf = GameFr;

Gf::Util::EventDataPoint::EventDataPoint(const Gf::Util::EventDataPoint& dataPoint) : position(dataPoint.position), additionalData(dataPoint.additionalData) {}

Gf::Util::EventDataPoint::EventDataPoint(const Vector2& pos, const std::array<int, 10>& data) : additionalData(data), position(pos){}

Gf::Event::Event(const Types t, const std::shared_ptr<const Entity2D> s, const std::shared_ptr<const Entity2D> r, const Util::EventDataPoint d) : type(t), sender(s), receiver(r), dataPoint(d){}

void Gf::EventQueue::CreateEvent(const std::shared_ptr<const Event>& event){
	queue[qp.Value()] = event;
	++qp;
}

std::shared_ptr<const Gf::Event> Gf::EventInterface::Listen(const std::shared_ptr<const Entity2D> parent){
	uint32_t limit = (qp.Value() <= queue->qp.Value()) ? queue->qp.Value() : 10000;
	for(; qp.Value() < limit ; ++qp){
		std::clog << "Qp: " << (int)qp.Value() << "\n";
		if (!queue->queue[qp.Value()]) break;
		if (queue->queue[qp.Value()]->receiver == parent) {
			++qp;
			return queue->queue[qp.Subtract(1)];
		}
		limit = (queue->qp.Value() != 0 && qp.Value() >= queue->queue.size() - 1) ? queue->qp.Value() : limit;
	}
	return nullptr;
}

std::shared_ptr<const Gf::Event> Gf::EventInterface::Listen(const Gf::Event::Types desiredType){
	uint32_t limit = (qp.Value() <= queue->qp.Value()) ? queue->qp.Value() : 10000;
	for(; qp.Value() < limit ; ++qp){
		std::clog << "Qp: " << (int)qp.Value() << "\n";
		if (!queue->queue[qp.Value()]) break;
		if (queue->queue[qp.Value()]->type == desiredType){
			++qp;
			return queue->queue[qp.Subtract(1)];
		}
		limit = (queue->qp.Value() != 0 && qp.Value() >= queue->queue.size() - 1) ? queue->qp.Value() : limit;
	}
	return nullptr;

}

Gf::EventInterface::EventInterface(const EventInterface& other) : queue(other.queue), qp(other.qp) {}
Gf::EventInterface::EventInterface(){}
void Gf::EventInterface::AssignQueue(const std::shared_ptr<EventQueue> q) {
	queue = q;
}
