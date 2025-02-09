
// source: www.techforcurious.website
// Command to run: 
// g++ hello.cpp `root-config --cflags --glibs`
// ./a.out

#include<iostream>
#include<TH1D.h>
#include<TFile.h>
using namespace std;
void multiply(){
  cout<<2*3<<endl;
}

void hello(){
  cout<<"Hello World"<<endl;
}

void addition(){
  cout<<2+3<<endl;
}

int main() {
  cout<<"Hello from main"<<endl;
  multiply();
  TH1D* h;
  TFile* f;
}
