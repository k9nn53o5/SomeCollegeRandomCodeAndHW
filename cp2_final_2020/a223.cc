#include <iostream>
#include <vector>
using namespace std;

int allhavewater(vector<int> &v){
	for(int i=0;i<v.size()-1;i++){
		if(v[i] > 0 ){
			return 0;
		}
	}
	return 1;
}

void merge(vector<int> &v){
	vector<int> tmp;
	int i=0,j=1;
	while(i<v.size() && j<v.size()){
		if(v[i] <=0 && v[j] <= 0){
			tmp.push_back(v[i]);
			i++;
			j++;
		}
		else if(v[i]*v[j] < 0 || v[i]>0&&v[j]>0){
			tmp.push_back(v[i]+v[j]);
			i+=2;
			j+=2;
		}
	}
	if(i<v.size()){
		tmp.push_back(v[i]);
	}
	v.clear();
	for(int i=0;i<tmp.size();i++){
		v.push_back(tmp[i]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i0=0;i0<T;i0++){
		int N;
		scanf("%d",&N);
		vector<int> v;
		for(int i=0;i<N;i++){
			int tmp;
			scanf("%d",&tmp);
			if(i==0){
				v.push_back(tmp);
			}
			else{
				if(tmp * v[v.size()-1] >=0 ){
					v[v.size()-1] = v[v.size()-1]+tmp;
				}
				else{
					v.push_back(tmp);
				}
			}
		}
/*		
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<"\n";
*/		
		while(allhavewater(v) == 0){
			merge(v);
		}
		
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	
		//cout<<v.size()<<"\n";		

	}
	return 0;
}
