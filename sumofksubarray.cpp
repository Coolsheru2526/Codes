#include<iostream>
#include<queue>
using namespace std;

int sumofsubarray(int arr[],int n,int k)
{
   deque<int>S(k),G(k);
   int i;
   for(i=0;i<k;i++)
   {
    while ((!S.empty()) && arr[S.back()]>=arr[i] )
    {
       S.pop_back();
    }
     while ((!G.empty()) && arr[G.back()]<=arr[i] )
    {
       G.pop_back();
    }
    G.push_back(i);
    S.push_back(i);
    for (  ; i < n; i++ )
    {
        // Element at the front of the deque 'G' & 'S'
        // is the largest and smallest
        // element of previous window respectively
        sum += arr[S.front()] + arr[G.front()];
 
        // Remove all elements which are out of this
        // window
        while ( !S.empty() && S.front() <= i - k){
            S.pop_front();}
        while ( !G.empty() && G.front() <= i - k){
            G.pop_front();}

        while ( (!S.empty()) && arr[S.back()] >= arr[i]){
            S.pop_back(); // Remove from rear}
 
        // remove all previous smaller that are elements
        // are useless
        while ( (!G.empty()) && arr[G.back()] <= arr[i]){
            G.pop_back(); // Remove from rear
            }
 
        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }
 
    // Sum of minimum and maximum element of last window
    sum += arr[S.front()] + arr[G.front()];
 
    return sum;
   }
}