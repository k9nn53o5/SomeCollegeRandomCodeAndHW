#include <iostream>
#include <string>
using namespace std;

struct pos{
		int x;
		int y;
};
class Room{
	public:
		void setid(unsigned int a);
		void setname(string b);
		void setdescrip(string c);
		void setpos(int d,int e);
		void setcate(string f);
		void setabbr(char g);
		void printAll();
		struct pos position;
		char abbr;
	private:
		unsigned int id;
		string name; 
		string description;
		string category;
};
void Room::setid(unsigned int a){
	id=a;
}
void Room::setname(string b){
	name=b;
}
void Room::setpos(int d,int e){
	position.x=d;
	position.y=e;	
}
void Room::setdescrip(string c){
	description=c;
}
void Room::setcate(string f){
	category=f;
}
void Room::setabbr(char g){
	abbr = g;
}
void Room::printAll(){
	cout<<"Room#"<<id<<" "<<name<<' '<<'('<<position.x<<','<<position.y<<')'<<' '<<description<<' '<<category<<' ';

}
int main(){
	int roomNum;
	cin >> roomNum;
	Room array[roomNum];
	char str[4];
	struct pos curpos[4];
	struct pos max;
	unsigned int a;
	string b,c,f;
	int d,e;
	char g;
	for(int i=0;i<roomNum;i++){
		cin >> a;
		array[i].setid(a);
		cin.ignore(10,' ');
		cin >> b;
		array[i].setname(b);
		cin.ignore(10,' ');
		cin >> d>>e;
		array[i].setpos(d,e);
		cin.ignore(10,' ');
		cin >> c;
		array[i].setdescrip(c);
		cin.ignore(10,' ');
		cin >>f;
		array[i].setcate(f);
		cin.ignore(10,' ');
		cin >>g;
		array[i].setabbr(g);
	}
	for(int i=0;i<3;i++){
		cin >>str[i];		
	}
	for(int i=0;i<roomNum;++i){
		if(max.x<array[i].position.x){
			max.x = array[i].position.x;
		}
		if(max.y<array[i].position.y){
			max.y = array[i].position.y;
		}
	}
	max.x++;
	max.y++;
	for(int i=0;i<4;i++){
		if(i==0){
			curpos[i].x=0;
			curpos[i].y=0;
		}
		else{
			if(str[i-1] == 'n' && curpos[i-1].y != max.y-1){curpos[i].x = curpos[i-1].x; curpos[i].y=curpos[i-1].y+1;}
			else if(str[i-1] == 's' && curpos[i-1].y!=0){curpos[i].x=curpos[i-1].x;curpos[i].y=curpos[i-1].y-1;}
			else if(str[i-1] == 'e' && curpos[i-1].x != max.x-1){curpos[i].x=curpos[i-1].x+1;curpos[i].y=curpos[i-1].y;}
			else if(str[i-1] == 'w' && curpos[i-1].x!=0){curpos[i].x=curpos[i-1].x-1;curpos[i].y=curpos[i-1].y;}
			else{curpos[i].x=curpos[i-1].x;curpos[i].y=curpos[i-1].y;}
		}
	}

	Room order[max.x][max.y];
	for(int i1=0;i1<max.y-1;i1++){
		for(int i2=0;i2<max.x-1;i2++){
			for(int i3=0;i3<roomNum;i3++){
				if(i1 == array[i3].position.y && i2 == array[i3].position.x){
					order[i1][i2] = array[i3];
				}
			}
		}
	}
//	for(int i3=0;i3<max.x * max.y;i3++){
//		for(int i2=0;i2<max.y;i2++){
//			for(int i1=0;i1<max.x;i1++){
//				if(array[i3].position.x == i1 || array[i3].position.y == i2)
//			}
//		}
//	}
	for(int i2=0;i2<4;i2++){
		for(int i1=0;i1<max.y+2;i1++){
			if(i1 == 0 || i1 == max.y+1){
				cout<<"++++++++++++++++++++";	
			}
			else{
				for(int i0=0;i0<4*max.x+1;i0++){
					if(i0%4 == 0){
						cout<<'+';
					}
					else if( i0%4 == 3){
						cout<<" ";
					}
					else if(i0%4 == 1 && curpos[i2].x !=(i0-1)/4 && curpos[i2].y!=max.y-i1){
						cout<<" "; 
					}
					else if(i0%4 == 1 && curpos[i2].x==(i0-1)/4  && curpos[i2].y==max.y-i1){
						cout<<"H";
					}
					else{
						cout<<order[max.y-i1][(i0-1)/4].abbr;
					}
				}
			}
			cout<<"\n";
		}	
	}
	for(int i=0;i<roomNum;i++){
		array[i].printAll();
		cout<<"\n";}
	cout<<"===============================\n";
	for(int i1=0;i1<max.y;i1++){
		for(int i2=0;i2<max.x;i2++){
		order[i1][i2].printAll();
		cout<<"\n";}}
/*
	for(int i2=0;i2<4;i2++){
		for(int i1=0;i1<roomNum;i1++){
			if(array[i1].position.x==curpos.x && array[i1].position.y==curpos.y){
				array[i1].printAll();
				if(i2 == 3)
				break;
				if(str[i2]=='n'){
					curpos.y++;
					if(curpos.y>max.y){
						curpos.y--;
					}
				}
				else if(str[i2]=='s'){
					curpos.y--;
					if(curpos.y<0){
						curpos.y=0;
					}
				}
				else if(str[i2]=='w'){
					curpos.x--;
					if(curpos.x<0){
						curpos.x = 0;
					}
				}
				else if(str[i2]=='e'){
					curpos.x++;
					if(curpos.x>max.x){
						curpos.x--;
					}
				}
				else{
					cout << "error" << endl;
				}
				break;
			}	
		}
	}																			*/
		return 0;
}
