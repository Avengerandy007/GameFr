#pragma once
#include "util/vectors.hpp"
#include <inttypes.h>
class Camera2D;
class Entity2D{
public:
	Vector2 position;
	uint32_t width, height;
	void Push(const Vector2& direction, const float& speed);
	bool CollidingRect(const Entity2D& other) const;
	bool CollidingCircle(const Entity2D& other, const uint32_t desiredDistance) const;
	virtual void Update() = 0;

protected:
	/*
	 *	Make sure to put this in an update function so that the renderer knows where to draw the object
	 *	Call it with the arguments of the rect that your rendering library is using
	 *	And the template argument that represents the type that the rect uses
	 *	Ex: 
	 *		Raylib: 
	 *		AssignDimensionsToRenderingLibRect<float>(rect.x, rect.y, rect.w, rect.h);
	 */
	template<typename T>
	void AssignDimensionsToRenderingLibRect(T& X, T& Y, T& W, T& H){
		X = position.X;
		Y = position.Y;
		W = width;
		H = height;
	}
	Vector2 renderingPostion;
	bool onScreen;
	void GetRenderingPosition(const Camera2D& camera);
};

class Entity3D{
	Vector3 position;
};
