#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int longestSeries(vector<int> &arr)
{
    unordered_map<int,bool> map;
    
    int size=-1;
    int num=-1;

    for(int ele:arr)
     {
         map[ele]=true;
     }
    
    for(auto key:map)
     {
         if(key.second)
          {
              if(map.find(key.first-1)!=map.end())
               {
                   map[key.first]=false;
               }

          }
     }

    for(auto key:map)
     {
         if(key.second)
          {
              int number=key.first+1;
              int smallSize=1;

              while(map.find(number)!=map.end())
               {
                   smallSize++;
                   number++;
               }
               if(smallSize>size)
                {
                    size=smallSize;
                    num=number;
                }
          }
     }
    return size;
}
int main(int args,char** argv)
{
    vector<int> arr={1,14,2,13,4,8,9,10,11,12,5,6};
    cout<<longestSeries(arr);
    return 0;
}