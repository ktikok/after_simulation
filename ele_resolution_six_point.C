// conda activate /fcc/tikim/mytool/miniconda3/envs/Root_ReverseGraph/

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

void ele_resolution_six_point()
{
  Int_t n = 6; //number of points
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
  
// merging ------------------------------------------------------

   TMultiGraph  *mg  = new TMultiGraph();
    mg->Add(gre2);
    mg->Add(gre3);
    mg->Add(gre4);
    mg->Add(f22, "L");
    mg->Add(f33, "L");
    mg->Add(f44, "L");
    //mg->add(f22);
    mg->Draw("A RX P");

    //////////////////////////////////////////////////////////////////// change name
    mg->SetTitle("Electron Energy Resolution (Iron, 0th, theta1.5)"); 
    //////////////////////////////////////////////////////////////////// 
    
    mg->GetXaxis()->SetTitle("1/#sqrt{E} [GeV^{-1/2}]");
    mg->GetYaxis()->SetTitle("#sigma/E");

// legend------------------------------------------------------
   TLegend *leg = new TLegend(0.6, 0.6, 0.9, 0.9);

  // string c_f = "#color[4]{#splitline{C : "+to_string(f2->GetParameter(1))+" #pm "+to_string(f2->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f2->GetParameter(0))+ " #pm "+to_string(f2->GetParError(0))+"}{#chi^{2} / n : "
  // the above one is for +- term

  // string c_f = "#color[4]{#splitline{C : "+to_string(f2->GetParameter(1))+" #pm "+to_string(f2->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f2->GetParameter(0))+ " #pm "+to_string(f2->GetParError(0))+"}{#chi^{2} / n : "
  string c_f = "#color[4]{#splitline{C : "+to_string(f2->GetParameter(1))+" #pm "+to_string(f2->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f2->GetParameter(0))+"}{#chi^{2} / n : "
                                      +to_string(f2->GetChisquare())+" / "+to_string(f2->GetNDF())+"}}";
  const char* c_ff = c_f.c_str();
  leg->AddEntry(gre2, c_ff, "lpe");

  // string s_f = "#color[2]{#splitline{S : "+to_string(f3->GetParameter(1))+" #pm "+to_string(f3->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f3->GetParameter(0))+ " #pm "+to_string(f3->GetParError(0))+"}{#chi^{2} / n : "
  string s_f = "#color[2]{#splitline{S : "+to_string(f3->GetParameter(1))+" #pm "+to_string(f3->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f3->GetParameter(0))+"}{#chi^{2} / n : "
                                    +to_string(f3->GetChisquare())+" / "+to_string(f3->GetNDF())+"}}";
  const char* s_ff = s_f.c_str();
  leg->AddEntry(gre3, s_ff, "lpe");
  
  // string a_f = "#color[1]{#splitline{Sum : "+to_string(f4->GetParameter(1))+" #pm "+to_string(f4->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f4->GetParameter(0))+ " #pm "+to_string(f4->GetParError(0))+"}{#chi^{2} / n : "
  string a_f = "#color[1]{#splitline{Sum : "+to_string(f4->GetParameter(1))+" #pm "+to_string(f4->GetParError(1))+" / "+"#sqrt{E} + "+to_string(f4->GetParameter(0))+"}{#chi^{2} / n : "
                                    +to_string(f4->GetChisquare())+" / "+to_string(f4->GetNDF())+"}}";
  const char* a_ff = a_f.c_str();
  leg->AddEntry(gre4, a_ff, "lpe");
  // string c_f = "#color[4]{#splitline{C : "+to_string(f2->GetParameter(1))+" / "+"#sqrt{E} + "+to_string(f2->GetParameter(0))+ +" }{#chi^{2} / n : "
  //                                     +to_string(f2->GetChisquare())+" / "+to_string(f2->GetNDF())+" }}";
  // const char* c_ff = c_f.c_str();
  // leg->AddEntry(gre2, c_ff, "lpe");

  // string s_f = "#color[2]{#splitline{S : "+to_string(f3->GetParameter(1))+" / "+"#sqrt{E} + "+to_string(f3->GetParameter(0))+ " }{#chi^{2} / n : "
  //                                   +to_string(f3->GetChisquare())+" / "+to_string(f3->GetNDF())+" }}";
  // const char* s_ff = s_f.c_str();
  // leg->AddEntry(gre3, s_ff, "lpe");

  // string a_f = "#color[1]{#splitline{Sum : "+to_string(f4->GetParameter(1))+" / "+"#sqrt{E} + "+to_string(f4->GetParameter(0))+ " }{#chi^{2} / n : "
  //                                   +to_string(f4->GetChisquare())+" / "+to_string(f4->GetNDF())+" }}";
  // const char* a_ff = a_f.c_str();
  // leg->AddEntry(gre4, a_ff, "lpe");

  leg->SetMargin(0.2);
  leg->Draw();
    cout<<""<<endl;
  myc->SaveAs("ele_resolution.png");

  TFile* validFile = new TFile(+"iron_resolution.root","RECREATE");
  // validFile->WriteTObject(myc);
  gre2->SetTitle("c_resolution");
  gre2->SetName("c_resolution");

  gre3->SetTitle("s_resolution");
  gre3->SetName("s_resolution");

  gre4->SetTitle("sum_resolution");
  gre4->SetName("sum_resolution");

  validFile->WriteTObject(gre2);
  validFile->WriteTObject(gre3);
  validFile->WriteTObject(gre4);

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
        FileName = "/fcc/tikim/results/ele/iron/"+energy+"GeV_CSS_MS_Error.txt";
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
}

