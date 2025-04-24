#pragma once
#include "raylib.h"
#include <iostream>
class Paddle {
    protected:
       void LimitMovement() {
           if (y <= 0) {
               y = 0;
           }
           if (y + height >= GetScreenHeight()) {
               y = GetScreenHeight() - height;
           }
       }
   
    public:
       float x, y;
       float width, height;
       int speed;
   
       void Draw() {
           DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
       }
   
       void Update() {
           if (IsKeyDown(KEY_UP)) {
               y = y - speed;
           }
           if (IsKeyDown(KEY_DOWN)) {
               y = y + speed;
           }
           LimitMovement();
       }
   };