/*
 * Программа для удаления строк двумерного массива, которые содержат 0
 * main.cpp
 *
 *  Created on: 4 апр. 2023 г.
 *      Author: maxim
 */
#include <iostream>
#include <string>
#include <locale.h>
#include <ctime>

template <typename T>
void delete_row(T**& arr, int raws, int cols, int raw_to_delete);

template <typename T>
void print_arr2D(T**& arr, int raws, int cols);



int main(){
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int raw = 4, col = 5;
	int** arr = new int*[raw];
	for(int i = 0; i < raw; i++){
		arr[i] = new int[col];
		for(int j = 0; j < col; j++){
			arr[i][j] = rand()%10;
		}
	}

	print_arr2D(arr, raw, col);

	bool flag = false;
	for(int i = 0; i < raw; ){
		flag = false;
		for(int j = 0; j < col; j++){
			if(arr[i][j] <= 0){
				delete_row(arr, raw, col, i);
				flag = false;
				raw--;
				break;
			}else
				flag = true;
		}
		if(flag)
			i++;
	}


	std::cout << std::endl;
	print_arr2D(arr, raw, col);


	for(int i = 0; i < raw; i++){
		delete[] arr[i];
	}

	delete[] arr;


	return 0;
}

template <typename T>
void print_arr2D(T**& arr, int raws, int cols){
	for(int i = 0; i < raws; i++){
		for(int j = 0; j < cols; j++){
			std::cout << arr[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}




template <typename T>
void delete_row(T**& arr, int raws, int cols, int raw_to_delete){
	T** temp_arr = new T*[raws - 1];
	for(int i = 0; i < raws - 1; i++){
		temp_arr[i] = new T[cols];
	}

	for (int i = 0; i < raw_to_delete; i++) {
		for (int j = 0; j < cols; j++){
			temp_arr[i][j] = arr[i][j];
		}
	}

	for (int i = raw_to_delete + 1; i < raws; i++) {
		for (int j = 0; j < cols; j++){
			temp_arr[i - 1][j] = arr[i][j];
		}
	}

	for(int i = 0; i < raws; i++){
		delete[] arr[i];
	}

	delete[] arr;

	arr = temp_arr;

}





