#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void adddata(const string& filename){
string roll_no,name,div,address;

cout<<"Enter Roll Number: ";
cin>>roll_no;
cin.ignore();
cout<<"Enter Name: ";
getline(cin,name);
cout<<"Enter Division: ";
getline(cin,div);
cout<<"Enter Address: ";
getline(cin,address);

ofstream outfile(filename,ios::app);
if(!outfile){
    cout<<"Error opening file";

}

outfile<<roll_no<<","<<name<<","<<div<<","<<address<<endl;
cout<<"Data Added Successfully"<<endl;

outfile.close();

}
void searchdata(const string& filename){
    string roll_no;
    cout<<"Enter roll number to display: ";
    cin>>roll_no;

    ifstream infile(filename);

    if(!infile){
        cout<<"error to open file.";
    }
    string line;
    bool found = false;

    while(getline(infile,line)){
        if(line.substr(0,line.find(','))==roll_no){
            found = true;
            cout<<"student Details: ";
            cout<<line<<endl;
            break;
        }

    }

    if(!found){
        cout<<"No Student found in file with"<<roll_no<<" roll number"<<endl;
    }

    infile.close();
}
void deletedata(const string& filename){
 string roll;

 cout<<"enter roll number to delete: ";
 cin>>roll;

 ifstream infile(filename);
 if (!infile){
    cout<<"error to open file";
 }

 string line;
 bool found = false;
 string tempfilename = "tmp.txt";
 ofstream tempfile(tempfilename);
 while(getline(infile,line)){
    if(line.substr(0,line.find(',')) !=roll){
       tempfile<<line<<"\n";
    }
    else{
        found = true;
    }
 }

 infile.close();
 tempfile.close();

 if (found){
    remove(filename.c_str());
    rename(tempfilename.c_str(),filename.c_str());
    cout<<"data deleted successully.";
 }
 else{
    cout<<"no student found with "<<roll<<" roll number";
 }

}


void displaydata(const string& filename){
    ifstream disfile(filename);
    if(!disfile){
        cout<<"Error opening file."<<endl;
    }
    cout<<"Displaying File Contents: "<<endl;
    string line;
    while(getline(disfile,line)){
        cout<<line<<endl;
    }

    disfile.close();
}


int main(){
    string filename = "student-info.txt";
    int choice;
    while(true){
    cout<<"Menu\n";
    cout<<"1.Add Data To File\n";
    cout<<"2.Display Data of File\n";
    cout<<"3.Search a Record in File\n";
    cout<<"4.Delete Record\n";
    cout<<"5.Exit\n";
    cout<<"Enter Your Choice(1-5): ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        adddata(filename);
        break;
    case 2:
         displaydata(filename);
         break;
    case 3:
         searchdata(filename);
         break;
    case 4:
         deletedata(filename);
         break;
    case 5:
         return 0;
         break;
    default:
        cout<<"enter valid choice(1-4)";
        break;
    }
    }
    
}