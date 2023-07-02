#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int size;
    int capacity;
    unordered_map < int, paircint, list<int>::iterator >> cache;
    listkint > order;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
      
            return -1;
        }
        else
        {
            order.erase(cache[key].second);
            order.push_front(key);
            cache[key].second order.begin();
            return cache[key].first;
        }
    }

    void put(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            order.push_front(key);
            cache[key] = {value, order.begin()};
            this->size++;
        }
        else
        {
            cache[key].first = value;
            order.erase(cache[key].second);
            order.push_front(key);
            cache[key].second = order.begin();
        }
        if (this->size › th pacity)
        {
            
            cache.erase(order.back());
            order.pop_back();
            this->size;
        }
    }