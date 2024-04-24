/**
 * Exponential search algorithm implementation in C++.
 * This is a modified version of linear search where the array is
 * divided into subsets. However, each jump index increases exponentially.
 * Once the subset with key is found, binary search is applied to find the key
 * within that subset.
*/

#include <iostream>
#include <cmath>
#include <vector>


// sort the array before searching
void bubble_sort(std::vector<int> &main_array)
{
    int len = main_array.size();
    bool swaped = false;

    for(int k=0; k<len-1; k++)
    {
        for(int i=0; i<len-k-1; i++)
        {
            if(main_array[i]>main_array[i+1])
            {
                int temp = main_array[i+1];
                main_array[i+1] = main_array[i];
                main_array[i] = temp;
                swaped = true;
            }
        }

        // if no swaping happened in any iteration then list is alredy sorted so break, saves time
        if(!swaped)
        {
            break;
        }
    }
}


// binary search algorithm O(logn)
int binary_search(std::vector<int> &main_array, int key)
{
    int low = 0;
    int high = main_array.size() - 1;

    while(low<=high)
    {
        int mid = (low+high)/2;

        if(main_array[mid]==key)
        {
            return mid;
        }

        if(key<main_array[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

// Time complexity O(logn)
int exponential_search(std::vector<int> &main_array, int key)
{
    // check if key at first index
    if(main_array[0]==key)
    {
        return 0;
    }

    int index = 1;
    int prev_index = 1;
    int power = 1;

    while(index<=main_array.size())
    {
        if(key<=main_array[index])
        {
            // if match key at index then return the fucntion
            if(main_array[index]==key)
            {
                return index;
            }

            // else binary search with the current block
            else
            {
                // vector slicing to get subarray with key
                std::vector<int> subarray;
                subarray = std::vector<int>(main_array.begin()+prev_index, main_array.begin()+index+1);
                int found_index = binary_search(subarray, key);

                if(found_index!=-1)
                {
                    found_index = found_index+prev_index;
                }

                return found_index;
            }
        }

        // update the index exponentially
        prev_index = index;
        index = std::pow(2, power);
        if(index<main_array.size())
        {
            index = main_array.size() - 1;
        }
        power++;
    }
}


// function to print search result
void print_index(int position, int key)
{
    if(position!=-1)
    {
        std::cout<<"The key: "<<key<<" is at index: "<<position<<std::endl;
    }
    else{
        std::cout<<"The key: "<<key<<" is not found\n";
    }
}


int main()
{
    // 1. create an array and sort it
    std::vector<int> age_list {34, 12, 17, 87, 47, 22, 90, 5, 39, 43, -22, -11, -9};

    bubble_sort(age_list);

    for(int& key: age_list)
    {
        std::cout<<key<<", ";
    }
    std::cout<<"\n";


    // 2. Perform interpolation search
    int key_list[9] = {34, 90, 13, 19, 5, 21, -6, -12, -22};

    for(int& key: key_list)
    {
        print_index(exponential_search(age_list, key), key);
    }

    return 0;
}
