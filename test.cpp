/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 *
 * <Aaron Brown>
 * <aarbro>
 *
 * <This project replicates the game 0hh1, a logic puzzle where you fill in 
 *  an even-numbered board with one of two colors in an attempt to make all 
 *  rows and columns even and have no more then two consecutive colors.>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();


void startTests() {
   
   test_count_unknown_squares();
   test_row_has_no_threes_of_color();
   test_col_has_no_threes_of_color();
   test_board_has_no_threes();
   test_rows_are_different();
   test_cols_are_different();
   test_board_has_no_duplicates();
    test_solve_balance_row();
    test_solve_balance_column();
    test_solve_three_in_a_row();
    
   test_solve_three_in_a_column();
   test_board_is_solved();
   test_check_valid_input();
    test_check_valid_move();
    // add your calls to test functions here
}
// suggested order: unknown squares, no threes of color (2), no threes, solve balance (2)
// RED = X, BLUE = O

void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    // test case 2
    string test_board_2[] = {"XX--XO",
                             "OXOX-O",
                             "X---XO",
                             "OO--X-",
                             "-O--X-",
                             "---XOX"};
    int size_2 = 6;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;

    //test case 3
    string test_board_3[] = {"--------",
                             "X---OXOO",
                             "----OOXO",
                             "XOXO--OO",
                             "XXOOX-OX",
                             "--X--O-X",
                             "XO---O--",
                             "----OOX-"};
    int size_3 = 8;
    read_board_from_string(board, test_board_3, size_3);
    cout << count_unknown_squares(board, size_3) << endl;
}


void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_color_board_1[] = {"XX--", 
                                   "-OOO",
                                   "XOXO",
                                   "OXOX"};
    int size_1 = 4;
    int row_1 = 1;
    read_board_from_string(board, test_color_board_1, size_1);
    cout << "Expected 0 Actual: ";
    cout << row_has_no_threes_of_color(board, size_1, row_1, BLUE) << endl;
   
    //test case 2
    string test_color_board_2[] = {"-XOX",
                                   "-OXO",
                                   "-XOX",
                                   "XXOO"};
    int size_2 = 4;
    int row_2 = 0;
    read_board_from_string(board, test_color_board_2, size_2);
    cout << "Expected 1 Actual: ";
    cout << row_has_no_threes_of_color(board, size_2, row_2, BLUE) << endl;

    //test case 3
    string test_color_board_3[] = {"X--XXO",
                                   "OXXO--",
                                   "---OOX",
                                   "OXOOXX",
                                   "--OXXO",
                                   "OOXXOX"};
    int size_3 = 6;
    int row_3 = 3;
    read_board_from_string(board, test_color_board_3, size_3);
    cout << "Expected 1 Actual: ";
    cout << row_has_no_threes_of_color(board, size_3, row_3, BLUE) << endl;
    return;
}

void test_col_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    string test_col_board_1[] = {"X--XXO",
                                 "OXXO--",
                                 "---OOX",
                                 "OXOOXX",
                                 "--OXXO",
                                 "OOXXOX"};
    int size_1 = 6;
    int col_1 = 0;
    read_board_from_string(board, test_col_board_1, size_1);
    cout << "Expected 1 Actual: ";
    cout << col_has_no_threes_of_color(board, size_1, col_1, BLUE) << endl;
   
    string test_col_board_2[] = {"-XOX",
                                 "-OXX",
                                 "-XOX",
                                 "XXOO"};
    int size_2 = 4;
    int col_2 = 3;
    read_board_from_string(board, test_col_board_2, size_2);
    cout << "Expected 0 Actual: ";
    cout << col_has_no_threes_of_color(board, size_2, col_2, RED);
    return;
}

void test_board_has_no_threes() {
    int board[MAX_SIZE][MAX_SIZE];

    string threes_test_board_1[] = {"X--XXO",
                                    "OXXO--",
                                    "---OOX",
                                    "OXOOXX",
                                    "--OXXO",
                                    "OOXXOX"};
    int size_1 = 6;
    read_board_from_string(board, threes_test_board_1, size_1);
    cout << "Expected 0 Actual: ";
    cout << board_has_no_threes(board, size_1) << endl;

    string threes_test_board_2[] = {"-XOX",
                                    "-OXO",
                                    "-XOX",
                                    "XXOO"};
    int size_2 = 4;
    read_board_from_string(board, threes_test_board_2, size_2);
    cout << "Expected 1 Actual: ";
    cout << board_has_no_threes(board, size_2) << endl;
    
    string threes_test_board_3[] = {"-XOX",
                                    "-OXO",
                                    "-XOX",
                                    "XXXO" };
    int size_3 = 4;
    read_board_from_string(board, threes_test_board_3, size_3);
    cout << "Expected 0 Actual: ";
    cout << board_has_no_threes(board, size_3) << endl;
    
    string threes_test_board_4[] = {"-OXX",
                                    "OOOX",
                                    "-XOX",
                                    "OXXO"};
    int size_4 = 4;
    read_board_from_string(board, threes_test_board_4, size_4);
    cout << "Expected 0 Actual: ";
    cout << board_has_no_threes(board, size_4) << endl;
    return;
}

void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    string row_diff_board_1[] = {"-OXX",
                             "OOOX",
                             "-XOX",
                             "OXXO"};
    int size_1 = 4;
    int row_1 = 1;
    int row_2 = 3;
    read_board_from_string(board, row_diff_board_1, size_1);
    cout << "Expected 1 Actual: ";
    cout << rows_are_different(board, size_1, row_1, row_2) << endl;

    string row_diff_board_2[] = {"-OXX",
                             "OOOX",
                             "-OXX",
                             "OXXO"};
    int size_2 = 4;
    int row_1_2 = 0;
    int row_2_2 = 2;
    read_board_from_string(board, row_diff_board_2, size_2);
    cout << "Expected 1 Actual: ";
    cout << rows_are_different(board, size_2, row_1_2, row_2_2) << endl;

    string row_diff_board_3[] = {"OOXX",
                             "XXOX",
                             "OOXX",
                             "OXXO" };
    int size_3 = 4;
    int row_1_3 = 0;
    int row_2_3 = 2;
    read_board_from_string(board, row_diff_board_3, size_3);
    cout << "Expected 0 Actual: ";
    cout << rows_are_different(board, size_3, row_1_3, row_2_3) << endl;
    return;
}

void test_cols_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    string col_diff_board_1[] = {"OOXX",
                                 "XXOX",
                                 "OOXX",
                                 "OXXO"};
    int size_1 = 4;
    int col_1_1 = 0;
    int col_2_1 = 1;
    read_board_from_string(board, col_diff_board_1, size_1);
    cout << "Expected 1 Actual: ";
    cout << cols_are_different(board, size_1, col_1_1, col_2_1) << endl;

    string col_diff_board_2[] = {"OOXX",
                                 "XXOX",
                                 "OOXX",
                                 "OOXO"};
    int size_2 = 4;
    int col_1_2 = 0;
    int col_2_2 = 1;
    read_board_from_string(board, col_diff_board_2, size_2);
    cout << "Expected 0 Actual: ";
    cout << cols_are_different(board, size_2, col_1_2, col_2_2) << endl;

    string col_diff_board_3[] = {"X--XXO",
                                 "-XXO--",
                                 "O--OOX",
                                 "XXOOXX",
                                 "X-OXXO",
                                 "OOXXOX" };
    int size_3 = 6;
    int col_1_3 = 0;
    int col_2_3 = 4;
    read_board_from_string(board, col_diff_board_3, size_3);
    cout << "Expected 1 Actual: ";
    cout << cols_are_different(board, size_3, col_1_3, col_2_3) << endl;
    return;
}

void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];

    string diff_board_1[] = {"X--XXO",
                             "-XXO--",
                             "O--OOX",
                             "XXOOXX",
                             "X-OXXO",
                             "OOXXOX"};
    int size_1 = 6;
    read_board_from_string(board, diff_board_1, size_1);
    cout << "Expected 1 Actual: ";
    cout << board_has_no_duplicates(board, size_1) << endl;

    string diff_board_2[] = {"X--XXO",
                             "OXXOO-",
                             "O--OOX",
                             "XXOOXX",
                             "X-OXXO",
                             "OOXXOX"};
    int size_2 = 6;
    read_board_from_string(board, diff_board_2, size_2);
    cout << "Expected 0 Actual: ";
    cout << board_has_no_duplicates(board, size_2) << endl;
   
    string diff_board_3[] = {"XOOXXO",
                             "-XXO--",
                             "O--OOX",
                             "XXOOXX",
                             "XOOXXO",
                             "OOXXOX"};
    int size_3 = 6;
    read_board_from_string(board, diff_board_3, size_3);
    cout << "Expected 0 Actual: ";
    cout << board_has_no_duplicates(board, size_3) << endl;
    return;
}

void test_solve_three_in_a_row() {
    int board[MAX_SIZE][MAX_SIZE];
    
    string solve_board_1[] = {"XX--XO",
                              "OXOX-O",
                              "X---XO",
                              "OO--X-",
                              "-O--X-",
                              "---XOX"};
    int size_1 = 6;
    int row_1 = 0;
    bool announce = true;
    read_board_from_string(board, solve_board_1, size_1);
    cout << "Expected: [0][2] to be O " << endl;
    solve_three_in_a_row(board, size_1, row_1, announce);
    
    string solve_board_2[] = {"XX--XO",
                              "OXOX-O",
                              "X---XO",
                              "OO--X-",
                              "-O--X-",
                              "-X-XOX"};
    int size_2 = 6;
    int row_2 = 5;
    read_board_from_string(board, solve_board_2, size_2);
    cout << "Expected [5][2] to be O " << endl;
    solve_three_in_a_row(board, size_2, row_2, announce);

    string solve_board_3[] = {"XOXO",
                              "--OO",
                              "---X",
                              "--O-"};
    int size_3 = 4;
    int row_3 = 1;
    read_board_from_string(board, solve_board_3, size_3);
    cout << "Expected [1][1] to be X " << endl;
    solve_three_in_a_row(board, size_3, row_3, announce);

    string solve_board_4[] = {"XOXO",
                              "---O",
                              "---X",
                              "-OO-" };
    int size_4 = 4;
    int row_4 = 3;
    read_board_from_string(board, solve_board_4, size_4);
    cout << "Expected [3][0] and [3][3] to be X " << endl;
    solve_three_in_a_row(board, size_4, row_4, announce);
    // test for consecutive unknowns????
    return;
}

void test_solve_three_in_a_column() {
    int board[MAX_SIZE][MAX_SIZE];

    string solve_board_1[] = {"XX--XO",
                              "OXOX-X",
                              "X---XO",
                              "OO--X-",
                              "-O--XX",
                              "---XOX" };
    int size_1 = 6;
    int col_1 = 5;
    bool announce = true;
    read_board_from_string(board, solve_board_1, size_1);
    cout << "Expected: [3][5] to be O " << endl;
    solve_three_in_a_column(board, size_1, col_1, announce);

    string solve_board_2[] = {"XX--XO",
                              "O-O--O",
                              "X---XO",
                              "O-O-X-",
                              "-O--X-",
                              "---XOX"};
    int size_2 = 6;
    int col_2 = 2;
    read_board_from_string(board, solve_board_2, size_2);
    cout << "Expected: [2][2] to be X " << endl;
    solve_three_in_a_column(board, size_2, col_2, announce);

    string solve_board_3[] = {"XX--XO",
                              "O-OX-O",
                              "X---XO",
                              "OO-XX-",
                              "-O--X-",
                              "---XOX"};
    int size_3 = 6;
    int col_3 = 1;
    read_board_from_string(board, solve_board_3, size_3);
    cout << "Expected: [2][1] and [5][1] to be X" << endl;
    solve_three_in_a_column(board, size_3, col_3, announce);
    return;
}

void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];
    string balance_board_1[] = {"XOXO",
                                "---O",
                                "---X",
                                "-OO-"};
    int size_1 = 4;
    int row_1 = 3;
    bool announce = true;
    read_board_from_string(board, balance_board_1, size_1);
    cout << "Expected [3][0] to be X and [3][3] to be X" << endl;
    solve_balance_row(board, size_1, row_1, announce);

    string balance_board_2[] = {"XOXO",
                                "---O",
                                "-O-X",
                                "-OO-"};
    int size_2 = 4;
    int row_2 = 2;
    
    read_board_from_string(board, balance_board_2, size_2);
    cout << "Expected no change" << endl;
    solve_balance_row(board, size_2, row_2, announce);

    string balance_board_3[] = {"XOXO--",
                                "---O--",
                                "---X--",
                                "OOO---",
                                "------",
                                "------"};
    int size_3 = 6;
    int row_3 = 3;
    
    read_board_from_string(board, balance_board_3, size_3);
    cout << "Expected [3][3], [3][4], and [3][5] to be X" << endl;
    solve_balance_row(board, size_3, row_3, announce);
    return;
}

void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];
    string balance_board_1[] = {"XOXO",
                                "---O",
                                "---X",
                                "-OO-" };
    int size_1 = 4;
    int col_1 = 3;
    bool announce = true;
    read_board_from_string(board, balance_board_1, size_1);
    cout << "Expected [3][3] to be X" << endl;
    solve_balance_column(board, size_1, col_1, announce);

    string balance_board_2[] = {"XOXO--",
                                "---O--",
                                "---X--",
                                "OOO---",
                                "---O--",
                                "------" };
    int size_2 = 6;
    int col_2 = 3;

    read_board_from_string(board, balance_board_2, size_2);
    cout << "Expected [3][3] and [3][5] to be X" << endl;
    solve_balance_column(board, size_2, col_2, announce);

    string balance_board_3[] = {"XOXO--",
                                "---O--",
                                "---X--",
                                "OOO---",
                                "---O--",
                                "------"};
    int size_3 = 6;
    int col_3 = 1;

    read_board_from_string(board, balance_board_3, size_3);
    cout << "Expected no change" << endl;
    solve_balance_column(board, size_3, col_3, announce);
    return;
}

void test_board_is_solved() {
    int board[MAX_SIZE][MAX_SIZE];
    string solved_board_1[] = { "XOXO",
                                "---O",
                                "---X",
                                "-OO-" };
    int size_1 = 4;
    read_board_from_string(board, solved_board_1, size_1);
    cout << "Expected: False(0)" << endl;
    cout << board_is_solved(board, size_1) << endl;

    string solved_board_2[] = { "XOXO",
                                "OXXO",
                                "OXOX",
                                "XOOX" };
    int size_2 = 4;
    read_board_from_string(board, solved_board_2, size_2);
    cout << "Expected: True(1)" << endl;
    cout << board_is_solved(board, size_2) << endl;

    string solved_board_3[] = { "XOXO",
                                "OXXO",
                                "OXXX",
                                "XOOX" };
    int size_3 = 4;
    read_board_from_string(board, solved_board_3, size_3);
    cout << "Expected: False(0)" << endl;
    cout << board_is_solved(board, size_3) << endl;
    return;
}

void test_check_valid_input() {
    int size_1 = 4;
    int row_input_1 = 3;
    char col_input_1 = 'C';
    char color_char_1 = RED_LETTER;
    int row_1 = 0;
    int col_1 = 0;

    cout << "expected True(1) actual: row : 2 col: 2 ";
    cout << check_valid_input(size_1, row_input_1, col_input_1, color_char_1, row_1, col_1) << endl;
    cout << row_1 << " " << col_1 << endl;
    
    int size_2 = 4;
    int row_input_2 = 3;
    char col_input_2 = 'c';
    char color_char_2 = 'x';
    int row_2 = 0;
    int col_2 = 0;

    cout << "expected True(1) actual: row: 2 col: 2";
    cout << check_valid_input(size_2, row_input_2, col_input_2, color_char_2, row_2, col_2) << endl;
    cout << row_2 << " " << col_2 << endl;

    int size_3 = 4;
    int row_input_3 = 5;
    char col_input_3 = 'c';
    char color_char_3 = 'x';
    int row_3 = 0;
    int col_3 = 0;

    cout << "expected False(0) actual: ";
    cout << check_valid_input(size_3, row_input_3, col_input_3, color_char_3, row_3, col_3) << endl;

    int size_4 = 4;
    int row_input_4 = 3;
    char col_input_4 = 'e';
    char color_char_4 = 'x';
    int row_4 = 0;
    int col_4 = 0;

    cout << "expected False(0) actual: ";
    cout << check_valid_input(size_4, row_input_4, col_input_4, color_char_4, row_4, col_4) << endl;
    return;
}

void test_check_valid_move() {
    int board[MAX_SIZE][MAX_SIZE];
    int Board[MAX_SIZE][MAX_SIZE];
    string orig_board_1[] = {"X---",
                             "---O",
                             "---X",
                             "--O-"};

    string curr_board_1[] = {"XOXO",
                             "OXXO",
                             "OXOX",
                             "X-OX"};
    int size_1 = 4;
    int row_1 = 3;
    int col_1 = 1;
    int color_1 = BLUE;
    read_board_from_string(board, orig_board_1, size_1);
    read_board_from_string(Board, curr_board_1, size_1);
    cout << "expected true(1) Actual: " << endl;
    cout << check_valid_move(board, Board, size_1, row_1, col_1, color_1) << endl;

    string orig_board_2[] = {"X---",
                             "---O",
                             "---X",
                             "--O-"};

    string curr_board_2[] = {"XOXO",
                             "OXXO",
                             "OXOX",
                             "X-OX"};
    int size_2 = 4;
    int row_2 = 3;
    int col_2 = 1;
    int color_2 = RED;
    read_board_from_string(board, orig_board_2, size_2);
    read_board_from_string(Board, curr_board_2, size_2);
    cout << "expected false(0) invalid input Actual: " << endl;
    cout << check_valid_move(board, Board, size_2, row_2, col_2, color_2) << endl;

    string orig_board_3[] = {"X---",
                             "---O",
                             "---X",
                             "--O-"};

    string curr_board_3[] = {"XOXO",
                             "OXXO",
                             "OXOX",
                             "X-OX"};
    int size_3 = 4;
    int row_3 = 0;
    int col_3 = 0;
    int color_3 = BLUE;
    read_board_from_string(board, orig_board_3, size_3);
    read_board_from_string(Board, curr_board_3, size_3);
    cout << "expected false(0) change original Actual: " << endl;
    cout << check_valid_move(board, Board, size_3, row_3, col_3, color_3) << endl;
    return;
}