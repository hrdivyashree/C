/************************ prologue *******************/
/*Copyrighted to Rajainder A. */
/* University of California Extension, Santa Cruz */
/* Advanced C Programming */
/* Instructor: Rajainder A. */
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 12 */
/* Topic: Sorting */
/* File name: assignment11.c*/
/* Date: August 23, 2017 */
/* Objective: Towers of Hanoi */
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/* References - http://www.geeksforgeeks.org*/
/****************************************************/

#include <stdio.h>
#include <stdlib.h>

static int arr[40];
FILE * ofp;

int readinput(){
    FILE* fp = fopen("sortinginput.doc", "r");
    if (NULL == fp) {
        perror("File not found!");
        exit(-1);
    }
    for (int i = 0; fscanf(fp, "%d%*c", &arr[i]) != EOF; i++) {
        ;
    }
    fclose(fp);
    fprintf(ofp,"Input data read from the Input File: ");
    for(int i=0; i < sizeof(arr)/sizeof(arr[0]); i++){
        fprintf(ofp,"%d ",arr[i]);
    }
    fprintf(ofp,"\n ");
    return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        fprintf(ofp,"%d ", arr[i]);
    fprintf(ofp,"\n");
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n){
    int i, j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min=i;
        for (j=i+1; j<n; j++)
            if (arr[j] < arr[min])
                min= j;
        // Swap
        swap(&arr[min], &arr[i]);
    }
}

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high-1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void selection(){
    fprintf(ofp,"Select a sort-routine number below or -1 to Quit:\n");
    fprintf(ofp,"1. Bubble Sort\n");
    fprintf(ofp,"2. Insertion Sort\n");
    fprintf(ofp,"3. Selection Sort\n");
    fprintf(ofp,"4. Shell Sort\n");
    fprintf(ofp,"5. Quick Sort\n");
    fprintf(ofp,"6. Merge Sort\n");
    fprintf(ofp,"7. Heap Sort\n");
    fprintf(ofp,"7. Heap Sort\n");
    fprintf(ofp,"-1. Quit\n");
    fprintf(ofp,"? ");
    fflush(ofp);
}
// Driver program to test above functions
int main()
{
    int n = sizeof(arr)/sizeof(arr[0]);
    int sort, choice=0;
    ofp = fopen("assignment12_out.doc", "w+");
    readinput();
    choice++;
    selection();
    scanf("%d",&sort);
    while(sort != -1){
    if (sort == -1){
        break;
    }
    readinput();
    switch(sort){
        case 1:
            fprintf(ofp,"User selected 1. bubble sort\n");
            bubbleSort(arr, n);
            fprintf(ofp,"Bubble Sort ");
            break;
        case 2:
            fprintf(ofp,"User selected 2. insertion sort\n");
            insertionSort(arr,n);
            fprintf(ofp,"Insertion Sort ");
            break;
        case 3:
            fprintf(ofp,"User selected 3. selection sort\n");
            selectionSort(arr,n);
            fprintf(ofp,"Selection Sort ");
            break;
        case 4:
            fprintf(ofp,"User selected 4. shell sort\n");
            shellSort(arr,n);
            fprintf(ofp,"Shell Sort ");
            break;
        case 5:
            fprintf(ofp,"User selected 5. quicksort\n");
            quickSort(arr, 0, n-1);
            fprintf(ofp,"Quick Sort ");
            break;
        case 6:
            fprintf(ofp,"User selected 6. mergesort\n");
            mergeSort(arr, 0, n-1);
            fprintf(ofp,"Merge Sort ");
            break;
        case 7:
            fprintf(ofp,"User selected 7. heapsort\n");
            heapSort(arr, n);
            fprintf(ofp,"Heap Sort ");
            break;
        default:
            selection();
            scanf("%d",&sort);
            break;
        }
        fprintf(ofp,"Sorted array: \n");
        printArray(arr, n);

//        if (choice >=2 ){
//            fprintf(ofp,"user reached 2 sort limit\n");
//            fclose(ofp);
//            exit(0);
//        }
        choice++;
        selection();
        scanf("%d",&sort);
    }
    fprintf(ofp,"User opted to Quit \n");
    fclose(ofp);
    return 0;
}
