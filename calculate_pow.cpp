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

double Pow(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }

    double temp = Pow(x, n / 2);

    if (n % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        if (n < 0)
        {
            return (temp * temp) / x;
        }
        else
        {
            return x * temp * temp;
        }
    }
}

int main()
{

    double num1 = 2;
    int power = -4;

    cout << Pow(34.001, -3) << endl;

    return 0;
}