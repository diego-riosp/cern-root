#include <ROOT/RDataFrame.hxx>
#include <TRandom.h>


void df000_simple() {

    ROOT::RDataFrame rdf(100); //Create a data frame with 100 rows
    auto rdf_x = rdf.Define("x", [](){ return gRandom->Rndm(); }); //Define a new column x that contains random numbers

    auto h = rdf_x.Histo1D("x"); //At the end of this function, the histogram pointed to by h will be deleted. Draw a copy of the histogram object instead:

    h->DrawClone(); //Draw a copy of the histogram object instead: 
    gROOT->GetListOfCanvases()->Draw(); //Draw all canvases
    
}
