//Codeforces word game

#include<iostream>
#include<unordered_set>
#include <vector>
using namespace std;


vector<int> solve(int numwords);


int main(){
    vector<vector<int>>v2;
    int test;
    int numwords;
    cout<<"Enter the number of test cases ";
    cin>>test;
    for (int i=0;i<test;i++){
        cout<<"Enter the number of words in test case "<<i+1<<" ";
        cin>>numwords;
        v2.push_back(solve(numwords));
    }
    for(auto p:v2){
        for (auto q:p){
            cout<<q<<" ";
        }
        cout<<endl;
    }

    return 0;
}
vector<int> solve(int numwords){
    string s;
    int pts1=0;
    int pts2=0;
    int pts3=0;
    vector<int>v1;
    unordered_set<string>s1;
    unordered_set<string>s2;
    unordered_set<string>s3;
    for (int i=0;i<numwords;i++){
        cout<<"Enter the "<<i+1<<" word for player 1 ";
        cin>>s;
        s1.insert(s);
    }
    for (int i=0;i<numwords;i++){
        cout<<"Enter the "<<i+1<<" word for player 2 ";
        cin>>s;
        s2.insert(s);
    }
    for (int i=0;i<numwords;i++){
        cout<<"Enter the "<<i+1<<" word for player 3 ";
        cin>>s;
        s3.insert(s);
    }


    for (auto p:s1){
        if(s2.find(p)==s2.end() && s3.find(p)==s3.end()){
            pts1=pts1+3;
        }
        else if (s2.find(p)!=s2.end() && s3.find(p)==s3.end()){
            pts1=pts1+1;
        }
        else if (s2.find(p)==s2.end() && s3.find(p)!=s3.end()){
            pts1=pts1+1;
        }
    }
    for (auto p:s2){
        if(s1.find(p)==s1.end() && s3.find(p)==s3.end()){
            pts2=pts2+3;
        }
        else if (s1.find(p)!=s1.end() && s3.find(p)==s3.end()){
            pts2=pts2+1;
        }
        else if (s1.find(p)==s1.end() && s3.find(p)!=s3.end()){
            pts2=pts2+1;
        }
    }
    for (auto p:s3){
        if(s1.find(p)==s1.end() && s2.find(p)==s2.end()){
            pts3=pts3+3;
        }
        else if (s1.find(p)!=s1.end() && s2.find(p)==s2.end()){
            pts3=pts3+1;
        }
        else if (s1.find(p)==s1.end() && s2.find(p)!=s2.end()){
            pts3=pts3+1;
        }
    }
    v1.push_back(pts1);
    v1.push_back(pts2);
    v1.push_back(pts3);
    return v1;
}