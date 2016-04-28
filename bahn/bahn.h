#if (!defined __BAHN)
#define __BAHN

#include <stdio.h>
#include <stdlib.h>
#include "gravity.h"
#include <windows.h>//Definition of the NULL pointer
using namespace gravity;

//---------------------------------------------------------------------------
// Gravity Settings
//---------------------------------------------------------------------------
int gravity::lmax=0;
int gravity::mmax=0,gravity::omodmax=0; 
double gravity::GM=0.398600436e15L, gravity::ae=6378137.0L, gravity::t0=0.0L;
char *gravity::potfilename = "";
double **gravity::Clm = NULL, **gravity::Slm = NULL;                               // potential coefficients
// Coefficients for indirect tides
double **gravity::Clm_moon= NULL, **gravity::Slm_moon= NULL;
double **gravity::Clm_sun= NULL, **gravity::Slm_sun= NULL;
double **gravity::Clm_st2= NULL, **gravity::Slm_st2= NULL;
double **gravity::Clm_pole= NULL, **gravity::Slm_pole= NULL;
int gravity::lmaxset=4;
//Rotation matrices
Matric gravity::nutmat(3), gravity::nutmat2(3), gravity::polmat(3), gravity::polmat2(3), gravity::prezmat(3), gravity::prezmat2(3);
int gravity::TrafoNr;


namespace bahn{
	//---------------------------------------------------------------------------
	// Default values
	//---------------------------------------------------------------------------
	double abstol=1e-16L, reltol=1e-16L, epstol=1e-16L;
	double t, dt=10.0L, ta=0.0L, te, t_gl=240.0L;
	double GM=0.398600436e15L, ae=6378137.0L, t0=0.0L;
	

	char buf[256];

	bool StartWerteOK=false,StartWerteChang=false,SolCheck=false,AtmoCheck=false,ChangeAllowed=true,
		 DirSunCheck=false,DirMoonCheck=false,SetSunCheck=false,SetMoonCheck=false,OtideCheck=false,
		 Step2Check=false,PtideCheck=false,WindCheck=false,CancelThread=false,Kepler=false;

	// Kepler
	double a, ecc, inc, omasc, omper, f;
	// DE
	DE_EQN_VECTOR X;
	
	int year=2001, month=1, day=15, max_grad=0, max_ordnung=0, flag=1,func, otidemax=0;
	
	//---------------------------------------------------------------------------
	// Constants
	//---------------------------------------------------------------------------
	double GMs=1.32712442076e20L;                     // IERS Conventions 2000 [m^3 s^-2]
	double GMm=4902.801e9L;                           // Montenbruck [m^3 s^-2]
	double facmue=1.0L/(1.0L+81.3005869999999931L);   // DE200 Header File
	double c_licht=299792458.0L;                      // IERS Conventions 1996 [m s^-1]
	double omega = 0.72921150000000E-04L;             // mittl. Drehrate aus Sidereal/Solar

	//---------------------------------------------------------------------------
	//Non-conservative Forces
	//---------------------------------------------------------------------------
	double SatMass = 1.0L;                            //mass of satellite  [kg]
	double MeanEffArea = 2.0L;                        //Mean effective area [m^2] for Air drag
	double MeanAirDensity = 2e-12L;                   //Mean Air density [kg/m^3] for Air drag
	double Airdrag_Alpha = 1.0L;                      //Coefficient for one parameter accomodation model
	double Airdrag_Cl=1.0L, Airdrag_Cd=1.0L;          //Drag and Lift coefficients
	double Airdrag_P=1.0L, Airdrag_Tau=1.0L;          //Coefficients for two parameter accomodation models
	int AtmoForceModelNr, AtmoModelNr;
	int NSat=0;

	// MSIS
	double IYD=0.0L,SEC,GLAT,GLONG,STL,F107A=162.3L,F107=169.4L,D[9],Temp[3],ALT,SW[26],AP[8],ISW,SWC[26];
	double APinterp[40],TIMEinterp[40];//For AP interpolation, AP values for three days before integration and
	int Lagrcheck;                     //corresponding time in julian centuries
	// DTM
	double KPinterp[40];                               // KP values for DTM94
	// HWM93
	double WW[3];

	//---------------------------------------------------------------------------
	//Gravity Calculation
	//---------------------------------------------------------------------------

	double **Clm_sik, **Slm_sik;                       // Backup of potential coefficients







	//---------------------------------------------------------------------------
	// Ocean tides
	//---------------------------------------------------------------------------
	double **omod, **dsnm_otide, **dcnm_otide, **dsnm_otide0, **dcnm_otide0,
		   **dsnm_otide1, **dcnm_otide1,*ldc;
	double totide0, totide1, dt_otide,xp=0.0L,yp=0.0L;       // For Ocean Tide interpolation




	time_t runtime;

	FILE *aus;                 // output file

	//Initial GAST
	double GAST0, GAST;


	// pathname of the exe-file
	//string exepath=
	Fektor testv(3), nutv(3);
	std::string exepath_hand;
	std::string exepath_str;
	std::string exepath;
}
#endif