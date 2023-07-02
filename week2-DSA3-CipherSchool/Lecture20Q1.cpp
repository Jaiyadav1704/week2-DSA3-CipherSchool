#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> s;
    vector<int> nge(nums.size());
    nge[nums.size() - 1] = -1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        while (!s.empty() && nums[S.top()] < nums[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = nums(s.top());
        }
        s.push(i);
    }
    return nge;
}

vector<int> nextGreaterElements(vector<int> &a)
{
    stack<int> s;
    vector<int> nge(a.size());
    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            s.pop();
        }
        s.push(i);
    }
    nge[a.size() - 1] = -1;
    for (int i = a.size() - 2; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = a[s.top()];
        }
        s.push(i);
    }
    return nge;
}

int main(){
    
}