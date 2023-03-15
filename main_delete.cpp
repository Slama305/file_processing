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

int main(){
    char str[10];
    cout<<"enter the name you need to delete for:\n";
    cin>>str;
    bool found=false;

    Student s1;
    ifstream in;
    in.open("D:\\codeblocks\\projects\\write\\Student.txt", ios::in);
    if(in.is_open()){


        in.read((char*) &s1, sizeof(s1));
        while(!in.eof()){
                if(strcmp(str,s1.name)==0){
                    cout<<"ID \tNAME \tAGE"<<endl;
                    cout << s1.id << "\t" << s1.name << "\t" << s1.age << endl;
                    found=true;
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
