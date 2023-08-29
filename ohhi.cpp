/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 *
 * <Aaron Brown>
 * <aarbro>
 *
 * <This project replicates the game 0hh1, a logic puzzle where you fill in 
 *  an even-numbered board with one of two colors in an attempt to make all 
 *  rows and columns even and have no more then two consecutive colors.>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == UNKNOWN) {
                ++count;
            }
        }
    }
    return count;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    // write your code here
    int count = 0;
    for (int j = 0; j < size - 2; ++j) {
        if (board[row][j] == color && 
            board[row][j] == board[row][j + 1] && 
            board[row][j] == board[row][j + 2]) {
            ++count;
        }
    }
    if (count > 0) {
        return false;
    }
    else {
        return true;
    }
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    int count = 0;
    for (int i = 0; i < size - 2; ++i) {
        if (board[i][col] == color &&
            board[i][col] == board[i + 1][col] &&
            board[i][col] == board[i + 2][col]) {
            ++count;
        }
    }
    if (count > 0) {
        return false;
    }
    else {
        return true;
    }
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (!row_has_no_threes_of_color(board, size, i, RED) || 
            !row_has_no_threes_of_color(board, size, i, BLUE)) {
            ++count;
        }
    }
    for (int j = 0; j < size; ++j) {
        if (!col_has_no_threes_of_color(board, size, j, RED) || 
            !col_has_no_threes_of_color(board, size, j, BLUE)) {
            ++count;
        }
    }
    
    if (count > 0) {
        return false;
    }
    else {
        return true;
    }
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    int count = 0;
    for (int j = 0; j < size; ++j) {
        if (board[row1][j] != UNKNOWN &&
            board[row2][j] != UNKNOWN &&
            board[row1][j] == board[row2][j]) {
            ++count;
        }
    }
    if (count == size) {
        return false;
    }
    else {
        return true;
    }
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (board[i][col1] != UNKNOWN &&
            board[i][col2] != UNKNOWN &&
            board[i][col1] == board[i][col2]) {
            ++count;
        }
    }
    if (count == size) {
        return false;
    }
    else {
        return true;
    }
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int count = 0; 

    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (!rows_are_different(board, size, i, j)) {
                ++count;
            }
        }
    }
    for (int k = 0; k < size - 1; ++k) {
        for (int l = k + 1; l < size; ++l) {
            if (!cols_are_different(board, size, k, l)) {
                ++count;
            }
        }
    }
    if (count > 0) {
        return false;
    }
    else {
        return true;
    }
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    int color = 0;
    for (int i = 0; i < size; ++i) {
        if (board[row][i] == UNKNOWN && size > 2) {
            // makes sure the checks remain within the array
            // checks two after
            if (i == 0) {
                if (board[row][i + 1] == board[row][i + 2] && 
                    board[row][i + 1] != UNKNOWN) {
                    color = opposite_color(board[row][i + 1]);
                    mark_square_as(board, size, row, i, color, announce);
                }
            }
            // checks middle and two after
            else if (i == 1) {
                if ((board[row][i - 1] == board[row][i + 1] || 
                    board[row][i + 1] == board[row][i + 2]) && 
                    board[row][i + 1] != UNKNOWN) {
                    color = opposite_color(board[row][i + 1]);
                    mark_square_as(board, size, row, i, color, announce);
                }
            }
            // checks middle and two before
            else if (i == size - 2) {
                if ((board[row][i - 1] == board[row][i + 1] ||
                    board[row][i - 1] == board[row][i - 2]) && 
                    board[row][i - 1] != UNKNOWN) {
                    color = opposite_color(board[row][i - 1]);
                    mark_square_as(board, size, row, i, color, announce);
                }
            }
            // checks two before
            else if (i == size - 1) {
                if (board[row][i - 1] == board[row][i - 2] && 
                    board[row][i - 1] != UNKNOWN) {
                    color = opposite_color(board[row][i - 1]);
                    mark_square_as(board, size, row, i, color, announce);
                }
            }
            // Checks middle, two before, and two behind
            else {
                if ((board[row][i - 1] == board[row][i + 1] ||
                     board[row][i + 1] == board[row][i + 2]) && 
                     board[row][i + 1] != UNKNOWN) {
                    color = opposite_color(board[row][i + 1]);
                    mark_square_as(board, size, row, i, color, announce);
                }
                else if (board[row][i - 1] == board[row][i - 2] && 
                         board[row][i - 1] != UNKNOWN) {
                    color = opposite_color(board[row][i - 1]);
                    mark_square_as(board, size, row, i, color, announce);
                }
            }
        }
    }
    return;
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    int color = 0;
    for (int i = 0; i < size; ++i) {
        if (board[i][col] == UNKNOWN && size > 2) {
            // makes sure the checks remain within the array
            // checks two after
            if (i == 0) {
                if (board[i + 1][col] == board[i + 2][col] &&
                    board[i + 1][col] != UNKNOWN) {
                    color = opposite_color(board[i + 1][col]);
                    mark_square_as(board, size, i, col, color, announce);
                }
            }
            // checks middle and two after
            else if (i == 1) {
                if ((board[i - 1][col] == board[i + 1][col] ||
                    board[i + 1][col] == board[i + 2][col]) &&
                    board[i + 1][col] != UNKNOWN) {
                    color = opposite_color(board[i + 1][col]);
                    mark_square_as(board, size, i, col, color, announce);
                }
            }
            // checks middle and two before
            else if (i == size - 2) {
                if ((board[i - 1][col] == board[i + 1][col] ||
                    board[i - 1][col] == board[i - 2][col]) &&
                    board[i - 1][col] != UNKNOWN) {
                    color = opposite_color(board[i - 1][col]);
                    mark_square_as(board, size, i, col, color, announce);
                }
            }
            // checks two before
            else if (i == size - 1) {
                if (board[i - 1][col] == board[i - 2][col] &&
                    board[i - 1][col] != UNKNOWN) {
                    color = opposite_color(board[i - 1][col]);
                    mark_square_as(board, size, i, col, color, announce);
                }
            }
            // Checks middle, two before, and two behind
            else {
                if ((board[i - 1][col] == board[i + 1][col] ||
                    board[i + 1][col] == board[i + 2][col]) &&
                    board[i + 1][col] != UNKNOWN) {
                    color = opposite_color(board[i + 1][col]);
                    mark_square_as(board, size, i, col, color, announce);
                }
                else if (board[i - 1][col] == board[i - 2][col] &&
                    board[i - 1][col] != UNKNOWN) {
                    color = opposite_color(board[i - 1][col]);
                    mark_square_as(board, size, i, col, color, announce);
                }
            }
        }
    }

    return;
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    // write counter to see how many of one color there is
    int num_blue = 0;
    int num_red = 0;
    int color;
    for (int i = 0; i < size; ++i) {
        if (board[row][i] == BLUE) {
            ++num_blue;
        }
        else if (board[row][i] == RED) {
            ++num_red;
        }
    }
    //compare colors
    if (num_blue > num_red) {
        color = BLUE;
    }
    else if (num_red > num_blue) {
        color = RED;
    }
    else {
        color = UNKNOWN;
    }
    //replace unknown with opposite color
    if (num_blue == size / 2 || num_red == size / 2) {
        color = opposite_color(color);
        for (int i = 0; i < size; ++i) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, color, announce);
            }
        }
    }

    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    // write counter to see how many of one color there is
    int num_blue = 0;
    int num_red = 0;
    int color;
    for (int i = 0; i < size; ++i) {
        if (board[i][col] == BLUE) {
            ++num_blue;
        }
        else if (board[i][col] == RED) {
            ++num_red;
        }
    }
    //compare colors
    if (num_blue > num_red) {
        color = BLUE;
    }
    else if (num_red > num_blue) {
        color = RED;
    }
    else {
        color = UNKNOWN;
    }
    //replace unknown with opposite color
    if (num_blue == size / 2 || num_red == size / 2) {
        color = opposite_color(color);
        for (int i = 0; i < size; ++i) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, color, announce);
            }
        }
    }

    return;
}


/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // write your code here
    if (count_unknown_squares(board, size) == 0 && board_is_valid(board, size)) {
        return true;
    }
    else {
        return false;
    }
   
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    // write your code here
    if (row_input >= 1 && row_input <= size &&
        toupper(col_input) >= 'A' && toupper(col_input) <= ('A' + size - 1) &&
        (toupper(color_char) == RED_LETTER || 
         toupper(color_char) == BLUE_LETTER || 
         toupper(color_char) == UNKNOWN_LETTER)) {
        row = row_input - 1;
        col = toupper(col_input) - 'A';
        return true;
    }
    else {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    // compare to see if original board was changed
    if (original_board[row][col] == UNKNOWN) {
        //make copy board and add input
        int copy[MAX_SIZE][MAX_SIZE];
        copy_board(current_board, copy, size);
        copy[row][col] = color;

        // check if input would be invalid 
        if (!board_is_valid(copy, size)) {
            cout << "Sorry, that move violates a rule." << endl;
            return false;
        }
        else {
            return true;
        }
    }
    else {
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
}
