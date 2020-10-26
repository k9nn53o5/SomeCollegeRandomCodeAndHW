#include<iostream> 
using namespace std; 
class Room{ 

	public: 
		void Set(int ID, string N , int x, int y, string D, string F,char AD); 
		int getX(); 
		int getY(); 
		char getAd(); 
	private: 
		int id; 
		int pos_x; 
		int pos_y; 
		string Desc; 
		string Name; 
		string ForCate; 
		char add; 
}; 
void Room::Set(int ID, string N ,int x,int y, string D, string F,char AD){ 
	id =ID; 
	pos_x=x; 
	pos_y=y; 
	Desc=D; 
	Name=N; 
	ForCate=F; 
	add=AD; 
} 

int Room::getX(){ 
	return pos_x; 
} 

int Room::getY(){ 
	return pos_y; 
} 

char Room::getAd(){ 
	return add; 
} 

int main(){ 
	Room rooms[1000]; 
	char position[5]; //news 
	int Cnt_R; 
	cin>>Cnt_R; 

	int in_id,in_x,in_y; 
	string d,n,f; 
	char ad; 
	for(int i=0;i<Cnt_R;i++){ 
		cin>>in_id>>n>>in_x>>in_y>>d>>f>>ad; 
		rooms[i].Set(in_id,n,in_x,in_y,d,f,ad); 
	} 

	for(int i=0;i<5;i++){ 
		cin>>position[i]; 
	} 

	int now_x,now_y,max_X,max_Y; 
	max_X = rooms[0].getX(); 
	max_Y = rooms[0].getY(); 

	for(int i=0;i<Cnt_R;i++){ 
		if(rooms[i].getX() > max_X) 
			max_X = rooms[i].getX(); 
		if(rooms[i].getY() > max_Y) 
			max_Y = rooms[i].getY(); 
	} 

	now_x=0; 
	now_y=0; 

	for(int i=0;i<6;i++){ 

		cout<<"++++++++++++++++++++"<<endl; 
		for(int r1=max_Y;r1>=0;r1--){ 
			for(int r2=0;r2<=max_X;r2++){ 
				cout<<'+'; 

				if(now_y==r1 && now_x==r2) 
					cout<<'H'; 
				else 
					cout<<' '; 
				int turn = 0; 
				for(int k=0;k<Cnt_R;k++){ 
					if(rooms[k].getX()==r2 && rooms[k].getY()==r1){ 
						cout<<rooms[k].getAd(); 
						turn = 1; 
						break; 
					} 
				} 
				if(turn!=1) 
					cout<<' '; 

				cout<<' '; 
			} 
			cout<<'+'<<endl; 
		} 
		cout<<"++++++++++++++++++++"<<endl; 
		if(i!=5){ //last time 

			if(position[i]=='n' && now_y+1<=max_Y){ 
				for(int k=0;k<Cnt_R;k++){ 
					if(rooms[k].getY() == now_y+1 && rooms[k].getX()== now_x){ 
						now_y+=1; 
						break; 
					} 
				} 
			} 
			else if(position[i]=='e' && now_x+1<=max_X){ 
				for(int k=0;k<Cnt_R;k++){ 
					if(rooms[k].getX() == now_x+1 && rooms[k].getY()== now_y){ 
						now_x+=1; 
						break; 
					} 
				} 
			} 
			else if(position[i]=='w' && now_x-1>=0){ 
				for(int k=0;k<Cnt_R;k++){ 
					if(rooms[k].getX() == now_x-1 && rooms[k].getY()== now_y ){ 
						now_x-=1; 
						break; 
					} 
				} 
			} 
			else if(position[i]=='s' && now_y-1>=0){ 
				for(int k=0;k<Cnt_R;k++){ 
					if(rooms[k].getY() == now_y-1 && rooms[k].getX()== now_x ){ 
						now_y-=1; 
						break; 
					} 
				} 
			} 
		} 
	} 

	return 0; 
}
