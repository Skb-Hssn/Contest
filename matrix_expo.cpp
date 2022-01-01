#include<bits/stdc++.h>
using namespace std;

struct Matrix
{
	int row, col;
	long long mod;
	vector<vector<long long>> mat;
	Matrix() {}
	Matrix(int _row, int _col) {
		row = _row;
		col = _col;
		mod = 1e9+7;
		mat = vector<vector<long long>>(row+1, vector<long long>(col+1, 0));
	}
	Matrix(int _row, int _col, long long _mod) {
		row = _row;
		col = _col;
		mod = _mod;
		mat = vector<vector<long long>>(row+1, vector<long long>(col+1, 0));
	}
	Matrix operator*(const Matrix& m) {
		int r = m.row;
		int c = m.col;
		Matrix res(row, c, mod);
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < c; j++) {
				for(int k = 0; k < col; k++) {
					res.mat[i][j] += mat[i][k] * m.mat[k][j];
					res.mat[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

