#include <iostream>
#include <fstream>
using namespace std;
class student{
	public:
		int id;
		char name[10];
		int age;
};
int main(int argc, char** argv) {
	fstream f;
	student s;
	//int id=0;
	string str;
	f.open("f.txt",ios::out);
	do{
		cout<<"Enter id : ";
		cin>>s.id;
		cout<<"Enter name : ";
		cin>>s.name;
		cout<<"Enter age : ";
		cin>>s.age;
		f.write((char*)&s,sizeof(s));
		cout<<"Enter (1) ! if you went to continue \n";
		cout<<"Enter (0) ! if you not went to continue \n";
		cin>>str;
	}while(str!="0");
	f.close();
	return 0;
}