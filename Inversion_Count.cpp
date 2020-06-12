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
#include <math.h>
#include <utility>
using namespace std;

long Merge(vector<int> &A, int lo, int mid, int hi)
{
    int k = lo, i = 0, j = 0, inv_count = 0;
    vector<int> L, R;

    L = vector<int>(A.begin() + lo, A.begin() + mid);
    R = vector<int>(A.begin() + mid, A.begin() + (hi + 1));

    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            ++k, ++i;
        }
        else
        {
            inv_count += L.size() - i;
            A[k] = R[j];
            ++k, ++j;
        }
    }

    while (i < L.size())
    {
        A[k] = L[i];
        ++k, ++i;
    }

    while (j < R.size())
    {
        A[k] = R[j];
        ++k, ++j;
    }
    return inv_count;
}

long MergeSort(vector<int> &A, int lo, int hi)
{

    int inv_count = 0;

    if (lo < hi)
    {
        int mid = (hi + lo) / 2;

        inv_count += MergeSort(A, lo, mid);
        inv_count += MergeSort(A, mid + 1, hi);
        inv_count += Merge(A, lo, mid + 1, hi);
    }

    return inv_count;
}

// Complete the countInversions function below.
long countInversions(vector<int> arr)
{
    return MergeSort(arr, 0, arr.size() - 1);
}

int main()
{

    vector<int> nums = {7, 5, 3, 1};

    cout << countInversions(nums) << endl;

    return 0;
}