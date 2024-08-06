//bubblesort using recursion;
/* In Bubble sort we compare adjacent element and swap */

void Bubblesort(int* arr,int n)
{
    if(n<=1)
    {
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    Bubblesort(arr,n--);
}


//selection sort
/* finding minimum and replacing it*/

void selectsort(int* arr,int n)
{
     if(n<=1)
    {
        return;
    }
    int min=arr[0],int index=0;
    for(int i=1;i<n;i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
            index=i;
        }
    }
    swap(arr[0],arr[index]);
    selectsort(arr+1,n--);
}


//Insertion sort
/*subarray sort is the term for subarray */

void insertionsort(int* arr,int n)
{
    if(n<=1)
    {
        return;
    }
    insertionsort(arr,n-1);
    int key =arr[n-1];
    int j=n-2;
    while (j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}

//Merge sort   Time Complexity ""O(nlogn)"" 
/* todooo merge krooo
    
    Inversion Counting
   Stable sorting Algorithm 
   whichh means it maintains relative order for equal element in an array

*/

void merge (int* arr,int i ,int j)//very sexy function 
{
    int mid=i+(j-i)/2;
    int n=mid-i+1;//length of left
    int m=j-mid;//length of right
    int k=i;
    int* left=new int [n];
    int* right= new int [m];
      for(int l=0;l<n;l++)
    {
        left[l]=arr[k++];
    }
    k=mid+1;
     for(int l=0;l<m;l++)
    {
        right[l]=arr[k++];
    }
    k=i;
    int index1=0;
    int index2=0;
    while(index1<n && index2<m)
    {
        if(left[index1]<right[index2])
        {
           arr[k]=left[index1];
           index1++;
        }
        else{
            arr[k]=right[index2];
            index2++;
        }
        k++;
    }
    while(index1<n)
    {
        arr[k]=left[index1];
           index1++;
           k++;
    }
    while(index2<m)
    {
        arr[k]=right[index2];
        k++;
        index2++;
    }
  delete []left;
  delete []right;

}


void mergesort(int* arr,int i,int j)
{
    if(i>=j)
    {
        return;
    }
    int mid =i+(j-i)>>1;       //j-i/2 right shift basically
    mergesort(arr,i,mid);
    mergesort(arr,mid+1,j);
    merge(arr,i,j);

}
//parition using pivot
/*Not stable Sort O(n^2) best time complexity O(n*logn )*/

int partition(int* arr,int s,int e)
{
    int pivot =s,int count=0;
    for(int i=s+1;i<=e;i++)
    {
         if(arr[pivot]>=arr[i])
         {
            count ++;
         }
    }
    pivot=pivot+count;
    swap(arr[pivot],arr[s]);
    int i=s,j=e;
    while(i<pivot && j>pivot)
    {
        while(arr[i]<arr[pivot])
        {
            i++;
        }
          while(arr[j]>arr[pivot])
        {
            j--;
        }
        if(i<pivot && j>pivot)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivot;
}

void quicksort(int* arr,int s,int e)
{
    if(s>=e)
    {
        return ;
    }
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}



void heapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
