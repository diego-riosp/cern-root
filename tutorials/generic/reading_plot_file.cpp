#include <TFile.h>
#include <TH1D.h>
#include <TGraph.h>

void reading_plot_file() {
    TFile * file = new TFile("tutorials/data/data.root", "READ");

    TH1D * h1;
    file->GetObject("hist1", h1); //Method 1 to read
    h1->Draw();
    
    TGraph * gr = (TGraph*) file->Get("graph1");
    gr->Draw();

}
