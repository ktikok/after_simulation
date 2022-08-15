// conda activate /fcc/tikim/mytool/miniconda3/envs/Root_ReverseGraph/

#include "TGraphErrors.h"
#include "TF1.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TMath.h"

#include <iostream>
#include <sstream>
#include <string>
  

using namespace std;
  
void makePoints_R(Int_t n, Double_t *x, Double_t *y, Double_t *e, Int_t p,  string Filename);
// void makePoints_R(Int_t n, Double_t *x, Double_t *y, Double_t *e, Int_t p);
void makePoints_L(Int_t n, Double_t *x, Double_t *y, Double_t *e, Int_t p,  string Filename);

void ele_six_point_all_in_one()
{

  Int_t n = 6; //number of points
  Double_t *x = new Double_t[n];
  Double_t *y = new Double_t[n];
  Double_t *e = new Double_t[n];

  TFile *f = new TFile("test.root", "RECREATE");  // recreate deletes the file if it already exists

    for(int j=0; j<1; j++){

    
        for(int i=2; i<5; i++){
            string canvasTitle;
            string canvasName;
            

            if(j==0){
                // TCanvas *myc = new TCanvas("myc",  "Energy Resolution");
                cout << "j==0" <<endl;
                canvasTitle= "Energy_Resolution";
                cout << canvasTitle <<endl;

            }
            else{
                canvasTitle= "Energy_Linearity";
            }



            if(i==2){
                // TCanvas *myc = new TCanvas("myc",  "Energy Resolution");
                canvasName= "myc_c_";
                cout << canvasName <<endl;
            
            }
            else if(i==3){
                // TCanvas *myc = new TCanvas("myc",  "Energy Resolution");
                canvasName= "myc_s_";
            }
            else{
                canvasName= "myc_sum_";
                
            }
            
            string canvasName1 = canvasName + canvasTitle;
            cout << canvasName1 << endl;
            const char* canvasName2= canvasName1.c_str();
            const char* canvasTitle1= canvasTitle.c_str();

            TCanvas *myc = new TCanvas(canvasName2,  canvasTitle1);
            TMultiGraph  *mg  = new TMultiGraph();
            TLegend *leg = new TLegend(0.6, 0.6, 0.9, 0.9);


            myc->SetGrid();
            mg->SetName("mg");


            //   string str = "copper";
            string str = "copper iron iron_theta3 lead tungsten tungsten_theta3";
            istringstream iss(str);

            
                // Iterate the istringstream
                // using do-while loop
            int flag=1;
            do {

                flag=flag+1;
                string subs;
        
                // Get the word from the istringstream
                iss >> subs;
                cout << subs << endl;
                // Print the word fetched
                // from the istringstream
                string FileName = "/fcc/tikim/results/ele/"+subs+"/";
                //  string title = "Electron Energy Resolution ("+subs+", 0th)";
                // c--------------------------------------------------------- 
                
                makePoints_R(n, x, y, e, i, FileName);
                TGraphErrors *gre2 = new TGraphErrors(n, x, y, 0, e);

                gre2->SetMarkerSize(2);
                const char*  subs1= subs.c_str();
                gre2->SetTitle(subs1);
                gre2->SetName(subs1);
                

                if(subs == "iron_theta3"||subs == "tungsten_theta3"){
                    gre2->SetMarkerStyle(22);

                }
                else{
                    gre2->SetMarkerStyle(20);

                }
                // gre2->SetMarkerColor(kBlue);
                if (subs == "copper"){
                    gre2->SetMarkerColor(kRed+2);
                    // gre2->SetLineColor(kBlue);  
                    gre2->SetLineColor(kRed+2);  
                } 
                else if (subs == "iron" ||subs == "iron_theta3"){
                    gre2->SetMarkerColor(kBlue+2);
                    // gre2->SetLineColor(kBlue);  
                    gre2->SetLineColor(kBlue+2);  
                    
                } 

                else if (subs == "lead"){

                    gre2->SetMarkerColor(kGreen+2);
                    // gre2->SetLineColor(kBlue);  
                    gre2->SetLineColor(kGreen+2);  
                } 

                else if (subs == "tungsten"||subs == "tungsten_theta3"){
                    gre2->SetMarkerColor(kMagenta+2);
                    // gre2->SetLineColor(kBlue);  
                    gre2->SetLineColor(kMagenta+2); 
                } 

                // gre2->SetMarkerColor(flag+2);
                // // gre2->SetLineColor(kBlue);  
                // gre2->SetLineColor(flag+2);  
                // //Fit the graph with the predefined "pol3" function

                gre2->Fit("pol1");
                //Access the fit resuts


                TF1 *f2 = gre2->GetFunction("pol1");
                //f2->SetLineColor(kBlue);
                f2->SetLineWidth(0);  


                auto *f22 = new TGraph();
                f22->SetPoint(0, 0.05, 0.05*(f2->GetParameter(1))+(f2->GetParameter(0)));
                f22->SetPoint(1,0.45, 0.45*(f2->GetParameter(1))+(f2->GetParameter(0)));

                if (subs == "copper"){
                    
                    
                    f22->SetLineColor(kRed+2);  
                } 
                else if (subs == "iron" ||subs == "iron_theta3"){
                    
                    
                    f22->SetLineColor(kBlue+2);  
                } 

                else if (subs == "lead"){

                    
                    
                    f22->SetLineColor(kGreen+2);  
                } 

                else if (subs == "tungsten"||subs == "tungsten_theta3"){
                    
                    
                    f22->SetLineColor(kMagenta+2); 
                } 

                // f22->SetLineColor(flag+2);
                f22->SetLineWidth(1);  

                // merging ------------------------------------------------------

                
                mg->Add(gre2);
                mg->Add(f22, "L");
                
                // legend------------------------------------------------------
                string a_f = "#color[1]{C "+subs+": "+to_string(f2->GetParameter(1))+" / "+"#sqrt{E} + "+to_string(f2->GetParameter(0))+"}";
                const char* a_ff = a_f.c_str();
                leg->AddEntry(gre2, a_ff, "lpe");

                if (subs =="tungsten_theta3"){
                    break;
                } 

            } while (iss);
                            
            mg->Draw("A RX P");
            if(i==2){
                mg->SetTitle("Electron Energy Resolution(0th, c)"); 

            }
            else if(i==3){
                mg->SetTitle("Electron Energy Resolution(0th, s)"); 

            }
            else if(i==4){
                mg->SetTitle("Electron Energy Resolution(0th, sum)"); 

            }
            
            //////////////////////////////////////////////////////////////////// change name
            
            //////////////////////////////////////////////////////////////////// 
            
            mg->GetXaxis()->SetTitle("1/#sqrt{E} [GeV^{-1/2}]");
            mg->GetYaxis()->SetTitle("#sigma/E");

            leg->SetMargin(0.2);
            leg->Draw();

            cout<<""<<endl;
            
            f->cd();
            myc->Write(canvasName2);  // you can specify here the name of the canvas inside the file, e.g. h1->Write("canvas1")...
            if(i==2){
                
                cout<<"saving C"<<i<<endl;

                myc->SaveAs("ele_resolution_c.root");
                myc->SaveAs("ele_resolution_c.png");
                myc->SaveAs("ele_resolution_c.pdf");
            }
            if(i==3){
                cout<<"saving S"<<i<<endl;

                myc->SaveAs("ele_resolution_s.root");
                myc->SaveAs("ele_resolution_s.png");
                myc->SaveAs("ele_resolution_s.pdf");

            }
            if(i==4){
                cout<<"saving Sum"<<i<<endl;

                myc->SaveAs("ele_resolution_sum.root");
                myc->SaveAs("ele_resolution_sum.png");
                myc->SaveAs("ele_resolution_sum.pdf");
            }
        }
    }

    f->Close();
}

void makePoints_R(Int_t n, Double_t *x, Double_t *y, Double_t *e, Int_t p,  string Filename)
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
        FileName = Filename+energy+"GeV_CSS_MS_Error.txt";
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

void makePoints_L(Int_t n, Double_t *x, Double_t *y, Double_t *e, Int_t p,  string Filename)
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
        FileName = Filename+energy+"GeV_CSS_MS_Error.txt";
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

int how_to_iterate_words()
{
  
    // Get the String
    string str = "GeeksforGeeks is a computer "
                 "science portal for Geeks";
  
    // Initialise the istringstream
    // with the given string
    istringstream iss(str);
  
    // Iterate the istringstream
    // using do-while loop
    do {
        string subs;
  
        // Get the word from the istringstream
        iss >> subs;
  
        // Print the word fetched
        // from the istringstream
        cout << subs << endl;
  
    } while (iss);
  
    return 0;
}