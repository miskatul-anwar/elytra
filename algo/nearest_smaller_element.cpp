#include <cstddef>
#include <iostream>
#include <stack>
using namespace std;

int main(void) {

  const size_t n = 8;
  int arr[n] = {1, 3, 4, 5, 2, 3, 4, 2};

  for (int i : arr)
    cout << i << ' ';
  cout << '\n';

  stack<int> st;
  // Nearest smaller elements
  for (int i = 0; i < n; i++) {
    while (!st.empty() && st.top() >= arr[i]) {
      st.pop();
    }

    if (st.empty()) {
      cout << -1 << ' ';
    } else {
      cout << st.top() << ' ';
    }

    st.push(arr[i]);
  }

  cout << '\n';
}