void tgraph_datafile() {
    TGraph* gr = new TGraph("tutorials/data/tgraph_data.dat","%lg %*lg %lg",",");
    gr->Draw();
}
