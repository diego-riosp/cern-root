//#include <TROOT.h>
#include <iostream>
#include <TObject.h>
#include <TFile.h>
#include <TTree.h>
//#include <TSystem.h>
#include </home/linuxuser/Documents/cern-root/tutorials/trees/particle_CLASS.h>

#define TREES_PATH "/home/linuxuser/Documents/cern-root/tutorials/trees/"

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

    TFile * f = new TFile(TREES_PATH"example1.root","recreate");
    t->Write();
    f->Close();
}

void example2() {

    TTree * t = new TTree("t", "A tree");

    int a[2] = {0};
    int b[3] = {0};
    
    t->Branch("A",a,"aa[2]/I");
    t->Branch("B",b,"bb[3]/I");
    
    a[0] = 10; b[0] = 9;
    a[1] = 110; b[1] = 99;
    b[2] = 999; t->Fill();

    t->Print();
    t->Scan();

    a[0] = 20; b[0] = 7;
    a[1] = 120; b[1] = 77;
    b[2] = 777; t->Fill();

    t->Print();
    t->Scan();

    TFile * f = new TFile(TREES_PATH"example2.root","recreate");
    t->Write();
    f->Close();
}

void example3() {

    TTree * t = new TTree("t", "A tree");

    const int n_max = 100;

    int energy[n_max] = {0};

    int n;

    t->Branch("Size", &n, "n/I");
    t->Branch("Energy", energy, "particle_energy[n]/I");

    n = 1; energy[0] = 9; t->Fill();
    n = 2; energy[0] = 11; energy[1] = 111; t->Fill();
    n = 3; energy[0] = 3; energy[1] = 33; energy[2] = 333; t->Fill();

    t->Print();
    t->Scan("n:particle_energy","","colsize=20");

    TFile * f = new TFile(TREES_PATH"example3.root","recreate");
    t->Write();
    f->Close();

}

void example4() {

    struct particle_STRUCT {
        float energy;
        float position[3];
    };

    particle_STRUCT sParticle;

    TTree * t = new TTree("t", "Tree with struct");

    t->Branch("Energy", &sParticle.energy,"p_energy/F");
    t->Branch("Position",sParticle.position,"p_position[3]/F");

    sParticle.energy = 11.;
    sParticle.position[0] = 7.7;
    sParticle.position[1] = 7.7;
    sParticle.position[2] = 7.7;
    t->Fill();

    sParticle.energy = 99.;
    sParticle.position[0] = 191.;
    sParticle.position[1] = 291.;
    sParticle.position[2] = 391.;
    t->Fill();

    t->Print();
    t->Scan();

    TFile * f = new TFile(TREES_PATH"example4.root","recreate");
    t->Write();
    f->Close();
}

void example5() {

    TTree * t = new TTree("t","A tree with class");
    //gSystem->Load(TREES_PATH"particle_CLASS_h.so");
    particle_CLASS * sParticle = new particle_CLASS();
    t->Branch("particle_info", &sParticle);

    sParticle->Set_energy(11);
    sParticle->Set_position(1.1,2.2,3.3);
    t->Fill();

    sParticle->Set_energy(99.);
    sParticle->Set_position(191.,291.,391.);
    t->Fill();
    
    t->GetListOfLeaves()->Print();
    t->Scan("energy:position[0]:position[1]:position[2]");
    
    TFile * f = new TFile(TREES_PATH"example5.root","recreate");
    t->Write();
    f->Close();

}

void example6() {
    TFile * f = new TFile(TREES_PATH"example1.root");
    TTree * t;
    f->GetObject("t", t);
    int a, b, c;
    t->SetBranchAddress("a", &a);
    t->SetBranchAddress("b", &b);
    t->SetBranchAddress("c", &c);
    
    /*
    |In SetBranchAdress("X", &x);
    |X must be the same char* in the loaded TTree
    |x is the variable afore defined.
    */
    
    t->Print();
    t->Scan();

    int i_max = t->GetEntries();
    for (int i = 0; i < i_max; i++) {
        t->GetEntry(i);
        cout<<a<<"\t"<<b<<"\t"<<c<<endl;
    }
    
}

void example7() {
    TFile * f = new TFile(TREES_PATH"example2.root");
    TTree * t; 
    f->GetObject("t", t);

    int a[2] = {0};
    int b[3] = {0};

    t->SetBranchAddress("A", a);
    t->SetBranchAddress("B", b);
    
    t->Print();
    t->Scan();

    t->GetEntry(0);
    cout<<a[0]<<"\t"<<a[1]<<endl;
    cout<<b[0]<<"\t"<<b[1]<<"\t"<<b[2]<<endl;

    t->GetEntry(1);
    cout<<a[0]<<"\t"<<a[1]<<endl;
    cout<<b[0]<<"\t"<<b[1]<<"\t"<<b[2]<<endl;
}


