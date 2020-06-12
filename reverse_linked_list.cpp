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
#include <math.h>
#include <deque>
#include <utility>
#include <set>
#include <list>
#include <functional>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr, *prev, *temp;
        curr = head, prev = temp = nullptr;

        while (curr)
        {
            temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

int main()
{
}