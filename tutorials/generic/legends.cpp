void legends() {
    TGraph * gr = new TGraph("tutorials/data/data.dat", "%lg %*lg %lg");
    gr->SetMarkerStyle(3);
    TF1 * f1 = new TF1("f1", "pol2");
    gr->Fit(f1);
    
    TLegend * leg = new TLegend(0.2,0.6,0.5,0.8); //Are the corners of the legend box.

    double * par = f1->GetParameters();

    leg->SetBorderSize(1);
    leg->SetFillColor(0);
    leg->SetFillStyle(0);
    //leg->SetNColumns(2);
    leg->SetHeader("My header","C");
    leg->AddEntry(gr, "Data points", "p");
    leg->AddEntry((TObject*)0,"Some text","");
    leg->AddEntry(f1, Form("%4.2fx^{2}+%4.2fx+%4.2f", par[2], par[1], par[0]), "l");
    
    gr->Draw();
    leg->Draw("same");
}
