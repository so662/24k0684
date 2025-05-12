#pragma once
#include "raylib.h"

class Paddle {
public:
    float x, y;
    float width, height;
    int speed;

    void LimitMovement() {
        if (y <= 0) y = 0;  
        if (y + height >= GetScreenHeight()) y = GetScreenHeight() - height;  
    }

public:
    Paddle(float x, float y, float width = 25, float height = 120, int speed = 7)
        : x(x), y(y), width(width), height(height), speed(speed) {}

    void Draw() {
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
    }

    void UpdatePlayer(int upKey, int downKey) {
        if (IsKeyDown(upKey)) y -= speed;  
        if (IsKeyDown(downKey)) y += speed;  
        LimitMovement();  
    }

    void UpdateAI(float ball_y) {
        if (y + height / 2 > ball_y) y -= speed;  
        if (y + height / 2 < ball_y) y += speed;  
        LimitMovement();  
    }

    float GetX() const { return x; }
    float GetY() const { return y; }
    float GetWidth() const { return width; }
    float GetHeight() const { return height; }
};