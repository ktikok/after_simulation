void myc()
{
//=========Macro generated from canvas: myc/Energy Resolution
//=========  (Tue Apr 12 14:08:40 2022) by ROOT version 6.24/00
   TCanvas *myc = new TCanvas("myc", "Energy Resolution",0,71,1707,996);
   myc->Range(-0.025,-0.01482713,0.525,0.1721353);
   myc->SetFillColor(0);
   myc->SetBorderMode(0);
   myc->SetBorderSize(2);
   myc->SetGridx();
   myc->SetGridy();
   myc->SetFrameBorderMode(0);
   myc->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("Electron Energy Resolution(0th, c)");
   
   Double_t Graph_fx1001[6] = {
   0.4472136,
   0.3162278,
   0.2236068,
   0.1825742,
   0.1414214,
   0.1195229};
   Double_t Graph_fy1001[6] = {
   0.08493641,
   0.06006291,
   0.04788689,
   0.03815445,
   0.02923824,
   0.02567702};
   Double_t Graph_fex1001[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1001[6] = {
   0.002077465,
   0.001595442,
   0.00111583,
   0.0009199859,
   0.0007070306,
   0.0006788429};
   TGraphErrors *gre = new TGraphErrors(6,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
   gre->SetName("Graph");
   gre->SetTitle("copper");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#990000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(2);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","copper",100,0.08675379,0.4799827);
   Graph_Graph1001->SetMinimum(0.01879661);
   Graph_Graph1001->SetMaximum(0.09321544);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   
   TF1 *pol11002 = new TF1("pol1","pol1",0.08675379,0.4799827, TF1::EAddToList::kNo);
   pol11002->SetFillColor(19);
   pol11002->SetFillStyle(0);
   pol11002->SetLineColor(2);
   pol11002->SetLineWidth(0);
   pol11002->SetChisquare(10.01024);
   pol11002->SetNDF(4);
   pol11002->GetXaxis()->SetLabelFont(42);
   pol11002->GetXaxis()->SetTitleOffset(1);
   pol11002->GetXaxis()->SetTitleFont(42);
   pol11002->GetYaxis()->SetLabelFont(42);
   pol11002->GetYaxis()->SetTitleFont(42);
   pol11002->SetParameter(0,0.003930985);
   pol11002->SetParError(0,0.000985903);
   pol11002->SetParLimits(0,0,0);
   pol11002->SetParameter(1,0.183945);
   pol11002->SetParError(1,0.005282258);
   pol11002->SetParLimits(1,0,0);
   pol11002->SetParent(gre);
   gre->GetListOfFunctions()->Add(pol11002);
   multigraph->Add(gre,"");
   
   Double_t _fx1[2] = {
   0.05,
   0.45};
   Double_t _fy1[2] = {
   0.01312823,
   0.08670622};
   TGraph *graph = new TGraph(2,_fx1,_fy1);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0.01,0.49);
   Graph_Graph1->SetMinimum(0.005770435);
   Graph_Graph1->SetMaximum(0.09406402);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   multigraph->Add(graph,"L");
   
   Double_t Graph_fx1003[6] = {
   0.4472136,
   0.3162278,
   0.2236068,
   0.1825742,
   0.1414214,
   0.1195229};
   Double_t Graph_fy1003[6] = {
   0.07969649,
   0.05999839,
   0.04461224,
   0.03598183,
   0.03065297,
   0.02547311};
   Double_t Graph_fex1003[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1003[6] = {
   0.001990776,
   0.00154306,
   0.001213399,
   0.0008131359,
   0.0007251019,
   0.0006181034};
   gre = new TGraphErrors(6,Graph_fx1003,Graph_fy1003,Graph_fex1003,Graph_fey1003);
   gre->SetName("Graph");
   gre->SetTitle("iron");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#000099");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#000099");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(2);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","iron",100,0.08675379,0.4799827);
   Graph_Graph1003->SetMinimum(0.01917178);
   Graph_Graph1003->SetMaximum(0.08737049);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1003->SetLineColor(ci);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   
   TF1 *pol11004 = new TF1("pol1","pol1",0.08675379,0.4799827, TF1::EAddToList::kNo);
   pol11004->SetFillColor(19);
   pol11004->SetFillStyle(0);
   pol11004->SetLineColor(2);
   pol11004->SetLineWidth(0);
   pol11004->SetChisquare(4.779717);
   pol11004->SetNDF(4);
   pol11004->GetXaxis()->SetLabelFont(42);
   pol11004->GetXaxis()->SetTitleOffset(1);
   pol11004->GetXaxis()->SetTitleFont(42);
   pol11004->GetYaxis()->SetLabelFont(42);
   pol11004->GetYaxis()->SetTitleFont(42);
   pol11004->SetParameter(0,0.005928113);
   pol11004->SetParError(0,0.000938595);
   pol11004->SetParLimits(0,0,0);
   pol11004->SetParameter(1,0.1682498);
   pol11004->SetParError(1,0.005077773);
   pol11004->SetParLimits(1,0,0);
   pol11004->SetParent(gre);
   gre->GetListOfFunctions()->Add(pol11004);
   multigraph->Add(gre,"");
   
   Double_t _fx2[2] = {
   0.05,
   0.45};
   Double_t _fy2[2] = {
   0.0143406,
   0.08164051};
   graph = new TGraph(2,_fx2,_fy2);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#000099");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","",100,0.01,0.49);
   Graph_Graph2->SetMinimum(0.007610611);
   Graph_Graph2->SetMaximum(0.0883705);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetTitleOffset(1);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetTitleOffset(1);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   multigraph->Add(graph,"L");
   
   Double_t Graph_fx1005[6] = {
   0.4472136,
   0.3162278,
   0.2236068,
   0.1825742,
   0.1414214,
   0.1195229};
   Double_t Graph_fy1005[6] = {
   0.08195232,
   0.05918226,
   0.04111653,
   0.03406743,
   0.02676014,
   0.0235654};
   Double_t Graph_fex1005[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1005[6] = {
   0.002002199,
   0.001372281,
   0.00101967,
   0.0008368284,
   0.0005726498,
   0.0005823471};
   gre = new TGraphErrors(6,Graph_fx1005,Graph_fy1005,Graph_fex1005,Graph_fey1005);
   gre->SetName("Graph");
   gre->SetTitle("iron_theta3");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#000099");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#000099");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(2);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","iron_theta3",100,0.08675379,0.4799827);
   Graph_Graph1005->SetMinimum(0.01688591);
   Graph_Graph1005->SetMaximum(0.09005166);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1005->SetLineColor(ci);
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   
   TF1 *pol11006 = new TF1("pol1","pol1",0.08675379,0.4799827, TF1::EAddToList::kNo);
   pol11006->SetFillColor(19);
   pol11006->SetFillStyle(0);
   pol11006->SetLineColor(2);
   pol11006->SetLineWidth(0);
   pol11006->SetChisquare(1.765616);
   pol11006->SetNDF(4);
   pol11006->GetXaxis()->SetLabelFont(42);
   pol11006->GetXaxis()->SetTitleOffset(1);
   pol11006->GetXaxis()->SetTitleFont(42);
   pol11006->GetYaxis()->SetLabelFont(42);
   pol11006->GetYaxis()->SetTitleFont(42);
   pol11006->SetParameter(0,0.001720859);
   pol11006->SetParError(0,0.0008701338);
   pol11006->SetParLimits(0,0,0);
   pol11006->SetParameter(1,0.1789379);
   pol11006->SetParError(1,0.00479598);
   pol11006->SetParLimits(1,0,0);
   pol11006->SetParent(gre);
   gre->GetListOfFunctions()->Add(pol11006);
   multigraph->Add(gre,"");
   
   Double_t _fx3[2] = {
   0.05,
   0.45};
   Double_t _fy3[2] = {
   0.01066776,
   0.08224293};
   graph = new TGraph(2,_fx3,_fy3);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#000099");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","",100,0.01,0.49);
   Graph_Graph3->SetMinimum(0.003510239);
   Graph_Graph3->SetMaximum(0.08940045);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3->SetLineColor(ci);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph3);
   
   multigraph->Add(graph,"L");
   
   Double_t Graph_fx1007[6] = {
   0.4472136,
   0.3162278,
   0.2236068,
   0.1825742,
   0.1414214,
   0.1195229};
   Double_t Graph_fy1007[6] = {
   0.09566487,
   0.07502763,
   0.0569642,
   0.05180559,
   0.04361599,
   0.04069158};
   Double_t Graph_fex1007[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1007[6] = {
   0.002401204,
   0.002090435,
   0.001467914,
   0.001294169,
   0.001106239,
   0.001133059};
   gre = new TGraphErrors(6,Graph_fx1007,Graph_fy1007,Graph_fex1007,Graph_fey1007);
   gre->SetName("Graph");
   gre->SetTitle("lead");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#009900");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(2);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","lead",100,0.08675379,0.4799827);
   Graph_Graph1007->SetMinimum(0.03370777);
   Graph_Graph1007->SetMaximum(0.1039168);
   Graph_Graph1007->SetDirectory(0);
   Graph_Graph1007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1007->SetLineColor(ci);
   Graph_Graph1007->GetXaxis()->SetLabelFont(42);
   Graph_Graph1007->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1007->GetXaxis()->SetTitleFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelFont(42);
   Graph_Graph1007->GetYaxis()->SetTitleFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelFont(42);
   Graph_Graph1007->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1007);
   
   
   TF1 *pol11008 = new TF1("pol1","pol1",0.08675379,0.4799827, TF1::EAddToList::kNo);
   pol11008->SetFillColor(19);
   pol11008->SetFillStyle(0);
   pol11008->SetLineColor(2);
   pol11008->SetLineWidth(0);
   pol11008->SetChisquare(1.503298);
   pol11008->SetNDF(4);
   pol11008->GetXaxis()->SetLabelFont(42);
   pol11008->GetXaxis()->SetTitleOffset(1);
   pol11008->GetXaxis()->SetTitleFont(42);
   pol11008->GetYaxis()->SetLabelFont(42);
   pol11008->GetYaxis()->SetTitleFont(42);
   pol11008->SetParameter(0,0.02006674);
   pol11008->SetParError(0,0.001397627);
   pol11008->SetParLimits(0,0,0);
   pol11008->SetParameter(1,0.169891);
   pol11008->SetParError(1,0.006829051);
   pol11008->SetParLimits(1,0,0);
   pol11008->SetParent(gre);
   gre->GetListOfFunctions()->Add(pol11008);
   multigraph->Add(gre,"");
   
   Double_t _fx4[2] = {
   0.05,
   0.45};
   Double_t _fy4[2] = {
   0.02856129,
   0.09651768};
   graph = new TGraph(2,_fx4,_fy4);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","",100,0.01,0.49);
   Graph_Graph4->SetMinimum(0.02176565);
   Graph_Graph4->SetMaximum(0.1033133);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph4->SetLineColor(ci);
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetTitleOffset(1);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetTitleOffset(1);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph4);
   
   multigraph->Add(graph,"L");
   
   Double_t Graph_fx1009[6] = {
   0.4472136,
   0.3162278,
   0.2236068,
   0.1825742,
   0.1414214,
   0.1195229};
   Double_t Graph_fy1009[6] = {
   0.1424624,
   0.1046954,
   0.08368998,
   0.07278528,
   0.07241676,
   0.063274};
   Double_t Graph_fex1009[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1009[6] = {
   0.004178061,
   0.002808129,
   0.003056592,
   0.003111466,
   0.003082494,
   0.002753455};
   gre = new TGraphErrors(6,Graph_fx1009,Graph_fy1009,Graph_fex1009,Graph_fey1009);
   gre->SetName("Graph");
   gre->SetTitle("tungsten");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#990099");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#990099");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(2);
   
   TH1F *Graph_Graph1009 = new TH1F("Graph_Graph1009","tungsten",100,0.08675379,0.4799827);
   Graph_Graph1009->SetMinimum(0.05190855);
   Graph_Graph1009->SetMaximum(0.1552524);
   Graph_Graph1009->SetDirectory(0);
   Graph_Graph1009->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1009->SetLineColor(ci);
   Graph_Graph1009->GetXaxis()->SetLabelFont(42);
   Graph_Graph1009->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1009->GetXaxis()->SetTitleFont(42);
   Graph_Graph1009->GetYaxis()->SetLabelFont(42);
   Graph_Graph1009->GetYaxis()->SetTitleFont(42);
   Graph_Graph1009->GetZaxis()->SetLabelFont(42);
   Graph_Graph1009->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1009->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1009);
   
   
   TF1 *pol11010 = new TF1("pol1","pol1",0.08675379,0.4799827, TF1::EAddToList::kNo);
   pol11010->SetFillColor(19);
   pol11010->SetFillStyle(0);
   pol11010->SetLineColor(2);
   pol11010->SetLineWidth(0);
   pol11010->SetChisquare(7.501982);
   pol11010->SetNDF(4);
   pol11010->GetXaxis()->SetLabelFont(42);
   pol11010->GetXaxis()->SetTitleOffset(1);
   pol11010->GetXaxis()->SetTitleFont(42);
   pol11010->GetYaxis()->SetLabelFont(42);
   pol11010->GetYaxis()->SetTitleFont(42);
   pol11010->SetParameter(0,0.03508048);
   pol11010->SetParError(0,0.003056163);
   pol11010->SetParLimits(0,0,0);
   pol11010->SetParameter(1,0.2279734);
   pol11010->SetParError(1,0.01263983);
   pol11010->SetParLimits(1,0,0);
   pol11010->SetParent(gre);
   gre->GetListOfFunctions()->Add(pol11010);
   multigraph->Add(gre,"");
   
   Double_t _fx5[2] = {
   0.05,
   0.45};
   Double_t _fy5[2] = {
   0.04647915,
   0.1376685};
   graph = new TGraph(2,_fx5,_fy5);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#990099");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","",100,0.01,0.49);
   Graph_Graph5->SetMinimum(0.03736021);
   Graph_Graph5->SetMaximum(0.1467875);
   Graph_Graph5->SetDirectory(0);
   Graph_Graph5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph5->SetLineColor(ci);
   Graph_Graph5->GetXaxis()->SetLabelFont(42);
   Graph_Graph5->GetXaxis()->SetTitleOffset(1);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetTitleOffset(1);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph5);
   
   multigraph->Add(graph,"L");
   
   Double_t Graph_fx1011[6] = {
   0.4472136,
   0.3162278,
   0.2236068,
   0.1825742,
   0.1414214,
   0.1195229};
   Double_t Graph_fy1011[6] = {
   0.1373396,
   0.1037887,
   0.07947227,
   0.07349707,
   0.06077763,
   0.05894939};
   Double_t Graph_fex1011[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1011[6] = {
   0.003586545,
   0.002769324,
   0.002029736,
   0.001936823,
   0.001452001,
   0.00148776};
   gre = new TGraphErrors(6,Graph_fx1011,Graph_fy1011,Graph_fex1011,Graph_fey1011);
   gre->SetName("Graph");
   gre->SetTitle("tungsten_theta3");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#990099");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#990099");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(2);
   
   TH1F *Graph_Graph1011 = new TH1F("Graph_Graph1011","tungsten_theta3",100,0.08675379,0.4799827);
   Graph_Graph1011->SetMinimum(0.04911518);
   Graph_Graph1011->SetMaximum(0.1492726);
   Graph_Graph1011->SetDirectory(0);
   Graph_Graph1011->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1011->SetLineColor(ci);
   Graph_Graph1011->GetXaxis()->SetLabelFont(42);
   Graph_Graph1011->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1011->GetXaxis()->SetTitleFont(42);
   Graph_Graph1011->GetYaxis()->SetLabelFont(42);
   Graph_Graph1011->GetYaxis()->SetTitleFont(42);
   Graph_Graph1011->GetZaxis()->SetLabelFont(42);
   Graph_Graph1011->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1011->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1011);
   
   
   TF1 *pol11012 = new TF1("pol1","pol1",0.08675379,0.4799827, TF1::EAddToList::kNo);
   pol11012->SetFillColor(19);
   pol11012->SetFillStyle(0);
   pol11012->SetLineColor(2);
   pol11012->SetLineWidth(0);
   pol11012->SetChisquare(4.968114);
   pol11012->SetNDF(4);
   pol11012->GetXaxis()->SetLabelFont(42);
   pol11012->GetXaxis()->SetTitleOffset(1);
   pol11012->GetXaxis()->SetTitleFont(42);
   pol11012->GetYaxis()->SetLabelFont(42);
   pol11012->GetYaxis()->SetTitleFont(42);
   pol11012->SetParameter(0,0.02873026);
   pol11012->SetParError(0,0.001923323);
   pol11012->SetParLimits(0,0,0);
   pol11012->SetParameter(1,0.2377612);
   pol11012->SetParError(1,0.009630652);
   pol11012->SetParLimits(1,0,0);
   pol11012->SetParent(gre);
   gre->GetListOfFunctions()->Add(pol11012);
   multigraph->Add(gre,"");
   
   Double_t _fx6[2] = {
   0.05,
   0.45};
   Double_t _fy6[2] = {
   0.04061832,
   0.1357228};
   graph = new TGraph(2,_fx6,_fy6);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#990099");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","",100,0.01,0.49);
   Graph_Graph6->SetMinimum(0.03110787);
   Graph_Graph6->SetMaximum(0.1452332);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph6->SetLineColor(ci);
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetTitleOffset(1);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetTitleOffset(1);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph6);
   
   multigraph->Add(graph,"L");
   multigraph->Draw("A RX P");
   multigraph->GetXaxis()->SetLimits(0.03, 0.47);
   multigraph->GetXaxis()->SetTitle("1/#sqrt{E} [GeV^{-1/2}]");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetTitleOffset(1);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("#sigma/E");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TPaveText *pt = new TPaveText(0.2076724,0.9339831,0.7923276,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Electron Energy Resolution(0th, c)");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","#color[1]{C copper: 0.183945 / #sqrt{E} + 0.003931}","lpe");

   ci = TColor::GetColor("#990000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#990000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","#color[1]{C iron: 0.168250 / #sqrt{E} + 0.005928}","lpe");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#000099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","#color[1]{C iron_theta3: 0.178938 / #sqrt{E} + 0.001721}","lpe");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#000099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","#color[1]{C lead: 0.169891 / #sqrt{E} + 0.020067}","lpe");

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#009900");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","#color[1]{C tungsten: 0.227973 / #sqrt{E} + 0.035080}","lpe");

   ci = TColor::GetColor("#990099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#990099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","#color[1]{C tungsten_theta3: 0.237761 / #sqrt{E} + 0.028730}","lpe");

   ci = TColor::GetColor("#990099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#990099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   leg->Draw();
   myc->Modified();
   myc->cd();
   myc->SetSelected(myc);
}
