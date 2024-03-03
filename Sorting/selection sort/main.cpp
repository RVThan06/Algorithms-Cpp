/**
 * This program demonstrates selection sort algorithm
 * implementation in c++.
*/

#include <iostream>
#include <vector>
#include <cmath>


void selection_sort(std::vector<int> &my_array)
{
    int length = my_array.size();
    int min = 0;

    for(int i=0; i<length; i++)
    {
        min = i;
        for(int j=i+1; j<length; j++)
        {
            if(my_array[min]>my_array[j])
            {
                min = j;
            }
        }
        int temp = my_array[i];
        my_array[i] = my_array[min];
        my_array[min] = temp;
    }
}

void print_array(std::vector<int> &my_array)
{
    for(const int& num: my_array)
    {
        std::cout<<num<<", ";
    }
    std::cout<<std::endl;
}


int main()
{

    // initialise vector
    std::vector<int> my_array {33, 42, 10, 14, 19, 27, 44, 26, 31};

    // selection sort
    selection_sort(my_array);

    // print the sorted list
    print_array(my_array);

    return 0;
}
