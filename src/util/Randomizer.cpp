#include "util/Randomizer.hpp"

namespace GameFr{
	Randomizer::Randomizer(int min, int max){
		gen.seed(rd());
		distrib = std::uniform_int_distribution(min, max);
	}
	void Randomizer::ChangeRange(int min, int max){
		distrib = std::uniform_int_distribution(min, max);
	}
	int Randomizer::GetRandomNumber(){
		return distrib(gen);
	}
}
