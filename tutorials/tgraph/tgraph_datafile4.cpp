// Program to plot datapoints directly using TGraph with first and third columns as well as delimiter ","
// Command to run: 
// root -l tgraph_datafile4.cpp

void tgraph_datafile4() {
  TGraph* gr = new TGraph("tutorials/data/data3delimit.dat","%lg %*lg %lg",",");// declaring TGraph pointer with first and third columns as well as delimiter ","
  gr->Draw();					// plotting graph on canvas
}
