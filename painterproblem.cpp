bool possible(vector<int> & boards,int s,int e,int mid,int k,int n)
{
    int d=1,sum=0;
    for(int i=0;i<n;i++)
    {
        if((sum+boards[i])<=mid)
        {
            sum=sum+boards[i];
        }
        else{
            d++;
            if(d>k || boards[i]>mid)
            {
                return false;
            }
            sum=boards[i];
        }
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int n=boards.size();
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+boards[i];
    }
    int e=sum;
    int mid=s+(e-s)/2;
    int ans=-1; 
    while(s<=e)
    {
        if(possible(boards,s,e,mid,k,n))
        {
            ans=mid;
          e=mid-1;
        }
        else{
             s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}