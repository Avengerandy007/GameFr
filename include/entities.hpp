#include "util/vectors.hpp"
class Entity2D{
public:
	Vector2 position;
	void Push(const Vector2& direction, const float& speed);
};

class Entity3D{
	Vector3 position;
};
