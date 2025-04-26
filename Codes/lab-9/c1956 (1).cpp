//Codeforces q 1956

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//A vector class to store the vector with the sequence
class vectors{
    private:
        vector<int> v1;
    public:
        vector<int> findnum();
};

int main(){
    class vectors v;
    vector<int> v4;
    int test;
    cout<<"Enter the number of test cases ";
    cin>>test;
    cout<<endl;
    for (int i=0;i<test;i++){
        v4=v.findnum();
        for (auto p:v4){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}
//Function to return the number of winners
vector<int> vectors::findnum(){
    int numseq;
    int rounds;
    int numpla;
    int seq;
    vector<int>v3;
    vector<int>v2;
    cout<<"Enter the number of elements in the sequence ";
    cin>>numseq;
    cout<<"Enter the number of rounds ";
    cin>>rounds;
    for (int i=0;i<numseq;i++){
        cout<<"Enter the "<<i+1<<" element in the sequence ";
        cin>>seq;
        v1.push_back(seq);
    }
    for (int i=0;i<rounds;i++){
        cout<<"Enter the number of players in round "<<i+1<<" ";
        cin>>numpla;
        v2.push_back(numpla);
    }
    for (int i=0;i<rounds;i++){
            if (v2[i]>=v1[0]){
                v3.push_back(v1[0]-1);
            }
            else{
                v3.push_back(v2[i]);
            }
        
    }
    v1.clear();
    v2.clear();
    cout<<endl;
    return v3;

}