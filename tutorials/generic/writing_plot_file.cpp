void writing_plot_file() {
    
    TFile * f = new TFile("tutorials/data/data.root", "RECREATE"); //RECREATE overwrties the file in case that it's actually created.

    //Making histogram
    TH1D * h1 = new TH1D("h1", "this is my tittle; x name; frequency", 50, 0, 100);
    TRandom3 * r = new TRandom3();

    for (int ij = 0; ij < 100; ij++) {
        h1->Fill(r->Gaus(30,10));
    }
    
    int bins = h1->GetNbinsX();
   
    int b=1;


    h1->Fit("gaus");

    h1->SetStats(0);
    h1->Draw();

    //Making Graph
    TGraph* gr;
    gr = new TGraph("tutorials/data/data.dat", "%lg %*lg %lg");
    gr->SetMarkerStyle(3);
    gr->Draw();

    h1->Write("hist1");
    gr->Write("graph1");
}
