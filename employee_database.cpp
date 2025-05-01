#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void adddata(const string& filename){
string emp_id,name,position,salary;

cout<<"Enter Employee ID: ";
cin>>emp_id;
cin.ignore();
cout<<"Enter Name: ";
getline(cin,name);
cout<<"Enter Position: ";
getline(cin,position);
cout<<"Enter Salary: ";
getline(cin,salary);

ofstream outfile(filename,ios::app);
if(!outfile){
    cout<<"Error opening file";

}

outfile<<emp_id<<","<<name<<","<<position<<","<<salary<<endl;
cout<<"Data Added Successfully"<<endl;

outfile.close();

}
void searchdata(const string& filename){
    string emp_id;
    cout<<"Enter Employee ID to display: ";
    cin>>emp_id;

    ifstream infile(filename);

    if(!infile){
        cout<<"error to open file.";
    }
    string line;
    bool found = false;

    while(getline(infile,line)){
        if(line.substr(0,line.find(','))==emp_id){
            found = true;
            cout<<"Employee Details: ";
            cout<<line<<endl;
            break;
        }

    }

    if(!found){
        cout<<"No Employee found in file with "<<emp_id<<" ID "<<endl;
    }

    infile.close();
}

void deletedata(const string& filename){
 string id;
 cout<<"Enter Employee ID to delete: ";
 cin>>id;

 ifstream infile(filename);
 if (!infile){
    cout<<"error to open file";
 }

 string line;
 bool found = false;
 string tempfilename = "tmp.txt";
 ofstream tempfile(tempfilename);
 while(getline(infile,line)){
    if(line.substr(0,line.find(',')) !=id){
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
    cout<<"no Employee found with "<<id<<" ID ";
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

void updatedata(const string& filename){
    string emp_id;
    cout<<"Enter Employee ID to update: ";
    cin>>emp_id;

    ifstream infile(filename);
    if (!infile){
        cout<<"Error opening file."<<endl;
        return;
    }

    string line;
    bool found = false;
    string tempfilename = "tmp.txt";
    ofstream tempfile(tempfilename);

    while(getline(infile,line)){
        if(line.substr(0,line.find(',')) == emp_id){
            found = true;
            string name, position, salary;
            cout<<"Enter new Name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter new Position: ";
            getline(cin, position);
            cout<<"Enter new Salary: ";
            getline(cin, salary);
            tempfile << emp_id << "," << name << "," << position << "," << salary << endl;
        } else {
            tempfile << line << endl;
        }
    }

    infile.close();
    tempfile.close();

    if (found){
        remove(filename.c_str());
        rename(tempfilename.c_str(), filename.c_str());
        cout<<"Data updated successfully."<<endl;
    } else {
        cout<<"No Employee found with "<<emp_id<<" ID."<<endl;
    }
}

int main(){
    string filename = "empdb.txt";
    int choice;
    while(true){
    cout<<"Menu\n";
    cout<<"1.Add Data To File\n";
    cout<<"2.Display Data of File\n";
    cout<<"3.Search a Record in File\n";
    cout<<"4.Delete Record\n";
    cout<<"5.Update Record\n";
    cout<<"6.Exit\n";
    cout<<"Enter Your Choice(1-6): ";
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
         updatedata(filename);
         break;
    case 6:
         return 0;
         break;
    default:
        cout<<"Enter valid choice(1-6)";
        break;
    }
    }
    
}
