#include "util/vectors.hpp"
#include <cmath>

Vector2 Vector2::GetDiference(const Vector2 &first, const Vector2 &second){
	Vector2 result;
	result.X = first.X - second.X;
	result.Y = first.Y - second.Y;
	return result;
}

float Vector2::GetDistance(const Vector2& first, const Vector2& second){
	Vector2 diff = GetDiference(first, second);
	float result = sqrt(pow(diff.X, 2) + pow(diff.Y, 2));
	return result;
}
