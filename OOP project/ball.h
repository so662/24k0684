#pragma once

#include "raylib.h"
#include <iostream>

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

int player_score = 0;
int cpu_score = 0;
class Ball {
    public:
       float x, y;
       int speed_x, speed_y;
       int radius;
   
       void Draw() {
           DrawCircle(x, y, radius, Yellow);
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
   
           int speed_choices[2] = {-1, 1};
           speed_x *= speed_choices[GetRandomValue(0, 1)];
           speed_y *= speed_choices[GetRandomValue(0, 1)];
       }
   };