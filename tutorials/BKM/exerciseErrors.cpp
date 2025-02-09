#include <iostream>
#include <TF1.h>
#include <TCanvas.h>
#include <TGraphErrors.h>
#include <TRandom3.h>
#include <TH1F.h>

using namespace std;


void exerciseErrors() {
    
    //Defining error graph
    TGraphErrors * g = new TGraphErrors(5);
    
    //Settinf 5 points
    g->SetPoint(0,1.0,2.1);
    g->SetPoint(1,2.0,2.9);
    g->SetPoint(2,3.0,4.05);
    g->SetPoint(3,4.0,5.2);
    g->SetPoint(4,5.0,5.95);
    
    //Declaring error in each point
    g->SetPointError(0,0.0,0.1);
    g->SetPointError(1,0.0,0.1);
    g->SetPointError(2,0.0,0.1);
    g->SetPointError(3,0.0,0.1);
    g->SetPointError(4,0.0,0.1);
    
    TF1 * f = new TF1("f","pol1");
    g->Fit(f,"","",0,5);

    TCanvas * c1 = new TCanvas("c1", "Errors in y=ax+b", 800, 600);
    g->Draw("AP");
    c1->Update();

    const double * par = f->GetParameters();
    const double * par_err = f->GetParErrors();

    cout<<"For y=ax+b,"<<endl;
    cout<<"a="<<par[0]<<"\tea="<<par_err[0]<<endl;
    cout<<"b="<<par[1]<<"\teb="<<par_err[1]<<endl;

    TH1F * h = new TH1F("h","Fitted gaussian histogram;x bins;frequency",100,-5,5);
    TRandom3 * r = new TRandom3();
    int i=0;
    while (i < 10000)
    {
        h->Fill(r->Gaus(0,1));
        i++;
    }
    TF1 * ff = new TF1("ff","gaus");

    TCanvas * c2 = new TCanvas("c2", "Fitted histogram", 800, 600);
    h->Fit(ff);
    h->Draw();
    c2->Update();
}
