#include <stdio.h>

void v_printArr(int s_len, int* p_arr)
{
    int s_index;
    for(s_index = 0; s_index<s_len; s_index++)
    {
        printf("%d ",p_arr[s_index]);
    }
    printf("\n");
}

void v_insertionSort(int s_len, int* p_arr) 
{
    int s_indexJ, s_indexI;
    int s_key;
    for(s_indexJ = 1; s_indexJ < s_len; s_indexJ++)
    {
        s_key = p_arr[s_indexJ];
        s_indexI = s_indexJ-1;
        while ((s_indexI >= 0) && (p_arr[s_indexI] > s_key))
        {
            p_arr[s_indexI+1] = p_arr[s_indexI];
            s_indexI--;
        }
        p_arr[s_indexI+1] = s_key;
        v_printArr(s_len,p_arr);
    }
}

int main()
{
    int s_list[] = {5, 2, 9, 1, 5, 6};

    v_printArr(6,s_list);
    v_insertionSort(6,s_list);
    // v_printArr(6,s_list);
    return 0;
}