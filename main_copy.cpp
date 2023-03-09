#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
	char s;
	ifstream in("f.txt",ios::in);
	ofstream out("copy f.txt",ios::out);
	while(in.get(s)){
		out.put(s);
	}
	in.close();
	out.close();
	return 0;
}