#include <TROOT.h>
#include <TObject.h>
#include <TFile.h>
#include <TTree.h>

using namespace std;

void example1() {

    TTree * t = new TTree("t","A tree");
    int a, b, c;

    t->Branch("a", &a, "a/I");
    t->Branch("b", &b, "b/I");
    t->Branch("c", &c, "c/I");

    t->Print();
    a = 16;     b = 25;     c = 36;     t->Fill();
    a = 2;     b = 4;     c = 6;     t->Fill();
    a = 100;     b = 300;     c = 400;     t->Fill();
    t->Print();
    t->Scan();

    TFile * f = new TFile("example1.root","recreate");
    t->Write();
    f->Close();
}

void example2() {

    TTree * t = new TTree();
}

