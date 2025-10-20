# GameFr
Is a c++ library designed to deal with the basic, somewhat boring parts of game dev so you can get faster to the cool parts.

# Building

## Dependencies:
 - Make
 - Cmake
 - a c++ compiler

## Instructions:

```bash
git clone https://github.com/Avengerandy007/GameFr
cd GameFr
cmake -S . -B build
cd GameFr/build
cmake --build .
```

# Usage:
1. Move the bin file and the headers in the directory of your project
2. Add them to you compiler and linker

# Features:
  - Predefined enitity class with basic functions like Push, rectangular and circular collision
  - Camera system to detect if an entity is on the screen and allows you to decide what to do in each case

# Documentation:
Everything inside the library can be found using the ```GameFr``` namespace.

## ``GameFr::Entity2D``
```C++
Vector2 position;
uint32_t width, height;
void Push(const Vector2& direction, const float& speed);                           //Push the entity towards 'direction'
bool CollidingRect(const Entity2D& other) const;                                   //AABB rectangular collision with the argument
bool CollidingCircle(const Entity2D& other, const uint32_t desiredDistance) const; //Verify if 'other' is in a radius of 'desiredDistance'
virtual void Update() = 0;                                                         //Call every frame of runtime

protected:

template<typename T>
void AssignDimensionsToRenderingLibRect(T& X, T& Y, T& W, T& H);                    //Assign the rect that your rendering lib is using to the correct equivilants

Vector2 renderingPosition;                                                         //Describes where the entity should be drawn on screen
bool onScreen;                                                                     //Determine if this entity can be found inside of the view of a camera
void GetRenderingPosition(const Camera2D&  camera)                                 //Determine 'onScreen' and 'renderingPosition'
```

## GameFr::Camera2D
```C++
enum struct Modes{
    DONT_FOLLOW,
    FOLLOW,
    KEEP_ON_SCREEN
};
Vector2 position;
const uint32_t resolutionX, resolutionY;
Modes camMode;
std::shared_ptr<Entity2D> entity;                                                                                           //The entity to FOLLOW or KEEP_ON_SCREEN
Camera2D(const uint32_t resX, const uint32_t resY)                                                                          //Init the camera with DONT_FOLLOW at the desired resolution
Camera2D(const Modes cameraMode, const std::shared_ptr<Entity2D> entityToFollow, const uint32_t resX, const uint32_t resY)  //Init camera with a mode, the desired entity and resolution
virtual void Update();
```

## GameFr::Util::Vector2
```C++
float X, Y;
Vector2(const float& x, const float& y);
Vector2();                                                                //Init both to 0
static float GetDistance(const Vector2& first, const Vector2& second);    //Get the distance between 2 vectors
static Vector2 GetDiference(const Vector2& first, const Vector2& second)  //Returns a vector of xFirst - xSecond, yFirst - ySecond
```
