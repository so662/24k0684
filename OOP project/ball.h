#pragma once
#include <iostream>
#include "raylib.h"
int player_score = 0;
int cpu_score = 0;

Color green = {0, 255, 0, 255};
Color dark_green = {0, 128, 0, 255};
Color light_green = {144, 238, 144, 255};
Color  yellow = {255, 255, 255, 255};
class Ball {
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw() {
        DrawCircle(x, y, radius, YELLOW);
    }

    void Update() {
        x += speed_x;
        y += speed_y;

        if (y + radius >= GetScreenHeight() || y - radius <= 0) {
            speed_y *= -1;
        }
        if (x + radius >= GetScreenWidth()) {
            cpu_score++;
            ResetBall();
        }
        if (x - radius <= 0) {
            player_score++;
            ResetBall();
        }
    }

    void ResetBall() {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;
        int dir[2] = {-1, 1};
        speed_x = 7 * dir[GetRandomValue(0, 1)];
        speed_y = 7 * dir[GetRandomValue(0, 1)];
    }

};
