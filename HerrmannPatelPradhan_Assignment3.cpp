//
//  main.cpp
//  Testing
//
//  Created by Kaushal Patel on 10/5/14.
//  Copyright (c) 2014 University of Cincinnati. All rights reserved.
//
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void merge(int*,int,int,int,int);
void mergeSort(int*,int,int,int);
void hybridSort(int*,int,int,int,int,int,int);
void quickSort(int*,int,int);
void bubbleSort(int*,int,int,int);
void insertSort(int*,int,int,int);
void print(int*,int);

char repeat = 'y';
int counter = 0;
int main()
{
    srand(clock());
    while (repeat == 'y') {
        int lSort, sSort, tHold, option;
        int runNumber = 10000;
        // (B)ubbleSort; (I)nsertSort; (M)ergeSort; (Q)uickSort
        cout<< "***************************"<<endl;
        cout<< "1. Bubble Sort"<<endl;
        cout<< "2. Insert Sort"<<endl;
        cout<< "3. Bubble Sort & Merge Sort"<<endl;
        cout<< "4. Bubble Sort & Quick Sort"<<endl;
        cout<< "5. Insert Sort & Merge Sort"<<endl;
        cout<< "6. Insert Sort & Quick Sort"<<endl;
        cout<< "***************************\n"<<endl;
        cout<< "Please pick a number representing the sorting methond you'd like to use. (1,2,3,4,5,6):"<<endl;
        cin>> option;
        if((option <1)&&(option>6))
        {
            cout<< "Please pick a number representing the sorting methond you'd like to use. (1,2,3,4,5,6):"<<endl;
            cin>>option;
        }

    int row, column= 0;
counter = 0;
    int n;
    cout<<"How long would you like the array to be?"<<endl;
    cin>>n;
        if((option>0)&&(option<7))
        {
            if((option ==1) || (option ==2)){tHold = n+1;}
            else
            {
                cout<<"Please enter the threshold value:"<<endl;
                cin>> tHold;
            }
        }
    const int size = n;
    int A[size];
        char display;
        int i;
    if(n<=30)
    {
        char c;
        cout<<"Would you like to enter the values to the array?(y/n)"<<endl;
        cin>>c;
        cout<<"Would you want the list to be displayed?(y/n)"<<endl;
        cin>>display;
        if(c == 'y')
        {
            for(i=0;i<n;i++)
            {
                cout<<"Enter the value in position "<<i<<" of array"<<endl;
                cin>>A[i];
		
            }
        }
        else
        {
            for(i=0;i<n;i++) A[i]= rand()%100;
            if(display == 'y')
            {
            	cout<<"Array will be populated randomly"<<endl<<"Generated Array:"<<endl;
                print(A, size);
                cout<<endl;
            }
        }
    }
    else
    {
        for(i=0;i<n;i++)
        A[i]= rand()%100;
        if(n<=100)
        {
        cout<<"Would you want the list to be displayed?(y/n)"<<endl;
        cin>>display;
            if(display == 'y')
            {	
                cout<<"Array will be populated randomly"<<endl<<"Generated Array:"<<endl;
                print(A, size);
            }
        }
        cout<<endl;
    }
        if((option >0) && (option <7))
        {
            if(option ==1){sSort = 0;}
            if(option ==2){sSort = 1;}
            if(option ==3){lSort = 0, sSort = 0;}
            if(option ==4){lSort = 1, sSort = 0;}
            if(option ==5){lSort = 0, sSort = 1;}
            if(option ==6){lSort = 1, sSort = 1;}
        }
        long time = clock();
        for(int rN=0; rN < runNumber; rN++)
        {
    hybridSort(A,lSort,sSort,tHold,0,size-1,size);
        }
        time = clock()- time;
        
	if(size<100 and display == 'y')
		{cout<<"Sorted Array:"<<endl;	
	        print(A, size);
	}
        cout<< "The runtime for the sort was: "<< (double)(1000000*time/runNumber)/CLOCKS_PER_SEC <<" microseconds per sort"<<endl;
	cout<<"There were "<<counter/runNumber<<" comparisons made per sort"<<endl;
        cout<<"Would you like to rerun the program? (y/n)"<<endl;       
	cin>>repeat;
}
}

void hybridSort(int *array,int largesort,int smallsort,int T,int low,int high,int size)//sorts the elements within its bounds
//largesort = 0 -> mergesort largesort = 1 -> quicksort
//smallsort = 0->bubblesort smallsort = 1 -> insertionsort
//T is the threshold
{
counter++;
    if(high - low <=T)
    {//small sort
        if(smallsort==0)
        {//bubble sort
            bubbleSort(array,low,high,size);
        }
        else
        {//insert sort
            insertSort(array, low, high, size);
        }
    }
    else
    {if(largesort == 0)
    {
        //merge sort
        if(low<high)
        {
            int mid = (low +high)/2;
            hybridSort(array,largesort,smallsort,T,low,mid,size);
            hybridSort(array,largesort,smallsort,T,mid+1,high, size);
            //cout<<"here"<<endl;
            merge(array,low,high,mid,size);
        }
    }
    else
    {
        //quick sort
        int i = low, j = high;
        int tmp;
        int pivot = array[(low + high) / 2];
        
        /* partition */
	counter++;         
	while (i < j) {
        counter++; 
	counter++;	
	while (array[i] < pivot)
                {i++;
counter++; }
	counter++;            
	while (array[j] > pivot)
            {    j--;
counter++; }
	    counter ++;
            if (i < j) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                i++;
                j--;
            }
        };
        
        /* recursion */
counter++; 
        if (low < j){
            hybridSort(array, largesort, smallsort, T, low, j, size);
        }
counter++; 
        if (i < high){
            hybridSort(array, largesort, smallsort, T, i, high, size);
        }
    }
    }
}
void bubbleSort(int* array, int low, int high, int size){
    int c;
    int d;
    int swap;     
counter++; 
	for (c = low ; c < high; c++)
	{counter++; 
        for (d = low ; d < high; d++)
        {counter++; 
            if (array[d] > array[d+1]) /* For increasing, need to use < if we are decresing */
            {
                swap       = array[d];
                array[d]   = array[d+1];
                array[d+1] = swap;
            }
	counter++; 
        }
	counter++; 
    }
}

void quickSort(int *array, int low, int high) {
    int i = low, j = high;
    int tmp;
    int pivot = array[(low + high) / 2];
    int mid = (low+high)/2;

    /* partition */
    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    };
    
    /* recursion */
    if (low < j){
        quickSort(array, low, mid);
    }
    if (i < high){
        quickSort(array, mid+1, high);
    }
}

void mergeSort(int *array,int low, int high,int size)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2; //calculate the midpoint, round down
        mergeSort(array, low, mid,size);
        mergeSort(array, mid + 1, high,size);
        merge(array, low, high, mid,size);
    }
}
void merge(int *array, int low, int high, int mid, int size)
{
    int i = low;
    int k = mid + 1;
    int j = low;
    int temp[size];
counter++; counter++; 
    while (i <= mid && k <= high)
    {counter++; 
        if (array[i] < array[k])
        {
            temp[j] = array[i];
            j++;
            i++;
        }
        else
        {
            temp[j] = array[k];
            j++;
            k++;
        }
counter++; 
    }
counter++; 
    while (i <= mid)
    {
	       temp[j] = array[i];
	       j++; i++;
counter++; 
    }     
counter++; 
    while (k <= high)
    {
        temp[j] = array[k];
        j++; k++;

counter++;     }
    //copy over the array
counter++; 
    for (int z = low; z <= high; z++)
    { array[z] = temp[z];
counter++; 
    }
}
void insertSort(int* array, int low, int high, int size)
{
    int i, j, temp;
counter++; 
    for(j = low+1; j <= high; j++)    // Starting j with low+1 (not low)
    {
        temp = array[j]; //array[j] assigned to temperory variable
counter++; counter++; 
        for(i = j - 1; (i >= low) && (array[i] > temp); i--)   //higher values move down
        {
            array[i+1] = array[i];
counter++; 
        }
        array[i+1] = temp; //put the original value back in place
counter++; 
    }
}
void print(int* array, int size)
{if(size>20)
{
    int j=0;
    int col;
    for(int i=0;i<size;i++)
    {
        for(col = 1;col<=10;col++)
        {
            if (j>=size){
                break;
            };
            cout<<array[j]<<"\t";
            j++;
        }
        i = i+col;
        cout<<endl;
    }
}
    else
    	for(int i = 0;i<size;i++)
    		cout<<array[i]<<endl;
}
