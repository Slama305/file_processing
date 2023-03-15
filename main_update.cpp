#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Student
{
public:
    int id, age;
    char name[10];
};

void readStudent(){
        Student s1;
    ifstream in;
    in.open("D:\\codeblocks\\projects\\write\\Student.txt", ios::in);
    if(in.is_open()){
        cout<<"ID \tNAME \tAGE"<<endl;
        in.read((char*) &s1, sizeof(s1));
        while(!in.eof()){
                cout << s1.id << "\t" << s1.name << "\t" << s1.age << endl;
                in.read((char*) &s1, sizeof(s1));
        }
        in.close();
    }
    else
    {
        cout << "Can not open the specified file\n";
    }
}
int main(){
    readStudent();
    char str[10];
    cout<<"enter the name you need to update for:\n";
    cin>>str;
    bool found=false;

    Student s1;
    fstream in;
    in.open("D:\\codeblocks\\projects\\write\\Student.txt", ios::in |ios::out);
    if(in.is_open()){
        in.read((char*) &s1, sizeof(s1));
        while(!in.eof()){
                if(strcmp(str,s1.name)==0){
                    cout<<"enter the new id for "<< str <<" " ;
                    cin>>s1.id;
                    cout<<"enter the new age for "<< str <<" " ;
                    cin>>s1.age;
                    int curpos =in.tellg();
                    int stusize =sizeof(s1);
                    in.seekp(curpos-stusize,ios::beg);
                    in.write((char*) &s1, sizeof(s1));

                    in.seekg(curpos-stusize,ios::beg);
                    in.read((char*) &s1, sizeof(s1));

                    cout<<"ID \tNAME \tAGE"<<endl;
                    cout << s1.id << "\t" << s1.name << "\t" << s1.age << endl;
                    found=true;
                    break;
                }
                in.read((char*) &s1, sizeof(s1));
        }
        if(!found)
            cout<<"the name not found\n";
        in.close();
    }
    else
    {
        cout << "Can not open the specified file\n";
    }
    return 0;
}
