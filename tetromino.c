#include "grid.c"

Tetromino Copy(Tetromino toCopy){ // a function that copy and allocate the tetrominos
	Tetromino new_tetromino = toCopy;
	char **copyshape = toCopy.shape;
	new_tetromino.shape = (char**)malloc(new_tetromino.size*sizeof(char*));
	int i, j;
		for(i = 0; i < new_tetromino.size; i++){
        		new_tetromino.shape[i] = (char*)malloc(new_tetromino.size*sizeof(char));
        		for(j=0; j < new_tetromino.size; j++) {
            			new_tetromino.shape[i][j] = copyshape[i][j];
        		}
    		}
    	return new_tetromino;
}

void DeleteTetromino(Tetromino toDelete){ // delete a tetromino
	int i;
    		for(i = 0; i < toDelete.size; i++){
        		free(toDelete.shape[i]);
    		}
	free(toDelete.shape);
}

void GetNewTetromino(){ // returns random tetromino
	Tetromino new_Tetromino = Copy(Shapes[rand()%7]);
	new_Tetromino.col = rand()%(COLS-new_Tetromino.size+1);
	new_Tetromino.row = 0;
	DeleteTetromino(current);
	current = new_Tetromino;
	if(!CheckTetrominoPosition(current)){
        GameOn = 0;
    	}
}

void RotateTetromino(Tetromino toRotate){ //rotates the tetromino clockwise
    Tetromino temp = Copy(toRotate);
    int i, j, k, size;
    size = toRotate.size;
    for(i = 0; i < size ; i++){
        for(j = 0, k = size-1; j < size ; j++, k--){
                toRotate.shape[i][j] = temp.shape[k][i];
        }
    }
    DeleteTetromino(temp);
}

void MoveCurrentTetromino(int keybind){ //move the tetromino in the grid
    Tetromino temp = Copy(current);
    switch(keybind){
        case KEY_DOWN:
            temp.row++;  // move down
            if(CheckTetrominoPosition(temp))
                current.row++;
            else {
                WriteToGrid();
                check_lines(); // check full lines, after putting it down
                GetNewTetromino();
            }
            break;
        case KEY_RIGHT:
            temp.col++;  // move right
            if(CheckTetrominoPosition(temp))
                current.col++;
            break;
        case KEY_LEFT:
            temp.col--;  //move left
            if(CheckTetrominoPosition(temp))
                current.col--;
            break;
        case KEY_UP:
            RotateTetromino(temp);  // rotate piece
            if(CheckTetrominoPosition(temp))
                RotateTetromino(current);
            break;
    }
    DeleteTetromino(temp);
    ShowGrid(GameOn);
}
