#include "util/vectors.hpp"
#include <math.h>
namespace GameFr{
	Vector2::Vector2(){
		X = 0;
		Y = 0;
	}

	Vector2::Vector2(const float& x, const float& y){
		X = x;
		Y = y;
	}

	bool operator==(const Vector2& l, const Vector2& r){
		if (l.X != r.X) return false;
		if (l.Y != r.Y) return false;
		return true;
	}

	Vector2 operator+(const Vector2& a, const float& b){
		return Vector2(a.X + b, a.Y + b);
	}

	Vector2 operator+(const Vector2& a, const Vector2& b){
		return Vector2(a.X + b.X, a.Y + b.Y);
	}

	Vector2 operator*(const Vector2& a, const float& b){
		return Vector2(a.X * b, a.Y * b);
	}
	
	Vector2 operator/(const Vector2& a, const float& b){
		return Vector2(a.X / b, a.Y / b);
	}

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

	float Vector2::DotProduct(const Vector2 &first, const Vector2 &second){
		return (first.X * second.X) + (first.Y * second.Y);
	}

	float Vector2::Magnitude(){
		return std::sqrt(X * X + Y * Y);
	}

	void Vector2::Normalize(){
		float magnitude = Magnitude();
		X /= magnitude;
		Y /= magnitude;
	}
}
