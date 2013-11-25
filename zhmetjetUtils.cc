#include <stdexcept>

#include "zhmetjetUtils.h"

#include "../CORE/MT2/MT2.h"

using namespace std;

Float_t getmt2bgen( const vector <LorentzVector> &genleps, const vector <LorentzVector> &bquarks, Float_t genmet, Float_t genmetphi, Float_t invpartmass, Bool_t verb )
{

  Float_t mT2bgen1 = 0.0;
  Float_t mT2bgen2 = 0.0;

  try
	{
	  mT2bgen1 = MT2( genmet, genmetphi, genleps.at(0) + bquarks.at(0), genleps.at(1) + bquarks.at(1), invpartmass, verb );
	  mT2bgen2 = MT2( genmet, genmetphi, genleps.at(0) + bquarks.at(1), genleps.at(1) + bquarks.at(0), invpartmass, verb );
	}
  catch(exception &e)
	{
	  cout<<"Error calculating mt2j!"<<endl;
	  cout<<"Exception: "<<e.what()<<endl;
	  exit(99);
	}

  return min(mT2bgen1, mT2bgen2);

}

// bool getbjets( vector <LorentzVector> &goodbs, const Float_t workingpoint )
// {
//   bool twogoodjets = false;
//   goodbs.clear();
//   if(       zmet.csv1() >= workingpoint && zmet.csv2() >= workingpoint && zmet.csv3() < workingpoint ){
// 	goodbs.push_back(zmet.jet1());
// 	goodbs.push_back(zmet.jet2());
// 	twogoodjets = true;
//   }else if( zmet.csv1() >= workingpoint && zmet.csv3() >= workingpoint && zmet.csv2() < workingpoint ){
// 	goodbs.push_back(zmet.jet1());
// 	goodbs.push_back(zmet.jet3());
// 	twogoodjets = true;
//   }else if( zmet.csv2() >= workingpoint && zmet.csv3() >= workingpoint && zmet.csv1() < workingpoint ){
// 	goodbs.push_back(zmet.jet2());
// 	goodbs.push_back(zmet.jet3());
// 	twogoodjets = true;
//   }
//   return twogoodjets;
// }

bool getbjets( vector <LorentzVector> &goodbs, const vector <LorentzVector> &jets, Float_t workingpoint, const vector <Float_t> &csvvals )
{
  bool twogoodjets = false;
  goodbs.clear();

  if( jets.size() == 2 ){
	if(       csvvals.at(0) >= workingpoint && csvvals.at(1) >= workingpoint ){
	  goodbs.push_back(jets.at(0));
	  goodbs.push_back(jets.at(1));
	  twogoodjets = true;
	}

  }else if( jets.size() == 3){
	if(       csvvals.at(0) >= workingpoint && csvvals.at(1) >= workingpoint && csvvals.at(2) < workingpoint ){
	  goodbs.push_back(jets.at(0));
	  goodbs.push_back(jets.at(1));
	  twogoodjets = true;
	}else if( csvvals.at(0) >= workingpoint && csvvals.at(2) >= workingpoint && csvvals.at(1) < workingpoint ){
	  goodbs.push_back(jets.at(0));
	  goodbs.push_back(jets.at(2));
	  twogoodjets = true;
	}else if( csvvals.at(1) >= workingpoint && csvvals.at(2) >= workingpoint && csvvals.at(0) < workingpoint ){
	  goodbs.push_back(jets.at(1));
	  goodbs.push_back(jets.at(2));
	  twogoodjets = true;
	}
  }

  return twogoodjets;
}
