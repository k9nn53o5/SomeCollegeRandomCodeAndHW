#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;


/*
   0
   1 2
   3 4 5 6
   7 8 9 10 11 12 13 14

po: po->left = po*2+1
po->right = po*2+2

 */

// 2**n-1+m = curnodenum
// 0<= m <=2**n

# define nullleaf -10e8
class atree{
	public:
		vector<int> tree;
		int nodenum;
		int treeh;
		atree();
		int pofloorlayer(int po);
		int poceillayer(int po);
		int findaddpo(int data,int rootpo);
		void aeit(int data);
		void printtree();
		int finddatapo(int data,int rootpo);
		void printBST(const std:: string& prefix,int index,bool isLeft);
		void printBST(int index);
	private:
};


atree:: atree(){
	tree.assign(1000,nullleaf);
	nodenum=0;
	treeh=0;
}

int atree:: pofloorlayer(int po){
	//layer not contain po node
	int h = floor(log2(po+1));
	return h;
}

int atree:: poceillayer(int po){
	//layer contain po node
	int h = ceil(log2(po+1));
	return h;
}

int atree:: findaddpo(int data,int rootpo){
	//find positon in the tree
	//po position 0:root 1:root->left 2:root->right 3:root->left->left ...
	if(tree[rootpo] == nullleaf){
		return rootpo;
	}
	int nextpo;
	if(data < tree[rootpo]){
		nextpo = rootpo*2+1;
	}
	else if(data >= tree[rootpo]){
		nextpo = rootpo*2+2;
	}
	return findaddpo(data,nextpo);
}

void atree:: aeit(int data){
	//add element in tree
	//it = tree.begin();
	int position = findaddpo(data,0);
	tree[position] = data;
	nodenum++;
	if(poceillayer(position) > treeh){
		treeh = poceillayer(position);
	}
	return;		
}
/*
void atree:: printtree(){
	//
	int treeheight = treeh;
	int printwidth = pow(2,treeheight)+3; 
	int curpo=0;

	for(int i=0;i<treeheight;i++){
		for(int j=0;j<pow(2,i);j++){
			for(int k=0;k<(int)(((printwidth-pow(2,i))/(pow(2,i)+1))+0.02*i);k++){
				printf(" ");
			}
			(tree[curpo] != nullleaf) ? printf("%d",tree[curpo]) : printf("x");
			curpo++;
		}
		printf("\n");
	}
}
*/

void atree:: printBST(const std::string& prefix,int index,bool isLeft){
	if(tree[index] != nullleaf){
		cout<<prefix;
		cout<<(isLeft ? "|--" : "\u2579--");
		
		cout<<tree[index]<<endl;

		printBST(prefix + (isLeft?"|  ":"   "),index*2+1,true);
		printBST(prefix + (isLeft?"|  ":"   "),index*2+2,false);
	}
}

void atree:: printBST(int index){
	printBST("",index,false);
}
int atree:: finddatapo(int data,int rootpo){
	if(tree[rootpo] == nullleaf){
		printf("This data is not in this tree\n");
		return -1;
	}
	if(tree[rootpo] == data){
		return rootpo;
	}
	int nextpo;
	if(data<tree[rootpo]){
		nextpo = rootpo*2 + 1;
	}
	else{
		nextpo = rootpo*2 + 2;
	}
	return finddatapo(data,nextpo);
}
int main(){
	//vector have 1000 place can carry data which all first intial as -1
	//bug: this tree can't put -10e9 in it
	//bug: this only can put 1000 data
	atree T;
	int list[12] = {4,7,5,8,2,1,6,2,10,3,9,2};
	printf("list input:");
	for(int i=0;i<12;i++){
		printf("%d ",list[i]);
	}
	printf("\n\n\n");
	for(int i=0;i<12;i++){
		T.aeit(list[i]);
	}
	//T.printtree();
	T.printBST(0);
	printf("\n\n");
	printf("find the position of 1,2,3:");
	printf("%d %d %d\n\n",T.finddatapo(1,0),T.finddatapo(2,0),T.finddatapo(3,0));
	return 0;
}
