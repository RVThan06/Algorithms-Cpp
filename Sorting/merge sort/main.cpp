#include <iostream>
#include <vector>


void merge_sort(std::vector<int> &main_array, std::vector<int> &left, std::vector<int> &right)
{
    int len = main_array.size();
    int left_len = left.size();
    int right_len = right.size();
    int i=0;
    int j=0;

    for(int k=0; k<len; k++)
    {
        // compare both subarrays and sort into main array
        if(i<left_len && j<right_len)
        {
            if(left[i]<right[j])
            {
                main_array[k]=left[i];
                i++;
            }
            else{
                main_array[k]=right[j];
                j++;
            }
        }

        // if left subarray is empty, then add remaining in right to main array
        else if(i==left_len)
        {
            main_array[k]=right[j];
            j++;
        }

        // if right subarray is empty, then add remaining in left to main array
        else if(j==right_len)
        {
            main_array[k]=left[i];
            i++;
        }

    }
}


void divide_merge(std::vector<int> &main_array)
{
    int len = main_array.size();

    // dive the array into half at each recursion
    if(len>1)
    {
        int mid = len/2;
        std::vector<int> right;
        std::vector<int> left;

        // divide_merge the left half of main array
        for(int i=0; i<mid; i++)
        {
            right.push_back(main_array[i]);
        }

        // divide_merge the right half of main array
        for(int i=0; i<len-mid; i++)
        {
            left.push_back(main_array[mid+i]);
        }

        divide_merge(left);
        divide_merge(right);
        merge_sort(main_array, left, right);
    }

}


int main()
{
    // 1. sort a simple list of 10 items

    // 1.a initialise the vector
    std::vector<int> age_list {34,12,17,87,47,22,90,5,39,43};

    // 1.b merge sort the vector
    divide_merge(age_list);

    // 1.c print the sorted vector
    std::cout<<"age_list after sorting: ";
    for(int val: age_list)
    {
        std::cout<<val<<",";
    }
    std::cout<<std::endl;

    // 2. sort a list of 1000000 items

    // 2.a initialise an empty vector
    std::vector<int> num_list;

    // 2.b add values to the empty vector
    for(int i=1000000; i>0; i--)
    {
        num_list.push_back(i);
    }

    // 2.c merge sort the vector
    divide_merge(num_list);

    // 2. print the sorted vector
    std::cout<<"num_list after sorting: ";
    for(int i=0; i<10; i++)
    {
        std::cout<<num_list[i]<<",";
    }

    return 0;
}
