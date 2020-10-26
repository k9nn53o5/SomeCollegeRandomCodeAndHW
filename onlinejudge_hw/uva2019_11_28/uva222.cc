#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct stainf{
	// dist from origin x
	// cost per gall cent
	double x;
	double cpg;
};

// function min money will spend
double mmws(double td,double cap,double mpg,int sn,struct stainf* arrptr,double po,int nowsta){
	//mds -> money had already spend
	/*	
	for(int i=0;i<sn;i++){
		cout<<"{"<<arrptr[i].x<<","<<arrptr[i].cpg<<"}";
	}
	*/
	if(po + mpg*cap >= td || nowsta == sn){
		return 0;
	}
	double best = 1e9;
	for(int i = nowsta+1; i < sn; i++){
		double gasleft = cap - ((arrptr[i].x - po) / mpg);
		if(gasleft < 0){break;}
		if(gasleft <= cap/2){
			best=min(best,200 + (cap - gasleft)*arrptr[i].cpg + mmws(
						td,cap,mpg,sn,arrptr,arrptr[i].x,i));
		}
		else if(gasleft >= cap/2 && i+1 < sn && arrptr[i+1].x - po > cap * mpg ){
			best=mmws(td,cap,mpg,sn,arrptr,arrptr[i].x,i);
		}
	}
	return best;
}

int main(){

	// claim total distance,tank capacilty, mile per gallon, first station cost(dollar)
	// station num
	double td,cap,mpg,fsc;
	int sn,casen=0;
	while(cin>>td){
		if(td == -1.0){
			break;
		}
		cin>>cap>>mpg>>fsc>>sn;
		struct stainf arrptr[sn];
		struct stainf* s = arrptr;
		for(int i=0;i<sn;i++){
			cin>>arrptr[i].x>>arrptr[i].cpg;
		}
		cout<<"Data Set #"<<++casen<<"\n";
		printf("minimum cost = $%.2f\n",fsc + (mmws(td,cap,mpg,sn,s,0,-1) / 100));
		//break;
		/*
		cout<<"td cap mpg fsc sn:"<<" "<<td<<" "<<cap<<" "<<mpg<<" "<<fsc<<" "<<sn<<"\n";
		for(int i=0;i<sn;i++){
			cout<<"{"<< arrptr[i].x<<","<<arrptr[i].cpg<<"}";
		}
		cout<<"\n";
		*/
	}	
	return 0;
}
