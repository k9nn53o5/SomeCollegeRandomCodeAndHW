#include <cstdio>
#include <vector>
using namespace std;

void swap(vector<int> & vec,int i,int j){
	int tmp = vec[i];
	vec[i] = vec[j];
	vec[j] = tmp;
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int n;
		vector <int> vec;
		int count=0;
		scanf("%d",&n);
			for(int j=0;j<n;j++){
				int tmp;
				scanf("%d",&tmp);
				vec.push_back(tmp);

				for(int k=0;k<vec.size()-1;k++){
					for(int l=0;l<vec.size()-1;l++){
						if(vec[l] > vec[l+1]){
							swap(vec,l,l+1);
							count++;
						}
					}
				}

			}
		printf("%d\n",count);
	}
}
