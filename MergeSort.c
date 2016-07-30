#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int* trgt_ary,int start, int end);
void merge(int* trgt_ary,int start, int end, int mid);

#define TRGT_ARY_MAX 200

int main(void)
{
    //declear area
    int trgt_ary[TRGT_ARY_MAX] = {};// target array
    const int start_num = 0;
    const int end_num = TRGT_ARY_MAX - 1;

    //create random seed
    srand(time(NULL));

    //create random numbers in array
    for (int i = 0; i < TRGT_ARY_MAX; i++) {
        trgt_ary[i]= rand()%1000;
    }

    //test print
    for (int i = 0; i < TRGT_ARY_MAX; i++) {
        printf("%3.0d  ", trgt_ary[i]);
        if((i+1)%10 == 0)
            printf("\n" );


    }
    printf("\n----------------------------------------------------------\n" );

    //sort target array with merge sort
    mergeSort(trgt_ary,start_num,end_num);

    for (int i = 0; i < TRGT_ARY_MAX; i++) {
        printf("%3.0d  ", trgt_ary[i]);
        if((i+1)%10 == 0)
            printf("\n" );

    }


    return 0;
}
void mergeSort(int* trgt_ary,int start, int end)
{

    if(start<end)
    {
        int mid = (start+end)/2;
         mergeSort(trgt_ary,start,mid);
         mergeSort(trgt_ary,mid+1,end);
         merge(trgt_ary,start,end,mid);
    }
    return ;
}

void merge(int* trgt_ary,int start, int end, int mid)
{
    //declear
    const int trgt_ary_elem_num = end - start +1;
    int* temp_ary = (int*)malloc(sizeof(int)*trgt_ary_elem_num);
    int left_ptr_num = start;
    int right_ptr_num = mid +1;

    //merge
    for (int count = 0; count < trgt_ary_elem_num; count++) {
        if(trgt_ary[left_ptr_num]>=trgt_ary[right_ptr_num])
        {
            if(left_ptr_num <= mid)
            {
                temp_ary[count]=trgt_ary[left_ptr_num];
                left_ptr_num ++;
            }
            else
            {
                temp_ary[count]=trgt_ary[right_ptr_num];
                right_ptr_num ++;
            }
        }
        else if(trgt_ary[right_ptr_num]>=trgt_ary[left_ptr_num])
        {
            if(right_ptr_num <= end)
            {
                temp_ary[count]=trgt_ary[right_ptr_num];
                right_ptr_num ++;
            }
            else
            {
                temp_ary[count]=trgt_ary[left_ptr_num];
                left_ptr_num ++;
            }
        }
    }

    //insert
    for (int count = 0; count < trgt_ary_elem_num; count++) {
        trgt_ary[start+count]=temp_ary[count];
    }

    free(temp_ary);
    return;
}
