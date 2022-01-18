#include "TGraphErrors.h"
#include "TF1.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TMath.h"
void makePoints(Int_t n, Double_t *x, Double_t *y, Double_t *e, Int_t p);
//void FitOne(Int_t i);
void ReverseXAxis (TH1 *h);
void ReverseYAxis (TH1 *h);

void EnergyLinearity()
{
  Int_t n = 8;
  Double_t *x = new Double_t[n];
  Double_t *y = new Double_t[n];
  Double_t *e = new Double_t[n];
  TCanvas *myc = new TCanvas("myc",  "Energy Resolution");
  myc->SetGrid();

  // c--------------------------------------------------------- 
  makePoints(n, x, y, e, 2);
  TGraphErrors *gre2 = new TGraphErrors(n, x, y, 0, e);
  gre2->SetMarkerStyle(20);
   gre2->SetMarkerColor(kBlue);
   gre2->SetLineColor(kBlue);  
  //Fit the graph with the predefined "pol3" function

// s-------------------------------------------------
  makePoints(n, x, y, e, 3);
  TGraphErrors *gre3 = new TGraphErrors(n, x, y, 0, e);
  //gre3->Draw("a*");
    gre3->SetMarkerStyle(20);
  gre3->SetMarkerColor(kRed);
  //Fit the graph with the predefined "pol3" function

  // sum-----------------------------------------------
  makePoints(n, x, y, e, 4);
  TGraphErrors *gre4 = new TGraphErrors(n, x, y, 0, e);
  //gre4->Draw("a*");
  gre4->SetMarkerStyle(20);
  gre4->SetMarkerColor(kBlack);

  // base line ----------------------------------------
  auto *f22 = new TGraph();
  f22->SetPoint(0, 5, 1);
  f22->SetPoint(1,110, 1);
  f22->SetLineColor(kBlack);
  f22->SetLineWidth(2);    

// merging ------------------------------------------------------

   TMultiGraph  *mg  = new TMultiGraph();
    mg->Add(gre2);
    mg->Add(gre3);
    mg->Add(gre4);
    mg->Add(f22,"L");
    mg->Draw("A P");

    mg->SetTitle("Electron Energy Linearity");
    mg->GetXaxis()->SetTitle("E [GeV]");
    mg->GetYaxis()->SetTitle("Response");

    mg->SetMinimum(0.98);
    mg->SetMaximum(1.02);

// legend------------------------------------------------------
   TLegend *leg = new TLegend(0.7, 0.75, 0.9, 0.9);

  string c_f = "#color[4]{C}";
  const char* c_ff = c_f.c_str();
  leg->AddEntry(gre2, c_ff, "lpe");

  string s_f = "#color[2]{S}";                               
  const char* s_ff = s_f.c_str();
  leg->AddEntry(gre3, s_ff, "lpe");

  string a_f = "#color[1]{Sum}";                                 
  const char* a_ff = a_f.c_str();
  leg->AddEntry(gre4, a_ff, "lpe");

  leg->SetMargin(0.05);
  leg->Draw("p");
    cout<<""<<endl;
    
}

void makeLine(Double_t *p0, Double_t *p1)
{
  //for ( int i = 0; i <  2 ; ++i ) {
    
}

void makePoints(Int_t n, Double_t *x, Double_t *y, Double_t *e, Int_t p)
{
  Int_t GeV[8]={110, 90, 70, 50, 30, 20, 10, 5};
  Float_t DoubleMS[8][7]={
    {110.5, 2.567, 110.2, 3.09, 220.8, 2.814, 110},
    {90.36, 2.188, 90.27, 2.634, 180.8, 2.474, 90},
    {70.2, 1.924, 70.19, 2.175, 140.4, 2.143, 70},
    {50.08, 1.561, 50.18, 1.664, 100.2, 1.719, 50},
    {29.99, 1.159, 30.06, 1.165, 60.08, 1.381, 30},
    {20.03, 0.9113, 20.04, 0.8757, 40.09, 1.085, 20},
    {9.979, 0.6418, 9.971, 0.5735, 19.98, 0.7492, 10},
    {4.982, 0.4292, 5.013, 0.3832, 9.984, 0.5512, 5}
  };

  Float_t DoubleMS_Error[8][7]={
    {0.1, 0.073, 0.1, 0.08, 0.1, 0.072, 110},
    {0.07, 0.057, 0.09, 0.071, 0.1, 0.066, 90},
    {0.1, 0.056, 0.07, 0.057, 0.1, 0.049, 70},
    {0.05, 0.041, 0.06, 0.039, 0.1, 0.042, 50},
    {0.04, 0.028, 0.04, 0.029, 0.04, 0.035, 30},
    {0.03, 0.0225, 0.03, 0.0216, 0.03, 0.027, 20},
    {0.022, 0.0160, 0.019, 0.0149, 0.02, 0.0168, 10},
    {0.014, 0.0100, 0.013, 0.0098, 0.018, 0.0134, 5}
  };

  //analysis.cc에서 바로 가져오기. 
  // 백업에다가 나온 그래프들 다 포함시키기! 

  //E_C Mean, Sigma and E_S Mean, Sigma and Sum Mean, Simga

  Int_t i;
  TRandom r;
  if (p==2) {
    //p==2 > cheren~
    for (i=0; i<n; i++) {
      x[i] = DoubleMS[i][6];
      // 1/sqrt(E)
      y[i]= DoubleMS[i][0]/DoubleMS[i][6];
      //  simga/mean
      
      //e[i]=0;
      // 
    }
  }
  if (p==3) {
    for (i=0; i<n; i++) {
      x[i] = DoubleMS[i][6];
      y[i]= DoubleMS[i][2]/DoubleMS[i][6];
      //e[i]=0;
    }
  }
  if (p==4) {
    for (i=0; i<n; i++) {
      x[i] = DoubleMS[i][6];
      y[i]= DoubleMS[i][4]/(2*DoubleMS[i][6]);
      //e[i]=0;
    }
  }
}