// C++ program to illustrate sliding window algorithm
#include <bits/stdc++.h;
using namespace std;

vector<int> next_greater_right(vector<int> arr)
{
    stack<int> keep;
    vector<int> nger(arr.size());
    keep.push(arr.size()-1);
    nger[arr.size()-1] = arr.size();
    
    for(int i=arr.size()-2;i>=0;i--)
    {
        while(!keep.empty() && arr[i]>arr[keep.top()])
        {
            keep.pop();
        }
        if(keep.empty())
        {
            nger[i] = arr.size();
        }else{
            nger[i] = keep.top();
        }
        keep.push(i);
    }
    return nger;
}
void sliding_window_technique(vector<int> arr,int k)
{
    vector<int> output;
    vector<int> getnge = next_greater_right(arr);
    int j=0;
    for(int i=0;i<=arr.size()-k;i++)
    {
        if(j<i)
        {
            j=i;
        }
        while(getnge[j] < i+k)
        {
            j = getnge[j];
        }
        output.push_back(arr[j]);
    }
    for(int i=0;i<output.size();i++)
    {
        cout << output[i] << " ";
    }
}
int main()
{
    int size;cin>>size;
    vector<int> arr;
    for(int i=0;i<size;i++)
    {
        int num;cin>>num;
        arr.push_back(num);
    }
    int k;cin >> k;
    sliding_window_technique(arr,k);
    
    return 0;
}