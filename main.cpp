#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<int> v1;
    int v1Size;
    std::cout << "Enter size for v1: ";
    std::cin >> v1Size;
    std::cout << "Enter " << v1Size << " elements for v1: ";
    for (int i = 0; i < v1Size; ++i)
    {
        int val;
        std::cin >> val;
        v1.push_back(val);
    }

    std::vector<int> v2(10, 0);

    int v3Size;
    std::cout << "Enter size for v3: ";
    std::cin >> v3Size;
    std::vector<int> v3;
    for (int i = 0; i < v3Size; ++i)
    {
        v3.push_back(std::rand() % 100);
    }

    std::vector<int> v4(v1);

    std::vector<int> v5;
    if (v3.size() >= 2)
    {
        v5.assign(v3.begin() + 1, v3.end() - 1);
    }

    std::cout << "\nVector v3 elements: ";
    for (int val : v3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector v1 elements in reverse: ";
    for (auto it = v1.rbegin(); it != v1.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        v2[i] = i + 1;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v2.begin(), v2.end(), g);

    if (v2.size() >= 2)
    {
        v2.erase(v2.begin() + 1);
    }
    if (!v2.empty())
    {
        v2.pop_back();
    }

    std::cout << "Vector v2 after shuffle and removals: ";
    for (int val : v2)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<int> v4Duplicated;
    for (int val : v4)
    {
        v4Duplicated.push_back(val);
        v4Duplicated.push_back(val);
    }
    v4 = v4Duplicated;

    v5.clear();
    for (int val : v4)
    {
        if (val % 2 == 0)
        {
            v5.push_back(val / 2);
        }
    }

    std::cout << "Vector v5 resulting elements: ";
    for (int val : v5)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    int targetValue;
    std::cout << "\nEnter target value to search in v5: ";
    std::cin >> targetValue;

    std::cout << "Positions of target value in v5: ";
    int index = 0;
    int matchCount = 0;
    for (auto it = v5.begin(); it != v5.end(); ++it)
    {
        if (*it == targetValue)
        {
            std::cout << index << " ";
            ++matchCount;
        }
        ++index;
    }
    std::cout << std::endl;
    std::cout << "Total match count in v5: " << matchCount << std::endl;

    v4.swap(v5);

    std::cout << "\nAfter swap, v4 size: " << v4.size() << std::endl;
    std::cout << "After swap, v5 size: " << v5.size() << std::endl;

    return 0;
}