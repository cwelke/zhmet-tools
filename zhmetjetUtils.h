#include <vector>

#include "TMath.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"

#ifndef BJETUTILS_H
#define BJETUTILS_H

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

Float_t getmt2bgen( const std::vector <LorentzVector> genleps, const std::vector <LorentzVector> bquarks, Float_t genmet, Float_t genmetphi, Float_t invpartmass = 0.0, Bool_t verb = false );
bool getbjets(  std::vector <LorentzVector> &goodbs, const std::vector <LorentzVector> &jets, Float_t workingpoint, const std::vector <Float_t> &csvvals );


#endif
