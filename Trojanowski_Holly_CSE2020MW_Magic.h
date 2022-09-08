#ifndef MAGIC_H_
#define MAGIC_H_

#include <iostream>
#include <vector>
#include <assert.h>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <math.h>

using namespace std;

pair<int, int> wrap(int, int, int);
pair<int, int> next_rc(vector<vector<int> >, int, int);
vector<vector<int> > magic(int);
void print_magic(const vector<vector<int> >&);
bool test_magic(const vector<vector<int>> &, int &);
int row_sum(int i, const vector<vector<int>> &);
int col_sum(int j, const vector<vector<int>> &);
int diag1_sum(const vector<vector<int>> &);
int diag2_sum(const vector<vector<int>> &);

#endif