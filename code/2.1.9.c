#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef char*  Ptr ;
#define ARR_LEN 10
void print(int *arr ,int len);
typedef void (*com_fun)(void);
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

       // print(arr,ARR_LEN);
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

double run_time(com_fun fun)
{
	time_t start,end ;
	double diff ;
	start = time(NULL);
	fun();
	end = time(NULL);
	diff = difftime(end,start);
	return diff ;
}

void test_3_sort_time(void)
{
	#define TEST_LEN 100000
	int arr[3][TEST_LEN];
	time_t start,end ;
	double diff1,diff2,diff3 ;
	generate(arr[0],TEST_LEN);

	memcpy((void*)arr[1],(void*)arr[0],sizeof(arr[0]));
	memcpy((void*)arr[2],(void*)arr[0],sizeof(arr[0]));


	start = time(NULL);
	insert_sort(arr[0],TEST_LEN);
	end = time(NULL);
	diff1 = difftime(end,start);

	start = time(NULL);
	insert_sort_index(arr[1],TEST_LEN);
	end = time(NULL);
	diff2 = difftime(end,start);

	start = time(NULL);
	shellsort(arr[2],TEST_LEN);
	end = time(NULL);
	diff3 = difftime(end,start);

	printf("%f,%f,%f\n",diff1,diff2,diff3);
	if(memcmp((void*)arr[0],(void*)arr[1],sizeof(arr[0])))
	{
		printf("sort err\n");
	}
	if(memcmp((void*)arr[0],(void*)arr[1],sizeof(arr[0])))
	{
		printf("sort err 2\n");
	}

}

void test(void )
{
  char str[] ={0,'a','b','c'};
  char dst[20]="abcdefg";
  strncpy(dst,str,10);
  printf("%s\n",dst);
}
int main(void)
{

    //test_shellsort();
    //test_insert_sort();
    //test_insert_sort_index();
    //test_3_sort_time();
    test();
}
