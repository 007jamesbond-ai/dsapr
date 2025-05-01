#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#include<string>

struct patient{
    string name;
    int priority;
    patient(string name,int priority):name(name),priority(priority){}

};

int main(){
    auto compare=[](patient& p1, patient& p2){
        return p1.priority > p2.priority;
    };
    priority_queue<patient,vector<patient>,decltype(compare)> pq(compare);

    int no;
    cout<<"enter number of patient: ";
    cin>>no;
    for(int i=0;i<no;i++){
        int p;
        string n;
        cout<<"enter Name: ";
        cin>>n;
        cout<<"enter priority: ";
        cin>>p;
        pq.emplace(n,p);
    }

    while(!pq.empty()){
        patient p = pq.top();
        pq.pop();
        string p_level;
        switch(p.priority){
            case 1:
               p_level = "Serious (Top  priority)";
               break;
            case 2:
               p_level = "Non-Serious (Medium  priority)";
               break;
            case 3:
               p_level = "General Checkup ";
               break;
            
        }
        cout<<"Patient: "<<p.name<<"  Priority: "<<p_level<<endl;
    }
    return 0;

}