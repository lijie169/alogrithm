#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARR_LEN 10
void print(int *arr ,int len);
size_t shellsort(int *arr,size_t len)
{
    size_t h = 1,j,i,count = 0;
    int tmp;
    while(h < len/3) h = h*3 + 1;

    while(h >= 1)
    {
        for(i = h; i < len ; i++)
            for(j = i; j>=h && arr[j]< arr[j-h]; j -= h)
            {
                count++ ;
                tmp = arr[j];
                arr[j] = arr[j - h];
                arr[j - h] = tmp;
            }

        h /= 3 ;
    }
    return count ;
}

void insert_sort(int *arr,size_t len)
{
    size_t i ,j ;
    int temp ;
    for( i = 1 ; i < len ; i++)
        for(j = i ; j > 0 && arr[j] < arr[j-1]; j--)
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp ;
        }
}
void insert_sort_index(int *arr,size_t len)
{
    int i ,j ;
    int temp ;
    for( i = 1 ; i < len ; i++)
    {
        temp = arr[i];
        //must use temp , memory mdify
        for(j = i - 1 ; j >= 0 && temp < arr[j]; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1]= temp;

        print(arr,ARR_LEN);
    }
}
void generate(int *arr ,int len)
{
    int i = 0;
    srand((unsigned)time(NULL));
    for(i = 0 ; i < len ; i++)
    {
     //   srand((unsigned)time(NULL));
        arr[i] = rand();
    }


}

void print(int *arr ,int len)
{
    int i = 0;
    for(i = 0 ; i < len ; i++)
    {
        printf(" %d ",arr[i]);
        if((i+1)%10 == 0)
            printf("\n");
    }
}
void test_shellsort(void)
{
//    #define ARR_LEN 500
    int arr[ARR_LEN];
    generate(arr,ARR_LEN);
    print(arr,ARR_LEN);
    printf("---------------------------------------\n");
    shellsort(arr,ARR_LEN);
    print(arr,ARR_LEN);

}

void test_insert_sort_index(void)
{

    int arr[ARR_LEN];
    generate(arr,ARR_LEN);
    print(arr,ARR_LEN);
    printf("---------------------------------------\n");
    insert_sort_index(arr,ARR_LEN);
    printf("---------------------------------------\n");
    print(arr,ARR_LEN);
}

void test_insert_sort(void)
{

    int arr[ARR_LEN];
    generate(arr,ARR_LEN);
    print(arr,ARR_LEN);
    printf("---------------------------------------\n");
    insert_sort(arr,ARR_LEN);
    printf("---------------------------------------\n");
    print(arr,ARR_LEN);
}
int main(void)
{

    //test_shellsort();
    //test_insert_sort();
    test_insert_sort_index();

}
