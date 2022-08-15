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

void ele_linearity_six_point()
{
  Int_t n = 6;
  Double_t *x = new Double_t[n];
  Double_t *y = new Double_t[n];
  Double_t *e = new Double_t[n];
  TCanvas *myc = new TCanvas("myc",  "Energy Linearity");
  myc->SetGrid();

  // c--------------------------------------------------------- 
  makePoints(n, x, y, e, 2);
  TGraphErrors *gre2 = new TGraphErrors(n, x, y, 0, e);
  gre2->SetMarkerStyle(20);
   gre2->SetMarkerColor(kBlue);
   gre2->SetLineColor(kBlue);  
  gre2->SetTitle("c");

  //Fit the graph with the predefined "pol3" function

// s-------------------------------------------------
  makePoints(n, x, y, e, 3);
  TGraphErrors *gre3 = new TGraphErrors(n, x, y, 0, e);
  //gre3->Draw("a*");
  gre3->SetMarkerStyle(20);
  gre3->SetMarkerColor(kRed);
   gre3->SetLineColor(kRed);  

  gre3->SetTitle("s");

  //Fit the graph with the predefined "pol3" function

  // sum-----------------------------------------------
  makePoints(n, x, y, e, 4);
  TGraphErrors *gre4 = new TGraphErrors(n, x, y, 0, e);
  //gre4->Draw("a*");
  gre4->SetMarkerStyle(20);
  gre4->SetMarkerColor(kBlack);
  gre4->SetTitle("sum");

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
    
    //////////////////////////////////////////////////////////////////// change name
    mg->SetTitle("Electron Energy Linearity (Brass, 0th, theta1.5)");
    //////////////////////////////////////////////////////////////////// change name

    mg->GetXaxis()->SetTitle("E [GeV]");
    mg->GetYaxis()->SetTitle("Response");
    
    mg->GetYaxis()->SetRangeUser(0.980,1.020);
    // axis range

    //mg->SetMinimum(0.98);
    //mg->SetMaximum(1.02);

// legend------------------------------------------------------
   TLegend *leg = new TLegend(0.75, 0.1, 0.9, 0.35);
  //  TLegend *leg = new TLegend(0.7, 0.75, 0.9, 0.9);
                                //   (           x2, y2)
                                //   (x1, y1,          )

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

  myc->SaveAs("ele_linearity.png");

  TFile* validFile = new TFile(+"Brass_linearity.root","RECREATE");
  gre2->SetTitle("c");
  gre2->SetName("c");

  gre3->SetTitle("s");
  gre3->SetName("s");

  gre4->SetTitle("sum");
  gre4->SetName("sum");

  validFile->cd();
  gre2->Write();
  gre3->Write();
  gre4->Write();
  // validFile->WriteTObject(myc);
  // validFile->WriteTObject(gre2);
  // validFile->WriteTObject(gre3);
  // validFile->WriteTObject(gre4);

  validFile->Close();

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
    for (int j=0; j<n; j++) {
        LineNum=0;
        
        if(j==0){
            energy = "5";
        } 
        else if(j==1){
            energy = "10";
        } 
        else if(j==2){
            energy = "20";
        } 
        else if(j==3){
            energy = "30";
        } 
        else if(j==4){
            energy = "50";
        } 
        else if(j==5){
            energy = "70";
        } 
        else if(j==6){
            energy = "90";
        } 
        else{
            energy = "110";
        }  

        //////////////////////////////////////////////////////////////////// change name
        FileName = "/fcc/tikim/results/ele/brass/"+energy+"GeV_CSS_MS_Error.txt";
        //////////////////////////////////////////////////////////////////// change name
        
        // FileName = "/data4/tikim/dual-readout/install/0_pion/"+energy+"GeV_pi/"+energy+"GeV_pi_CSS_MS_Error.txt";
        ifstream myfile (FileName);//("/data4/tikim/dual-readout/install/0_pion/10GeV_pi/10GeV_pi_CSS_MS_Error.txt");
        while ( getline (myfile,line) )
        {
          //cout << line << '\n';
            flag=0;
            flag1 = ' ';
            for (int i=0; i<100; i++) {
                if(line[i]!=' ' && flag1==' '){
                    //cout<<"first "<<i<<endl;
                    //cout<<flag<<endl;

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
                    StringValues[j][LineNum*2+(flag-3)]=line.substr(flag3,flag4-flag3);
                    flag3=0;
                    flag4=0;
                    if(flag==4){
                        break;
                    }
                }
                flag1=line[i];
//  

            }
            LineNum=LineNum+1;
            //break;
        }
        myfile.close();
        
        //break;
    }
    for (int j=0; j<n; j++) {
        for (int i=0; i<6; i++) {
            //cout << StringValues[j][i] << " ";
            stringstream ss(StringValues[j][2*i]);
            ss>>DoubleMS[j][i];
            stringstream ss1(StringValues[j][2*i+1]);
            ss1>>DoubleMS_Error[j][i];
        }
    }
    DoubleMS[7][6]=110;
    DoubleMS_Error[7][6]=110;
    DoubleMS[6][6]=90;
    DoubleMS_Error[6][6]=90;
    DoubleMS[5][6]=70;
    DoubleMS_Error[5][6]=70;
    DoubleMS[4][6]=50;
    DoubleMS_Error[4][6]=50;
    DoubleMS[3][6]=30;
    DoubleMS_Error[3][6]=30;
    DoubleMS[2][6]=20;
    DoubleMS_Error[2][6]=20;
    DoubleMS[1][6]=10;
    DoubleMS_Error[1][6]=10;
    DoubleMS[0][6]=5;
    DoubleMS_Error[0][6]=5;


  //analysis.cc에서 바로 가져오기. 
  // 백업에다가 나온 그래프들 다 포함시키기! 

  //E_C Mean, Sigma and E_S Mean, Sigma and Sum Mean, Simga

  Int_t i;
  TRandom r;
  if (p==2) {
    //p==2 > cheren~
    for (i=0; i<n; i++) {
      x[i] = DoubleMS[i][6];
      // E
      y[i]= DoubleMS[i][0]/DoubleMS[i][6];
      //  E_simulation/E_true
      
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