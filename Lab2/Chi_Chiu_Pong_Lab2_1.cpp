// Lab Number : CS 008 Lab 2
// Student Name & ID: Chi Chiu Pong, 10413663
// Submission Date: 8/29/2024
// Time taken to complete the code: 30 minutes 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
using namespace std;

// Release memory function
// Preconditions: A is a pointer to a 2D array of integers, m is the number of rows
// Postconditions: Memory Allocated to matrix A is freed
void deleteMatrix(int** A, int m) {
	for (int i = 0; i < m; i++) {
		delete[] A[i];
	}
}

// Main function
int main() {
	// Find matrix Product C, defined by A * B = C, A in m * n, B is n * p

	// 1. get file name
	string fileName1, fileName2;
	cout << "Enter file 1 : ";
	cin >> fileName1;
	cout << "Enter file 2 : ";
	cin >> fileName2;

	// 2. Open file with matrix A and B
	ifstream file1(fileName1);
	ifstream file2(fileName2);

	// 3. Determine size of matrix A and B
	int m, n, o, p;
	file1 >> m >> n;
	file2 >> o >> p;

	// If n != o, then matrix product is not defined
	assert(n==o);

	cout << setw(3);

	// 4. Create matrix A and B
	int** A = new int* [m];
	for (int i = 0; i < m; i++) {
		A[i] = new int[n];
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
			file1 >> A[i][j];
		}
	}

	int** B = new int* [o];
	for (int i = 0; i < o; i++) {
		B[i] = new int[p];
		for (int j = 0; j < p; j++) {
			B[i][j] = 0;
			file2 >> B[i][j];
		}
	}

	// 5. Verify matrix A and B

	cout << "< Matrix 1 >" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "< Matrix 2 >" << endl;
	for (int i = 0; i < o; i++) {
		for (int j = 0; j < p; j++) {
			cout << setw(3) << B[i][j] << " ";
		}
		cout << endl;
	}

	// 6. Create matrix C

	int** C = new int* [m];
	for (int i = 0; i < m; i++) {
		C[i] = new int[p];
		for (int j = 0; j < p; j++) {
			C[i][j] = 0;
		}
	}

	// 7. Compute matrix product C = A * B

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	cout << endl;

	// 8. Verify Matrix C

	cout << "< Matrix Product of 1 & 2 >" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			cout << setw(3) << C[i][j] << " ";
		}
		cout << endl;
	}

	// 9. Release dynamic memory
	deleteMatrix(A, m);
	deleteMatrix(B, o);
	deleteMatrix(C, m);
	return EXIT_SUCCESS;
}