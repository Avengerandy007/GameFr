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
		X = renderingPostion.X;
		Y = renderingPostion.Y;
		W = width;
		H = height;
	}
	/*
	 *	Use the following three in an update function
	 *	Their purpose is to check if this entity is visible on camera
	 */
	Vector2 renderingPostion;				//The position that reflects where on screen this entity is located
	bool onScreen;						//Is assigned in GetRenderingPosition(), use to chek if this is on screen in Update()
	void GetRenderingPosition(const Camera2D& camera);	/* Gets the position that reflects where this should be rendered
								 * and also checks if it's visible on the given camera
								*/
};

class Entity3D{
	Vector3 position;
};
