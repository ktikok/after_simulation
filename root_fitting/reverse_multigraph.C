void reverse_multigraph()
{
    // https://root.cern.ch/doc/master/classTMultiGraph.html#MG02
//   Reverse axis

//Since
//   ROOT version 6.19/02

//When a TMultiGraph is drawn, the X-axis is drawn with increasing values from left to right and the Y-axis from bottom to top. The two options RX and RY allow to change this order. The option RX allows to draw the X-axis with increasing values from right to left and the RY option allows to draw the Y-axis with increasing values from top to bottom. The following example illustrate how to use these options.
   auto *c = new TCanvas();
   c->Divide(2,1);
 
   auto *g1 = new TGraphErrors();
   g1->SetPoint(0,-4,-3);
   g1->SetPoint(1,1,1);
   g1->SetPoint(2,2,1);
   g1->SetPoint(3,3,4);
   g1->SetPoint(4,5,5);
   g1->SetPointError(0,1.,2.);
   g1->SetPointError(1,2,1);
   g1->SetPointError(2,2,3);
   g1->SetPointError(3,3,2);
   g1->SetPointError(4,4,5);
   g1->SetMarkerStyle(21);

   auto *g2 = new TGraph();
   g2->SetPoint(0,4,8);
   g2->SetPoint(1,5,9);
   g2->SetPoint(2,6,10);
   g2->SetPoint(3,10,11);
   g2->SetPoint(4,15,12);
   g2->SetLineColor(kRed);
   g2->SetLineWidth(5);

//////////////////////////////////////////////////////////////
//    TF1 *fa = new TF1("fa","[0]*x*sin([1]*x)",-3,3);
//
//    //This creates a function of variable x with 2 parameters. The parameters must be initialized via:
//    fa->SetParameter(0,1);
//    fa->SetParameter(1,2);
//
//    //Parameters may be given a name:
//    fa->SetParName(0,"Constant");
//////////////////////////////////////////////////////////////
 
   auto mg = new TMultiGraph();
   mg->Add(g1,"P");
   mg->Add(g2,"L");
   mg->Add(fa, "P");
 
   c->cd(1); gPad->SetGrid(1,1);
   mg->Draw("A");
 
   c->cd(2); gPad->SetGrid(1,1);
   mg->Draw("A RX RY");


    // I added ---------
    // wherever these codes locaed, it did same thing.

    g1->Fit("pol1"); // It draws fitting line and is not reversed.
    
    // if I comment the above line the bellow lines raise errors
    TF1 *f1 = g1->GetFunction("pol1");
    f1->SetLineColor(kBlue);
    f1->SetLineWidth(0);  

    // -----------------

}
