#include "util/GFmath.hpp"
#include "vectors.hpp"
#include <math.h>

float GameFr::Util::Math::Pythagorean(const float a, const float b){
	return std::sqrt(a * a + b * b);
}

float GameFr::Util::Math::AngleBetweenVectors(const GameFr::Vector2 &a, const GameFr::Vector2 &b){
	return std::acos(GameFr::Vector2::DotProduct(a, b) / (a.Magnitude() * b.Magnitude())) RAD_TO_DEGREES;
}
