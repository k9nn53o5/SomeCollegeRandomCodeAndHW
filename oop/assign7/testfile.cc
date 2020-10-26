#include <iostream>
#include <fstream>
using namespace std;
int main(){
	int inter;
	fstream file1,file2;
	file1.open("intq.dat");
	 if(!file1.is_open()){
		 cout<<"open file1 fail"<<endl;
		   }
	 else{
		   do{
		        file1 >> inter;
			    cout << inter;
		    
		  }while(!file1.eof());
		file1.close();
	 }

	return 0;
}
