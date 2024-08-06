bool issort(int arr[],int size)
{
    if(size==0|| size ==1)
    {
        return true;
    }
    if(arr[0]>arr[1])
    {
        return false;
    }
    else{
        bool ans= issort(arr+1,size--);
    }
}

int sum(int *arr,int n)
{
    if(n==1)
    {
        return  arr[0];
    }
    else{
        return(arr[0]+sum(arr+1,n-1));
    }
}