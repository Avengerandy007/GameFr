#include "camera.hpp"
#include <cstdint>
namespace GameFr{
	Camera2D::Camera2D(const uint32_t resX, const uint32_t resY) : camMode(Modes::DONT_FOLLOW), resolutionX(resX), resolutionY(resY){}

	Camera2D::Camera2D(const Modes cameraMode, const std::shared_ptr<Entity2D>entityToFollow, const uint32_t resX, const uint32_t resY) : camMode(cameraMode), entity(entityToFollow), resolutionX(resX), resolutionY(resY){}

	void Camera2D::Update(){
		switch (camMode) {
			case Modes::DONT_FOLLOW: break;

			case Modes::FOLLOW:
				position.X = entity->position.X - (float)resolutionX / 2;
				position.Y = entity->position.Y - (float)resolutionY / 2;
				break;
			case Modes::KEEP_ON_SCREEN:
				if (entity->position.X + entity->width >= position.X + resolutionX) position.X += resolutionX;
				if (entity->position.X <= position.X) position.X -= resolutionX;
				if (entity->position.Y + entity->height >= position.Y + resolutionY) position.Y += resolutionY;
				if (entity->position.Y <= position.Y) position.Y -= resolutionY;
				break;
		}
	}
}
