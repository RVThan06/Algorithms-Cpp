/**
 * Program to perform linear search. This algorithm has a o(n)
 * complexity during worst case since it has to iterate through
 * every other element. Suitable for small datasets.
*/

#include <iostream>
#include <vector>

// Time complexity O(n)
int linear_search(std::vector<int> &main_array, int key)
{
    int len = main_array.size();

    for(int i=0; i<len; i++)
    {
        if (main_array[i] == key)
        {
            return i;
        }
    }

    return -1;
}

// function to print search result
void print_index(int position, int key)
{
    if (position != -1)
    {
        std::cout<<"The key: "<<key<<" is located at index: "<<position<<std::endl;
    }

    else
    {
        std::cout<<"The key: "<<key<<" is not found."<<std::endl;
    }
}



int main()
{
    // 1. create a vector of numbers
    std::vector<int> age_list {34,12,17,87,47,22,90,5,39,43};

    // 2. create another list of keys to be searched
    std::vector<int> key_list {34,12,19,100,36,22,5,43,-2,-18};

    // 3. Search for each key from key list in age list
    for(int& key: key_list)
    {
        print_index(linear_search(age_list, key), key);
    }

    return 0;
}
