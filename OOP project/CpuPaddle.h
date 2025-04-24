#pragma once
#include "raylib.h"
#include <iostream>
#include "paddle.h"
class CpuPaddle : public Paddle {
    public:
       void Update(int ball_y){
           if (y + height / 2 > ball_y) {
               y = y - speed;
           }
           if (y + height / 2 <= ball_y) {
               y = y + speed;
           }
           LimitMovement();
       }
   };