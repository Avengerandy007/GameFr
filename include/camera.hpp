#pragma once
#include <memory>
#include <cstdint>
#include "entities.hpp"
class Camera2D{
	enum struct Modes{
		DONT_FOLLOW,
		FOLLOW,
		KEEP_ON_SCREEN
	};
public:
	Vector2 position;
	const uint32_t resolutionX, resolutionY;
	Modes camMode;
	std::shared_ptr<Entity2D> entity;

	Camera2D(const uint32_t resX, const uint32_t resY);
	Camera2D(const Modes cameraMode, const std::shared_ptr<Entity2D>entityToFollow, const uint32_t resX, const uint32_t resY);

	virtual void Update();
};
