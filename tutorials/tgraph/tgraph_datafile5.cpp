// Program to plot datapoints directly using TGraph with first and third columns as well as delimiter "," and ";"
// Command to run: 
// root -l tgraph_datafile5.cpp

void tgraph_datafile5() {
  TGraph* gr = new TGraph("tutorials/data/data3delimit1.dat","%lg %*lg %lg",",;"); //declaring TGraph pointer with first and third columns as well as delimiter "," and ";"
  gr->Draw();					// plotting graph on canvas
}
