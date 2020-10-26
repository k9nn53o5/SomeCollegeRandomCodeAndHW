/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     QueueTest.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Dec 11, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
}

#include <iostream>
#include <fstream>
#include "AnsiPrint.h"
#include "Node.h"
#include "Queue.h"

using namespace std;

/**
 * Print my id 
 */

void
PrintMyID(const char *studId) {

  char *str= new char[strlen(studId)+5];
  sprintf(str,"ID: %s",studId);
  AnsiPrint(str,yellow,red,true,true);
  cout << endl ;
  delete [] str;

}

/**
 * PrintUsage
 */

void
PrintUsage(const char *progName) {

    assert(progName);
    cout << "Usage: " << progName << " [passes [display [seed]]]" << endl;

}

int
main(int argc, char **argv) {

  istream *is1=&cin,*is2=&cin;

  if (argc>3) {
    PrintUsage(argv[0]);
    exit(-1);
  } else if (argc>2) {
    is2 = new ifstream(argv[2]);
    if (is2==NULL) {
      cerr << "Can't open file " << argv[2] << endl;
      exit(1);
    }
  } 
  if (argc>1) {
    is1 = new ifstream(argv[1]);
    if (is1==NULL) {
      cerr << "Can't open file " << argv[1] << endl;
      exit(2);
    }
  }

  // You need to provide testing exercises here
  char ch;int inter;
  ifstream file1,file2;
  Queue<int> intQ;
  Queue<char> chQ;
  file1.open(argv[1]);
  if(!file1.is_open()){
		cout<<"open file1 fail"<<endl;
  }
  else{
	while(1){
		file1 >> inter;
		if(inter == '\0'||file1.eof()||inter=='\n'){
			break;
		}
		if(intQ.enqueue(inter)){
		}
		else{
			cout<<"enqueue fail";
		}
	}
	file1.close();
  }
  file2.open(argv[2]);
  if(!file2.is_open()){
		cout<<"open file2 fail"<<endl;
  }
  else{
	while(1){
		file2>>ch;
		if(ch == '\0'||file2.eof()||ch=='\n' ){
			break;
		}
		if(chQ.enqueue(ch)){
		}
		else{
			cout<<"enqueue fail";
		}
	}
	file2.close();
  }
  char *str1="Interger Queue:";
  AnsiPrint(str1,yellow,nochange,false,true);
  while(1){
  	cout<<endl<<intQ.peek();
  	if(intQ.dequeue()){}
	else if(!intQ.dequeue()||intQ.isempty()){
	//	char *str="Attemp to dequeue empty queue";
	//	AnsiPrint(str,red,yellow,true,true);
		cout<<endl;
		break;
	}
  }
  char *str2="Character Queue:";
  AnsiPrint(str2,yellow,nochange,false,true);
  while(1){
	cout<<endl<<chQ.peek();
	if(chQ.dequeue()){}
	else if(!chQ.dequeue()||chQ.isempty()){
		char *str ="Attemp to dequeue empty queue";
		AnsiPrint(str,red,yellow,true,true);
		cout<<endl;
		break;
	}
  }
  
  
  PrintMyID("105703037");
  return 0;
    
}
