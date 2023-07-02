#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElementToTheLeft(vector<int> &heights)
{
    int len = heights.size();
    vector<int> nsl(len);
    stack<int> s;
    for (int i = 0; i < len; i++)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        nsl[i] = (s.empty() ? -1 : s.top());
        s.push(i);
    }
    return nsl;
}

vector<int> nextSmallerElementToTheRight(vector<int> &heights)
{
    int len = heights.size();
    vector<int> nsr(len);
    stack<int> s;
    for (int i = len - 1; i >= 0; i--)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        nsr[i] = (s.empty() ? len : s.top());
        s.push(i);
    }
    return nsr;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> left = nextSmallerElementToTheLeft(heights);
    vector<int> right = nextSmallerElementToTheRight(heights);
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int j = left[i];
        int k = right[i];
        int width = (k - 1) - (j + 1) + 1;
        maxArea = max(maxArea, width * heights[i]);
    }
    return maxArea;
}

int main()
{
}