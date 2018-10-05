#include "TETRIS_xingyuwa.h"
/*
TETRIS GAME
Created by: XingYu Wang
24-780 HW5
09/28/2018
*/

/*
HOW TO PLAY:
keyboard up = rotate block
left = move left
right = move right
down = move down
space = restart
ESC = quit
*/

int main() {
	// open window
	FsOpenWindow(16, 16, WINDOW_X, WINDOW_Y, 1);
	
	// create a game board and clear it
	Board board;
	board.clear();

	// setup seed to generate random blocks
	int seed = time(NULL);
	srand(seed);

	// create two block object, one for the current time and one for the next
	Block next_block = Block::generate_block();
	Block current_block;

	// keep track of the clock to automatically move blocks downward
	unsigned short current_cycle = 0;

	// keep track of the highest score and gameover status
	int highest_score = 0;
	bool gameover = false;
	
	// play some nice background music
	PlaySound("bg_music.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	// let's get the game started
	while (!gameover)
	{
		// keep track of the time, automatically move blocks downward after each period
		current_cycle += SLEEP_TIME;
		if (current_cycle > LOOP_TIME) {
			current_cycle %= LOOP_TIME;
			current_block.move(FSKEY_DOWN,board);
		}

		// get user input
		FsPollDevice();
		int key = FsInkey();
		switch (key) {
			// press ESC to quit the game
		case FSKEY_ESC:
			gameover = true;
			break;
			// press ESC to restart the game
		case FSKEY_SPACE:
			board.clear();
			current_block.show = false;
			break;
			// press directional keys to move the block
		case FSKEY_DOWN:
		case FSKEY_LEFT:
		case FSKEY_RIGHT:
			current_block.move(key,board);
			break;
		case FSKEY_UP:
			current_block.flip(board);
			break;
		}

		// check if the board have enough space to keep playing
		// if not, stop all the calculations and free the graphics
		if (isValid(next_block.x, next_block.y, board)) {

			// if there is no block showing in main board, make the next block be the current block
			// also generate another block for the furture step
			if (!current_block.show) {
				current_block = next_block;
				next_block = Block::generate_block();
			}

			// draw everything
			DrawBackground();
			next_block.draw_next();
			current_block.draw();
			board.draw();
			DrawFrame(board.score, highest_score);

			// check if there is any rows to clear
			board.checkComplete();

			// update highest score
			if (board.score > highest_score) highest_score = board.score;

			// refresh screen
			FsSwapBuffers(); 
		}

		FsSleep(SLEEP_TIME);
	}

	return 0;
}