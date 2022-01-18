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

void fitLinear_except_reverse()
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
  gre2->Fit("pol1");
  //Access the fit resuts
  // 옵션 , R&sames, R 했을때랑 차이 보기. root fit option.
  // pol1 대신에, "[0]+[1]*x"
  //GetParameter(0)
//GetParameter(1)


  TF1 *f2 = gre2->GetFunction("pol1");
     f2->SetLineColor(kBlue);
  f2->SetLineWidth(1);  
    

// s-------------------------------------------------
  makePoints(n, x, y, e, 3);
  TGraphErrors *gre3 = new TGraphErrors(n, x, y, 0, e);
  //gre3->Draw("a*");
    gre3->SetMarkerStyle(20);

  gre3->SetMarkerColor(kRed);
  gre3->SetLineColor(kRed); 
  //Fit the graph with the predefined "pol3" function
  gre3->Fit("pol1");
  //Access the fit resuts
  TF1 *f3 = gre3->GetFunction("pol1");
     f3->SetLineColor(kRed);

  f3->SetLineWidth(1);  
  

  // sum-----------------------------------------------
  makePoints(n, x, y, e, 4);
  TGraphErrors *gre4 = new TGraphErrors(n, x, y, 0, e);
  //gre4->Draw("a*");
  gre4->SetMarkerStyle(20);
  gre4->SetMarkerColor(kBlack);
  gre4->SetLineColor(kBlack); 
  // https://root.cern.ch/doc/master/classTAttMarker.html#M2
  //Fit the graph with the predefined "pol3" function
  //gre4->Draw("A RX P");
  gre4->Fit("pol1");
  //Access the fit resuts
  
  TF1 *f4 = gre4->GetFunction("pol1");
     f4->SetLineColor(kBlack);

  f4->SetLineWidth(1);      
  //f4->GetXaxis()->SetNdivisions(520);
  //gPad->SetGrid(1,1);
  
// merging ------------------------------------------------------

   TMultiGraph  *mg  = new TMultiGraph();
    mg->Add(gre2);
    mg->Add(gre3);
    mg->Add(gre4);
    //mg->Add(leg);
    //mg->SetMarkerStyle(20);
    
    mg->Draw("A P");
    // it works for most latest version of csmsw.

    // “*” A star is plotted at each point
    //  “A” Axis are drawn around the graph
    //gre2->Draw("a*");
    // "E2" Draw error rectangles
    //  // https://root.cern.ch/root/htmldoc/guides/users-guide/Graphs.html#graphs-with-error-bars


    mg->SetTitle("Electron Energy Resolution");
    mg->GetXaxis()->SetTitle("1/#sqrt{E}");
    mg->GetYaxis()->SetTitle("#sigma/E");
    //mg->Draw("R");

    //mg->Draw("A* RX PL");
    //mg->Draw();
    //g->Draw("A RX RY PL");
    //mg->Draw("R");
    // there was no axis
    
  //  ReverseXAxis(mg);
  //  ReverseYAxis(mg);

// legend------------------------------------------------------
   TLegend *leg = new TLegend(0.12, 0.7, 0.4, 0.9);
    //leg->SetBorderSize(0);
   //(x1,y1,x2,y2) are the coordinates of the Legend in the current pad (in normalised coordinates by default)
  //  leg->AddEntry(gre2, "Ec",  "p");
  //  leg->AddEntry(gre3, "Es", "p");
  //  leg->AddEntry(gre4, "Esum", "p");


  
  //string c_f; // a variable of str data type

  // using to_string to convert an int into a string
  
  //  c_f = "#splitline{#splitline{#color[4]{-C : "+to_string(f2->GetParameter(1))+"#pm"+to_string(f2->GetParError(1))+"/"+"#sqrt{E}+"+to_string(f2->GetParameter(0))+ "#pm"+to_string(f2->GetParError(0))
                                      // +"}}{#color[2]{-S : "+to_string(f3->GetParameter(1))+"#pm"+to_string(f3->GetParError(1))+"/"+"#sqrt{E}+"+to_string(f3->GetParameter(0))+ "#pm"+to_string(f3->GetParError(0))
                            //  +"}}}{#color[1]{-A : "+to_string(f4->GetParameter(1))+"#pm"+to_string(f4->GetParError(1))+"/"+"#sqrt{E}+"+to_string(f4->GetParameter(0))+ "#pm"+to_string(f4->GetParError(0))
                  // +"}} ";

  string c_f = "#color[4]{#splitline{C : "+to_string(f2->GetParameter(1))+" #pm "+to_string(f2->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f2->GetParameter(0))+ " #pm "+to_string(f2->GetParError(0))+"}{#chi^{2} / n : "
                                      +to_string(f2->GetChisquare())+" / "+to_string(f2->GetNDF())+"}}";


  const char* c_ff = c_f.c_str();
  // fit->GetParError(0);
    //leg->AddEntry(gre2,  c_ff, "l");
    //leg->SetHeader(c_ff);
   
    // L: draw line associated with TAttLine if obj inherits fom TAttLine
    // P: draw polymarker associated with TAttMarker if obj inerits from TAttMarker
    // F: draw a box with fill associated wit TAttFill if obj inherits TAttFill
    // E: draw vertical error bar if option "L" is also specified 
    leg->AddEntry(gre2, c_ff, "lpe");

    string s_f = "#color[2]{#splitline{S : "+to_string(f3->GetParameter(1))+" #pm "+to_string(f3->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f3->GetParameter(0))+ " #pm "+to_string(f3->GetParError(0))+"}{#chi^{2} / n : "
                                      +to_string(f3->GetChisquare())+" / "+to_string(f3->GetNDF())+"}}";
    const char* s_ff = s_f.c_str();
    leg->AddEntry(gre3, s_ff, "lpe");

    string a_f = "#color[1]{#splitline{Sum : "+to_string(f4->GetParameter(1))+" #pm "+to_string(f4->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f4->GetParameter(0))+ " #pm "+to_string(f4->GetParError(0))+"}{#chi^{2} / n : "
                                      +to_string(f4->GetChisquare())+" / "+to_string(f4->GetNDF())+"}}";
    const char* a_ff = a_f.c_str();
    leg->AddEntry(gre4, a_ff, "lpe");

    leg->SetMargin(0.05);
   leg->Draw();
    cout<<""<<endl;
    
}

void makePoints(Int_t n, Double_t *x, Double_t *y, Double_t *e, Int_t p)
{
  Int_t GeV[8]={110, 90, 70, 50, 30, 20, 10, 5};
  Float_t MSMSMS_GeV[8][7]={
    {110.5, 2.567, 110.2, 3.09, 220.8, 2.814, 110},
    {90.36, 2.188, 90.27, 2.634, 180.8, 2.474, 90},
    {70.2, 1.924, 70.19, 2.175, 140.4, 2.143, 70},
    {50.83, 1.561, 50.18, 1.664, 100.2, 1.719, 50},
    {29.99, 1.159, 30.06, 1.165, 60.08, 1.381, 30},
    {20.03, 0.9113, 20.04, 0.8757, 40.09, 1.085, 20},
    {9.979, 0.6418, 9.971, 0.5735, 19.98, 0.7492, 10},
    {4.982, 0.4292, 5.013, 0.3832, 9.984, 0.5512, 5}
  };

  Float_t MSMSMS_GeV_Error[8][7]={
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
      x[i] = 1/sqrt(MSMSMS_GeV[i][6]);
      // 1/sqrt(E)
      y[i]= MSMSMS_GeV[i][1]/MSMSMS_GeV[i][0];
      //  simga/mean
      
      //e[i]=0;
      e[i] = (MSMSMS_GeV[i][1]/MSMSMS_GeV[i][0])*sqrt(pow(MSMSMS_GeV_Error[i][0]/MSMSMS_GeV[i][0],2)+pow(MSMSMS_GeV_Error[i][1]/MSMSMS_GeV[i][1],2));
      // 
    }
  }
  if (p==3) {
    for (i=0; i<n; i++) {
      x[i] = 1/sqrt(MSMSMS_GeV[i][6]);
      y[i]= MSMSMS_GeV[i][3]/MSMSMS_GeV[i][2];
      //e[i]=0;
      e[i] = (MSMSMS_GeV[i][3]/MSMSMS_GeV[i][2])*sqrt(pow(MSMSMS_GeV_Error[i][2]/MSMSMS_GeV[i][2],2)+pow(MSMSMS_GeV_Error[i][3]/MSMSMS_GeV[i][3],2));
    }
  }
  if (p==4) {
    for (i=0; i<n; i++) {
      x[i] = 1/sqrt(MSMSMS_GeV[i][6]);
      y[i]= MSMSMS_GeV[i][5]/MSMSMS_GeV[i][4];
      //e[i]=0;
      e[i] = (MSMSMS_GeV[i][5]/MSMSMS_GeV[i][4])*sqrt(pow(MSMSMS_GeV_Error[i][4]/MSMSMS_GeV[i][4],2)+pow(MSMSMS_GeV_Error[i][5]/MSMSMS_GeV[i][5],2));
    }
  }
  //{
  //   // create the points
  //   Int_t n = 10;
  //   Double_t x[n]  = {-.22,.05,.25,.35,.5,.61,.7,.85,.89,.95};
  //   Double_t y[n]  = {1,2.9,5.6,7.4,9,9.6,8.7,6.3,4.5,1};
  //   Double_t x2[n]  = {-.12,.15,.35,.45,.6,.71,.8,.95,.99,1.05};
  //   Double_t y2[n]  = {1,2.9,5.6,7.4,9,9.6,8.7,6.3,4.5,1};
  //
  //   // create the width of errors in x and y direction
  //   Double_t ex[n] = {.05,.1,.07,.07,.04,.05,.06,.07,.08,.05};
  //   Double_t ey[n] = {.8,.7,.6,.5,.4,.4,.5,.6,.7,.8};
  //
  //   // create two graphs
  //   TGraph *gr1 = new TGraph(n,x2,y2);
  //   TGraphErrors *gr2 = new TGraphErrors(n,x,y,ex,ey);
  //
  //   // create a multigraph and draw it
  //   TMultiGraph  *mg  = new TMultiGraph();
  //   mg->Add(gr1);
  //   mg->Add(gr2);
  //   mg->Draw("ALP");
  //}
}