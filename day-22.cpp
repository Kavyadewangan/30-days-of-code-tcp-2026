#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main (){
     int I;
     cin>> I;
     while(I--){
        int Q;
        cin>> Q;

        queue<int> q;
        int last = -1;

        while(Q--){
            char J;
            cin>>J;

            if(J == 'a'){
                int x;
                cin >> x;
                q.push(x);
            }
            else if(J == 'b' ){
                if(!q.empty()){
                    cout<<q.front() << " ";
                    q.pop();
                     if(q.empty())last = -1;
                    }else{
                        cout<<-1<<" ";
                    }
                }

                else if(J == 'c'){
                    cout<<q.size()<<" ";
                }
                else if(J == 'd'){
                    if(!q.empty()){
                        cout<<q.front()<<" ";
                    }else{
                        cout<<-1<<" ";
                    }
                }
                else if(J == 'e'){
                    if(!q.empty()){
                        cout<<q.back()<<" ";
                    }else{
                        cout<<-1<<" ";
                    }
                }
            }
            cout<<endl;
     }
     return 0;
}