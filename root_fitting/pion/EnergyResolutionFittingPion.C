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

void EnergyResolutionFittingPion()
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

  TF1 *f2 = gre2->GetFunction("pol1");
  //f2->SetLineColor(kBlue);
  f2->SetLineWidth(0);  


  auto *f22 = new TGraph();
  f22->SetPoint(0, 0.05, 0.05*(f2->GetParameter(1))+(f2->GetParameter(0)));
  f22->SetPoint(1,0.45, 0.45*(f2->GetParameter(1))+(f2->GetParameter(0)));
  f22->SetLineColor(kBlue);
  f22->SetLineWidth(1);  

  // TFitResultPtr r =   gre2->Fit("pol1","S");  // TFitResultPtr contains the TFitResult
  // r->Print("V");                                // print full information of fit including covariance matrix
  // r->Write();                                   // store the result in a file

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
     //f3->SetLineColor(kRed);
  f3->SetLineWidth(0);  
  
  auto *f33 = new TGraph();
  f33->SetPoint(0, 0.05, 0.05*(f3->GetParameter(1))+(f3->GetParameter(0)));
  f33->SetPoint(1,0.45, 0.45*(f3->GetParameter(1))+(f3->GetParameter(0)));
  f33->SetLineColor(kRed);
  f33->SetLineWidth(1);  

  // sum-----------------------------------------------
  makePoints(n, x, y, e, 4);
  TGraphErrors *gre4 = new TGraphErrors(n, x, y, 0, e);
  //gre4->Draw("a*");
  gre4->SetMarkerStyle(20);
  gre4->SetMarkerColor(kBlack);
  gre4->SetLineColor(kBlack); 
  gre4->Fit("pol1");
  //Access the fit resuts
  
  TF1 *f4 = gre4->GetFunction("pol1");
    // f4->SetLineColor(kBlack);

  f4->SetLineWidth(0);      

  auto *f44 = new TGraph();
  f44->SetPoint(0, 0.05, 0.05*(f4->GetParameter(1))+(f4->GetParameter(0)));
  f44->SetPoint(1,0.45, 0.45*(f4->GetParameter(1))+(f4->GetParameter(0)));
  f44->SetLineColor(kBlack);
  f44->SetLineWidth(1);  

  // grey sum-----------------------------------------------
  makePoints(n, x, y, e, 5);
  TGraphErrors *gre5 = new TGraphErrors(n, x, y, 0, e);
  //gre4->Draw("a*");
  gre5->SetMarkerStyle(20);
  gre5->SetMarkerColor(12);
  gre5->SetLineColor(12); 
  gre5->Fit("pol1");
  //Access the fit resuts
  
  TF1 *f5 = gre5->GetFunction("pol1");
    // f5->SetLineColor(kBlack);

  f5->SetLineWidth(0);      

  auto *f55 = new TGraph();
  f55->SetPoint(0, 0.05, 0.05*(f5->GetParameter(1))+(f5->GetParameter(0)));
  f55->SetPoint(1,0.45, 0.45*(f5->GetParameter(1))+(f5->GetParameter(0)));
  f55->SetLineColor(12);
  f55->SetLineWidth(1);  
  
// merging and reversing ------------------------------------------------------
   TMultiGraph  *mg  = new TMultiGraph();
    mg->Add(gre2);
    mg->Add(gre3);
    mg->Add(gre4);
    mg->Add(gre5);
    mg->Add(f22, "L");
    mg->Add(f33, "L");
    mg->Add(f44, "L");
    mg->Add(f55, "L");
    //mg->add(f22);
    mg->Draw("A RX P");

    mg->SetTitle("Pi+ Energy Resolution");
    mg->GetXaxis()->SetTitle("1/#sqrt{E} [GeV^{-1/2}]");
    mg->GetYaxis()->SetTitle("#sigma/E");
// merging and reversing ------------------------------------------------------

// legend------------------------------------------------------
   TLegend *leg = new TLegend(0.6, 0.6, 0.9, 0.9);

  // string c_f = "#color[4]{#splitline{C : "+to_string(f2->GetParameter(1))+" #pm "+to_string(f2->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f2->GetParameter(0))+ " #pm "+to_string(f2->GetParError(0))+"}{#chi^{2} / n : "
                                      // +to_string(f2->GetChisquare())+" / "+to_string(f2->GetNDF())+"}}";
// 
// 
  // const char* c_ff = c_f.c_str();
  // leg->AddEntry(gre2, c_ff, "lpe");
  // string s_f = "#color[2]{#splitline{S : "+to_string(f3->GetParameter(1))+" #pm "+to_string(f3->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f3->GetParameter(0))+ " #pm "+to_string(f3->GetParError(0))+"}{#chi^{2} / n : "
                                    // +to_string(f3->GetChisquare())+" / "+to_string(f3->GetNDF())+"}}";
  // const char* s_ff = s_f.c_str();
  // leg->AddEntry(gre3, s_ff, "lpe");
  // string a_f = "#color[1]{#splitline{Sum : "+to_string(f4->GetParameter(1))+" #pm "+to_string(f4->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f4->GetParameter(0))+ " #pm "+to_string(f4->GetParError(0))+"}{#chi^{2} / n : "
                                    // +to_string(f4->GetChisquare())+" / "+to_string(f4->GetNDF())+"}}";
  // const char* a_ff = a_f.c_str();
  // leg->AddEntry(gre4, a_ff, "lpe");
  string c_f = "#color[4]{#splitline{C : "+to_string(f2->GetParameter(1))+" / "+"#sqrt{E} + "+to_string(f2->GetParameter(0))+ +" }{#chi^{2} / n : "
                                      +to_string(f2->GetChisquare())+" / "+to_string(f2->GetNDF())+" }}";


  const char* c_ff = c_f.c_str();
  leg->AddEntry(gre2, c_ff, "lpe");
  string s_f = "#color[2]{#splitline{S : "+to_string(f3->GetParameter(1))+" / "+"#sqrt{E} + "+to_string(f3->GetParameter(0))+ " }{#chi^{2} / n : "
                                    +to_string(f3->GetChisquare())+" / "+to_string(f3->GetNDF())+" }}";
  const char* s_ff = s_f.c_str();
  leg->AddEntry(gre3, s_ff, "lpe");
  string a_f = "#color[1]{#splitline{Sum : "+to_string(f4->GetParameter(1))+" / "+"#sqrt{E} + "+to_string(f4->GetParameter(0))+ " }{#chi^{2} / n : "
                                    +to_string(f4->GetChisquare())+" / "+to_string(f4->GetNDF())+" }}";
  const char* a_ff = a_f.c_str();

  leg->AddEntry(gre4, a_ff, "lpe");
  leg->SetMargin(0.2);
  leg->Draw();
    cout<<""<<endl;
    // legend-----------------------------------------------------------------------------
    
  myc->SaveAs("PionResolution.png");
  // ->SaveAs(filename+"_EcsHist.png");
}

void makePoints(Int_t n, Double_t *x, Double_t *y, Double_t *e, Int_t p)
{
    
    string StringValues[8][12];
    double DoubleMS[8][7]={0.0};
    double DoubleMS_Error[8][7]={0.0};

    int flag;
    char flag1;
    int flag3=0;
    int flag4=0;
    int flag5;
    
    int LineNum;

    string line;

    string energy;
    string FileName;
    for (int j=0; j<8; j++) {
        LineNum=0;
        
        if(j==0){
            energy = "110";
        } 
        else if(j==1){
            energy = "90";
        } 
        else if(j==2){
            energy = "70";
        } 
        else if(j==3){
            energy = "50";
        } 
        else if(j==4){
            energy = "30";
        } 
        else if(j==5){
            energy = "20";
        } 
        else if(j==6){
            energy = "10";
        } 
        else{
            energy = "5";
        } 
        FileName = "/data4/tikim/dual-readout/install/0_pion/3000Events/"+energy+"GeV_pi/"+energy+"GeV_pi_CSS_MS_Error.txt";
        ifstream myfile (FileName);//("/data4/tikim/dual-readout/install/0_pion/10GeV_pi/10GeV_pi_CSS_MS_Error.txt");
        while ( getline (myfile,line) )
        {
          // cout << line << '\n';
          // cout << LineNum << '\n';
          if(LineNum<4){
            flag=0;
            flag1 = ' ';
            for (int i=0; i<100; i++) {
                if(line[i]!=' ' && flag1==' ')
                {
                    // a letter after a blank

                    flag=flag+1;
                    if(flag>1){
                      flag3=i;
                      // cout<< "mean and simga value" << line.substr(flag3,7) <<endl;
                      StringValues[j][LineNum*2]=line.substr(flag3,7);
                      StringValues[j][LineNum*2+1]="0";
                      flag3=0;
                      break;
                    }    






                }
                flag1=line[i];
            }            
          }
          if(LineNum>13){

            flag=0;
            flag1 = ' ';
            for (int i=0; i<100; i++) {
                if(line[i]!=' ' && flag1==' '){
                    //cout<<"first "<<i<<endl;
                    //cout<<flag<<endl;

                    // a letter after a blank

                    flag=flag+1;
                    if(flag>2){
                        flag3=i;
                    }
                    //if(flag==4){
                    //    flag4=i;
                    //}
                    //if(flag==5){
                    //    flag5=i;
                    //}                
                }
                if(line[i] == ' ' && flag1 != ' '){
                    //cout<<"second "<<i<<endl;
                    if(flag>2){
                        flag4=i;
                    }                
                }

                if(flag3 !=0 && flag4 != 0){
                    //cout << flag3<<" "<< flag4<<endl;
                    //cout << line.substr(flag3,flag4-flag3) << endl;
                    StringValues[j][(LineNum-10)*2+(flag-3)]=line.substr(flag3,flag4-flag3);
                    flag3=0;
                    flag4=0;
                    if(flag==4){
                        break;
                    }
                }
                flag1=line[i];
            }

          }
          LineNum=LineNum+1;
          if(LineNum>15){
            break;
          }
            //break;
        }
        myfile.close();
        
        //break;
    }
    for (int j=0; j<8; j++) {
        for (int i=0; i<6; i++) {
            // cout << StringValues[j][2*i] << " ";
            // cout << StringValues[j][2*i+1] << " ";

            stringstream ss(StringValues[j][2*i]);
            ss>>DoubleMS[j][i];
            stringstream ss1(StringValues[j][2*i+1]);
            ss1>>DoubleMS_Error[j][i];
        }
        // cout << " " <<endl;

    }
    DoubleMS[0][6]=110;
    DoubleMS_Error[0][6]=110;
    DoubleMS[1][6]=90;
    DoubleMS_Error[1][6]=90;
    DoubleMS[2][6]=70;
    DoubleMS_Error[2][6]=70;
    DoubleMS[3][6]=50;
    DoubleMS_Error[3][6]=50;
    DoubleMS[4][6]=30;
    DoubleMS_Error[4][6]=30;
    DoubleMS[5][6]=20;
    DoubleMS_Error[5][6]=20;
    DoubleMS[6][6]=10;
    DoubleMS_Error[6][6]=10;
    DoubleMS[7][6]=5;
    DoubleMS_Error[7][6]=5;


  //analysis.cc에서 바로 가져오기. 
  // 백업에다가 나온 그래프들 다 포함시키기! 

  //E_C Mean, Sigma and E_S Mean, Sigma and Sum Mean, Simga

  Int_t i;
  TRandom r;
  if (p==2) {
    //p==2 > cheren~
    for (i=0; i<n; i++) {
      x[i] = 1/sqrt(DoubleMS[i][6]);
      // 1/sqrt(E)
      y[i]= DoubleMS[i][1]/DoubleMS[i][0];
      //  simga/mean
      
      //e[i]=0;
      e[i] = (DoubleMS[i][1]/DoubleMS[i][0])*sqrt(pow(DoubleMS_Error[i][0]/DoubleMS[i][0],2)+pow(DoubleMS_Error[i][1]/DoubleMS[i][1],2));
      // 
    }
  }
  if (p==3) {
    for (i=0; i<n; i++) {
      x[i] = 1/sqrt(DoubleMS[i][6]);
      y[i]= DoubleMS[i][3]/DoubleMS[i][2];
      //e[i]=0;
      e[i] = (DoubleMS[i][3]/DoubleMS[i][2])*sqrt(pow(DoubleMS_Error[i][2]/DoubleMS[i][2],2)+pow(DoubleMS_Error[i][3]/DoubleMS[i][3],2));
    }
  }
  if (p==4) {
    for (i=0; i<n; i++) {
      x[i] = 1/sqrt(DoubleMS[i][6]);
      y[i]= DoubleMS[i][5]/DoubleMS[i][4];
      //e[i]=0;
      e[i] = (DoubleMS[i][5]/DoubleMS[i][4])*sqrt(pow(DoubleMS_Error[i][4]/DoubleMS[i][4],2)+pow(DoubleMS_Error[i][5]/DoubleMS[i][5],2));
    }
  }

  if (p==5) {
    DoubleMS[0][5]=3.18377e+00;
    DoubleMS_Error[0][5]=4.72412e-02;
    DoubleMS[1][5]=2.88831e+00;
    DoubleMS_Error[1][5]=4.40362e-02;
    DoubleMS[2][5]=2.41645e+00;
    DoubleMS_Error[2][5]=3.54487e-02;
    DoubleMS[3][5]=2.00132e+00;
    DoubleMS_Error[3][5]=2.97152e-02;
    DoubleMS[4][5]=1.47818e+00;
    DoubleMS_Error[4][5]=1.96266e-02;
    DoubleMS[5][5]=1.16678e+00;
    DoubleMS_Error[5][5]=1.55831e-02;
    DoubleMS[6][5]=8.04919e-01;
    DoubleMS_Error[6][5]=1.21206e-02;
    DoubleMS[7][5]=5.84330e-01;
    DoubleMS_Error[7][5]=8.11624e-03;



//   
//   
//  }
//  }
//  }

    DoubleMS[0][4]=1.06769e+02;
    DoubleMS_Error[0][4]=6.99512e-02;
    DoubleMS[1][4]=8.73093e+01;
    DoubleMS_Error[1][4]=5.88007e-02;
    DoubleMS[2][4]=6.77578e+01;
    DoubleMS_Error[2][4]=4.89535e-02;
    DoubleMS[3][4]=4.83252e+01;
    DoubleMS_Error[3][4]=3.82855e-02;
    DoubleMS[4][4]=2.89249e+01;
    DoubleMS_Error[4][4]=2.78292e-02;
    DoubleMS[5][4]=1.92062e+01;
    DoubleMS_Error[5][4]=2.18955e-02;
    DoubleMS[6][4]=9.57434e+00;
    DoubleMS_Error[6][4]=1.51492e-02;
    DoubleMS[7][4]=4.82471e+00;
    DoubleMS_Error[7][4]=1.09641e-02;

    // DoubleMS[] = {
      // {81.9013 0 10.483 0 99.5504 0 4.50936 0       1.06769e+02 6.99512e-02      3.18377e+00 4.72412e-02}
      // {66.0581 0 8.9412 0 81.1784 0 3.90976 0       8.73093e+01 5.88007e-02      2.88831e+00 4.40362e-02}
      // {50.4531 0 7.33711 0 62.7447 0 3.19554       0 6.77578e+01 4.89535e-02      2.41645e+00 3.54487e-02}
      // {35.3738 0 5.70716 0 44.5657 0 2.44804       0 4.83252e+01 3.82855e-02      2.00132e+00 2.97152e-02}
      // {20.4624 0 3.83834 0 26.4594 0 1.70327       0 2.89249e+01 2.78292e-02      1.47818e+00 1.96266e-02}
      // {13.333 0 2.81872 0 17.5039 0 1.28632 0       1.92062e+01 2.18955e-02      1.16678e+00 1.55831e-02}
      // {6.37702 0 1.6665 0 8.6509 0 0.77110 0       9.57434e+00 1.51492e-02       8.04919e-01 1.21206e-02}
      // {2.7628 0 1.08376 0 4.22292 0 0.53853 0       4.82471e+00 1.09641e-02      5.84330e-01 8.11624e-03}
    // }
    for (i=0; i<n; i++) {
      x[i] = 1/sqrt(DoubleMS[i][6]);
      y[i]= DoubleMS[i][5]/DoubleMS[i][4];
      //e[i]=0;
      e[i] = (DoubleMS[i][5]/DoubleMS[i][4])*sqrt(pow(DoubleMS_Error[i][4]/DoubleMS[i][4],2)+pow(DoubleMS_Error[i][5]/DoubleMS[i][5],2));
    }
  }
}