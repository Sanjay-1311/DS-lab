//Codeforces q 1760c

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//A vector class to store the vector with the strength of each contestant
class vectors{
    private:
        vector<int> v1;
    public:
        vector<int> finddiff();
};

int main(){
    class vectors v;
    int test;
    vector<int> v3;
    cout<<"Enter the number of test cases ";
    cin>>test;
    cout<<endl;
    for (int i=0;i<test;i++){
        v3=v.finddiff();
        for (auto p:v3){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}
//Function to find the advantage of each participant
vector<int> vectors::finddiff(){
    int numpla;
    int ind;
    int max1;
    int max2;
    int stren;
    vector<int> v4;
    max1=0;
    max2=0;
    cout<<"Enter the number of Participants ";
    cin>>numpla;
    for (int i=0;i<numpla;i++){
        cout<<"Enter the strength of the "<<i+1<<" Participant";
        cin>>stren;
        v1.push_back(stren);
    }
    for (int i=0;i<numpla;i++){
        if(v1[i]>max1){
            max1=v1[i];
            ind=i;
        }
    } 
    for (int i=0;i<numpla;i++){
        if(v1[i]>max2 && i!=ind){
            max2=v1[i];
        }
    }
    for (int i=0;i<numpla;i++){
        if (i==ind){
            v4.push_back(v1[i]-max2);
        }
        else{
            v4.push_back(v1[i]-max1);
        }
    }
    v1.clear();
    return v4;
}