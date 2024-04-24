/**
 * Interpolation search implementation in C++.
 * This search algorithm uses an interpolation function to find a
 * possible guess for the index of the key to be searched.
 * It is aa divide and conquer algorithm similar to binary search.
 * It works well with uniformly distributed data.
*/

#include <iostream>
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


// Time complexity 0(log(logn))
int interpolation_search(std::vector<int> &main_array, int key)
{
    int high = main_array.size() - 1;
    int low = 0;

    // check if only one item left and also if the target is within the range of high and lows
    while(low<=high && main_array[low]<=key && key<=main_array[high])
    {
        // probe equation
        int mid = low + (((double)(high - low) / (main_array[high] - main_array[low])) * (key - main_array[low]));

        if(main_array[mid]==key)
        {
            return mid;
        }
        else if (key<main_array[mid])
        {
            high = mid - 1;
        }
        else if (key>main_array[mid])
        {
            low = mid + 1;
        }
    }

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
        print_index(interpolation_search(age_list, key), key);
    }

}
