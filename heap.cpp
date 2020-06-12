#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <functional>
using namespace std;

int main()
{
    vector<int> myHeap = {4, 4, 5, 6, 23, 45, 8, 1, 2, 9, 5, 36};

    make_heap(myHeap.begin(), myHeap.end(), greater<int>());

    cout << myHeap.front() << endl;

    pop_heap(myHeap.begin(), myHeap.end(), greater<int>());
    myHeap.pop_back();

    cout << myHeap.front() << endl;

    pop_heap(myHeap.begin(), myHeap.end(), greater<int>());
    myHeap.pop_back();

    cout << myHeap.front() << endl;

    myHeap.push_back(99);
    push_heap(myHeap.begin(), myHeap.end(), greater<int>());

    cout << myHeap.front() << endl;
    return 0;
}