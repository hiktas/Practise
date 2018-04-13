// practise_BIT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define MAXSIZE 100005
using namespace std;
int arr[MAXSIZE] = { 0, };
//int bit2[MAXSIZE] = { 0, };

int N = 4;

void update(int bit[], int size, int d, int index)
{
	int id = index+1;
	while (id <= size)
	{
		bit[id] += d;
		id = id + (id & (-id));
	}
}

int query(int bit[], int index)
{
	int id = index+1;
	int sum = 0;
	while (id > 0)
	{
		sum += bit[id];
		id = id - (id & (-id));
	}
	return sum;
}
void constructAux(int mat[][4], int aux[][4 + 1])
{
	// Initialise Auxiliary array to 0
	for (int i = 0; i <= N; i++)
	for (int j = 0; j <= N; j++)
		aux[i][j] = 0;

	// Construct the Auxiliary Matrix
	for (int j = 1; j <= N; j++)
	for (int i = 1; i <= N; i++)
		aux[i][j] = mat[N - j][i - 1];

	return;
}
void construct2DBIT(int mat[][4], int BIT[][4 + 1])
{
	// Create an auxiliary matrix
	int aux[5][5];
	constructAux(mat, aux);

}
int main() {
	int mat[4][4] = { { 1, 2, 3, 4 },
	{ 5, 3, 8, 1 },
	{ 4, 6, 7, 5 },
	{ 2, 4, 8, 9 } };

	// Create a 2D Binary Indexed Tree
	int BIT[5][5];
	construct2DBIT(mat, BIT);
	return 0;
}