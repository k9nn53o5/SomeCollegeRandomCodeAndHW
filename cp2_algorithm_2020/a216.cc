#include <iostream>
#include <math.h>
#include <list>
using namespace std;

class Point {
	public:
		int xval, yval;
		Point(double x = 0.0, double y = 0.0) {
			xval = x;
			yval = y;
		}
		double x() const { return xval; }
		double y() const { return yval; }

		double dist(const Point & other) const {
			double xd = xval - other.xval;
			double yd = yval - other.yval;
			return sqrt(xd*xd + yd*yd);
		}

		Point add(Point b) const
		{
			return Point(xval + b.xval, yval + b.yval);
		}
		Point sub(Point b) const
		{
			return Point(xval - b.xval, yval - b.yval);
		}

		void move(double a, double b)
		{
			xval += a;
			yval += b;
		}


		void print(ostream &strm) const
		{
			strm << "(" << xval << "," << yval << ")";
		}
};

void printMaze(char** maze2D,int N){
	printf("\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<100&&maze2D[i][j]!='\0';j++){
			printf("%c ",maze2D[i][j]);
		}
		printf("\n");
	}
	return;
}

bool judgeAdj(char** maze2D,int x,int y,int N){
	if(x<0 || y<0 || x>=N){
		return false;
	}
	if(maze2D[x][y] == '\0' || maze2D[x][y]=='#' || maze2D[x][y]=='*'){
		return false;
	}
	return true;
}

int bfs(char** maze2D,int N){
	//find the start_point and target
	Point s(0,0);
	int distM[N][100];

	for(int i=0;i<N;i++){
		for(int j=0;j<100&&maze2D[i][j]!='\0';j++){
			if(maze2D[i][j] == 'K'){
				distM[i][j]=0;
				s.move(i,j);
			}
			else if(maze2D[i][j] == '@'){
				distM[i][j]=0;
			}
			else if(maze2D[i][j] == '.'){
				distM[i][j]=0;
			}
			else{
				distM[i][j]=-1;
			}
		}
	}
	/*
	if(t.xval==-1 && t.yval==-1){
		return -1;
	}
	*/
	//do bfs to find the closest target
	//count step at the same time
	//       # wall   . unvisitedpoint    * visitedpoint and distance
	//       K startpoin      @ target
	list<Point> queue;

	maze2D[s.xval][s.yval] = '*';
	queue.push_back(s);

	while(!queue.empty()){
		Point p = queue.front();

		//p.print(cout);
		queue.pop_front();
		
		if(judgeAdj(maze2D,p.xval-1,p.yval,N)){
			Point tmp(p.xval-1,p.yval);
					
			if(maze2D[tmp.xval][tmp.yval] == '@'){
				maze2D[tmp.xval][tmp.yval] = '*';
				distM[tmp.xval][tmp.yval] = distM[p.xval][p.yval] + 1;
				return distM[tmp.xval][tmp.yval];
			}
		
			
			maze2D[tmp.xval][tmp.yval] = '*';
			distM[tmp.xval][tmp.yval] = distM[p.xval][p.yval] + 1;

			queue.push_back(tmp);
		}
		if(judgeAdj(maze2D,p.xval,p.yval-1,N)){
			Point tmp(p.xval,p.yval-1);	
			if(maze2D[tmp.xval][tmp.yval] == '@'){
				maze2D[tmp.xval][tmp.yval] = '*';
				distM[tmp.xval][tmp.yval] = distM[p.xval][p.yval] + 1;
				return distM[tmp.xval][tmp.yval];
			}
			
			maze2D[tmp.xval][tmp.yval] = '*';
			distM[tmp.xval][tmp.yval] = distM[p.xval][p.yval] + 1;
			
			queue.push_back(tmp);
		}
		if(judgeAdj(maze2D,p.xval+1,p.yval,N)){
			Point tmp(p.xval+1,p.yval);

			
			if(maze2D[tmp.xval][tmp.yval] == '@'){
				maze2D[tmp.xval][tmp.yval] = '*';
				distM[tmp.xval][tmp.yval] = distM[p.xval][p.yval] + 1;
				return distM[tmp.xval][tmp.yval];
			}

			maze2D[tmp.xval][tmp.yval] = '*';
			distM[tmp.xval][tmp.yval] = distM[p.xval][p.yval] + 1;
			
			queue.push_back(tmp);
		}
		if(judgeAdj(maze2D,p.xval,p.yval+1,N)){		
			Point tmp(p.xval,p.yval+1);
			
			
			if(maze2D[tmp.xval][tmp.yval] == '@'){
				maze2D[tmp.xval][tmp.yval] = '*';
				distM[tmp.xval][tmp.yval] = distM[p.xval][p.yval] + 1;
				return distM[tmp.xval][tmp.yval];
			}

			maze2D[tmp.xval][tmp.yval] = '*';
			distM[tmp.xval][tmp.yval] = distM[p.xval][p.yval] + 1;
			
			queue.push_back(tmp);
		}
	}
	return -1;
}

int main(){
	int N;
	while(cin>>N){
		if(N == 0){break;}
		getchar();
		char maze[N][100];
		char* mazeptr[N];
		char** maze2D = mazeptr;			
		for(int i=0;i<N;i++){
			scanf("%[^\n]",maze[i]);
			getchar();
			mazeptr[i] = maze[i];
		}
		int result = bfs(maze2D,N);
		
		if(result == -1){
			cout<<"= ="<<endl;
		}
		else{
			cout<<result<<endl;
		}
		
		//printMaze(maze2D,N);

	}
	return 0;
}
