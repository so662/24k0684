Project Report
Project Title
Raylib-Based Pong Game with AI and Multiplayer Support
Group Members
Soofiyan (24K-0684)
Hammad Younis (24K-0689)
1. Introduction

This report documents the design, development, and implementation of a 2D Pong game built in C++ using the Raylib library. The game includes both single-player (against CPU) and two-player (same machine) modes. The game includes an intro interface, a winning condition, and file storage for scores.

2. Objectives

- Implement a Raylib-based Pong game with two control modes (CPU and multiplayer).
- Add user interface for game start mode selection.
- Track and store player names and scores using file I/O.
- Declare winner based on reaching score 15 first.

3. Tools and Technologies

- Language: C++
- Library: Raylib
- IDE: Visual Studio Code / Visual Studio
- Compilation: g++
- OS: Windows (MSYS2 with raylib)

4. Implementation Details

The code was divided across multiple header and source files:
- ball.h: Handles ball movement, scoring, and collisions.
- paddle.h: Base class for paddles with movement handling.
- CpuPaddle.h: Inherits from Paddle; adds basic AI.
- main.cpp: Main game loop, initialization, drawing, and interaction.

Additional planned features:
- Interface for choosing play mode.
- File handling for saving player names and highest score.
- Declaration of winner on first to reach 15 points.

5. Contribution Distribution

- Soofiyan: Raylib setup, main game logic, file handling.
- Hammad Younis: Class header implementation, menu interface creation, layout design.

6. Challenges Faced

- Configuring Raylib with C++ and VS Code on Windows.
- Handling collision precision and AI paddle movement.
- Designing simple yet clear interface layout.

7. Conclusion

The project successfully implemented a Pong game with required features. The use of Raylib for graphics and C++ for structure provided a strong base. The game meets all stated objectives and is ready for further polish.

