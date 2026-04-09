#ifndef SDL3PROJECT_CAMERA_H
#define SDL3PROJECT_CAMERA_H

struct Vector2
{
    float x , y;
};

struct Camera
{
    Camera(const Vector2& inPosition, int inWidth, int inHeight) : cameraPosition(inPosition), width(inWidth), height(inHeight) {}
    Vector2 cameraPosition;
    int width;
    int height;

};
#endif //SDL3PROJECT_CAMERA_H
