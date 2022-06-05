#include "tetromino.c"

int CheckTetrominoPosition(Tetromino toCheck){ // check the position of the copied shape
	char **shape = toCheck.shape;
	int i, j;
	for(i = 0; i < toCheck.size;i++) {
        	for(j = 0; j < toCheck.size ;j++){
            		if((toCheck.col+j < 0 || toCheck.col+j >= COLS || toCheck.row+i >= ROWS)){ // out of borders
                		if(shape[i][j])
                    		return 0;
            		}
            		else if(Grid[toCheck.row+i][toCheck.col+j] && shape[i][j])
                		return 0;
        	}
    	}
    		return 1;
}

void check_lines(){ // check if a line is completed
   int i, j, sum, count=0;
    for(i=0;i<ROWS;i++){
        sum = 0;
        for(j=0;j< COLS;j++) {
            switch(Grid[i][j]){ //
		case 'S' : sum++;
			break;
		case 'T' : sum++;
			break;
		case 'I' : sum++;
			break;
		case 'L' : sum++;
			break;
		case 'J' : sum++;
			break;
		case 'O' : sum++;
			break;
		case 'Z' : sum++;
			break;
		}
        }
        if(sum==COLS){
            count++;
            int l, k;
            for(k = i;k >=1;k--)
                for(l=0;l<COLS;l++)
                    Grid[k][l]=Grid[k-1][l];
            for(l=0;l<COLS;l++)
                Grid[k][l]=0;
        }
    }
    timer-=1000; score += 100*count;
}

void WriteToGrid(){
    int i, j;
    for(i = 0; i < current.size ;i++){
        for(j = 0; j < current.size ; j++){
            if(current.shape[i][j])
                Grid[current.row+i][current.col+j] = current.shape[i][j];
        }
    }
}
