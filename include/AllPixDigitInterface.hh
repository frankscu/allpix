/**
 *  Author:  John Idarraga <idarraga@cern.ch>
 */

#ifndef AllPixDigitInterface_h
#define AllPixDigitInterface_h 1

#include "G4VDigi.hh"
#include "G4TDigiCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

/**
 *  Interface Digit class.
 */

class AllPixDigitInterface : public G4VDigi {

public:

	AllPixDigitInterface(){};
	virtual ~AllPixDigitInterface(){};

	// This one can't be pure virtual
	AllPixDigitInterface(const AllPixDigitInterface &) : G4VDigi() { } ;

	// Don't need abstraction for the following
	//const AllPixDigitInterface & operator=(const AllPixDigitInterface &) { return *this; };
	//int operator==(const AllPixDigitInterface &) const;
	//virtual void* operator new(size_t);
	//virtual void  operator delete(void*);

	virtual void Draw() = 0;
	virtual void Print() = 0;

	virtual void SetPixelIDX(G4int) = 0;
	virtual void SetPixelIDY(G4int) = 0;
	virtual void SetPixelCounts(G4int) = 0;	//TOT (nalipour)
	virtual void SetPixelEnergyMC(G4double) = 0; //MC only
	virtual void SetPixelEnergyDep(G4double) = 0;     // MC + charge sharing (nalipour)
	virtual void SetPrimaryVertex(G4ThreeVector) = 0; // MC //
	virtual void IncreasePixelCounts() = 0;

	virtual G4int GetPixelIDX() = 0;
	virtual G4int GetPixelIDY() = 0;
	virtual G4int GetPixelCounts() = 0; //TOT
	virtual G4double GetPixelEnergyDep() = 0;     // MC+charge sharing
	virtual G4double GetPixelEnergyMC() = 0;     //MC only (nalipour)
	virtual G4ThreeVector GetPrimaryVertex() = 0; // MC //

	virtual void Set_posX_WithRespectoToPixel(G4double pos) =0; //nalipour
	virtual void Set_posY_WithRespectoToPixel(G4double pos) =0; //nalipour
	virtual void Set_posZ_WithRespectoToPixel(G4double pos) =0; //nalipour
	virtual G4double Get_posX_WithRespectoToPixel() =0; //nalipour
	virtual G4double Get_posY_WithRespectoToPixel() =0;//nalipour
	virtual G4double Get_posZ_WithRespectoToPixel() =0;//nalipour

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

typedef G4TDigiCollection<AllPixDigitInterface> AllPixDigitsCollectionInterface;

extern G4Allocator<AllPixDigitInterface> AllPixDigitAllocatorInterface;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....



/*
inline void* AllPixMimosa26Digit::operator new(size_t)
{
	void* aDigi;
	aDigi = (void*) AllPixMimosa26DigitAllocator.MallocSingle();
	return aDigi;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void AllPixMimosa26Digit::operator delete(void* aDigi)
{
	AllPixMimosa26DigitAllocator.FreeSingle((AllPixMimosa26Digit*) aDigi);
}
*/
#endif

