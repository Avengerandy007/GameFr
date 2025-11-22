#include "event.hpp"
#include <iostream>

namespace Gf = GameFr;

Gf::Util::EventDataPoint::EventDataPoint(const Gf::Util::EventDataPoint& dataPoint) : position(dataPoint.position), additionalData(dataPoint.additionalData) {}

Gf::Util::EventDataPoint::EventDataPoint(const Vector2& pos, const std::array<int, 10>& data) : additionalData(data), position(pos){}

Gf::Event::Event(const Types t, const std::shared_ptr<const Entity2D> s, const std::shared_ptr<const Entity2D> r, const Util::EventDataPoint d) : type(t), sender(s), receiver(r), dataPoint(d){}

void Gf::EventQueue::CreateEvent(std::shared_ptr<const Event> event){
	try{
		if (!event) throw -1;
		queue.push_back(event);
	}
	catch(int e){
		std::cout << "Event ptr in nullptr\n";
	}
}

std::shared_ptr<const Gf::Event> Gf::EventInterface::Listen(const std::shared_ptr<const Entity2D> parent){
	try {
		if (!queue) throw -1;
		for(; qp < queue->queue.size(); qp++){
			if (queue->queue[qp]->receiver == parent) {
				qp++;
				return queue->queue[qp - 1];
			}
		}
	}
	catch(int e){
		std::cout << "queue == nullptr in Listen()\n";
	}
	return nullptr;
}

std::shared_ptr<const Gf::Event> Gf::EventInterface::Listen(const Gf::Event::Types desiredType){
	try {
		if (!queue) throw -1;
		for(; qp < queue->queue.size(); qp++){
			if (queue->queue[qp]->type == desiredType) {
				qp++;
				return queue->queue[qp - 1];
			}
		}
	}
	catch(int e){
		std::cout << "queue == nullptr in Listen()\n";
	}
	return nullptr;

}

Gf::EventInterface::EventInterface(const EventInterface& other) : queue(other.queue), qp(other.qp) {}
Gf::EventInterface::EventInterface(){}
void Gf::EventInterface::AssignQueue(const std::shared_ptr<EventQueue> q) {
	queue = q;
}
