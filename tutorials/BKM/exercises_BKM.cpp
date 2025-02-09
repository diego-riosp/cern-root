#include <iostream>
#include <TF1.h>
#include <TCanvas.h>
#include <TGraphErrors.h>
#include <TRandom3.h>
#include <TLegend.h>
#include <TH1F.h>

using namespace std;
void exercises_BKM() {
cout<<"This is a solution of each proposed exercise in ROOT tutorial by Brunner, Krucker and Mohamed"<<endl;
}

void exerciseHistograms() {
    
    TCanvas *c1 = new TCanvas("c1", "Example Canvas", 800, 600);

    TH1F * h = new TH1F("h","Exercise 1: Creating a histogram; x bins; Frequency",10,0,100);
    h->Fill(11.3);
    h->Fill(25.4);
    h->Fill(18.1);

    int i = 0;
    while (i<=9)
    {
        h->Fill(i*i);
        i++;
    }

     
    h->Fit("gaus");
    h->Draw("hist");
    TAttLine *att = (TAttLine*)h->GetListOfFunctions()->FindObject("line");
    if (att) {
       att->SetLineColor(kRed); 
    }
    cout<<"Mean value: "<<h->GetMean()<<endl;
    cout<<"RMS: "<<h->GetRMS()<<endl;
    
    
    int x = 0;

    for (int i = 0; i < h->GetNbinsX(); i++) {
          x = 10*(h->GetBinContent(i)) + x;      
    }

    cout<<"Histogram integral: "<<x<<"\t"<<h->Integral()<<endl;
    cout<<"Maximum frequency bin; "<<h->GetMaximum()<<endl;

    c1->Update();
}

void exerciseCanvas() {
    //Creating Canvas     
    TCanvas * c1 = new TCanvas("c1","Canvas(1) Exercise",800,600); 
    //Defining 1-dimensional float histograms
    TH1F * h1 = new TH1F("h1","Histogram 1;x bins;Frequency",50,-3,3);
    TH1F * h2 = new TH1F("h2","Histogram 2;x bins;Frequency",50,-3,3);
    
    //Filling first histogram
    TRandom3 * r = new TRandom3();
    for (int i = 0; i < 1000; i++) {
        h1->Fill(r->Gaus(2,1));
    }
    
    //Filling second histogram 
    h2->FillRandom("pol2",500);
    
    //Cloning histograms

    TH1F * h1b = (TH1F*) h1->Clone();
    TH1F * h2b = (TH1F*) h2->Clone();
    
    TF1 * f = new TF1("f","gaus");
    h1->Fit(f);
    h2->Fit(f);

    
    //Changing histogram styles
    h1->SetLineColor(1);
    h2->SetLineColor(2);
    h1->SetLineWidth(3);
    h2->SetLineWidth(3);
    
    //Plotting histograms
    h1->Draw();
    h2->Draw("same");
    
    //Creating legend
    TLegend * l1 = new TLegend(0.16, 0.63, 0.45, 0.91);
    l1->AddEntry(h1, "Gaussian", "l");
    l1->AddEntry(h2, "Polygon", "l");

    //Plotting legend
    l1->Draw();

    //Updating canvas
    c1->Update();
    
    //Creating second canvas
    TCanvas * c2 = new TCanvas("c2","Canvas(2) Exercise",800,600);

    //Computing histogram integrals    
    double intgr1 = h1b->Integral();
    double intgr2 = h2b->Integral();
    
    //Normalising cloned histograms
    int n=1;
    while(n<=h1b->GetNbinsX()){
        double entrie1 = h1b->GetBinContent(n);
        double entrie2 = h2b->GetBinContent(n);
        h1b->SetBinContent(n, pow(intgr1,-1) * entrie1);
        h2b->SetBinContent(n, pow(intgr2,-1) * entrie2);
        n++;
    }
    
    //Verifying normalisation
    cout<<"Now, the histogram 1(2) clonated is normalized to: "<<h1b->Integral()<<"("<<h2b->Integral()<<")"<<endl;
    


    //Setting cloned histogram styles
    h1b->SetLineColor(1);
    h2b->SetLineColor(2);
    h1b->SetLineWidth(3);
    h2b->SetLineWidth(3);
    
    TF1 * ff = new TF1("ff","gaus");

    h1b->Fit(ff);
    h2b->Fit(ff);
    
    h1b->Draw();
    h2b->Draw("same");
    
    //Creating legend for cloned histograms
    TLegend * l2 = new TLegend(0.16, 0.63, 0.45, 0.91);
    l2->AddEntry(h1b, "Gaussian normalised", "l");
    l2->AddEntry(h2b, "Polygon normalised", "l");

    //Plotting legend
    l2->Draw();

    //Writing .pdf and .root files for each canva 
    c1->SaveAs("tutorials/BKM/exerciseCanvas1.pdf");
    c1->SaveAs("tutorials/BKM/exerciseCanvas1.root");
    c2->SaveAs("tutorials/BKM/exerciseCanvas2.pdf");
    c2->SaveAs("tutorials/BKM/exerciseCanvas2.root");
}
