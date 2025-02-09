// Program to plot datapoints one by one using method SetPoint in TGraph
// Command to run: 
// root -l tgraph_points.cpp

#include <TGraph.h>
#include <fstream>

using namespace std;

void tgraph_points() {
  ifstream infile;		// input file handle
  infile.open("tutorials/data/data2.dat");	// opening input data file 

  double x,y;			// variable for storing data points while reading

  TGraph* gr = new TGraph();	// declaring TGraph pointer
  int i=0;			// counter for index of data point
  while (infile>>x>>y) {	// reading data point in while loop
    //cout<<x<<"\t"<<y<<endl;	
    gr->SetPoint(++i,x,y);	// Adding data point to graph
  }

  gr->Draw();			// plotting graph on canvas
}
