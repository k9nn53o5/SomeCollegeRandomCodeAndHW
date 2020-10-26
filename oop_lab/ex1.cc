#include <iostream>
#include <string>
using namespace std;

int main()
{
	// collect all string and combine them
	//string pNL("OOP is watching you!");

	string sGetInput, sTotal;
	getline(cin,sGetInput);
	while (sGetInput.size() != 0){
		sTotal += sGetInput;
		getline(cin,sGetInput);
//		if (pNL == sGetInput)
//			goto CLEANUP;

	}
	cout << sTotal << endl;

	return 0;

//CLEANUP:
	//cout << pNL << endl;
//	return 1;
}
