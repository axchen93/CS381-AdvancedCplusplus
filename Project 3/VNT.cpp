#include<iostream>
#include "Matrix.cpp"

class VNT {
private:
	Matrix<int>* table;
	int row, col, nextRow, nextCol, size, maxSize;

	void swap(int & i, int & j){
		int temp = i;
		i = j;
		j = temp;
	}
public:
	VNT(int row, int col) {
		this->row = row;
		this->col = col;
		table = new Matrix<int>(row, col);
		table->setMax();
		nextRow = nextCol = 0;
		size = 0;
		maxSize = row * col;
	}

	~VNT(){
		delete table;
	}

	bool isFull(){
		return size == maxSize;
	}

	void add(int i){
		if(isFull()) return;
		int x = nextRow, y = nextCol;
		(*table)[x][y] = i;
		size++;
		nextCol++;
		if(nextCol == col){
			nextCol = 0;
			nextRow++;
		}
		while(x-1 >= 0 && y-1 >= 0){
			int left = (*table)[x][y-1];
			int up = (*table)[x-1][y];
			if(left > up){
				if(left > i){
					swap((*table)[x][y-1], (*table)[x][y]);
					y--;
				}else return;
			}else{
				if(up > i){
					swap((*table)[x-1][y], (*table)[x][y]);
					x--;
				}else return;
			}
		}
		while(x-1 >= 0){
			int up = (*table)[x-1][y];
			if(up > i){
				swap((*table)[x-1][y], (*table)[x][y]);
				x--;
			}else return;

		}
		while(y-1 >= 0){
			int left = (*table)[x][y-1];
			if(left > i){
				swap((*table)[x][y-1], (*table)[x][y]);
				y--;
			}else return;
		}

	}

	int getMin(){
		int min = (*table)[0][0];
		size--;
		nextCol--;
		if(nextCol == -1){
			nextCol = col-1;
			nextRow--;
		}
		int x = 0, y = 0;
		(*table)[x][y] = INT_MAX;
		while(x+1<row && y+1<col){
			int right = (*table)[x][y+1];
			int down = (*table)[x+1][y];
			if(right < down){
				swap((*table)[x][y], (*table)[x][y+1]);
				y++;
			}else{
				swap((*table)[x][y], (*table)[x+1][y]);
				x++;
			}
		}
		while(x+1<row){
			int down = (*table)[x+1][y];
			if(down < INT_MAX){
				swap((*table)[x][y], (*table)[x+1][y]);
				x++;
			}else break;
		}
		while(y+1<col){
			int right = (*table)[x][y+1];
			if(right < INT_MAX){
				swap((*table)[x][y], (*table)[x][y+1]);
				y++;
			}else break;
		}
		return min;
	}

	void sort(int k[], int size){
		VNT temp(1,10);
		for(int i = 0; i<size; i++)
			temp.add(k[i]);
		for(int i = 0; i<size; i++)
			k[i] = temp.getMin();
	}

	bool find(int i){
		int x = 0, y =0;
		for(; x<row; x++){
			int current = (*table)[x][y];
			if(current == i) return true;
			if(current > i){
				x--;
				break;
			}
		}
		for(; y<col; y++){
			int current = (*table)[x][y];
			if(current == i) return true;
		}
		return false;
	}

	void print(){
		table->print();
	}

};