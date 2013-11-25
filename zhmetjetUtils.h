#include <vector>

#include "TMath.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"

#ifndef BJETUTILS_H
#define BJETUTILS_H

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

Float_t getmt2bgen( std::vector <LorentzVector> genleps, std::vector <LorentzVector> bquarks, Float_t genmet, Float_t genmetphi, Float_t invpartmass, Bool_t verb = false );


#endif
