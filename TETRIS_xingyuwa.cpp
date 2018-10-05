#include "TETRIS_xingyuwa.h"

// this function draws the background color
void DrawBackground() {
	// draw backround color
	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUADS);
	glColor3ub(3, 15, 35);
	glVertex2i(0, 0);
	glColor3ub(8, 60, 73);
	glVertex2i(WINDOW_X, 0);
	glColor3ub(5, 9, 48);
	glVertex2i(WINDOW_X, WINDOW_Y);
	glColor3ub(46, 23, 104);
	glVertex2i(0, WINDOW_Y);
	glEnd();
}

// this function draws the game main frame
void DrawFrame(int score, int highest) {
	// draw main game frame
	glColor3ub(255, 255, 255);
	glBegin(GL_LINE_LOOP);
	glVertex2i(FRAME_THICK, FRAME_THICK);
	glVertex2i(FRAME_THICK + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK);
	glVertex2i(FRAME_THICK + BLOCK_SIZE * BLOCK_PER_ROW, WINDOW_Y- FRAME_THICK);
	glVertex2i(10, WINDOW_Y- FRAME_THICK);
	glEnd();

	// draw next block frame
	glBegin(GL_LINE_LOOP);
	glVertex2i(FRAME_THICK*2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK+70);
	glVertex2i(WINDOW_X - FRAME_THICK, FRAME_THICK+70);
	glVertex2i(WINDOW_X - FRAME_THICK, FRAME_THICK+70+35*4+FRAME_THICK);
	glVertex2i(FRAME_THICK*2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK + 70 + 35 * 4 + FRAME_THICK);
	glEnd();

	// draw score frame
	glBegin(GL_LINE_LOOP);
	glVertex2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK * 3 + 130 + 35 * 4 );
	glVertex2i(WINDOW_X - FRAME_THICK, FRAME_THICK * 3 + 130 + 35 * 4);
	glVertex2i(WINDOW_X - FRAME_THICK, FRAME_THICK * 3 + 130 + 35 * 4 + 70);
	glVertex2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK * 3 + 130 + 35 * 4 + 70);
	glEnd();

	// draw highest score frame
	glBegin(GL_LINE_LOOP);
	glVertex2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK * 4 + 270 + 35 * 4);
	glVertex2i(WINDOW_X - FRAME_THICK, FRAME_THICK * 4 + 270 + 35 * 4);
	glVertex2i(WINDOW_X - FRAME_THICK, FRAME_THICK * 4 + 270 + 35 * 4 + 70);
	glVertex2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK * 4 + 270 + 35 * 4 + 70);
	glEnd();

	// write "NEXT"
	glRasterPos2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW + 50, FRAME_THICK + 60);
	YsGlDrawFontBitmap20x32("NEXT");

	// write "SCORE"
	glRasterPos2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW + 40, FRAME_THICK + 280);
	YsGlDrawFontBitmap20x32("SCORE");

	// write "HIGHEST"
	glRasterPos2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW + 20, FRAME_THICK + 430);
	YsGlDrawFontBitmap20x32("HIGHEST");

	// Convert score information to c-string
	char score_str[5];
	char highest_str[5];
	sprintf(score_str, "%04d", score);
	sprintf(highest_str, "%04d", highest);

	// write score
	glRasterPos2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW + 45, FRAME_THICK + 340);
	YsGlDrawFontBitmap20x32(score_str);

	// write highest score
	glRasterPos2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW + 45, FRAME_THICK + 490);
	YsGlDrawFontBitmap20x32(highest_str);

	// draw instruction frame
	glBegin(GL_LINE_LOOP);
	glVertex2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK + 540);
	glVertex2i(WINDOW_X - FRAME_THICK, FRAME_THICK + 540);
	glVertex2i(WINDOW_X - FRAME_THICK, FRAME_THICK + 610);
	glVertex2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK + 610);
	glEnd();

	// write instruction
	glRasterPos2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW + 15, FRAME_THICK + 570);
	YsGlDrawFontBitmap16x24("Space Bar");
	glRasterPos2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW + 15, FRAME_THICK + 605);
	YsGlDrawFontBitmap16x24("= Restart");

	// write my name
	glRasterPos2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK + 660);
	YsGlDrawFontBitmap16x24("Created by:");
	glRasterPos2i(FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW, FRAME_THICK + 695);
	YsGlDrawFontBitmap16x24("XingYu Wang");
}

// this function sets the color
void SetColor(Color key) {
	switch (key) {
	case none:
		break;
	case white:
		glColor3ub(255, 255, 255);
		break;
	case red:
		glColor3ub(255,0, 0);
		break;
	case yellow:
		glColor3ub(255, 255, 0);
		break;
	case blue:
		glColor3ub(0, 255, 255);
		break;
	case pink:
		glColor3ub(255, 0, 255);
		break;
	case green:
		glColor3ub(0, 255, 0);
		break;
	case orange:
		glColor3ub(255, 128, 0);
		break;
	case grey:
		glColor3ub(125, 125, 125);
		break;
	case black:
		glColor3ub(0, 0, 0);
		break;
	}
}

// this function checks if a move is valid in the game board
bool isValid(const short x1[], const short y1[], const Board & board) {
	for (int i = 0; i < 4; i++) {
		// if x or y location of some square is out of the main board, return invalid
		if (x1[i] < 0 || x1[i] >= BLOCK_PER_ROW) return false;
		if (y1[i] > (BLOCK_PER_ROW * 2) || y1[i] < 0) return false;

		// if the x,y location on the board already has a square on it, return invalid
		if (board.p[y1[i]][x1[i]]) return false;
	}
	return true; // otherwise return ok
}

// this function draws the board
void Board::draw() {
	// for each square location, draw a square with specified color and also draw a black outline
	for (int j = 0; j <= BLOCK_PER_ROW * 2; j++) {
		for (int i = 0; i < BLOCK_PER_ROW; i++) {
			if (p[j][i] && j>0) {
				SetColor(p[j][i]);
				glBegin(GL_QUADS);
				glVertex2i(FRAME_THICK + i * BLOCK_SIZE, FRAME_THICK + (j - 1) * BLOCK_SIZE);
				glVertex2i(FRAME_THICK + (i + 1) * BLOCK_SIZE, FRAME_THICK + (j - 1) * BLOCK_SIZE);
				glVertex2i(FRAME_THICK + (i + 1) * BLOCK_SIZE, FRAME_THICK + j * BLOCK_SIZE);
				glVertex2i(FRAME_THICK + i * BLOCK_SIZE, FRAME_THICK + j * BLOCK_SIZE);
				glEnd();
				SetColor(black);
				glBegin(GL_LINE_LOOP);
				glVertex2i(FRAME_THICK + i * BLOCK_SIZE, FRAME_THICK + (j - 1) * BLOCK_SIZE);
				glVertex2i(FRAME_THICK + (i + 1) * BLOCK_SIZE, FRAME_THICK + (j - 1) * BLOCK_SIZE);
				glVertex2i(FRAME_THICK + (i + 1) * BLOCK_SIZE, FRAME_THICK + j * BLOCK_SIZE);
				glVertex2i(FRAME_THICK + i * BLOCK_SIZE, FRAME_THICK + j * BLOCK_SIZE);
				glEnd();
			}
		}
	}
}

// this function checks if a row is filled with blocks, clear them if they do, and count up scores
void Board::checkComplete() {
	short completed_row, reference;
	short number = 0;
	bool test;

	// check if any row is all filled with blocks
	for (int j = 1; j <= BLOCK_PER_ROW * 2; j++) {
		test = true;
		for (int i = 0; i < BLOCK_PER_ROW; i++) {
			test = test && p[j][i];
		}
		if (test) {
			completed_row = j;
			number++;
		}
	}

	// if none, do no more
	if (number == 0) return;

	// if there is a row filled, remove it by shifting all rows above downward
	for (int j = completed_row; j > 0; j--) {
		reference = j - number;
		if (reference < 0) reference = 0;
		for (int i = 0; i < BLOCK_PER_ROW; i++) {
			p[j][i] = p[reference][i];
		}
	}

	// update the score
	// for each row that player cleared simutaneously, the player get a score that is 3 to the power of the number of cleard rows + 1
	score += pow(3, float(number)) + 1;
}

// this function generates a random block
Block Block::generate_block() {
	Block result;
	result.show = true;

	int key = rand() % 7; // generate a random number

	// for each differnt type, initiate the location of it accordingly
	switch (key) {
	case 0:
		result.type = I;
		result.color = red;
		result.x[0] = 3;
		result.y[0] = 1;
		result.x[1] = 4;
		result.y[1] = 1;
		result.x[2] = 5;
		result.y[2] = 1;
		result.x[3] = 6;
		result.y[3] = 1;
		break;
	case 1:
		result.type = L;
		result.color = yellow;
		result.x[0] = 4;
		result.y[0] = 1;
		result.x[1] = 5;
		result.y[1] = 0;
		result.x[2] = 4;
		result.y[2] = 0;
		result.x[3] = 6;
		result.y[3] = 0;
		break;
	case 2:
		result.type = J;
		result.color = blue;
		result.x[0] = 4;
		result.y[0] = 0;
		result.x[1] = 5;
		result.y[1] = 0;
		result.x[2] = 6;
		result.y[2] = 0;
		result.x[3] = 6;
		result.y[3] = 1;
		break;
	case 3:
		result.type = O;
		result.color = pink;
		result.x[0] = 4;
		result.y[0] = 0;
		result.x[1] = 5;
		result.y[1] = 0;
		result.x[2] = 4;
		result.y[2] = 1;
		result.x[3] = 5;
		result.y[3] = 1;
		break;
	case 4:
		result.type = Z;
		result.color = green;
		result.x[0] = 4;
		result.y[0] = 0;
		result.x[1] = 5;
		result.y[1] = 0;
		result.x[2] = 5;
		result.y[2] = 1;
		result.x[3] = 6;
		result.y[3] = 1;
		break;
	case 5:
		result.type = S;
		result.color = orange;
		result.x[0] = 4;
		result.y[0] = 1;
		result.x[1] = 5;
		result.y[1] = 0;
		result.x[2] = 5;
		result.y[2] = 1;
		result.x[3] = 6;
		result.y[3] = 0;
		break;
	case 6:
		result.type = T;
		result.color = grey;
		result.x[0] = 4;
		result.y[0] = 0;
		result.x[1] = 5;
		result.y[1] = 0;
		result.x[2] = 5;
		result.y[2] = 1;
		result.x[3] = 6;
		result.y[3] = 0;
		break;
	}
	return result;
}

// this function draws the block on the "next" frame
void Block::draw_next() {
	// calculate the boundry location
	int leftside = FRAME_THICK * 2 + BLOCK_SIZE * BLOCK_PER_ROW;
	int topside = FRAME_THICK + 70;

	// for each different type, draw with different coordinate
	// but all the squares are drawn with filled quad and black outline
	switch(type){
	case I:
		for (int i = 0; i < 4; i++) {
			SetColor(color);
			glBegin(GL_QUADS);
			glVertex2i(leftside + 35 / 2 + i * 35, topside + 52);
			glVertex2i(leftside + 35 / 2 + i * 35 + 35, topside + 52);
			glVertex2i(leftside + 35 / 2 + i * 35 + 35, topside + 87);
			glVertex2i(leftside + 35 / 2 + i * 35, topside + 87);
			glEnd();
			SetColor(black);
			glBegin(GL_LINE_LOOP);
			glVertex2i(leftside + 35 / 2 + i * 35, topside + 52);
			glVertex2i(leftside + 35 / 2 + i * 35 + 35, topside + 52);
			glVertex2i(leftside + 35 / 2 + i * 35 + 35, topside + 87);
			glVertex2i(leftside + 35 / 2 + i * 35, topside + 87);
			glEnd();
		}
		break;
	case O:
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				SetColor(color);
				glBegin(GL_QUADS);
				glVertex2i(leftside + 52 + i * 35, topside + 35 + j * 35);
				glVertex2i(leftside + 87 + i * 35, topside + 35 + j * 35);
				glVertex2i(leftside + 87 + i * 35, topside + 70 + j * 35);
				glVertex2i(leftside + 52 + i * 35, topside + 70 + j * 35);
				glEnd();
				SetColor(black);
				glBegin(GL_LINE_LOOP);
				glVertex2i(leftside + 52 + i * 35, topside + 35 + j * 35);
				glVertex2i(leftside + 87 + i * 35, topside + 35 + j * 35);
				glVertex2i(leftside + 87 + i * 35, topside + 70 + j * 35);
				glVertex2i(leftside + 52 + i * 35, topside + 70 + j * 35);
				glEnd();
			}
		}
		break;
	case J:
	case L:
	case Z:
	case S:
	case T:
		for (int i = 0; i < 4; i++) {
			SetColor(color);
			glBegin(GL_QUADS);
			glVertex2i(leftside + 35 + (x[i] - 4) * 35, topside + 35 + y[i] * 35);
			glVertex2i(leftside + 35 + (x[i] - 3) * 35, topside + 35 + y[i] * 35);
			glVertex2i(leftside + 35 + (x[i] - 3) * 35, topside + 35 + (y[i] + 1) * 35);
			glVertex2i(leftside + 35 + (x[i] - 4) * 35, topside + 35 + (y[i] + 1) * 35);
			glEnd();
			SetColor(black);
			glBegin(GL_LINE_LOOP);
			glVertex2i(leftside + 35 + (x[i] - 4) * 35, topside + 35 + y[i] * 35);
			glVertex2i(leftside + 35 + (x[i] - 3) * 35, topside + 35 + y[i] * 35);
			glVertex2i(leftside + 35 + (x[i] - 3) * 35, topside + 35 + (y[i] + 1) * 35);
			glVertex2i(leftside + 35 + (x[i] - 4) * 35, topside + 35 + (y[i] + 1) * 35);
			glEnd();
		}
		break;
	}
}

// this function draws the block in the game board
void Block::draw() {
	// if the block is not shown, do nothing
	if (!show) return;
	// otherwise draw it with certain color and location
	for (int i = 0; i < 4; i++) {
		if (y[i] == 0) continue;
		SetColor(color);
		glBegin(GL_QUADS);
		glVertex2i(FRAME_THICK + x[i] * BLOCK_SIZE, FRAME_THICK + (y[i] - 1) * BLOCK_SIZE);
		glVertex2i(FRAME_THICK + (x[i] + 1) * BLOCK_SIZE, FRAME_THICK + (y[i] - 1) * BLOCK_SIZE);
		glVertex2i(FRAME_THICK + (x[i] + 1) * BLOCK_SIZE, FRAME_THICK + y[i] * BLOCK_SIZE);
		glVertex2i(FRAME_THICK + x[i] * BLOCK_SIZE, FRAME_THICK + y[i] * BLOCK_SIZE);
		glEnd();
		SetColor(black);
		glBegin(GL_LINE_LOOP);
		glVertex2i(FRAME_THICK + x[i] * BLOCK_SIZE, FRAME_THICK + (y[i] - 1) * BLOCK_SIZE);
		glVertex2i(FRAME_THICK + (x[i] + 1) * BLOCK_SIZE, FRAME_THICK + (y[i] - 1) * BLOCK_SIZE);
		glVertex2i(FRAME_THICK + (x[i] + 1) * BLOCK_SIZE, FRAME_THICK + y[i] * BLOCK_SIZE);
		glVertex2i(FRAME_THICK + x[i] * BLOCK_SIZE, FRAME_THICK + y[i] * BLOCK_SIZE);
		glEnd();
	}
}

// this function tries to flip the block
void Block::flip(const Board & board) {
	// if the block is type O, you can't raelly flip it
	if (type == O) return;

	// otherwise try to rotate them clockwise with its second square as the center of rotation
	short new_x[4];
	short new_y[4];
	short temp;

	// first get the relative x,y location of each square with respect to the second square
	for (int i = 0; i < 4; i++) {
		new_x[i] = x[i] - x[1];
		new_y[i] = y[i] - y[1];
	}
	// then rotate them clockwise
	for (int i = 0; i < 4; i++) {
		temp = new_x[i];
		new_x[i] = new_y[i];
		new_y[i] = temp * (-1);
	}
	// finally covert them back to global coordinate
	for (int i = 0; i < 4; i++) {
		new_x[i] = new_x[i] + x[1];
		new_y[i] = new_y[i] + y[1];
	}

	// before returning, we need to make sure that the new set of coordinate are valid
	// if not, we say the flip is impossible, so we still use the old coordinate
	if (isValid(new_x, new_y, board)) {
		for (int i = 0; i < 4; i++) {
			x[i] = new_x[i];
			y[i] = new_y[i];
		}
	}
}

// this function moves the block and check if it is legal
void Block::move(int direction, Board & board) {
	// if the block is not shown, do nothing
	if (!show) return;

	short new_x[4];
	short new_y[4];

	// otherwise move according to user input
	switch (direction) {
	case FSKEY_DOWN:
		for (int i = 0; i < 4; i++) {
			new_x[i] = x[i];
			new_y[i] = y[i] + 1;
		}
		break;
	case FSKEY_RIGHT:
		for (int i = 0; i < 4; i++) {
			new_x[i] = x[i] + 1;
			new_y[i] = y[i];
		}
		break;
	case FSKEY_LEFT:
		for (int i = 0; i < 4; i++) {
			new_x[i] = x[i] - 1;
			new_y[i] = y[i];
		}
		break;
	}

	// with the new coordinates, we need to make sure that they are valid
	if (isValid(new_x, new_y, board)) {
		for (int i = 0; i < 4; i++) {
			x[i] = new_x[i];
			y[i] = new_y[i];
		}
	}
	// if the coordinates are not valid, and it is resulted from a downward move
	// we know that the block has reached the end of the board
	// so we fix the block on the board and get ready to deploy the next block
	else if (direction == FSKEY_DOWN) {
		for (int i = 0; i < 4; i++) {
			board.p[y[i]][x[i]] = color;
			show = false;
		}
	}
}
