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
	int id=0;
	string n;
	int c=0;
	cout<<"please ..!Enter user name.: ";
	cin>>n;
	f.open("f.txt",ios::in);
	int flag=0;
	while(!f.eof()){
		c++;
		f.read((char*)&s,sizeof(s));
		if(s.id!=id){
	    	if(s.name == n){
		   	cout<<"Record\tid\tname\tage\n";
	    	   cout<<c<<"\t"<<s.id<<"\t"<<s.name<<"\t"<<s.age<<"\n";
	    	   flag=1;
	      }
	      id=s.id;
	   } 
	}
	if(flag==0){
		cout<<"this name not found..!";
	}
	f.close();
	return 0;
}