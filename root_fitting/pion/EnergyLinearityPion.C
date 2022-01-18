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

void EnergyLinearityPion()
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
    mg->Add(f22,"L");
    mg->Add(gre2);
    mg->Add(gre3);
    mg->Add(gre4);
    
    mg->Draw("A P");

    mg->SetTitle("Pi+ Energy Linearity");
    mg->GetXaxis()->SetTitle("E [GeV]");
    mg->GetYaxis()->SetTitle("Response");

    //mg->SetMinimum(0.98);
    //mg->SetMaximum(1.02);

// legend------------------------------------------------------
   TLegend *leg = new TLegend(0.75, 0.1, 0.9, 0.35);

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

  myc->SaveAs("PionLinearity.png");


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
            //break;            //break;
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
      y[i]= DoubleMS[i][4]/DoubleMS[i][6];
      //e[i]=0;
    }
  }
}