#include "event.hpp"
#include <assert.h>

namespace Gf = GameFr;

Gf::Util::EventDataPoint::EventDataPoint(const Gf::Util::EventDataPoint& dataPoint) : position(dataPoint.position), additionalData(dataPoint.additionalData) {}

Gf::Util::EventDataPoint::EventDataPoint(const Vector2& pos, const std::array<int, 10>& data) : additionalData(data), position(pos){}

Gf::Event::Event(const Types t, const std::shared_ptr<const Entity2D> s, const std::shared_ptr<const Entity2D> r, const Util::EventDataPoint d) : type(t), sender(s), receiver(r), dataPoint(d){}

void Gf::EventQueue::CreateEvent(const std::shared_ptr<const Event>& event){
	assert(event);
	if (qp >= 10000){
		qp = 0;
	}
	if (!event) throw -1;
	queue[qp] = event;
	qp++;
		
}

std::shared_ptr<const Gf::Event> Gf::EventInterface::Listen(const std::shared_ptr<const Entity2D> parent){
	assert(queue);
	qp = (qp < 9999) ? qp : 0;
	assert(qp <= 9999);
	uint32_t limit = (qp <= queue->qp) ? queue->qp : 10000;
	for(; qp < limit ; qp++){
		if (qp > 9999 && queue->qp < 9999){
			limit = queue->qp;
			qp = 0;
		}
		if (!queue->queue[qp]) break;
		if (queue->queue[qp]->receiver == parent) {
			qp++;
			return queue->queue[qp - 1];
		}
	}
	return nullptr;
}

std::shared_ptr<const Gf::Event> Gf::EventInterface::Listen(const Gf::Event::Types desiredType){
	assert(queue);
	qp = (qp < 9999) ? qp : 0;
	assert(qp <= 9999);
	uint32_t limit = (qp <= queue->qp) ? queue->qp : 10000;
	for(; qp < limit ; qp++){
		if (qp > 9999 && queue->qp < 9999){
			limit = queue->qp;
			qp = 0;
		}
		if (!queue->queue[qp]) break;
		if (queue->queue[qp]->type == desiredType) {
			qp++;
			return queue->queue[qp - 1];
		}
	}
	return nullptr;

}

Gf::EventInterface::EventInterface(const EventInterface& other) : queue(other.queue), qp(other.qp) {}
Gf::EventInterface::EventInterface(){}
void Gf::EventInterface::AssignQueue(const std::shared_ptr<EventQueue> q) {
	queue = q;
}
