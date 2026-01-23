#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s){
    unordered_map<char, int> freq;
    for(char c: s){
        freq[c]++;
    }

vector<pair<char,int>>v;
for(auto it : freq){
    v.push_back(it);
}

sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b){
    return a.second> b.second;
});

string result = "";
for(auto p : v){
    result = result + string(p.second, p.first);
}

return result;
}

int main(){
    string s;
    cin>> s;

    cout<<frequencySort(s);
    return 0;
}