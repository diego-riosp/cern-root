#include <iostream>
#include <TGraph.h>
#include <TF1.h>

using namespace std;

void regression() {
    TGraph* gr = new TGraph("tutorials/data/data.dat", "%lg %*lg %lg");
    TF1* fn = new TF1("fn", "[2]*x*x + [1]*x + [0]", -10, 10);
    gr->Fit("fn");
    //gr->Fit("fn","","",3,7); That is for bounds the regression between 3 and 7.
    gr->Draw("A*");
    //fn->SetParameters(20, 1, 1);
    // fn->SerParameter(1, 3) is another way to set the value of a parameter, saying that [1] = 3.
    //fn->Draw();
 
    double a = fn->GetParameter(2);
    double b = fn->GetParameter(1);
    double c = fn->GetParameter(0);

    double* par = fn->GetParameters();

    cout<<a<<"\t"<<b<<"\t"<<c<<endl;
    cout<<par[0]<<"\t"<<par[1]<<"\t"<<par[2]<<endl;
}

void fn_parameters() {
    TF1 *fn = new TF1("fn", "[3]*x*x*x + [2]*x*x + [1]*x + [0]", -8, 20);
    fn->SetParameter(0, 1);
    fn->SetParameter(1, -4);
    fn->SetParameter(2, 2);
    fn->SetParameter(3, 4);
    
    //fn->SetParameters(1,-4,2,4); Is another way to declare the values.

    fn->Draw();
}

void fn_polinomies() {
    TF1 *fn = new TF1("fn", "pol1", -8, 20);
    fn->SetParameters(2,-5);

    TF1 *gn = new TF1("gn", "pol2", -10, 16);
    gn->SetParameters(4,0,7);

    TF1 *hn = new TF1("hn", "pol3", -3, 24);
    hn->SetParameters(-3,5,0,-1);

    fn->Draw();
    gn->Draw("same");
    hn->Draw("same");
}

