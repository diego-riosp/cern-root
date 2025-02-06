// Program to plot datapoints using array in TGraph
// root -l tgraph_array.cpp

void tgraph_array() {
  double x[]={1,2,3,4,5};		// array for x list
  double y[]={1,4,9,16,25};		// array for y list

  TGraph* gr = new TGraph(5,x,y);	// declaring TGraph pointer using array
  gr->Draw();				// plotting graph on canvas
}
