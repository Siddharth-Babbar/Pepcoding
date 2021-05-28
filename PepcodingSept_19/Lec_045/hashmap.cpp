#include<iostream>
#include<unordered_map>

using namespace std;
void HashMapCreation01()
{
    unordered_map<string,int> map;
    map.insert({"India",1000});
    map.insert({"China",1000});
    map.insert({"USA",1000});
    map.insert({"Pak",1000});
    map.insert({"Nepal",1000});
    map["India"]=3000;
    
    for(auto ele:map)
     {
         cout<<ele.first<<":->"<<ele.second<<endl;
     }
}
int main(int args,char** argv)
{
    HashMapCreation01();
    return 0;
}