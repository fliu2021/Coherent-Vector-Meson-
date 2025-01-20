/*void analysis_1(int index1,int index2){
	std::vector<double> total_xsection = { 6.460 , 509.690/1000. , 1.424/1000. , 9.087,
										  36.942 ,  2.625	     , 8.312/1000. , 50.428,
										  31.239 ,	2.235        , 7.043/1000. , 42.725,
										  48.761 ,  3.429        , 10.927/1000., 66.376,
										  112.544,  7.736        , 24.949/1000., 152.273, //\mu barn


	};


	
	std::string dir="/Users/lf/Desktop/muon-collider/estarlight/build/";
	std::vector<std::string> colliders;
	
	
	colliders.push_back("ep_eRHIC");
	//colliders.push_back("eA_eRHIC");
	colliders.push_back("ep_LHeC");
	//colliders.push_back("eA_LHeC");
	colliders.push_back("ep_MuIC");
	//colliders.push_back("eA_MuIC");
	colliders.push_back("ep_MuIC2");
	colliders.push_back("ep_LHmuC");
	//colliders.push_back("eA_LHmuC");
	std::vector<std::string> Q2;
	Q2.push_back("/0_01/");
	Q2.push_back("/1_8/");
	Q2.push_back("/50/");
	Q2.push_back("/total/");

	double xsection=total_xsection[index1*4+index2];

	std::string directory=dir+colliders[index1]+Q2[index2];
	std::string a="slight.root";
	std::string b="xsection.root";
	std::string indir=directory+a;
	std::string outdir=directory+b;
	const char *in=indir.c_str();
	const char *out=outdir.c_str();


	TFile *f1=TFile::Open(in);
	TTree *tree=(TTree *)f1->Get("starlightTree");
	TFile *fout=new TFile(out,"recreate");
	TH1D *mrp=new TH1D("mrp","mrp",100,-10,10);
	TLorentzVector *Parent=new TLorentzVector();
	int entries=tree->GetEntries();
	tree->SetBranchAddress("parent",&Parent);
	for(int i=0;i<entries;i++){
		tree->GetEntry(i);
		mrp->Fill( Parent->Rapidity() );
	}

	mrp->Scale( 1./ mrp->Integral() * xsection, "width");
	TGraph *gr=new TGraph(mrp);
	gr->Write();
	fout->Close();
	f1->Close();
	printf("%f",xsection);


	



}*/




void xsection(){


	TFile *f1 =TFile::Open("/Users/lf/Desktop/muon-collider/estarlight/build/ep_eRHIC/total/xsection.root");
	TFile *f2 =TFile::Open("/Users/lf/Desktop/muon-collider/estarlight/build/ep_LHeC/total/xsection.root");
	TFile *f3 =TFile::Open("/Users/lf/Desktop/muon-collider/estarlight/build/ep_MuIC/total/xsection.root");
	TFile *f4 =TFile::Open("/Users/lf/Desktop/muon-collider/estarlight/build/ep_MuIC2/total/xsection.root");
	TFile *f5 =TFile::Open("/Users/lf/Desktop/muon-collider/estarlight/build/ep_LHmuC/total/xsection.root");
	TGraph *gr1=(TGraph *)f1->Get("Graph_from_mrp");
	TGraph *gr2=(TGraph *)f2->Get("Graph_from_mrp");
	TGraph *gr3=(TGraph *)f3->Get("Graph_from_mrp");
	TGraph *gr4=(TGraph *)f4->Get("Graph_from_mrp");
	TGraph *gr5=(TGraph *)f5->Get("Graph_from_mrp");

	TCanvas *c1=new TCanvas("c1","c1",1100,800);
	gStyle->SetOptStat(0);
	TPad *pad1=new TPad();
	pad1->Draw();
	pad1->cd();
	gPad->SetTickx(0.);
	gPad->SetTicky(0.);
	gPad->SetTopMargin(0.05);
	gPad->SetRightMargin(0.05);
	gPad->SetBottomMargin(0.15);
	gPad->SetLeftMargin(0.15);


	//(his[3])
	gr5->SetLineColor(kRed);
	gr5->SetLineStyle(2);
	gr5->SetLineWidth(3);
	gr5->GetXaxis()->SetTitle("J/#psi Rapidity");
	gr5->GetYaxis()->SetTitle("#frac{d #sigma }{dy} [nb]");
	gr5->SetTitle("");
	gr5->Draw();
	gr5->Draw("C");


	//his[7]

	gr2->SetLineColor(kBlue);
	gr2->SetLineStyle(3);
	gr2->SetLineWidth(3);
	gr2->SetTitle("");
	gr2->Draw("C");


	//his[11]


	gr3->SetLineColor(kGreen);
	gr3->SetLineStyle(4);
	gr3->SetLineWidth(3);
	gr3->SetTitle("");
	gr3->Draw("C");


	//his[15]

	gr4->SetLineColor(kBlack);
	gr4->SetLineStyle(5);
	gr4->SetLineWidth(3);
	gr4->SetTitle("");
	gr4->Draw("C");


	//his[19]


	gr1->SetLineColor(kViolet);
	gr1->SetLineStyle(6);
	gr1->SetLineWidth(3);
	gr1->SetTitle("");
	gr1->Draw("C");



	TLatex *ltx1=new TLatex();
	ltx1->SetTextSize(0.048);
	ltx1->SetTextFont(22);
	ltx1->DrawLatexNDC(0.2,0.85,"e+p coherent J/#psi");



	TLegend* leg1=new TLegend(0.2,0.68,0.6,0.79);
	leg1->SetTextFont(22);
	leg1->SetTextSize(0.028);
	leg1->SetBorderSize(0);
	leg1->AddEntry(gr1,"eRHIC:e(18 GeV)+p(275 GeV)","l");
	leg1->AddEntry(gr2,"LHeC:e(60 Gev)+p(7 TeV)","l");
	leg1->AddEntry(gr3,"MuIC:#mu(960 GeV)+p(275 GeV)","l");
	leg1->AddEntry(gr4,"MuIC2:#mu(960 GeV)+p(960 GeV)","l");
	leg1->AddEntry(gr5,"LHmuC:#mu(1.5 TeV)+p(7 TeV)","l");
	leg1->SetFillColorAlpha(0,0);
	leg1->Draw();







	






	}