#include "util/Randomizer.hpp"
#include <cassert>
#include <random>

namespace GameFr{
	Randomizer::Randomizer(int min, int max){
		gen.seed(rd());
		minimum = min;
		maximum = max;
	}
	Randomizer::Randomizer(const Randomizer& other){
		gen = other.gen;
		minimum = other.minimum;
		maximum = other.maximum;
	}
	void Randomizer::ChangeRange(int min, int max){
		minimum = min;
		maximum = max;
	}
	int Randomizer::GetRandomNumber(){
		assert(minimum <= maximum);
		std::uniform_int_distribution<int> distrib(minimum, maximum);
		return distrib(gen);
	}
}
