void load_datafile() {
    ifstream infile;
    infile.open("tutorials/data/data1.dat");
    
    double x, y;
    int i;

    TGraph* gr = new TGraph();

    while (infile>>x>>y) {
        cout<<x<<"\t"<<y<<endl;
        gr->SetPoint(++i,x,y);
    }

    gr->Draw();
}
