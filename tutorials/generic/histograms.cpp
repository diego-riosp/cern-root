#include <iostream>
#include <TCanvas.h>
#include <TRandom3.h>
#include <TH1D.h>

using namespace std;

void histograms() {
    TCanvas * c1 = new TCanvas("c1", "Histograms", 800, 600);
    TH1D * h1 = new TH1D("h1", "this is my tittle; x name; frequency", 50, 0, 100);
    TRandom3 * r = new TRandom3();

    for (int ij = 0; ij < 100; ij++) {
        //h1->Fill(r->Uniform(20,70));
        h1->Fill(r->Gaus(30,10));
    }
    
    int bins = h1->GetNbinsX();
    
    int b=1;

    while (b<bins)
    {
        cout<<b<<"\t"<<h1->GetBinCenter(b)<<"\t"<<h1->GetBinContent(b)<<endl;
        b++;
    }

    h1->Fit("gaus");
    //h1->Draw("hist");
    h1->Draw();

    //h1->SetMaximum(120);
    //h1->SetMinimum(-10);
    h1->SetStats(0); //Hide the stats in the top square
    h1->GetXaxis()->SetRangeUser(5,70);

}
