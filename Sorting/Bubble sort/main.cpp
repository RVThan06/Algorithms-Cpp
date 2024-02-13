#include <iostream>


void bubble_sort(int main_array[10])
{
    int len = 10;
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



int main()
{
    int age_list[10] = {34,12,17,87,47,22,90,5,39,43};

    bubble_sort(age_list);

    for(int val: age_list)
    {
        std::cout<<val<<",";
    }

    return 0;
}
