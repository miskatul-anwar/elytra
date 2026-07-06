#include <iostream>
using namespace std;

// C++ code to implement Hash Sort Algorithm
// dimension values variable, i.e. 3x3 matrix
int Dim = 3;

// function implementing Hash Sort
void HashSort(int data[][3], int N, int low) {
  int swapCount = 0, hysteresisCount = 0;
  int position = 0;
  int value;

  // condition to check if the end of data list is
  // reached
  while ((swapCount < N) && (hysteresisCount < N)) {
    value = data[(position) / Dim][(position) % Dim];
    int d = (value - low) / Dim;
    int m = (value - low) % Dim;

    // if hysteresis occurs
    if (data[d][m] == value) {

      // force push the position by 1 to avoid
      // hysteresis
      position++;
      hysteresisCount++;
    }

    // if no hysteresis, then swap the positions
    else {
      int temp = data[(position) / Dim][(position) % Dim];
      data[(position) / Dim][(position) % Dim] = data[d][m];
      data[d][m] = temp;
      swapCount++;
    }
  }
}

// Driver Code

int main() {
  int N = 1;
  int arr[][3] = {{5, 8, 1}, {9, 7, 2}, {4, 6, 3}};
  HashSort(arr, 9, N);
  cout << "The resultant sorted array is: " << endl;

  // printing the resultant sorted array
  for (int i = 0; i < 9; ++i) {
    cout << arr[i / 3][i % 3] << " ";
  }

  cout << endl;

  return 0;
}

// This code is contributed by satwik4409.