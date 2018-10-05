#pragma comment(lib, "Winmm.lib")
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <Mmsystem.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"

#define WINDOW_X 555 // in pixel
#define WINDOW_Y 720 // in pixel
#define FRAME_THICK 10 // in pixel
#define BLOCK_PER_ROW 10 // in pixel
#define BLOCK_SIZE ((WINDOW_Y - FRAME_THICK * 2) / BLOCK_PER_ROW / 2) // in pixel
#define SLEEP_TIME 25 // in ms
#define LOOP_TIME 500 // in ms

enum Color {
	none, white, black, red, yellow, blue, pink, green, orange, grey
}; // this is the different type of color we have

enum block_type {
	I,L,J,O,Z,S,T
}; // this is the different type of block we have

void DrawBackground(); // this function draws the background color
void DrawFrame(int, int); // this function draws the game main frame
void SetColor(Color); // this function sets the color

// this structure describes the game board
struct Board {
	Color p[BLOCK_PER_ROW * 2 + 1][BLOCK_PER_ROW];
	int score;

	// this function resets the board
	void clear() {
		memset(p, 0, sizeof(p));
		score = 0;
	}

	// this function draws the board
	void draw();

	// this function checks if a row is filled with blocks, clear them if they do, and count up scores
	void checkComplete();
};

// this function checks if a move is valid in the game board
bool isValid(const short[], const short[], const Board &);

// this structure describes each different blocks
struct Block {
	short x[4]; // location of each small square
	short y[4];
	Color color;
	block_type type; // defines different types of block
	bool show = false; 

	// this function moves the block and check if it is legal
	void move(int, Board &);

	// this function tries to flip the block
	void flip(const Board &);

	// this function draws the block on the "next" frame
	void draw_next();

	// this function draws the block in the game board
	void draw();

	// this function generates a random block
	static Block generate_block();
};
