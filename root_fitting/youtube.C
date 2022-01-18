void setStyle(){
    gROOT->SetStyle("Plain");
    gStyle->SetOptStat(111110);
    gStyle->SetOptFit(111);
    gStyle->SetOptTitle(1);
}

void grafico(){
    TGraphErrors * graphC =new TGraphErrors("youtube", "%lg%lg");
    graphC->SetTitle("Energy Resolution; 1/root(E); sigma/E");
    graphC->SetMarkerStyle(kFullCircle);
    graphC->SetMarkerStyle(kBlack);

    TF1 *f1 = new TF1("Linear law", "[0]+x*[1]", 0.05, 0.5);
    f1->SetLineColor(kRed);
    f1->SetLineStyle(2);
    f1->SetParNames("x","y");

    graphC->Fit(f1);
    
    TCanvas *cC = new TCanvas();
    cC -> cd();
    graphC->Draw("APE");
    // axis, points, errors

    TLegend *legC=new TLegend(.1, .7, .3, .9, "Legenda");
    legC->SetFillColor(0);
    graphC->SetFillColor(0);
    legC->AddEntry(graphC, "Dati sperimentli");
    legC->AddEntry(f1, "Fit");
    legC->Draw("Same");

    cC->Print("youtube.pdf");
    cout << "x and y mearsuements correlation="<<graphC->GetCorrelationFactor()<<endl;
    // run root
    // .L youtube.C
    // setStyle()
    // grafico()
}