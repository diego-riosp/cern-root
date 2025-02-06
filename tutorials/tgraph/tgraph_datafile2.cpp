// Program to plot datapoints directly using TGraph with first two columns out of 3 columns
// Command to run: 
// root -l tgraph_datafile2.cpp

void tgraph_datafile2() {
  TGraph* gr = new TGraph("tutorials/data/data3.dat");		// declaring TGraph pointer with first two columns out of 3 columns
  gr->Draw();					// plotting graph on canvas
}
