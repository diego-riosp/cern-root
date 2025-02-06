// Program to plot datapoints directly using TGraph with first two columns
// Command to run: 
// root -l tgraph_datafile1.cpp

void tgraph_datafile1() {
  TGraph* gr = new TGraph("tutorials/data/data2.dat");		// declaring TGraph pointer using data file name with first two columns
  gr->Draw();					// plotting graph on canvas
}
