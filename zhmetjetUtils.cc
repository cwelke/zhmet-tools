#include <stdexcept>

#include "zhmetjetUtils.h"

#include "../CORE/MT2/MT2.h"

using namespace std;

Float_t getmt2bgen( vector <LorentzVector> genleps, vector <LorentzVector> bquarks, Float_t genmet, Float_t genmetphi, Float_t invpartmass, Bool_t verb )
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
	  exit(99);
	}

  return min(mT2bgen1, mT2bgen2);

}
