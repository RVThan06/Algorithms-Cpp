/*
 This file contains quick sort implementation in C++.
 The algorithm has two section, one to partion and sort the array based on the pivot.
 The second function recursively performs the partion on the left and right subarray
 of the pivot.
*/

#include <iostream>
#include <vector>


// Fucntion to sort using pivot and return index of pivot.
int partition(std::vector<int> &main_array, int start, int end)
{
    // last index is the pivot and first index will be p_index
    int p_index = start;

    // terate to compare all element from start till element before pivot
    for(int i=start; i<end; i++)
    {
        // if item less than pivot swap it with item at p_index
        if(main_array[i] < main_array[end])
        {
            int temp = main_array[i];
            main_array[i] = main_array[p_index];
            main_array[p_index] = temp;
            p_index++;
        }
    }

    // upon completing sorting based on pivot, insert pivot in middle
    // swap pivot with p_index element
    int temp = main_array[p_index];
    main_array[p_index] = main_array[end];
    main_array[end] = temp;

    return p_index;
}

// To divide the arary and recursively call partition to sort.
void quick_sort(std::vector<int> &main_array, int start, int end)
{
    // if only there are at least 2 elements in subara
    if(start<end)
    {
        // partition and sort to the left and right and get pivot index
        int pivot = partition(main_array, start, end);
        // call partition recursively to sort left subarray of pivot
        quick_sort(main_array, start, pivot-1);
        // call partition recursively to sort right subarray of pivot
        quick_sort(main_array, pivot+1, end);
    }

    // remainder: we pass the same array so, rearrangement happens without
    // splicing the arrays into subarrays in memory, instead we provide
    // a range for the indices
}



int main()
{
    // 1. initialise a vector with 16 elements
    std::vector<int> age_list {85, 28, 34, 64, 22, 31, 59, 38, 72, 94, 27, 16, 13, 11, 39, 11};
    std::cout<<"Before sorting"<<std::endl;
    for(int val: age_list)
    {
        std::cout<<val<<", ";
    }
    std::cout<<std::endl;

    // 2. quick sort the list of items
    int last = age_list.size() - 1;
    quick_sort(age_list, 0, last);

    // 3. Print list after sorting
    std::cout<<"After sorting"<<std::endl;
    for(int val: age_list)
    {
        std::cout<<val<<", ";
    }

}
