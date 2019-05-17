#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
typedef long long int long_int;
const int max_int = 1000000001; // value, that could't be in the table. Analog of NULL.

// function for calculation of hash    
inline int hash(long_int a_prime, long_int b_prime, int p_prime, int table_size, int key)
{
    return (((a_prime * key + b_prime) % p_prime) % table_size);
}

// class for mini-hash table in cells of main hash-table 
class Bucket
{
    vector<int> _cells;
    int size; // the size of mini-table should be greater then 4 
    long_int hash_a;
    long_int hash_b;
    int prime;

public:
    Bucket() {}
    void Initialize()
    {
        prime = 17;
        hash_a = std::rand() % prime;
        hash_b =  1 + std::rand() % (prime - 1);
    }

    // construct hash table from list of elements
    void Construct(list<int>& input)
    {
        if (input.empty())
        {
            size = 0;
            return;
        }

        size = input.size() * input.size();
        bool flag = true;

        // while there is no collisions in table 
        while (flag)
        {
            _cells.assign(size, max_int);
            Initialize();
            list<int>::iterator elem = input.begin();
            while (elem != input.end() && flag)
            {
                int hashKey = hash(hash_a, hash_b, prime, size, *elem);
                if (hashKey < 0) 
                    hashKey = - hashKe  if (_cells[hashKey] != max_int) 
                {
                    flag = false;
                    break;
                }
                _cells[hashKey] = *elem;
                ++elem;
            }

            if (!flag)
                flag = true;
            else 
                flag = false;
        }
    }

    bool Contains(int elem)
    {
        if (size == 0)
            return false;
        int hashKey = hash(hash_a, hash_b, prime, size, elem);
        if (hashKey < 0) 
            hashKey = - hashKey;
        if (_cells[hashKey] == elem)
            return true;
        return false;
    }
};

// class for main hash table
class FixedSet
{
    int _tableSize;
    long_int _hashFuncA;
    long_int _hashFuncB;
    int _primeNumber;
    vector<list<int> > _elementsInCells;
    vector<Bucket> _buckets;

public:
    FixedSet()
    {
        _primeNumber = 100013; // the maximum prime number
        _hashFuncA = std::rand() % _primeNumber;
        _hashFuncB =  1 + std::rand() % (_primeNumber - 1);
    }

    void setTableSize(int size)
    {
        _tableSize = size;
        _buckets.resize(size);
    }


