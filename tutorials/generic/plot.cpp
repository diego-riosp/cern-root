// Program to plot with predefined settings
// Command to run: 
// root -l plot.cpp

void plot() {
  gStyle->SetAxisColor(2, "XY");
  gStyle->SetLabelColor(2, "XY");
  gStyle->SetLabelFont(42, "XY");
  gStyle->SetLabelSize(0.05, "XY");
  gStyle->SetTitleSize(0.07, "XY");
  gStyle->SetTitleColor(2, "XY");
  gStyle->SetTitleFont(42, "XY");
  gStyle->SetTitleOffset(0.69, "X");
  gStyle->SetTitleOffset(0.65, "Y");
        
  TGraph* gr = new TGraph("tutorials/data/data.dat","%lg %lg %*lg");
  gr->SetTitle("Distance Time Graph;Time (s); Distance (m)");
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(2);
  gr->SetMarkerColor(4);
  gr->SetLineWidth(3);
  gr->SetLineColor(4);
  gr->GetXaxis()->CenterTitle(true);
  gr->GetYaxis()->CenterTitle(true);
  
  TCanvas* c1 = new TCanvas("c1", "c1", 83, 137, 894, 713);
  c1->SetFillColor(41);
  c1->SetGridx();
  c1->SetGridy();  
  c1->SetFrameFillColor(30);
  c1->SetFrameLineWidth(3);
  
  TPaveText *pt = new TPaveText(0.3621076,0.9270073,0.7724215,0.9810219,"blNDC");
  pt->SetName("title");
  pt->SetBorderSize(0);
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetTextAlign(32);
  pt->SetTextColor(2);
  pt->SetTextFont(42);
  pt->SetTextSize(0.07320644);
  TText *pt_LaTex = pt->AddText("Distance Time Graph");
  gr->Draw();
  pt->Draw("same");
  c1->Print("plot.pdf");
  c1->Print("plot_settings.C");
}
