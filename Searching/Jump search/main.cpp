/**
 * Python implementation of jump search.
 * This program is a modified versiob of linear search of a sorted
 * array. Instead of searching every element, we skip a few elements
 * at a time and try to find the subset with the key.
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


// Time complexity O(sqrt(n))
int jump_search(std::vector<int> &main_array, int key)
{
    int index = 0;
    int block_size = std::sqrt(main_array.size());

    // checks from 0 t0 len - 1
    while(index<=main_array.size()-1)
    {
        int j = index + block_size -1;

        // find the block where key could be located within
        if(key<=main_array[j])
        {
            // if key is at the jump index itself then end the function
            if(main_array[j]==key)
            {
                return index;
            }

            // linear search within block less than the current jump index index+block_size
            for(int i=index; i<j; i++)
            {
                if(main_array[i]==key)
                {
                    return i;
                }
            }

            // not in the lower block so element not found
            return -1;
        }

        // if key larger than value at jump index, we jump to next by a block size
        index+=block_size;
    }

    // if key is larger than all items in the array
    return -1;
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
        print_index(jump_search(age_list, key), key);
    }

    return 0;
}
