#include<map>
#include <iostream>
#include<unordered_map>
using namespace std;


int main(){
   map<string,int>mp;
     //insertion
      mp.insert(make_pair("bhupendra",5)); 
       mp["tiwar"]=20;
       cout <<mp["tiwar"]<<endl;
       cout<<mp.at("bhupendra")<<endl;
       cout<<mp.count("bhupendra")<<endl;//count functuion
       cout<<mp.count("Mataa")<<endl;

       // iterator
       map<string,int> :: iterator it=mp.begin();
       while(it!=mp.end())
       {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
       }
    return 0;
}