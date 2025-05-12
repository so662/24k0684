#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "ball.h"
#include "paddle.h"

using namespace std;

class Game {
private:
    Ball ball;
    Paddle player;
    Paddle cpu;     

    string input_name1 = "";
    string input_name2 = "";
    string player_name1 = "";
    string player_name2 = "";
    string winner_name = "";
    bool in_menu = true;
    bool entering_name = false;
    bool game_started = false;
    bool game_over = false;
    bool multiplayer = false;
    int current_name_index = 1;

    Sound collisionSound;
    Sound gameOverSound;
    Sound startSound;  

    void SaveMatchResult(const string& name1, int score1, const string& name2, int score2) {
        ofstream file("scores.txt", ios::app);
        if (file.is_open()) {
            file << name1 << " : " << score1 << " vs " << name2 << " : " << score2 << "\n";
            file.close();
        }
    }

    void LoadMatchHistory() {
        ifstream file("scores.txt");
        string line;
        int y = 100;

        ClearBackground(DARKBLUE);
        DrawText("MATCH HISTORY", 100, 40, 40, YELLOW);

        while (getline(file, line)) {
            DrawText(line.c_str(), 100, y, 30, WHITE);
            y += 40;
            if (y > GetScreenHeight() - 40) break;
        }

        DrawText("Press ENTER to return to menu", 100, y + 40, 20, LIGHTGRAY);
        file.close();
    }

    void ApplyDifficultySettings()  {
            
            cpu.speed = 7;
            ball.speed_x = (ball.speed_x > 0) ? 8 : -8;
            ball.speed_y = (ball.speed_y > 0) ? 7 : -7;
        }


public:
    Game()
        : player(1280 - 35, 800 / 2 - 60), 
          cpu(10, 800 / 2 - 60) {          
        InitWindow(1280, 800, "Pong Game");
        SetTargetFPS(60);

        InitAudioDevice();
        collisionSound = LoadSound("bounce.mp3");
        gameOverSound = LoadSound("game-over.mp3");
        startSound = LoadSound("start.mp3");  

        PlaySound(startSound);  
    }

    ~Game() {
        UnloadSound(collisionSound);
        UnloadSound(gameOverSound);
        UnloadSound(startSound);  
        CloseAudioDevice();
        CloseWindow();
    }

    void Run() {
        while (!WindowShouldClose()) {
            BeginDrawing();

            if (in_menu) {
                ClearBackground(DARKBLUE);
                DrawText("PONG GAME", 1280 / 2 - 150, 800 / 4, 60, YELLOW);
                DrawText("1. Play with Computer", 1280 / 2 - 150, 800 / 2 - 40, 30, WHITE);
                DrawText("2. Play Multiplayer", 1280 / 2 - 150, 800 / 2, 30, WHITE);
                DrawText("3. View Match History", 1280 / 2 - 150, 800 / 2 + 40, 30, WHITE);
                DrawText("4. Exit", 1280 / 2 - 150, 800 / 2 + 80, 30, WHITE);
                DrawText("Created by Hammad and Soofiyan", 1280 / 2 - 200, 800 - 50, 20, LIGHTGRAY);

                if (IsKeyPressed(KEY_ONE)) {
                    multiplayer = false;
                    entering_name = true;
                    current_name_index = 1;
                    in_menu = false;
                } else if (IsKeyPressed(KEY_TWO)) {
                    multiplayer = true;
                    entering_name = true;
                    current_name_index = 1;
                    in_menu = false;
                } else if (IsKeyPressed(KEY_THREE)) {
                    while (!WindowShouldClose() && !IsKeyPressed(KEY_ENTER)) {
                        BeginDrawing();
                        LoadMatchHistory();
                        EndDrawing();
                    }
                } else if (IsKeyPressed(KEY_FOUR)) {
                    break;
                }
                   } else if (entering_name) {
                ClearBackground(DARKBLUE);
                DrawText("Enter Name:", 1280 / 2 - 200, 300, 40, YELLOW);
                string& current_input = (current_name_index == 1) ? input_name1 : input_name2;
                DrawText(current_input.c_str(), 1280 / 2 - 200, 360, 40, WHITE);

                int key = GetCharPressed();
                if (key >= 32 && key <= 125) {
                    current_input += (char)key;
                }
                if (IsKeyPressed(KEY_BACKSPACE) && !current_input.empty()) {
                    current_input.pop_back();
                }
                if (IsKeyPressed(KEY_ENTER)) {
                    if (current_name_index == 1 && multiplayer) {
                        current_name_index = 2;
                    } else {
                        player_name1 = input_name1;
                        player_name2 = multiplayer ? input_name2 : "CPU";
                        entering_name = false;
                        game_started = true;

                        player.width = 25;
                        player.height = 120;
                        player.x = 1280 - player.width - 10;
                        player.y = 800 / 2 - player.height / 2;

                        cpu.width = 25;
                        cpu.height = 120;
                        cpu.x = 10;
                        cpu.y = 800 / 2 - cpu.height / 2;

                        ball.radius = 20;
                        ball.x = 1280 / 2;
                        ball.y = 800 / 2;
                        ball.speed_x = 7;
                        ball.speed_y = 7;
                        ball.speed_x = (ball.speed_x > 0) ? 8 : -8;
                        ball.speed_y = (ball.speed_y > 0) ? 7 : -7;
                    }
                }
            } else if (game_started && !game_over) {
                ClearBackground(DARKGREEN);
                DrawRectangle(1280 / 2, 0, 1280 / 2, 800, light_green);
                DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 100, LIGHTGRAY);
                DrawLine(1280 / 2, 0, 1280 / 2, 800, WHITE);

                ball.Update();
                player.UpdatePlayer(KEY_UP, KEY_DOWN);  
                if (multiplayer) {
                    cpu.UpdatePlayer(KEY_W, KEY_S);  
                } else {
                    cpu.UpdateAI(ball.y);  
                }

            
                if (CheckCollisionCircleRec({ ball.x, ball.y }, ball.radius, { player.GetX(), player.GetY(), player.GetWidth(), player.GetHeight() })) {
                    ball.speed_x *= -1;
                    PlaySound(collisionSound);
                }
                if (CheckCollisionCircleRec({ ball.x, ball.y }, ball.radius, { cpu.GetX(), cpu.GetY(), cpu.GetWidth(), cpu.GetHeight() })) {
                    ball.speed_x *= -1;
                    PlaySound(collisionSound);
                }

                
                if (ball.x < 0) {  
                    cpu_score++; 
                    ball.x = 1280 / 2;
                    ball.y = 800 / 2;
                    ball.speed_x *= -1;  
                } else if (ball.x > 1280) {  
                    player_score++;  
                    
                    ball.x = 1280 / 2;
                    ball.y = 800 / 2;
                    ball.speed_x *= -1;  
                }

                
                if (player_score >= 10 || cpu_score >= 10) {
                    winner_name = (player_score >= 10) ? player_name1 : player_name2;
                    game_over = true;
                    PlaySound(gameOverSound);
                    SaveMatchResult(player_name1, player_score, player_name2, cpu_score);
                }

                DrawRectangle(0, 0, 1280, 100, DARKBLUE);
                DrawText(TextFormat("%s: %i", player_name2.c_str(), cpu_score), 1280 / 4 - 50, 20, 40, WHITE);
                DrawText(TextFormat("%s: %i", player_name1.c_str(), player_score), 3 * 1280 / 4 - 50, 20, 40, WHITE);

            
                ball.Draw();
                cpu.Draw();
                player.Draw();
            } else if (game_over) {
                ClearBackground(DARKBLUE);
                DrawText("GAME OVER!", 1280 / 2 - 200, 800 / 2 - 100, 60, RED);
                DrawText(TextFormat("Winner: %s", winner_name.c_str()), 1280 / 2 - 200, 800 / 2, 40, WHITE);
                DrawText("Press ENTER to return to Main Menu", 1280 / 2 - 250, 800 / 2 + 80, 30, GRAY);

                if (IsKeyPressed(KEY_ENTER)) {
                    game_started = false;
                    game_over = false;
                    in_menu = true;
                    input_name1 = "";
                    input_name2 = "";
                    player_score = 0;
                    cpu_score = 0;
                }
            }

            EndDrawing();
        }
    }
};

int main() {
    Game game;
    game.Run();
    return 0;
}
