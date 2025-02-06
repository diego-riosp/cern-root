#ifdef __CLING__
#pragma cling optimize(0)
#endif
void plot_settings()
{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Feb  6 18:38:13 2025) by ROOT version 6.32.08
   TCanvas *c1 = new TCanvas("c1", "c1",2621,41,894,713);
   c1->Range(-1.25,-2.5,12.25,24.5);
   c1->SetFillColor(41);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetFrameFillColor(30);
   c1->SetFrameLineWidth(3);
   c1->SetFrameBorderMode(0);
   c1->SetFrameFillColor(30);
   c1->SetFrameLineWidth(3);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   Double_t Graph0_fy1[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
   TGraph *graph = new TGraph(10,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Distance Time Graph");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(3);
   graph->SetMarkerColor(4);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Distance Time Graph",100,0.1,10.9);
   Graph_Graph01->SetMinimum(0.2);
   Graph_Graph01->SetMaximum(21.8);
   Graph_Graph01->SetDirectory(nullptr);
   Graph_Graph01->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph01->SetLineColor(ci);
   Graph_Graph01->GetXaxis()->SetTitle("Time (s)");
   Graph_Graph01->GetXaxis()->CenterTitle(true);
   Graph_Graph01->GetXaxis()->SetAxisColor(2);
   Graph_Graph01->GetXaxis()->SetLabelColor(2);
   Graph_Graph01->GetXaxis()->SetLabelFont(42);
   Graph_Graph01->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph01->GetXaxis()->SetTitleSize(0.07);
   Graph_Graph01->GetXaxis()->SetTitleOffset(0.69);
   Graph_Graph01->GetXaxis()->SetTitleColor(2);
   Graph_Graph01->GetXaxis()->SetTitleFont(42);
   Graph_Graph01->GetYaxis()->SetTitle(" Distance (m)");
   Graph_Graph01->GetYaxis()->CenterTitle(true);
   Graph_Graph01->GetYaxis()->SetAxisColor(2);
   Graph_Graph01->GetYaxis()->SetLabelColor(2);
   Graph_Graph01->GetYaxis()->SetLabelFont(42);
   Graph_Graph01->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph01->GetYaxis()->SetTitleSize(0.07);
   Graph_Graph01->GetYaxis()->SetTitleOffset(0.65);
   Graph_Graph01->GetYaxis()->SetTitleColor(2);
   Graph_Graph01->GetYaxis()->SetTitleFont(42);
   Graph_Graph01->GetZaxis()->SetLabelFont(42);
   Graph_Graph01->GetZaxis()->SetTitleOffset(1);
   Graph_Graph01->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph01);
   
   graph->Draw("alp");
   
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
   pt->Draw();
   c1->Modified();
   c1->SetSelected(c1);
}
