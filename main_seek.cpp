#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream in;
    in.open("D:\\codeblocks\\projects\\write\\Student.txt", ios::in);
    if(in.is_open()){
        in.seekg(0,ios::end);
        cout<<"the length of the file is "<<in.tellg();
        in.close();
    }

    return 0;
}
