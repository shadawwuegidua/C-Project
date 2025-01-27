#include <stdio.h>
#include <stdlib.h>

int isSafe(int* board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

void solveNQueens(int* board, int row, int n, int* solutions) {
    if (row == n) {
        (*solutions)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            solveNQueens(board, row + 1, n, solutions);
        }
    }
}

int totalNQueens(int n) {
    int* board = (int*)malloc(n * sizeof(int));
    int solutions = 0;
    solveNQueens(board, 0, n, &solutions);
    free(board);
    return solutions;
}

int main() {
    int n;
    scanf("%d", &n);
    int result = totalNQueens(n);
    printf("%d\n", result);
    return 0;
}
