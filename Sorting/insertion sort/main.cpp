#include <iostream>
#include <vector>


void sort_ascending(std::vector<int> &my_array)
{
    for(int j=1; j<=my_array.size()-1; j++)
    {
        int key = my_array[j];
        int i = j-1;

        while(i>=0 && my_array[i]>key)
        {
            int temp = my_array[i];
            my_array[i] = key;
            my_array[i+1] = temp;
            i--;
        }
    }
}


void sort_descending(std::vector<int> &my_array)
{
    for(int j=1; j<=my_array.size()-1; j++)
    {
        int key = my_array[j];
        int i = j-1;

        while(i>=0 && my_array[i]<key)
        {
            int temp = my_array[i];
            my_array[i] = key;
            my_array[i+1] = temp;
            i--;
        }
    }
}



int main()
{
    std::vector<int> my_array {12,18,11,5,26,17,9,3,4};

    sort_ascending(my_array);

    for(int val: my_array)
    {
        std::cout<<val<<",";
    }
    std::cout<<std::endl;

    sort_descending(my_array);

    for(int val: my_array)
    {
        std::cout<<val<<",";
    }

    return 0;
}
