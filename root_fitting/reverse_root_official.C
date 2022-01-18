void reverse_root_official()
{
   auto *c = new TCanvas();
   c->Divide(2,1);
   auto *g = new TGraphErrors();
   g->SetTitle("Simple Graph");
   g->SetPoint(0,-4,-3);
   g->SetPoint(1,1,1);
   g->SetPoint(2,2,1);
   g->SetPoint(3,3,4);
   g->SetPoint(4,5,5);
   g->SetPointError(0,1.,2.);
   g->SetPointError(1,2,1);
   g->SetPointError(2,2,3);
   g->SetPointError(3,3,2);
   g->SetPointError(4,4,5);
   g->GetXaxis()->SetNdivisions(520);
   g->SetMarkerStyle(21);
   c->cd(1); gPad->SetGrid(1,1);
   g->Draw("APL");
   c->cd(2); gPad->SetGrid(1,1);
   g->Draw("A RX PL");
    g->Fit("pol1");

   //g->Draw("A RX RY PL");
}