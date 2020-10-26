# include <iostream>
using namespace std;

class Tax{
	public:
		void input_salar(int a,int b);
		int total();
		int pay_tax(int c);
	private:
		int mon_salar[12];

};
void Tax::input_salar(int a,int b){
	mon_salar[b]=a;
}
int Tax::total(){
	int Total=0;
	for(int i=0;i < 12;i++){
		Total+=mon_salar[i];
	}
	return Total;
}
int Tax::pay_tax(int c){
	return c/20;
}
int main(){
	int usr_num,input;
	Tax t;
	cin >> usr_num;
	for(int i=0;i < usr_num;i++){
		cout << "User" << i+1 << "'s salary per month:";
		for(int j=0;j < 12;j++){
			cin >> input;
			t.input_salar(input,j);
			cout << input << (j<11?" ":"\n");	
		}
		cout << "User" << i+1 << "has to pay $" << t.pay_tax(t.total()) <<" this year ." << '\n' << "==========" << '\n';
	}
	return 0;
}
