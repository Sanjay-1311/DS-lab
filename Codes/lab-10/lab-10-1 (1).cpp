//Codeforces unique elements

#include<iostream>
#include<unordered_set>
#include <vector>
using namespace std;
int solve(int numele);
int main(){
    int test;
    int numelements;
    vector<int>v1;
    cout<<"Enter the number of test cases ";
    cin>>test;
    for (int i=0;i<test;i++){
        cout<<"Enter the number of elements in case "<<i+1<<" ";
        cin>>numelements;
        v1.push_back(solve(numelements));
    }
    for(auto p:v1){
        cout<<p<<endl;
    }
    return 0;
}
//Function to calculate the minimum number of moves required to make the sequence distinct
int solve(int numele){
    vector<int>v2;
    unordered_set<int>s;
    int ele;
    for(int i=0;i<numele;i++){
        cout<<"Enter the "<<i+1<<" element";
        cin>>ele;
        v2.push_back(ele);
    }
    if(v2.size()<=1){
        return 0;
    }
    for (int i=v2.size()-1;i>=0;i--){
        if (s.find(v2[i])!=s.end()){
            return i+1;
        }
        else{
            s.insert(v2[i]);
        }
    }
    return 0;

}