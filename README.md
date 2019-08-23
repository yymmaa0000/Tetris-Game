# Tetris-Game
This is my project to create a Tetris game using C++ and OpenGL library     
Overview:  
![alt text](https://github.com/yymmaa0000/Tetris-Game/blob/master/Intro.bmp)  
Project description:  
My project is a simple version of this very famous game Tetris with the following features:
1. Simple-style interface
2. Nice background music
3. Score board and highest score count
4. Easy to re-start the game and get addicted

How to play my game:   
keyboard up = rotate block   
left = move left   
right = move right   
down = move down   
space = restart   
ESC = quit   
For each row that player cleared simultaneously, the player gets a score that is equal to (3 to the power of the number of rows cleared) + 1   

Files written by me:
1. TETRIS_main_xingyuwa.cpp
2. TETRIS_xingyuwa.cpp
3. TETRIS_xingyuwa.h

Note: if you have trouble compiling my file due to the background music, or if the music is not playing correctly, you can comment out line 43 in the main file to disable the music. The program should till run correctly without music. You can also replace the music file with the ones that you like while playing this very addictive game    

Other files that are necessary to include in order to run the program:
1. fssimplewindow.cpp
2. fssimplewindow.h
3. ysglfontdata.c
4. ysglfontdata.h
