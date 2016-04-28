#pragma once


#include "MODDTM94.h"
//#include "P:\SharedWithWork\Files_downloaded_by_AirDroid\OrbInt\Bahnint_aktuell\Bahnint260804\atmofun.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "de.h"
#include "skalmat.h"
#include "nutwink.h"
#include "atmofun.h"
#include "gravity.h"
#include "bahn.h"
#include "vektormat.h"
#include "vektormat2.h"	

using namespace gravity;
namespace bahn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Xml;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Orbitint : public System::Windows::Forms::Form
	{
	public:
		Orbitint(void)
		{
			InitializeComponent();
			fn_InitializeGUI();
			fn_InitializeBackgroundWorker();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Orbitint()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txt_InitialConditions;
	protected: 

	protected: BackgroundWorker^ bgWorker_WriterThread;
	private: System::Windows::Forms::Label^  lbl_InitialConditions;
	private: System::Windows::Forms::GroupBox^  grp_Integrator;
	private: System::Windows::Forms::TextBox^  txt_Precision;

	private: System::Windows::Forms::TextBox^  txt_StepSize;

	private: System::Windows::Forms::Label^  lbl_Precision;

	private: System::Windows::Forms::Label^  lbl_StepSize;
	private: System::Windows::Forms::Button^  btn_FromFile;
	private: System::Windows::Forms::Button^  btn_Default;
	private: System::Windows::Forms::Button^  btn_ToFile;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btn_Exit;
	private: System::Windows::Forms::Button^  btn_CancelIntegration;
	private: System::Windows::Forms::Button^  btn_StartIntegration;
	private: System::Windows::Forms::Label^  lbl_Progress;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::StatusStrip^  statStrip_Main;
	private: System::Windows::Forms::GroupBox^  grp_CoordinateSystem;
	private: System::Windows::Forms::RadioButton^  rb_Cartesian;

	private: System::Windows::Forms::RadioButton^  rb_Spherical;
	private: System::Windows::Forms::Label^  lbl_GravityFieldComputation;
	private: System::Windows::Forms::GroupBox^  grp_Tranformation;




	private: System::Windows::Forms::RadioButton^  rb_GAST;


	private: System::Windows::Forms::GroupBox^  grp_GravityFieldModel;
	private: System::Windows::Forms::Label^  lbl_CoefficientFile;

	private: System::Windows::Forms::Button^  btn_Current;
	private: System::Windows::Forms::TextBox^  txt_OMEGA;
	private: System::Windows::Forms::TextBox^  txt_MaxOrder;
	private: System::Windows::Forms::TextBox^  txt_MaxDegree;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  lbl_MaxDegree;

	private: System::Windows::Forms::Label^  lbl_Note;
	private: System::Windows::Forms::Label^  lbl_R;
	private: System::Windows::Forms::Label^  lbl_GM;
	private: System::Windows::Forms::Label^  lbl_Mmax;
	private: System::Windows::Forms::Label^  lbl_Lmax;
	private: System::Windows::Forms::GroupBox^  grp_PolarMotion;
	private: System::Windows::Forms::Button^  btn_FillIn;
	private: System::Windows::Forms::TextBox^  txt_yp;
	private: System::Windows::Forms::Label^  lbl_yp;
	private: System::Windows::Forms::TextBox^  txt_xp;
	private: System::Windows::Forms::Label^  lbl_xp;
	private: System::Windows::Forms::Button^  btn_ChooseCoefficientFile;
	private: System::Windows::Forms::GroupBox^  grp_SurfaceForces;
	private: System::Windows::Forms::Label^  lbl_SurfaceForces;
	private: System::Windows::Forms::CheckBox^  chk_UseSurfaceModel;


	private: System::Windows::Forms::CheckBox^  chk_WindModel;

	private: System::Windows::Forms::CheckBox^  chk_SolarPressure;


	private: System::Windows::Forms::CheckBox^  chk_AtmosphericDrag;
	private: System::Windows::Forms::GroupBox^  grp_MassOfSatellite;
	private: System::Windows::Forms::TextBox^  txt_MassOfSatellite;
	private: System::Windows::Forms::Label^  lbl_Kg;
private: System::Windows::Forms::GroupBox^  grp_ChooseSurfaceModel;
private: System::Windows::Forms::RadioButton^  rb_GraceOldModel;
private: System::Windows::Forms::RadioButton^  rb_Grace;
private: System::Windows::Forms::RadioButton^  rb_Champ;
private: System::Windows::Forms::GroupBox^  grp_MeanArea;
private: System::Windows::Forms::TextBox^  txt_MeanArea;
private: System::Windows::Forms::Label^  lbl_m2;
private: System::Windows::Forms::GroupBox^  grp_SolidEarthTides;
private: System::Windows::Forms::CheckBox^  cb_SolidEarthMoon;
private: System::Windows::Forms::CheckBox^  cb_SolidEarthSun;


private: System::Windows::Forms::GroupBox^  grp_DirectTidalAcceleration;
private: System::Windows::Forms::Label^  lbl_EphemerisFileName;
private: System::Windows::Forms::Button^  btn_ChooseEphemeris;
private: System::Windows::Forms::CheckBox^  cb_Moon;
private: System::Windows::Forms::CheckBox^  cb_Sun;
private: System::Windows::Forms::Label^  lbl_TidalEffects;
private: System::Windows::Forms::GroupBox^  grp_OceanTides;

private: System::Windows::Forms::GroupBox^  grp_SolidEarthPoleTide;
private: System::Windows::Forms::CheckBox^  cb_SolidEarthPoleTide;
private: System::Windows::Forms::CheckBox^  cb_FreqDepCorr;
private: System::Windows::Forms::TextBox^  txt_DegOrdOceanTide;

private: System::Windows::Forms::Label^  lbl_InterpolationIntervalOceanTide;

private: System::Windows::Forms::Label^  lbl_DegOrderOceanTides;

private: System::Windows::Forms::GroupBox^  grp_OceanTideModel;
private: System::Windows::Forms::RadioButton^  rb_FES2002;
private: System::Windows::Forms::RadioButton^  rb_FES1;
private: System::Windows::Forms::RadioButton^  rb_Topex;
private: System::Windows::Forms::RadioButton^  rb_Schwiderski;
private: System::Windows::Forms::CheckBox^  chk_EnableOceanTide;

private: System::Windows::Forms::TextBox^  txt_InterplationIntervalOceanTide;
private: System::Windows::Forms::Label^  lbl_AtmosphericDragForceModel;
private: System::Windows::Forms::GroupBox^  grp_ChooseForceModel;
private: System::Windows::Forms::RadioButton^  rb_TwoParameter;

private: System::Windows::Forms::RadioButton^  rb_OneParameter;

private: System::Windows::Forms::RadioButton^  rb_DragAndLift;

private: System::Windows::Forms::RadioButton^  rb_onlyDrag;
private: System::Windows::Forms::CheckBox^  chk_AirDensityViaModel;

private: System::Windows::Forms::GroupBox^  grp_AmbientTemperature;

private: System::Windows::Forms::GroupBox^  grp_MeanAirDensity;
private: System::Windows::Forms::ComboBox^  cmb_Molecule;


private: System::Windows::Forms::TextBox^  txt_AirDensity;
private: System::Windows::Forms::Label^  lbl_AirDensityUnit;
private: System::Windows::Forms::GroupBox^  grp_CdValue;
private: System::Windows::Forms::TextBox^  txt_CdValue;
private: System::Windows::Forms::TextBox^  txt_AmbientTemperature;
private: System::Windows::Forms::Label^  lbl_DegreesC;
private: System::Windows::Forms::GroupBox^  grp_ClValue;
private: System::Windows::Forms::TextBox^  txt_ClValue;
private: System::Windows::Forms::TabPage^  tab_AtmospherParameters;
private: System::Windows::Forms::GroupBox^  grp_AP;
private: System::Windows::Forms::TextBox^  txt_DailyAP;

private: System::Windows::Forms::Label^  lbl_DailyAP;

private: System::Windows::Forms::GroupBox^  grp_MagneticActivity;
private: System::Windows::Forms::RadioButton^  rb_3HourAp;
private: System::Windows::Forms::RadioButton^  rb_DailyAp;
private: System::Windows::Forms::GroupBox^  grp_SolarFlux;
private: System::Windows::Forms::TextBox^  txt_DailyF107;

private: System::Windows::Forms::Label^  lbl_DailyF107;
private: System::Windows::Forms::GroupBox^  grp_Interpolate;
private: System::Windows::Forms::Button^  btn_InterpolateFillIn;

private: System::Windows::Forms::CheckBox^  chk_Interpolate;
private: System::Windows::Forms::TextBox^  txt_DailyF107A;
private: System::Windows::Forms::Label^  lbl_DailyF107A;
private: System::Windows::Forms::GroupBox^  grp_AtmosphereModel;
private: System::Windows::Forms::RadioButton^  rb_DTM94;
private: System::Windows::Forms::RadioButton^  rb_MSIS86;
private: System::Windows::Forms::CheckBox^  chk_DeriveAlpha;


private: System::Windows::Forms::GroupBox^  grp_ChooseModel;
private: System::Windows::Forms::RadioButton^  rb_Mazanek;
private: System::Windows::Forms::RadioButton^  rb_Klinkrad;
private: System::Windows::Forms::RadioButton^  rb_Thalhammer;
private: System::Windows::Forms::GroupBox^  grp_param_tau;
private: System::Windows::Forms::TextBox^  txt_param_tau;
private: System::Windows::Forms::GroupBox^  grp_param_p;
private: System::Windows::Forms::TextBox^  txt_param_p;
private: System::Windows::Forms::GroupBox^  grp_OrderInterval;
private: System::Windows::Forms::OpenFileDialog^  od_gravityCoeffFile;
private: System::Windows::Forms::TextBox^  txt_Header;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::GroupBox^  grp_AccuracyOutput;
private: System::Windows::Forms::RadioButton^  rb_AccuracyMax;
private: System::Windows::Forms::RadioButton^  rb_mmlevel;
private: System::Windows::Forms::CheckBox^  chk_OutOceanTide;

private: System::Windows::Forms::CheckBox^  chk_Step2Acc;

private: System::Windows::Forms::CheckBox^  chk_IndirectSun;

private: System::Windows::Forms::CheckBox^  chk_OutIndirectMoon;

private: System::Windows::Forms::CheckBox^  chk_DirectTidalAcc;

private: System::Windows::Forms::CheckBox^  chk_OutNonCons;

private: System::Windows::Forms::CheckBox^  chk_OutSolarPressure;
private: System::Windows::Forms::CheckBox^  chk_OutGravityGradients;



private: System::Windows::Forms::CheckBox^  chk_OutTrackAngle;

private: System::Windows::Forms::CheckBox^  chk_OutKeplerVector;

private: System::Windows::Forms::CheckBox^  chk_OutVelocityInertial;

private: System::Windows::Forms::CheckBox^  chk_OutOrbitTerrestrial;

private: System::Windows::Forms::CheckBox^  chk_OutOrbitInertial;

private: System::Windows::Forms::CheckBox^  chk_OutJD2000;


private: System::Windows::Forms::CheckBox^  chk_GAST;

private: System::Windows::Forms::CheckBox^  chk_OutTime;
private: System::Windows::Forms::CheckBox^  chk_PoleTide;
private: System::Windows::Forms::RadioButton^  rb_Exact;
private: System::Windows::Forms::RadioButton^  rb_Omega;
private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;















	private: System::Windows::Forms::MenuStrip^  menu_MainWindow;
	protected: 

	protected: 
		void fn_InitializeGUI(){
			this->tab_InitialConditions->Text = "Initial Conditions";
			this->tab_Gravity->Text = "Gravity";
			this->tab_SurfaceForces->Text = "Surface Forces";
			this->tab_Output->Text = "Output";
			this->tab_Plot->Text = "Plot";
			this->tab_Tides->Text = "Tides";
			
			this->tab_AtmosphericForces->Enabled = false;
			this->tabControl_Main->Controls->RemoveByKey("tab_AtmosphericForces");	
			this->tabControl_Main->Controls->RemoveByKey("tab_AtmospherParameters");
			this->bgWorker_WriterThread = gcnew System::ComponentModel::BackgroundWorker;
			AtmoForceModelNr = 0;
			AtmoModelNr = 0;
			System::String^ exepath_SystemString = Path::GetFullPath("\\mydir\\");
			//exepath_str = (char *)(void *)Marshal::StringToHGlobalAnsi(exepath_hand);

		}
		void fn_InitializeBackgroundWorker(){
			this->bgWorker_WriterThread->DoWork += gcnew DoWorkEventHandler(this, &Orbitint::bgWorker_DoWork);
			this->bgWorker_WriterThread->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &Orbitint::bg_WorkerRunWorkerCompleted);
			this->bgWorker_WriterThread->ProgressChanged += gcnew ProgressChangedEventHandler(this, &Orbitint::bg_WorkerProgressChanged);

		}
		void bgWorker_DoWork(Object^ sender, DoWorkEventArgs^ e){
		}
		void bg_WorkerRunWorkerCompleted(Object^ sender, RunWorkerCompletedEventArgs^ e){
		}
		void bg_WorkerProgressChanged(Object^ sender, ProgressChangedEventArgs^ e){
		}
	
	private: System::Windows::Forms::ToolStripMenuItem^  downloadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  createDataFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  atmosphericParametersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  solarFluxToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  eOPToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  allFilesToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl_Main;
	private: System::Windows::Forms::TabPage^  tab_InitialConditions;
	private: System::Windows::Forms::TabPage^  tab_Gravity;
	private: System::Windows::Forms::TabPage^  tab_SurfaceForces;
	private: System::Windows::Forms::TabPage^  tab_Tides;
	private: System::Windows::Forms::TabPage^  tab_Output;
	private: System::Windows::Forms::TabPage^  tab_Plot;
	private: System::Windows::Forms::TabPage^ tab_AtmosphericForces;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menu_MainWindow = (gcnew System::Windows::Forms::MenuStrip());
			this->downloadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->atmosphericParametersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->solarFluxToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eOPToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createDataFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl_Main = (gcnew System::Windows::Forms::TabControl());
			this->tab_InitialConditions = (gcnew System::Windows::Forms::TabPage());
			this->btn_FromFile = (gcnew System::Windows::Forms::Button());
			this->btn_Default = (gcnew System::Windows::Forms::Button());
			this->btn_ToFile = (gcnew System::Windows::Forms::Button());
			this->grp_Integrator = (gcnew System::Windows::Forms::GroupBox());
			this->txt_Precision = (gcnew System::Windows::Forms::TextBox());
			this->txt_StepSize = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Precision = (gcnew System::Windows::Forms::Label());
			this->lbl_StepSize = (gcnew System::Windows::Forms::Label());
			this->txt_InitialConditions = (gcnew System::Windows::Forms::TextBox());
			this->lbl_InitialConditions = (gcnew System::Windows::Forms::Label());
			this->tab_Gravity = (gcnew System::Windows::Forms::TabPage());
			this->grp_PolarMotion = (gcnew System::Windows::Forms::GroupBox());
			this->btn_FillIn = (gcnew System::Windows::Forms::Button());
			this->txt_yp = (gcnew System::Windows::Forms::TextBox());
			this->lbl_yp = (gcnew System::Windows::Forms::Label());
			this->txt_xp = (gcnew System::Windows::Forms::TextBox());
			this->lbl_xp = (gcnew System::Windows::Forms::Label());
			this->grp_GravityFieldModel = (gcnew System::Windows::Forms::GroupBox());
			this->btn_ChooseCoefficientFile = (gcnew System::Windows::Forms::Button());
			this->txt_MaxOrder = (gcnew System::Windows::Forms::TextBox());
			this->txt_MaxDegree = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lbl_MaxDegree = (gcnew System::Windows::Forms::Label());
			this->lbl_Note = (gcnew System::Windows::Forms::Label());
			this->lbl_R = (gcnew System::Windows::Forms::Label());
			this->lbl_GM = (gcnew System::Windows::Forms::Label());
			this->lbl_Mmax = (gcnew System::Windows::Forms::Label());
			this->lbl_Lmax = (gcnew System::Windows::Forms::Label());
			this->lbl_CoefficientFile = (gcnew System::Windows::Forms::Label());
			this->grp_Tranformation = (gcnew System::Windows::Forms::GroupBox());
			this->btn_Current = (gcnew System::Windows::Forms::Button());
			this->txt_OMEGA = (gcnew System::Windows::Forms::TextBox());
			this->rb_Exact = (gcnew System::Windows::Forms::RadioButton());
			this->rb_GAST = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Omega = (gcnew System::Windows::Forms::RadioButton());
			this->grp_CoordinateSystem = (gcnew System::Windows::Forms::GroupBox());
			this->rb_Cartesian = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Spherical = (gcnew System::Windows::Forms::RadioButton());
			this->lbl_GravityFieldComputation = (gcnew System::Windows::Forms::Label());
			this->tab_SurfaceForces = (gcnew System::Windows::Forms::TabPage());
			this->grp_SurfaceForces = (gcnew System::Windows::Forms::GroupBox());
			this->grp_MeanArea = (gcnew System::Windows::Forms::GroupBox());
			this->txt_MeanArea = (gcnew System::Windows::Forms::TextBox());
			this->lbl_m2 = (gcnew System::Windows::Forms::Label());
			this->grp_ChooseSurfaceModel = (gcnew System::Windows::Forms::GroupBox());
			this->rb_GraceOldModel = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Grace = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Champ = (gcnew System::Windows::Forms::RadioButton());
			this->grp_MassOfSatellite = (gcnew System::Windows::Forms::GroupBox());
			this->txt_MassOfSatellite = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Kg = (gcnew System::Windows::Forms::Label());
			this->chk_UseSurfaceModel = (gcnew System::Windows::Forms::CheckBox());
			this->chk_WindModel = (gcnew System::Windows::Forms::CheckBox());
			this->chk_SolarPressure = (gcnew System::Windows::Forms::CheckBox());
			this->chk_AtmosphericDrag = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_SurfaceForces = (gcnew System::Windows::Forms::Label());
			this->tab_AtmosphericForces = (gcnew System::Windows::Forms::TabPage());
			this->grp_param_tau = (gcnew System::Windows::Forms::GroupBox());
			this->txt_param_tau = (gcnew System::Windows::Forms::TextBox());
			this->grp_param_p = (gcnew System::Windows::Forms::GroupBox());
			this->txt_param_p = (gcnew System::Windows::Forms::TextBox());
			this->chk_DeriveAlpha = (gcnew System::Windows::Forms::CheckBox());
			this->grp_ChooseModel = (gcnew System::Windows::Forms::GroupBox());
			this->rb_Mazanek = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Klinkrad = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Thalhammer = (gcnew System::Windows::Forms::RadioButton());
			this->grp_ClValue = (gcnew System::Windows::Forms::GroupBox());
			this->txt_ClValue = (gcnew System::Windows::Forms::TextBox());
			this->grp_AmbientTemperature = (gcnew System::Windows::Forms::GroupBox());
			this->txt_AmbientTemperature = (gcnew System::Windows::Forms::TextBox());
			this->lbl_DegreesC = (gcnew System::Windows::Forms::Label());
			this->grp_MeanAirDensity = (gcnew System::Windows::Forms::GroupBox());
			this->cmb_Molecule = (gcnew System::Windows::Forms::ComboBox());
			this->txt_AirDensity = (gcnew System::Windows::Forms::TextBox());
			this->lbl_AirDensityUnit = (gcnew System::Windows::Forms::Label());
			this->grp_CdValue = (gcnew System::Windows::Forms::GroupBox());
			this->txt_CdValue = (gcnew System::Windows::Forms::TextBox());
			this->chk_AirDensityViaModel = (gcnew System::Windows::Forms::CheckBox());
			this->grp_ChooseForceModel = (gcnew System::Windows::Forms::GroupBox());
			this->rb_TwoParameter = (gcnew System::Windows::Forms::RadioButton());
			this->rb_OneParameter = (gcnew System::Windows::Forms::RadioButton());
			this->rb_DragAndLift = (gcnew System::Windows::Forms::RadioButton());
			this->rb_onlyDrag = (gcnew System::Windows::Forms::RadioButton());
			this->lbl_AtmosphericDragForceModel = (gcnew System::Windows::Forms::Label());
			this->tab_Tides = (gcnew System::Windows::Forms::TabPage());
			this->grp_OceanTides = (gcnew System::Windows::Forms::GroupBox());
			this->grp_OrderInterval = (gcnew System::Windows::Forms::GroupBox());
			this->txt_InterplationIntervalOceanTide = (gcnew System::Windows::Forms::TextBox());
			this->lbl_DegOrderOceanTides = (gcnew System::Windows::Forms::Label());
			this->txt_DegOrdOceanTide = (gcnew System::Windows::Forms::TextBox());
			this->lbl_InterpolationIntervalOceanTide = (gcnew System::Windows::Forms::Label());
			this->grp_OceanTideModel = (gcnew System::Windows::Forms::GroupBox());
			this->rb_FES2002 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_FES1 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Topex = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Schwiderski = (gcnew System::Windows::Forms::RadioButton());
			this->chk_EnableOceanTide = (gcnew System::Windows::Forms::CheckBox());
			this->grp_SolidEarthPoleTide = (gcnew System::Windows::Forms::GroupBox());
			this->cb_SolidEarthPoleTide = (gcnew System::Windows::Forms::CheckBox());
			this->grp_SolidEarthTides = (gcnew System::Windows::Forms::GroupBox());
			this->cb_FreqDepCorr = (gcnew System::Windows::Forms::CheckBox());
			this->cb_SolidEarthMoon = (gcnew System::Windows::Forms::CheckBox());
			this->cb_SolidEarthSun = (gcnew System::Windows::Forms::CheckBox());
			this->grp_DirectTidalAcceleration = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_EphemerisFileName = (gcnew System::Windows::Forms::Label());
			this->btn_ChooseEphemeris = (gcnew System::Windows::Forms::Button());
			this->cb_Moon = (gcnew System::Windows::Forms::CheckBox());
			this->cb_Sun = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_TidalEffects = (gcnew System::Windows::Forms::Label());
			this->tab_Output = (gcnew System::Windows::Forms::TabPage());
			this->chk_PoleTide = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutOceanTide = (gcnew System::Windows::Forms::CheckBox());
			this->chk_Step2Acc = (gcnew System::Windows::Forms::CheckBox());
			this->chk_IndirectSun = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutIndirectMoon = (gcnew System::Windows::Forms::CheckBox());
			this->chk_DirectTidalAcc = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutNonCons = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutSolarPressure = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutGravityGradients = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutTrackAngle = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutKeplerVector = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutVelocityInertial = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutOrbitTerrestrial = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutOrbitInertial = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutJD2000 = (gcnew System::Windows::Forms::CheckBox());
			this->chk_GAST = (gcnew System::Windows::Forms::CheckBox());
			this->chk_OutTime = (gcnew System::Windows::Forms::CheckBox());
			this->txt_Header = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->grp_AccuracyOutput = (gcnew System::Windows::Forms::GroupBox());
			this->rb_AccuracyMax = (gcnew System::Windows::Forms::RadioButton());
			this->rb_mmlevel = (gcnew System::Windows::Forms::RadioButton());
			this->tab_Plot = (gcnew System::Windows::Forms::TabPage());
			this->tab_AtmospherParameters = (gcnew System::Windows::Forms::TabPage());
			this->grp_AtmosphereModel = (gcnew System::Windows::Forms::GroupBox());
			this->rb_DTM94 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_MSIS86 = (gcnew System::Windows::Forms::RadioButton());
			this->grp_Interpolate = (gcnew System::Windows::Forms::GroupBox());
			this->btn_InterpolateFillIn = (gcnew System::Windows::Forms::Button());
			this->chk_Interpolate = (gcnew System::Windows::Forms::CheckBox());
			this->grp_SolarFlux = (gcnew System::Windows::Forms::GroupBox());
			this->txt_DailyF107A = (gcnew System::Windows::Forms::TextBox());
			this->lbl_DailyF107A = (gcnew System::Windows::Forms::Label());
			this->txt_DailyF107 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_DailyF107 = (gcnew System::Windows::Forms::Label());
			this->grp_AP = (gcnew System::Windows::Forms::GroupBox());
			this->txt_DailyAP = (gcnew System::Windows::Forms::TextBox());
			this->lbl_DailyAP = (gcnew System::Windows::Forms::Label());
			this->grp_MagneticActivity = (gcnew System::Windows::Forms::GroupBox());
			this->rb_3HourAp = (gcnew System::Windows::Forms::RadioButton());
			this->rb_DailyAp = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btn_Exit = (gcnew System::Windows::Forms::Button());
			this->btn_CancelIntegration = (gcnew System::Windows::Forms::Button());
			this->btn_StartIntegration = (gcnew System::Windows::Forms::Button());
			this->lbl_Progress = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->statStrip_Main = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->od_gravityCoeffFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menu_MainWindow->SuspendLayout();
			this->tabControl_Main->SuspendLayout();
			this->tab_InitialConditions->SuspendLayout();
			this->grp_Integrator->SuspendLayout();
			this->tab_Gravity->SuspendLayout();
			this->grp_PolarMotion->SuspendLayout();
			this->grp_GravityFieldModel->SuspendLayout();
			this->grp_Tranformation->SuspendLayout();
			this->grp_CoordinateSystem->SuspendLayout();
			this->tab_SurfaceForces->SuspendLayout();
			this->grp_SurfaceForces->SuspendLayout();
			this->grp_MeanArea->SuspendLayout();
			this->grp_ChooseSurfaceModel->SuspendLayout();
			this->grp_MassOfSatellite->SuspendLayout();
			this->tab_AtmosphericForces->SuspendLayout();
			this->grp_param_tau->SuspendLayout();
			this->grp_param_p->SuspendLayout();
			this->grp_ChooseModel->SuspendLayout();
			this->grp_ClValue->SuspendLayout();
			this->grp_AmbientTemperature->SuspendLayout();
			this->grp_MeanAirDensity->SuspendLayout();
			this->grp_CdValue->SuspendLayout();
			this->grp_ChooseForceModel->SuspendLayout();
			this->tab_Tides->SuspendLayout();
			this->grp_OceanTides->SuspendLayout();
			this->grp_OrderInterval->SuspendLayout();
			this->grp_OceanTideModel->SuspendLayout();
			this->grp_SolidEarthPoleTide->SuspendLayout();
			this->grp_SolidEarthTides->SuspendLayout();
			this->grp_DirectTidalAcceleration->SuspendLayout();
			this->tab_Output->SuspendLayout();
			this->grp_AccuracyOutput->SuspendLayout();
			this->tab_AtmospherParameters->SuspendLayout();
			this->grp_AtmosphereModel->SuspendLayout();
			this->grp_Interpolate->SuspendLayout();
			this->grp_SolarFlux->SuspendLayout();
			this->grp_AP->SuspendLayout();
			this->grp_MagneticActivity->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->statStrip_Main->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu_MainWindow
			// 
			this->menu_MainWindow->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->downloadToolStripMenuItem, 
				this->createDataFileToolStripMenuItem});
			this->menu_MainWindow->Location = System::Drawing::Point(0, 0);
			this->menu_MainWindow->Name = L"menu_MainWindow";
			this->menu_MainWindow->Size = System::Drawing::Size(753, 24);
			this->menu_MainWindow->TabIndex = 0;
			this->menu_MainWindow->Text = L"menuStrip1";
			// 
			// downloadToolStripMenuItem
			// 
			this->downloadToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->atmosphericParametersToolStripMenuItem, 
				this->solarFluxToolStripMenuItem, this->eOPToolStripMenuItem, this->allFilesToolStripMenuItem});
			this->downloadToolStripMenuItem->Name = L"downloadToolStripMenuItem";
			this->downloadToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->downloadToolStripMenuItem->Text = L"Download";
			// 
			// atmosphericParametersToolStripMenuItem
			// 
			this->atmosphericParametersToolStripMenuItem->Name = L"atmosphericParametersToolStripMenuItem";
			this->atmosphericParametersToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->atmosphericParametersToolStripMenuItem->Text = L"Atmospheric Parameters";
			// 
			// solarFluxToolStripMenuItem
			// 
			this->solarFluxToolStripMenuItem->Name = L"solarFluxToolStripMenuItem";
			this->solarFluxToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->solarFluxToolStripMenuItem->Text = L"Solar Flux";
			// 
			// eOPToolStripMenuItem
			// 
			this->eOPToolStripMenuItem->Name = L"eOPToolStripMenuItem";
			this->eOPToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->eOPToolStripMenuItem->Text = L"EOP";
			// 
			// allFilesToolStripMenuItem
			// 
			this->allFilesToolStripMenuItem->Name = L"allFilesToolStripMenuItem";
			this->allFilesToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->allFilesToolStripMenuItem->Text = L"All files";
			// 
			// createDataFileToolStripMenuItem
			// 
			this->createDataFileToolStripMenuItem->Name = L"createDataFileToolStripMenuItem";
			this->createDataFileToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->createDataFileToolStripMenuItem->Text = L"Create Data File";
			// 
			// tabControl_Main
			// 
			this->tabControl_Main->Controls->Add(this->tab_InitialConditions);
			this->tabControl_Main->Controls->Add(this->tab_Gravity);
			this->tabControl_Main->Controls->Add(this->tab_SurfaceForces);
			this->tabControl_Main->Controls->Add(this->tab_AtmosphericForces);
			this->tabControl_Main->Controls->Add(this->tab_Tides);
			this->tabControl_Main->Controls->Add(this->tab_Output);
			this->tabControl_Main->Controls->Add(this->tab_Plot);
			this->tabControl_Main->Controls->Add(this->tab_AtmospherParameters);
			this->tabControl_Main->Location = System::Drawing::Point(23, 27);
			this->tabControl_Main->Name = L"tabControl_Main";
			this->tabControl_Main->SelectedIndex = 0;
			this->tabControl_Main->Size = System::Drawing::Size(704, 434);
			this->tabControl_Main->TabIndex = 1;
			// 
			// tab_InitialConditions
			// 
			this->tab_InitialConditions->Controls->Add(this->btn_FromFile);
			this->tab_InitialConditions->Controls->Add(this->btn_Default);
			this->tab_InitialConditions->Controls->Add(this->btn_ToFile);
			this->tab_InitialConditions->Controls->Add(this->grp_Integrator);
			this->tab_InitialConditions->Controls->Add(this->txt_InitialConditions);
			this->tab_InitialConditions->Controls->Add(this->lbl_InitialConditions);
			this->tab_InitialConditions->Location = System::Drawing::Point(4, 22);
			this->tab_InitialConditions->Name = L"tab_InitialConditions";
			this->tab_InitialConditions->Padding = System::Windows::Forms::Padding(3);
			this->tab_InitialConditions->Size = System::Drawing::Size(696, 408);
			this->tab_InitialConditions->TabIndex = 0;
			this->tab_InitialConditions->Text = L"Initial Conditions";
			this->tab_InitialConditions->UseVisualStyleBackColor = true;
			// 
			// btn_FromFile
			// 
			this->btn_FromFile->Location = System::Drawing::Point(489, 360);
			this->btn_FromFile->Name = L"btn_FromFile";
			this->btn_FromFile->Size = System::Drawing::Size(176, 23);
			this->btn_FromFile->TabIndex = 5;
			this->btn_FromFile->Text = L"From File";
			this->btn_FromFile->UseVisualStyleBackColor = true;
			// 
			// btn_Default
			// 
			this->btn_Default->Location = System::Drawing::Point(252, 360);
			this->btn_Default->Name = L"btn_Default";
			this->btn_Default->Size = System::Drawing::Size(169, 23);
			this->btn_Default->TabIndex = 4;
			this->btn_Default->Text = L"Default";
			this->btn_Default->UseVisualStyleBackColor = true;
			this->btn_Default->Click += gcnew System::EventHandler(this, &Orbitint::btn_Default_Click);
			// 
			// btn_ToFile
			// 
			this->btn_ToFile->Location = System::Drawing::Point(32, 360);
			this->btn_ToFile->Name = L"btn_ToFile";
			this->btn_ToFile->Size = System::Drawing::Size(160, 23);
			this->btn_ToFile->TabIndex = 3;
			this->btn_ToFile->Text = L"To File";
			this->btn_ToFile->UseVisualStyleBackColor = true;
			this->btn_ToFile->Click += gcnew System::EventHandler(this, &Orbitint::btn_ToFile_Click);
			// 
			// grp_Integrator
			// 
			this->grp_Integrator->Controls->Add(this->txt_Precision);
			this->grp_Integrator->Controls->Add(this->txt_StepSize);
			this->grp_Integrator->Controls->Add(this->lbl_Precision);
			this->grp_Integrator->Controls->Add(this->lbl_StepSize);
			this->grp_Integrator->Location = System::Drawing::Point(62, 260);
			this->grp_Integrator->Name = L"grp_Integrator";
			this->grp_Integrator->Size = System::Drawing::Size(568, 77);
			this->grp_Integrator->TabIndex = 2;
			this->grp_Integrator->TabStop = false;
			this->grp_Integrator->Text = L"Integrator";
			// 
			// txt_Precision
			// 
			this->txt_Precision->Location = System::Drawing::Point(329, 36);
			this->txt_Precision->Name = L"txt_Precision";
			this->txt_Precision->Size = System::Drawing::Size(100, 20);
			this->txt_Precision->TabIndex = 3;
			// 
			// txt_StepSize
			// 
			this->txt_StepSize->Location = System::Drawing::Point(97, 36);
			this->txt_StepSize->Name = L"txt_StepSize";
			this->txt_StepSize->Size = System::Drawing::Size(100, 20);
			this->txt_StepSize->TabIndex = 2;
			// 
			// lbl_Precision
			// 
			this->lbl_Precision->AutoSize = true;
			this->lbl_Precision->Location = System::Drawing::Point(348, 20);
			this->lbl_Precision->Name = L"lbl_Precision";
			this->lbl_Precision->Size = System::Drawing::Size(50, 13);
			this->lbl_Precision->TabIndex = 1;
			this->lbl_Precision->Text = L"Precision";
			// 
			// lbl_StepSize
			// 
			this->lbl_StepSize->AutoSize = true;
			this->lbl_StepSize->Location = System::Drawing::Point(114, 20);
			this->lbl_StepSize->Name = L"lbl_StepSize";
			this->lbl_StepSize->Size = System::Drawing::Size(61, 13);
			this->lbl_StepSize->TabIndex = 0;
			this->lbl_StepSize->Text = L"Stepsize [s]";
			// 
			// txt_InitialConditions
			// 
			this->txt_InitialConditions->AcceptsReturn = true;
			this->txt_InitialConditions->AcceptsTab = true;
			this->txt_InitialConditions->Location = System::Drawing::Point(32, 53);
			this->txt_InitialConditions->Multiline = true;
			this->txt_InitialConditions->Name = L"txt_InitialConditions";
			this->txt_InitialConditions->ReadOnly = true;
			this->txt_InitialConditions->Size = System::Drawing::Size(633, 201);
			this->txt_InitialConditions->TabIndex = 1;
			// 
			// lbl_InitialConditions
			// 
			this->lbl_InitialConditions->AutoSize = true;
			this->lbl_InitialConditions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_InitialConditions->Location = System::Drawing::Point(258, 15);
			this->lbl_InitialConditions->Name = L"lbl_InitialConditions";
			this->lbl_InitialConditions->Size = System::Drawing::Size(188, 25);
			this->lbl_InitialConditions->TabIndex = 0;
			this->lbl_InitialConditions->Text = L"Initial Conditions";
			// 
			// tab_Gravity
			// 
			this->tab_Gravity->Controls->Add(this->grp_PolarMotion);
			this->tab_Gravity->Controls->Add(this->grp_GravityFieldModel);
			this->tab_Gravity->Controls->Add(this->grp_Tranformation);
			this->tab_Gravity->Controls->Add(this->grp_CoordinateSystem);
			this->tab_Gravity->Controls->Add(this->lbl_GravityFieldComputation);
			this->tab_Gravity->Location = System::Drawing::Point(4, 22);
			this->tab_Gravity->Name = L"tab_Gravity";
			this->tab_Gravity->Padding = System::Windows::Forms::Padding(3);
			this->tab_Gravity->Size = System::Drawing::Size(696, 408);
			this->tab_Gravity->TabIndex = 1;
			this->tab_Gravity->Text = L"Gravity";
			this->tab_Gravity->UseVisualStyleBackColor = true;
			// 
			// grp_PolarMotion
			// 
			this->grp_PolarMotion->Controls->Add(this->btn_FillIn);
			this->grp_PolarMotion->Controls->Add(this->txt_yp);
			this->grp_PolarMotion->Controls->Add(this->lbl_yp);
			this->grp_PolarMotion->Controls->Add(this->txt_xp);
			this->grp_PolarMotion->Controls->Add(this->lbl_xp);
			this->grp_PolarMotion->Location = System::Drawing::Point(311, 250);
			this->grp_PolarMotion->Name = L"grp_PolarMotion";
			this->grp_PolarMotion->Size = System::Drawing::Size(354, 120);
			this->grp_PolarMotion->TabIndex = 5;
			this->grp_PolarMotion->TabStop = false;
			this->grp_PolarMotion->Text = L"Polar Motion";
			// 
			// btn_FillIn
			// 
			this->btn_FillIn->Location = System::Drawing::Point(130, 80);
			this->btn_FillIn->Name = L"btn_FillIn";
			this->btn_FillIn->Size = System::Drawing::Size(75, 23);
			this->btn_FillIn->TabIndex = 4;
			this->btn_FillIn->Text = L"Fill In";
			this->btn_FillIn->UseVisualStyleBackColor = true;
			// 
			// txt_yp
			// 
			this->txt_yp->Enabled = false;
			this->txt_yp->Location = System::Drawing::Point(221, 38);
			this->txt_yp->Name = L"txt_yp";
			this->txt_yp->Size = System::Drawing::Size(100, 20);
			this->txt_yp->TabIndex = 3;
			this->txt_yp->Text = L"0";
			this->txt_yp->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lbl_yp
			// 
			this->lbl_yp->AutoSize = true;
			this->lbl_yp->Location = System::Drawing::Point(197, 41);
			this->lbl_yp->Name = L"lbl_yp";
			this->lbl_yp->Size = System::Drawing::Size(18, 13);
			this->lbl_yp->TabIndex = 2;
			this->lbl_yp->Text = L"yp";
			// 
			// txt_xp
			// 
			this->txt_xp->Enabled = false;
			this->txt_xp->Location = System::Drawing::Point(36, 39);
			this->txt_xp->Name = L"txt_xp";
			this->txt_xp->Size = System::Drawing::Size(100, 20);
			this->txt_xp->TabIndex = 1;
			this->txt_xp->Text = L"0";
			this->txt_xp->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lbl_xp
			// 
			this->lbl_xp->AutoSize = true;
			this->lbl_xp->Location = System::Drawing::Point(12, 42);
			this->lbl_xp->Name = L"lbl_xp";
			this->lbl_xp->Size = System::Drawing::Size(18, 13);
			this->lbl_xp->TabIndex = 0;
			this->lbl_xp->Text = L"xp";
			// 
			// grp_GravityFieldModel
			// 
			this->grp_GravityFieldModel->Controls->Add(this->btn_ChooseCoefficientFile);
			this->grp_GravityFieldModel->Controls->Add(this->txt_MaxOrder);
			this->grp_GravityFieldModel->Controls->Add(this->txt_MaxDegree);
			this->grp_GravityFieldModel->Controls->Add(this->label5);
			this->grp_GravityFieldModel->Controls->Add(this->lbl_MaxDegree);
			this->grp_GravityFieldModel->Controls->Add(this->lbl_Note);
			this->grp_GravityFieldModel->Controls->Add(this->lbl_R);
			this->grp_GravityFieldModel->Controls->Add(this->lbl_GM);
			this->grp_GravityFieldModel->Controls->Add(this->lbl_Mmax);
			this->grp_GravityFieldModel->Controls->Add(this->lbl_Lmax);
			this->grp_GravityFieldModel->Controls->Add(this->lbl_CoefficientFile);
			this->grp_GravityFieldModel->Location = System::Drawing::Point(311, 67);
			this->grp_GravityFieldModel->Name = L"grp_GravityFieldModel";
			this->grp_GravityFieldModel->Size = System::Drawing::Size(354, 158);
			this->grp_GravityFieldModel->TabIndex = 4;
			this->grp_GravityFieldModel->TabStop = false;
			this->grp_GravityFieldModel->Text = L"Gravity Field Model";
			// 
			// btn_ChooseCoefficientFile
			// 
			this->btn_ChooseCoefficientFile->Location = System::Drawing::Point(178, 92);
			this->btn_ChooseCoefficientFile->Name = L"btn_ChooseCoefficientFile";
			this->btn_ChooseCoefficientFile->Size = System::Drawing::Size(143, 34);
			this->btn_ChooseCoefficientFile->TabIndex = 10;
			this->btn_ChooseCoefficientFile->Text = L"Choose Coefficient File";
			this->btn_ChooseCoefficientFile->UseVisualStyleBackColor = true;
			this->btn_ChooseCoefficientFile->Click += gcnew System::EventHandler(this, &Orbitint::btn_ChooseCoefficientFile_Click);
			// 
			// txt_MaxOrder
			// 
			this->txt_MaxOrder->Location = System::Drawing::Point(218, 57);
			this->txt_MaxOrder->Name = L"txt_MaxOrder";
			this->txt_MaxOrder->Size = System::Drawing::Size(100, 20);
			this->txt_MaxOrder->TabIndex = 9;
			this->txt_MaxOrder->Text = L"0";
			this->txt_MaxOrder->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// txt_MaxDegree
			// 
			this->txt_MaxDegree->Location = System::Drawing::Point(218, 31);
			this->txt_MaxDegree->Name = L"txt_MaxDegree";
			this->txt_MaxDegree->Size = System::Drawing::Size(100, 20);
			this->txt_MaxDegree->TabIndex = 8;
			this->txt_MaxDegree->Text = L"0";
			this->txt_MaxDegree->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(108, 61);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(78, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Maximum order";
			// 
			// lbl_MaxDegree
			// 
			this->lbl_MaxDegree->AutoSize = true;
			this->lbl_MaxDegree->Location = System::Drawing::Point(108, 36);
			this->lbl_MaxDegree->Name = L"lbl_MaxDegree";
			this->lbl_MaxDegree->Size = System::Drawing::Size(87, 13);
			this->lbl_MaxDegree->TabIndex = 6;
			this->lbl_MaxDegree->Text = L"Maximum degree";
			// 
			// lbl_Note
			// 
			this->lbl_Note->AutoSize = true;
			this->lbl_Note->Location = System::Drawing::Point(10, 139);
			this->lbl_Note->Name = L"lbl_Note";
			this->lbl_Note->Size = System::Drawing::Size(140, 13);
			this->lbl_Note->TabIndex = 5;
			this->lbl_Note->Text = L"No time variable coefficients";
			// 
			// lbl_R
			// 
			this->lbl_R->AutoSize = true;
			this->lbl_R->Location = System::Drawing::Point(12, 113);
			this->lbl_R->Name = L"lbl_R";
			this->lbl_R->Size = System::Drawing::Size(69, 13);
			this->lbl_R->TabIndex = 4;
			this->lbl_R->Text = L"R = 6378137";
			// 
			// lbl_GM
			// 
			this->lbl_GM->AutoSize = true;
			this->lbl_GM->Location = System::Drawing::Point(9, 87);
			this->lbl_GM->Name = L"lbl_GM";
			this->lbl_GM->Size = System::Drawing::Size(105, 13);
			this->lbl_GM->TabIndex = 3;
			this->lbl_GM->Text = L"GM = 0.3986005e15";
			// 
			// lbl_Mmax
			// 
			this->lbl_Mmax->AutoSize = true;
			this->lbl_Mmax->Location = System::Drawing::Point(9, 60);
			this->lbl_Mmax->Name = L"lbl_Mmax";
			this->lbl_Mmax->Size = System::Drawing::Size(53, 13);
			this->lbl_Mmax->TabIndex = 2;
			this->lbl_Mmax->Text = L"Mmax = 0";
			// 
			// lbl_Lmax
			// 
			this->lbl_Lmax->AutoSize = true;
			this->lbl_Lmax->Location = System::Drawing::Point(9, 34);
			this->lbl_Lmax->Name = L"lbl_Lmax";
			this->lbl_Lmax->Size = System::Drawing::Size(50, 13);
			this->lbl_Lmax->TabIndex = 1;
			this->lbl_Lmax->Text = L"Lmax = 0";
			// 
			// lbl_CoefficientFile
			// 
			this->lbl_CoefficientFile->AutoSize = true;
			this->lbl_CoefficientFile->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_CoefficientFile->Location = System::Drawing::Point(6, 16);
			this->lbl_CoefficientFile->Name = L"lbl_CoefficientFile";
			this->lbl_CoefficientFile->Size = System::Drawing::Size(189, 14);
			this->lbl_CoefficientFile->TabIndex = 0;
			this->lbl_CoefficientFile->Text = L"Coefficient File: no model";
			// 
			// grp_Tranformation
			// 
			this->grp_Tranformation->Controls->Add(this->btn_Current);
			this->grp_Tranformation->Controls->Add(this->txt_OMEGA);
			this->grp_Tranformation->Controls->Add(this->rb_Exact);
			this->grp_Tranformation->Controls->Add(this->rb_GAST);
			this->grp_Tranformation->Controls->Add(this->rb_Omega);
			this->grp_Tranformation->Location = System::Drawing::Point(31, 206);
			this->grp_Tranformation->Name = L"grp_Tranformation";
			this->grp_Tranformation->Size = System::Drawing::Size(218, 164);
			this->grp_Tranformation->TabIndex = 3;
			this->grp_Tranformation->TabStop = false;
			this->grp_Tranformation->Text = L"Transformation Earth-Fixed <=> Inertial";
			// 
			// btn_Current
			// 
			this->btn_Current->Location = System::Drawing::Point(110, 76);
			this->btn_Current->Name = L"btn_Current";
			this->btn_Current->Size = System::Drawing::Size(75, 23);
			this->btn_Current->TabIndex = 4;
			this->btn_Current->Text = L"Current";
			this->btn_Current->UseVisualStyleBackColor = true;
			// 
			// txt_OMEGA
			// 
			this->txt_OMEGA->Location = System::Drawing::Point(100, 41);
			this->txt_OMEGA->Name = L"txt_OMEGA";
			this->txt_OMEGA->Size = System::Drawing::Size(100, 20);
			this->txt_OMEGA->TabIndex = 3;
			this->txt_OMEGA->Text = L"0";
			// 
			// rb_Exact
			// 
			this->rb_Exact->AutoSize = true;
			this->rb_Exact->Location = System::Drawing::Point(6, 109);
			this->rb_Exact->Name = L"rb_Exact";
			this->rb_Exact->Size = System::Drawing::Size(52, 17);
			this->rb_Exact->TabIndex = 2;
			this->rb_Exact->TabStop = true;
			this->rb_Exact->Text = L"Exact";
			this->rb_Exact->UseVisualStyleBackColor = true;
			// 
			// rb_GAST
			// 
			this->rb_GAST->AutoSize = true;
			this->rb_GAST->Location = System::Drawing::Point(6, 76);
			this->rb_GAST->Name = L"rb_GAST";
			this->rb_GAST->Size = System::Drawing::Size(76, 17);
			this->rb_GAST->TabIndex = 1;
			this->rb_GAST->TabStop = true;
			this->rb_GAST->Text = L"GAST only";
			this->rb_GAST->UseVisualStyleBackColor = true;
			// 
			// rb_Omega
			// 
			this->rb_Omega->AutoSize = true;
			this->rb_Omega->Checked = true;
			this->rb_Omega->Location = System::Drawing::Point(6, 44);
			this->rb_Omega->Name = L"rb_Omega";
			this->rb_Omega->Size = System::Drawing::Size(86, 17);
			this->rb_Omega->TabIndex = 0;
			this->rb_Omega->TabStop = true;
			this->rb_Omega->Text = L"OMEGA only";
			this->rb_Omega->UseVisualStyleBackColor = true;
			// 
			// grp_CoordinateSystem
			// 
			this->grp_CoordinateSystem->Controls->Add(this->rb_Cartesian);
			this->grp_CoordinateSystem->Controls->Add(this->rb_Spherical);
			this->grp_CoordinateSystem->Location = System::Drawing::Point(32, 67);
			this->grp_CoordinateSystem->Name = L"grp_CoordinateSystem";
			this->grp_CoordinateSystem->Size = System::Drawing::Size(217, 100);
			this->grp_CoordinateSystem->TabIndex = 2;
			this->grp_CoordinateSystem->TabStop = false;
			this->grp_CoordinateSystem->Text = L"Coordinate System for Computation";
			// 
			// rb_Cartesian
			// 
			this->rb_Cartesian->AutoSize = true;
			this->rb_Cartesian->Location = System::Drawing::Point(6, 61);
			this->rb_Cartesian->Name = L"rb_Cartesian";
			this->rb_Cartesian->Size = System::Drawing::Size(137, 17);
			this->rb_Cartesian->TabIndex = 1;
			this->rb_Cartesian->Text = L"Cartesian (Cunningham)";
			this->rb_Cartesian->UseVisualStyleBackColor = true;
			// 
			// rb_Spherical
			// 
			this->rb_Spherical->AutoSize = true;
			this->rb_Spherical->Checked = true;
			this->rb_Spherical->Location = System::Drawing::Point(6, 29);
			this->rb_Spherical->Name = L"rb_Spherical";
			this->rb_Spherical->Size = System::Drawing::Size(123, 17);
			this->rb_Spherical->TabIndex = 0;
			this->rb_Spherical->TabStop = true;
			this->rb_Spherical->Text = L"Spherical (Legendre)";
			this->rb_Spherical->UseVisualStyleBackColor = true;
			// 
			// lbl_GravityFieldComputation
			// 
			this->lbl_GravityFieldComputation->AutoSize = true;
			this->lbl_GravityFieldComputation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_GravityFieldComputation->Location = System::Drawing::Point(209, 29);
			this->lbl_GravityFieldComputation->Name = L"lbl_GravityFieldComputation";
			this->lbl_GravityFieldComputation->Size = System::Drawing::Size(271, 25);
			this->lbl_GravityFieldComputation->TabIndex = 1;
			this->lbl_GravityFieldComputation->Text = L"Gravity Field Calculation";
			// 
			// tab_SurfaceForces
			// 
			this->tab_SurfaceForces->Controls->Add(this->grp_SurfaceForces);
			this->tab_SurfaceForces->Controls->Add(this->lbl_SurfaceForces);
			this->tab_SurfaceForces->Location = System::Drawing::Point(4, 22);
			this->tab_SurfaceForces->Name = L"tab_SurfaceForces";
			this->tab_SurfaceForces->Padding = System::Windows::Forms::Padding(3);
			this->tab_SurfaceForces->Size = System::Drawing::Size(696, 408);
			this->tab_SurfaceForces->TabIndex = 2;
			this->tab_SurfaceForces->Text = L"Surface Forces";
			this->tab_SurfaceForces->UseVisualStyleBackColor = true;
			// 
			// grp_SurfaceForces
			// 
			this->grp_SurfaceForces->Controls->Add(this->grp_MeanArea);
			this->grp_SurfaceForces->Controls->Add(this->grp_ChooseSurfaceModel);
			this->grp_SurfaceForces->Controls->Add(this->grp_MassOfSatellite);
			this->grp_SurfaceForces->Controls->Add(this->chk_UseSurfaceModel);
			this->grp_SurfaceForces->Controls->Add(this->chk_WindModel);
			this->grp_SurfaceForces->Controls->Add(this->chk_SolarPressure);
			this->grp_SurfaceForces->Controls->Add(this->chk_AtmosphericDrag);
			this->grp_SurfaceForces->Location = System::Drawing::Point(62, 56);
			this->grp_SurfaceForces->Name = L"grp_SurfaceForces";
			this->grp_SurfaceForces->Size = System::Drawing::Size(572, 326);
			this->grp_SurfaceForces->TabIndex = 3;
			this->grp_SurfaceForces->TabStop = false;
			this->grp_SurfaceForces->Text = L"Enable Desired Surface Forces";
			// 
			// grp_MeanArea
			// 
			this->grp_MeanArea->Controls->Add(this->txt_MeanArea);
			this->grp_MeanArea->Controls->Add(this->lbl_m2);
			this->grp_MeanArea->Location = System::Drawing::Point(312, 193);
			this->grp_MeanArea->Name = L"grp_MeanArea";
			this->grp_MeanArea->Size = System::Drawing::Size(200, 100);
			this->grp_MeanArea->TabIndex = 6;
			this->grp_MeanArea->TabStop = false;
			this->grp_MeanArea->Text = L"Mean Effective Area";
			this->grp_MeanArea->Visible = false;
			// 
			// txt_MeanArea
			// 
			this->txt_MeanArea->Location = System::Drawing::Point(26, 41);
			this->txt_MeanArea->Name = L"txt_MeanArea";
			this->txt_MeanArea->Size = System::Drawing::Size(100, 20);
			this->txt_MeanArea->TabIndex = 1;
			this->txt_MeanArea->Text = L"2";
			this->txt_MeanArea->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lbl_m2
			// 
			this->lbl_m2->AutoSize = true;
			this->lbl_m2->Location = System::Drawing::Point(145, 44);
			this->lbl_m2->Name = L"lbl_m2";
			this->lbl_m2->Size = System::Drawing::Size(27, 13);
			this->lbl_m2->TabIndex = 0;
			this->lbl_m2->Text = L"m^2";
			// 
			// grp_ChooseSurfaceModel
			// 
			this->grp_ChooseSurfaceModel->Controls->Add(this->rb_GraceOldModel);
			this->grp_ChooseSurfaceModel->Controls->Add(this->rb_Grace);
			this->grp_ChooseSurfaceModel->Controls->Add(this->rb_Champ);
			this->grp_ChooseSurfaceModel->Location = System::Drawing::Point(312, 62);
			this->grp_ChooseSurfaceModel->Name = L"grp_ChooseSurfaceModel";
			this->grp_ChooseSurfaceModel->Size = System::Drawing::Size(200, 100);
			this->grp_ChooseSurfaceModel->TabIndex = 5;
			this->grp_ChooseSurfaceModel->TabStop = false;
			this->grp_ChooseSurfaceModel->Text = L"Choose Surface Model";
			this->grp_ChooseSurfaceModel->Visible = false;
			// 
			// rb_GraceOldModel
			// 
			this->rb_GraceOldModel->AutoSize = true;
			this->rb_GraceOldModel->Location = System::Drawing::Point(26, 67);
			this->rb_GraceOldModel->Name = L"rb_GraceOldModel";
			this->rb_GraceOldModel->Size = System::Drawing::Size(116, 17);
			this->rb_GraceOldModel->TabIndex = 2;
			this->rb_GraceOldModel->TabStop = true;
			this->rb_GraceOldModel->Text = L"GRACE (old model)";
			this->rb_GraceOldModel->UseVisualStyleBackColor = true;
			// 
			// rb_Grace
			// 
			this->rb_Grace->AutoSize = true;
			this->rb_Grace->Location = System::Drawing::Point(26, 43);
			this->rb_Grace->Name = L"rb_Grace";
			this->rb_Grace->Size = System::Drawing::Size(62, 17);
			this->rb_Grace->TabIndex = 1;
			this->rb_Grace->TabStop = true;
			this->rb_Grace->Text = L"GRACE";
			this->rb_Grace->UseVisualStyleBackColor = true;
			// 
			// rb_Champ
			// 
			this->rb_Champ->AutoSize = true;
			this->rb_Champ->Location = System::Drawing::Point(26, 22);
			this->rb_Champ->Name = L"rb_Champ";
			this->rb_Champ->Size = System::Drawing::Size(63, 17);
			this->rb_Champ->TabIndex = 0;
			this->rb_Champ->TabStop = true;
			this->rb_Champ->Text = L"CHAMP";
			this->rb_Champ->UseVisualStyleBackColor = true;
			// 
			// grp_MassOfSatellite
			// 
			this->grp_MassOfSatellite->Controls->Add(this->txt_MassOfSatellite);
			this->grp_MassOfSatellite->Controls->Add(this->lbl_Kg);
			this->grp_MassOfSatellite->Location = System::Drawing::Point(62, 180);
			this->grp_MassOfSatellite->Name = L"grp_MassOfSatellite";
			this->grp_MassOfSatellite->Size = System::Drawing::Size(200, 100);
			this->grp_MassOfSatellite->TabIndex = 4;
			this->grp_MassOfSatellite->TabStop = false;
			this->grp_MassOfSatellite->Text = L"Mass Of Satellite";
			this->grp_MassOfSatellite->Visible = false;
			// 
			// txt_MassOfSatellite
			// 
			this->txt_MassOfSatellite->Location = System::Drawing::Point(20, 47);
			this->txt_MassOfSatellite->Name = L"txt_MassOfSatellite";
			this->txt_MassOfSatellite->Size = System::Drawing::Size(100, 20);
			this->txt_MassOfSatellite->TabIndex = 1;
			// 
			// lbl_Kg
			// 
			this->lbl_Kg->AutoSize = true;
			this->lbl_Kg->Location = System::Drawing::Point(143, 50);
			this->lbl_Kg->Name = L"lbl_Kg";
			this->lbl_Kg->Size = System::Drawing::Size(20, 13);
			this->lbl_Kg->TabIndex = 0;
			this->lbl_Kg->Text = L"Kg";
			// 
			// chk_UseSurfaceModel
			// 
			this->chk_UseSurfaceModel->AutoSize = true;
			this->chk_UseSurfaceModel->Location = System::Drawing::Point(62, 134);
			this->chk_UseSurfaceModel->Name = L"chk_UseSurfaceModel";
			this->chk_UseSurfaceModel->Size = System::Drawing::Size(117, 17);
			this->chk_UseSurfaceModel->TabIndex = 3;
			this->chk_UseSurfaceModel->Text = L"Use Surface Model";
			this->chk_UseSurfaceModel->UseVisualStyleBackColor = true;
			this->chk_UseSurfaceModel->Visible = false;
			this->chk_UseSurfaceModel->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::chk_UseSurfaceModel_CheckedChanged);
			// 
			// chk_WindModel
			// 
			this->chk_WindModel->AutoSize = true;
			this->chk_WindModel->Location = System::Drawing::Point(62, 110);
			this->chk_WindModel->Name = L"chk_WindModel";
			this->chk_WindModel->Size = System::Drawing::Size(83, 17);
			this->chk_WindModel->TabIndex = 2;
			this->chk_WindModel->Text = L"Wind Model";
			this->chk_WindModel->UseVisualStyleBackColor = true;
			this->chk_WindModel->Visible = false;
			// 
			// chk_SolarPressure
			// 
			this->chk_SolarPressure->AutoSize = true;
			this->chk_SolarPressure->Location = System::Drawing::Point(62, 86);
			this->chk_SolarPressure->Name = L"chk_SolarPressure";
			this->chk_SolarPressure->Size = System::Drawing::Size(94, 17);
			this->chk_SolarPressure->TabIndex = 1;
			this->chk_SolarPressure->Text = L"Solar Pressure";
			this->chk_SolarPressure->UseVisualStyleBackColor = true;
			this->chk_SolarPressure->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::chk_SolarPressure_CheckedChanged);
			// 
			// chk_AtmosphericDrag
			// 
			this->chk_AtmosphericDrag->AutoSize = true;
			this->chk_AtmosphericDrag->Location = System::Drawing::Point(62, 62);
			this->chk_AtmosphericDrag->Name = L"chk_AtmosphericDrag";
			this->chk_AtmosphericDrag->Size = System::Drawing::Size(110, 17);
			this->chk_AtmosphericDrag->TabIndex = 0;
			this->chk_AtmosphericDrag->Text = L"Atmospheric Drag";
			this->chk_AtmosphericDrag->UseVisualStyleBackColor = true;
			this->chk_AtmosphericDrag->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::chk_AtmosphericDrag_CheckedChanged);
			// 
			// lbl_SurfaceForces
			// 
			this->lbl_SurfaceForces->AutoSize = true;
			this->lbl_SurfaceForces->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_SurfaceForces->Location = System::Drawing::Point(226, 28);
			this->lbl_SurfaceForces->Name = L"lbl_SurfaceForces";
			this->lbl_SurfaceForces->Size = System::Drawing::Size(172, 25);
			this->lbl_SurfaceForces->TabIndex = 2;
			this->lbl_SurfaceForces->Text = L"Surface Forces";
			// 
			// tab_AtmosphericForces
			// 
			this->tab_AtmosphericForces->BackColor = System::Drawing::Color::Transparent;
			this->tab_AtmosphericForces->Controls->Add(this->grp_param_tau);
			this->tab_AtmosphericForces->Controls->Add(this->grp_param_p);
			this->tab_AtmosphericForces->Controls->Add(this->chk_DeriveAlpha);
			this->tab_AtmosphericForces->Controls->Add(this->grp_ChooseModel);
			this->tab_AtmosphericForces->Controls->Add(this->grp_ClValue);
			this->tab_AtmosphericForces->Controls->Add(this->grp_AmbientTemperature);
			this->tab_AtmosphericForces->Controls->Add(this->grp_MeanAirDensity);
			this->tab_AtmosphericForces->Controls->Add(this->grp_CdValue);
			this->tab_AtmosphericForces->Controls->Add(this->chk_AirDensityViaModel);
			this->tab_AtmosphericForces->Controls->Add(this->grp_ChooseForceModel);
			this->tab_AtmosphericForces->Controls->Add(this->lbl_AtmosphericDragForceModel);
			this->tab_AtmosphericForces->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->tab_AtmosphericForces->Location = System::Drawing::Point(4, 22);
			this->tab_AtmosphericForces->Name = L"tab_AtmosphericForces";
			this->tab_AtmosphericForces->Padding = System::Windows::Forms::Padding(3);
			this->tab_AtmosphericForces->Size = System::Drawing::Size(696, 408);
			this->tab_AtmosphericForces->TabIndex = 3;
			this->tab_AtmosphericForces->Text = L"Atmospheric Forces";
			// 
			// grp_param_tau
			// 
			this->grp_param_tau->Controls->Add(this->txt_param_tau);
			this->grp_param_tau->Location = System::Drawing::Point(70, 320);
			this->grp_param_tau->Name = L"grp_param_tau";
			this->grp_param_tau->Size = System::Drawing::Size(226, 49);
			this->grp_param_tau->TabIndex = 12;
			this->grp_param_tau->TabStop = false;
			this->grp_param_tau->Text = L"tau";
			this->grp_param_tau->Visible = false;
			// 
			// txt_param_tau
			// 
			this->txt_param_tau->Location = System::Drawing::Point(32, 20);
			this->txt_param_tau->Name = L"txt_param_tau";
			this->txt_param_tau->Size = System::Drawing::Size(100, 20);
			this->txt_param_tau->TabIndex = 0;
			this->txt_param_tau->Text = L"1.0";
			// 
			// grp_param_p
			// 
			this->grp_param_p->Controls->Add(this->txt_param_p);
			this->grp_param_p->Location = System::Drawing::Point(70, 266);
			this->grp_param_p->Name = L"grp_param_p";
			this->grp_param_p->Size = System::Drawing::Size(226, 49);
			this->grp_param_p->TabIndex = 11;
			this->grp_param_p->TabStop = false;
			this->grp_param_p->Text = L"p";
			this->grp_param_p->Visible = false;
			// 
			// txt_param_p
			// 
			this->txt_param_p->Location = System::Drawing::Point(32, 20);
			this->txt_param_p->Name = L"txt_param_p";
			this->txt_param_p->Size = System::Drawing::Size(100, 20);
			this->txt_param_p->TabIndex = 0;
			this->txt_param_p->Text = L"1.0";
			// 
			// chk_DeriveAlpha
			// 
			this->chk_DeriveAlpha->AutoSize = true;
			this->chk_DeriveAlpha->Location = System::Drawing::Point(239, 231);
			this->chk_DeriveAlpha->Name = L"chk_DeriveAlpha";
			this->chk_DeriveAlpha->Size = System::Drawing::Size(118, 17);
			this->chk_DeriveAlpha->TabIndex = 10;
			this->chk_DeriveAlpha->Text = L"Derive Alpha model";
			this->chk_DeriveAlpha->UseVisualStyleBackColor = true;
			this->chk_DeriveAlpha->Visible = false;
			// 
			// grp_ChooseModel
			// 
			this->grp_ChooseModel->Controls->Add(this->rb_Mazanek);
			this->grp_ChooseModel->Controls->Add(this->rb_Klinkrad);
			this->grp_ChooseModel->Controls->Add(this->rb_Thalhammer);
			this->grp_ChooseModel->Location = System::Drawing::Point(342, 345);
			this->grp_ChooseModel->Name = L"grp_ChooseModel";
			this->grp_ChooseModel->Size = System::Drawing::Size(281, 47);
			this->grp_ChooseModel->TabIndex = 9;
			this->grp_ChooseModel->TabStop = false;
			this->grp_ChooseModel->Text = L"Choose Individual Model";
			this->grp_ChooseModel->Visible = false;
			// 
			// rb_Mazanek
			// 
			this->rb_Mazanek->AutoSize = true;
			this->rb_Mazanek->Location = System::Drawing::Point(206, 18);
			this->rb_Mazanek->Name = L"rb_Mazanek";
			this->rb_Mazanek->Size = System::Drawing::Size(69, 17);
			this->rb_Mazanek->TabIndex = 2;
			this->rb_Mazanek->Text = L"Mazanek";
			this->rb_Mazanek->UseVisualStyleBackColor = true;
			this->rb_Mazanek->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::rb_Mazanek_CheckedChanged);
			// 
			// rb_Klinkrad
			// 
			this->rb_Klinkrad->AutoSize = true;
			this->rb_Klinkrad->Location = System::Drawing::Point(95, 20);
			this->rb_Klinkrad->Name = L"rb_Klinkrad";
			this->rb_Klinkrad->Size = System::Drawing::Size(105, 17);
			this->rb_Klinkrad->TabIndex = 1;
			this->rb_Klinkrad->Text = L"Klinkrad/Fritsche";
			this->rb_Klinkrad->UseVisualStyleBackColor = true;
			this->rb_Klinkrad->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::rb_Klinkrad_CheckedChanged);
			// 
			// rb_Thalhammer
			// 
			this->rb_Thalhammer->AutoSize = true;
			this->rb_Thalhammer->Checked = true;
			this->rb_Thalhammer->Location = System::Drawing::Point(7, 20);
			this->rb_Thalhammer->Name = L"rb_Thalhammer";
			this->rb_Thalhammer->Size = System::Drawing::Size(83, 17);
			this->rb_Thalhammer->TabIndex = 0;
			this->rb_Thalhammer->TabStop = true;
			this->rb_Thalhammer->Text = L"Thalhammer";
			this->rb_Thalhammer->UseVisualStyleBackColor = true;
			this->rb_Thalhammer->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::rb_Thalhammer_CheckedChanged);
			// 
			// grp_ClValue
			// 
			this->grp_ClValue->Controls->Add(this->txt_ClValue);
			this->grp_ClValue->Location = System::Drawing::Point(74, 326);
			this->grp_ClValue->Name = L"grp_ClValue";
			this->grp_ClValue->Size = System::Drawing::Size(200, 54);
			this->grp_ClValue->TabIndex = 7;
			this->grp_ClValue->TabStop = false;
			this->grp_ClValue->Text = L"Cl Value";
			this->grp_ClValue->Visible = false;
			// 
			// txt_ClValue
			// 
			this->txt_ClValue->Location = System::Drawing::Point(45, 19);
			this->txt_ClValue->Name = L"txt_ClValue";
			this->txt_ClValue->Size = System::Drawing::Size(100, 20);
			this->txt_ClValue->TabIndex = 0;
			this->txt_ClValue->Text = L"2.1";
			this->txt_ClValue->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// grp_AmbientTemperature
			// 
			this->grp_AmbientTemperature->Controls->Add(this->txt_AmbientTemperature);
			this->grp_AmbientTemperature->Controls->Add(this->lbl_DegreesC);
			this->grp_AmbientTemperature->Location = System::Drawing::Point(423, 222);
			this->grp_AmbientTemperature->Name = L"grp_AmbientTemperature";
			this->grp_AmbientTemperature->Size = System::Drawing::Size(200, 100);
			this->grp_AmbientTemperature->TabIndex = 8;
			this->grp_AmbientTemperature->TabStop = false;
			this->grp_AmbientTemperature->Text = L"Ambient Temperature";
			this->grp_AmbientTemperature->Visible = false;
			// 
			// txt_AmbientTemperature
			// 
			this->txt_AmbientTemperature->Location = System::Drawing::Point(29, 44);
			this->txt_AmbientTemperature->Name = L"txt_AmbientTemperature";
			this->txt_AmbientTemperature->Size = System::Drawing::Size(69, 20);
			this->txt_AmbientTemperature->TabIndex = 1;
			this->txt_AmbientTemperature->Text = L"1100";
			// 
			// lbl_DegreesC
			// 
			this->lbl_DegreesC->AutoSize = true;
			this->lbl_DegreesC->Location = System::Drawing::Point(115, 47);
			this->lbl_DegreesC->Name = L"lbl_DegreesC";
			this->lbl_DegreesC->Size = System::Drawing::Size(24, 13);
			this->lbl_DegreesC->TabIndex = 0;
			this->lbl_DegreesC->Text = L"(°K)";
			// 
			// grp_MeanAirDensity
			// 
			this->grp_MeanAirDensity->Controls->Add(this->cmb_Molecule);
			this->grp_MeanAirDensity->Controls->Add(this->txt_AirDensity);
			this->grp_MeanAirDensity->Controls->Add(this->lbl_AirDensityUnit);
			this->grp_MeanAirDensity->Location = System::Drawing::Point(423, 93);
			this->grp_MeanAirDensity->Name = L"grp_MeanAirDensity";
			this->grp_MeanAirDensity->Size = System::Drawing::Size(200, 91);
			this->grp_MeanAirDensity->TabIndex = 7;
			this->grp_MeanAirDensity->TabStop = false;
			this->grp_MeanAirDensity->Text = L"Mean Air Density";
			this->grp_MeanAirDensity->Visible = false;
			// 
			// cmb_Molecule
			// 
			this->cmb_Molecule->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb_Molecule->FormattingEnabled = true;
			this->cmb_Molecule->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"He", L"O", L"N2", L"O2", L"Ar", L"H", L"N", 
				L"Distributed"});
			this->cmb_Molecule->Location = System::Drawing::Point(29, 54);
			this->cmb_Molecule->Name = L"cmb_Molecule";
			this->cmb_Molecule->Size = System::Drawing::Size(121, 21);
			this->cmb_Molecule->TabIndex = 2;
			// 
			// txt_AirDensity
			// 
			this->txt_AirDensity->Location = System::Drawing::Point(29, 19);
			this->txt_AirDensity->Name = L"txt_AirDensity";
			this->txt_AirDensity->Size = System::Drawing::Size(75, 20);
			this->txt_AirDensity->TabIndex = 1;
			this->txt_AirDensity->Text = L"2e-12";
			// 
			// lbl_AirDensityUnit
			// 
			this->lbl_AirDensityUnit->AutoSize = true;
			this->lbl_AirDensityUnit->Location = System::Drawing::Point(124, 22);
			this->lbl_AirDensityUnit->Name = L"lbl_AirDensityUnit";
			this->lbl_AirDensityUnit->Size = System::Drawing::Size(45, 13);
			this->lbl_AirDensityUnit->TabIndex = 0;
			this->lbl_AirDensityUnit->Text = L"Kg/m^3";
			// 
			// grp_CdValue
			// 
			this->grp_CdValue->Controls->Add(this->txt_CdValue);
			this->grp_CdValue->Location = System::Drawing::Point(74, 266);
			this->grp_CdValue->Name = L"grp_CdValue";
			this->grp_CdValue->Size = System::Drawing::Size(200, 54);
			this->grp_CdValue->TabIndex = 6;
			this->grp_CdValue->TabStop = false;
			this->grp_CdValue->Text = L"Cd Value";
			// 
			// txt_CdValue
			// 
			this->txt_CdValue->Location = System::Drawing::Point(45, 19);
			this->txt_CdValue->Name = L"txt_CdValue";
			this->txt_CdValue->Size = System::Drawing::Size(100, 20);
			this->txt_CdValue->TabIndex = 0;
			this->txt_CdValue->Text = L"2.2";
			this->txt_CdValue->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// chk_AirDensityViaModel
			// 
			this->chk_AirDensityViaModel->AutoSize = true;
			this->chk_AirDensityViaModel->Location = System::Drawing::Point(74, 231);
			this->chk_AirDensityViaModel->Name = L"chk_AirDensityViaModel";
			this->chk_AirDensityViaModel->Size = System::Drawing::Size(159, 17);
			this->chk_AirDensityViaModel->TabIndex = 5;
			this->chk_AirDensityViaModel->Text = L"Derive Air Density via Model";
			this->chk_AirDensityViaModel->UseVisualStyleBackColor = true;
			this->chk_AirDensityViaModel->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::cb_AirDensityViaModel_CheckedChanged);
			// 
			// grp_ChooseForceModel
			// 
			this->grp_ChooseForceModel->Controls->Add(this->rb_TwoParameter);
			this->grp_ChooseForceModel->Controls->Add(this->rb_OneParameter);
			this->grp_ChooseForceModel->Controls->Add(this->rb_DragAndLift);
			this->grp_ChooseForceModel->Controls->Add(this->rb_onlyDrag);
			this->grp_ChooseForceModel->Location = System::Drawing::Point(74, 86);
			this->grp_ChooseForceModel->Name = L"grp_ChooseForceModel";
			this->grp_ChooseForceModel->Size = System::Drawing::Size(260, 139);
			this->grp_ChooseForceModel->TabIndex = 4;
			this->grp_ChooseForceModel->TabStop = false;
			this->grp_ChooseForceModel->Text = L"Choose Force Model";
			// 
			// rb_TwoParameter
			// 
			this->rb_TwoParameter->AutoSize = true;
			this->rb_TwoParameter->Location = System::Drawing::Point(15, 90);
			this->rb_TwoParameter->Name = L"rb_TwoParameter";
			this->rb_TwoParameter->Size = System::Drawing::Size(208, 17);
			this->rb_TwoParameter->TabIndex = 3;
			this->rb_TwoParameter->Text = L"Two Parameter Accommodation Model";
			this->rb_TwoParameter->UseVisualStyleBackColor = true;
			this->rb_TwoParameter->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::rb_TwoParameter_CheckedChanged);
			// 
			// rb_OneParameter
			// 
			this->rb_OneParameter->AutoSize = true;
			this->rb_OneParameter->Location = System::Drawing::Point(15, 65);
			this->rb_OneParameter->Name = L"rb_OneParameter";
			this->rb_OneParameter->Size = System::Drawing::Size(207, 17);
			this->rb_OneParameter->TabIndex = 2;
			this->rb_OneParameter->Text = L"One Parameter Accommodation Model";
			this->rb_OneParameter->UseVisualStyleBackColor = true;
			this->rb_OneParameter->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::rb_OneParameter_CheckedChanged);
			// 
			// rb_DragAndLift
			// 
			this->rb_DragAndLift->AutoSize = true;
			this->rb_DragAndLift->Location = System::Drawing::Point(15, 42);
			this->rb_DragAndLift->Name = L"rb_DragAndLift";
			this->rb_DragAndLift->Size = System::Drawing::Size(86, 17);
			this->rb_DragAndLift->TabIndex = 1;
			this->rb_DragAndLift->Text = L"Drag and Lift";
			this->rb_DragAndLift->UseVisualStyleBackColor = true;
			this->rb_DragAndLift->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::rb_DragAndLift_CheckedChanged);
			// 
			// rb_onlyDrag
			// 
			this->rb_onlyDrag->AutoSize = true;
			this->rb_onlyDrag->Checked = true;
			this->rb_onlyDrag->Location = System::Drawing::Point(15, 19);
			this->rb_onlyDrag->Name = L"rb_onlyDrag";
			this->rb_onlyDrag->Size = System::Drawing::Size(101, 17);
			this->rb_onlyDrag->TabIndex = 0;
			this->rb_onlyDrag->TabStop = true;
			this->rb_onlyDrag->Text = L"Only drag, no lift";
			this->rb_onlyDrag->UseVisualStyleBackColor = true;
			this->rb_onlyDrag->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::rb_onlyDrag_CheckedChanged);
			// 
			// lbl_AtmosphericDragForceModel
			// 
			this->lbl_AtmosphericDragForceModel->AutoSize = true;
			this->lbl_AtmosphericDragForceModel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_AtmosphericDragForceModel->Location = System::Drawing::Point(148, 27);
			this->lbl_AtmosphericDragForceModel->Name = L"lbl_AtmosphericDragForceModel";
			this->lbl_AtmosphericDragForceModel->Size = System::Drawing::Size(379, 25);
			this->lbl_AtmosphericDragForceModel->TabIndex = 3;
			this->lbl_AtmosphericDragForceModel->Text = L"Force Model For Atmospheric Drag";
			// 
			// tab_Tides
			// 
			this->tab_Tides->Controls->Add(this->grp_OceanTides);
			this->tab_Tides->Controls->Add(this->grp_SolidEarthPoleTide);
			this->tab_Tides->Controls->Add(this->grp_SolidEarthTides);
			this->tab_Tides->Controls->Add(this->grp_DirectTidalAcceleration);
			this->tab_Tides->Controls->Add(this->lbl_TidalEffects);
			this->tab_Tides->Location = System::Drawing::Point(4, 22);
			this->tab_Tides->Name = L"tab_Tides";
			this->tab_Tides->Padding = System::Windows::Forms::Padding(3);
			this->tab_Tides->Size = System::Drawing::Size(696, 408);
			this->tab_Tides->TabIndex = 3;
			this->tab_Tides->Text = L"Tides";
			this->tab_Tides->UseVisualStyleBackColor = true;
			// 
			// grp_OceanTides
			// 
			this->grp_OceanTides->Controls->Add(this->grp_OrderInterval);
			this->grp_OceanTides->Controls->Add(this->grp_OceanTideModel);
			this->grp_OceanTides->Controls->Add(this->chk_EnableOceanTide);
			this->grp_OceanTides->Location = System::Drawing::Point(489, 54);
			this->grp_OceanTides->Name = L"grp_OceanTides";
			this->grp_OceanTides->Size = System::Drawing::Size(188, 279);
			this->grp_OceanTides->TabIndex = 7;
			this->grp_OceanTides->TabStop = false;
			this->grp_OceanTides->Text = L"Ocean Tides";
			// 
			// grp_OrderInterval
			// 
			this->grp_OrderInterval->Controls->Add(this->txt_InterplationIntervalOceanTide);
			this->grp_OrderInterval->Controls->Add(this->lbl_DegOrderOceanTides);
			this->grp_OrderInterval->Controls->Add(this->txt_DegOrdOceanTide);
			this->grp_OrderInterval->Controls->Add(this->lbl_InterpolationIntervalOceanTide);
			this->grp_OrderInterval->Location = System::Drawing::Point(25, 171);
			this->grp_OrderInterval->Name = L"grp_OrderInterval";
			this->grp_OrderInterval->Size = System::Drawing::Size(151, 102);
			this->grp_OrderInterval->TabIndex = 8;
			this->grp_OrderInterval->TabStop = false;
			this->grp_OrderInterval->Text = L"-";
			this->grp_OrderInterval->Visible = false;
			// 
			// txt_InterplationIntervalOceanTide
			// 
			this->txt_InterplationIntervalOceanTide->Location = System::Drawing::Point(9, 71);
			this->txt_InterplationIntervalOceanTide->Name = L"txt_InterplationIntervalOceanTide";
			this->txt_InterplationIntervalOceanTide->Size = System::Drawing::Size(72, 20);
			this->txt_InterplationIntervalOceanTide->TabIndex = 5;
			this->txt_InterplationIntervalOceanTide->TextChanged += gcnew System::EventHandler(this, &Orbitint::textBox7_TextChanged);
			// 
			// lbl_DegOrderOceanTides
			// 
			this->lbl_DegOrderOceanTides->AutoSize = true;
			this->lbl_DegOrderOceanTides->Location = System::Drawing::Point(6, 16);
			this->lbl_DegOrderOceanTides->Name = L"lbl_DegOrderOceanTides";
			this->lbl_DegOrderOceanTides->Size = System::Drawing::Size(139, 13);
			this->lbl_DegOrderOceanTides->TabIndex = 2;
			this->lbl_DegOrderOceanTides->Text = L"Maximum Degree and Order";
			// 
			// txt_DegOrdOceanTide
			// 
			this->txt_DegOrdOceanTide->Location = System::Drawing::Point(9, 32);
			this->txt_DegOrdOceanTide->Name = L"txt_DegOrdOceanTide";
			this->txt_DegOrdOceanTide->Size = System::Drawing::Size(72, 20);
			this->txt_DegOrdOceanTide->TabIndex = 4;
			// 
			// lbl_InterpolationIntervalOceanTide
			// 
			this->lbl_InterpolationIntervalOceanTide->AutoSize = true;
			this->lbl_InterpolationIntervalOceanTide->Location = System::Drawing::Point(3, 55);
			this->lbl_InterpolationIntervalOceanTide->Name = L"lbl_InterpolationIntervalOceanTide";
			this->lbl_InterpolationIntervalOceanTide->Size = System::Drawing::Size(128, 13);
			this->lbl_InterpolationIntervalOceanTide->TabIndex = 3;
			this->lbl_InterpolationIntervalOceanTide->Text = L"Interpolation Interval [min]";
			// 
			// grp_OceanTideModel
			// 
			this->grp_OceanTideModel->Controls->Add(this->rb_FES2002);
			this->grp_OceanTideModel->Controls->Add(this->rb_FES1);
			this->grp_OceanTideModel->Controls->Add(this->rb_Topex);
			this->grp_OceanTideModel->Controls->Add(this->rb_Schwiderski);
			this->grp_OceanTideModel->Location = System::Drawing::Point(29, 48);
			this->grp_OceanTideModel->Name = L"grp_OceanTideModel";
			this->grp_OceanTideModel->Size = System::Drawing::Size(127, 117);
			this->grp_OceanTideModel->TabIndex = 1;
			this->grp_OceanTideModel->TabStop = false;
			this->grp_OceanTideModel->Text = L"Ocean Tide Model";
			this->grp_OceanTideModel->Visible = false;
			// 
			// rb_FES2002
			// 
			this->rb_FES2002->AutoSize = true;
			this->rb_FES2002->Location = System::Drawing::Point(26, 89);
			this->rb_FES2002->Name = L"rb_FES2002";
			this->rb_FES2002->Size = System::Drawing::Size(72, 17);
			this->rb_FES2002->TabIndex = 3;
			this->rb_FES2002->TabStop = true;
			this->rb_FES2002->Text = L"FES 2002";
			this->rb_FES2002->UseVisualStyleBackColor = true;
			// 
			// rb_FES1
			// 
			this->rb_FES1->AutoSize = true;
			this->rb_FES1->Location = System::Drawing::Point(26, 66);
			this->rb_FES1->Name = L"rb_FES1";
			this->rb_FES1->Size = System::Drawing::Size(78, 17);
			this->rb_FES1->TabIndex = 2;
			this->rb_FES1->TabStop = true;
			this->rb_FES1->Text = L"FES 95.2.1";
			this->rb_FES1->UseVisualStyleBackColor = true;
			// 
			// rb_Topex
			// 
			this->rb_Topex->AutoSize = true;
			this->rb_Topex->Location = System::Drawing::Point(26, 43);
			this->rb_Topex->Name = L"rb_Topex";
			this->rb_Topex->Size = System::Drawing::Size(61, 17);
			this->rb_Topex->TabIndex = 1;
			this->rb_Topex->TabStop = true;
			this->rb_Topex->Text = L"TOPEX";
			this->rb_Topex->UseVisualStyleBackColor = true;
			// 
			// rb_Schwiderski
			// 
			this->rb_Schwiderski->AutoSize = true;
			this->rb_Schwiderski->Location = System::Drawing::Point(26, 20);
			this->rb_Schwiderski->Name = L"rb_Schwiderski";
			this->rb_Schwiderski->Size = System::Drawing::Size(82, 17);
			this->rb_Schwiderski->TabIndex = 0;
			this->rb_Schwiderski->TabStop = true;
			this->rb_Schwiderski->Text = L"Schwiderski";
			this->rb_Schwiderski->UseVisualStyleBackColor = true;
			// 
			// chk_EnableOceanTide
			// 
			this->chk_EnableOceanTide->AutoSize = true;
			this->chk_EnableOceanTide->Location = System::Drawing::Point(62, 19);
			this->chk_EnableOceanTide->Name = L"chk_EnableOceanTide";
			this->chk_EnableOceanTide->Size = System::Drawing::Size(59, 17);
			this->chk_EnableOceanTide->TabIndex = 0;
			this->chk_EnableOceanTide->Text = L"Enable";
			this->chk_EnableOceanTide->UseVisualStyleBackColor = true;
			this->chk_EnableOceanTide->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::cb_EnableOceanTide_CheckedChanged);
			// 
			// grp_SolidEarthPoleTide
			// 
			this->grp_SolidEarthPoleTide->Controls->Add(this->cb_SolidEarthPoleTide);
			this->grp_SolidEarthPoleTide->Location = System::Drawing::Point(252, 222);
			this->grp_SolidEarthPoleTide->Name = L"grp_SolidEarthPoleTide";
			this->grp_SolidEarthPoleTide->Size = System::Drawing::Size(200, 100);
			this->grp_SolidEarthPoleTide->TabIndex = 6;
			this->grp_SolidEarthPoleTide->TabStop = false;
			this->grp_SolidEarthPoleTide->Text = L"Solid Earth Pole Tide";
			// 
			// cb_SolidEarthPoleTide
			// 
			this->cb_SolidEarthPoleTide->AutoSize = true;
			this->cb_SolidEarthPoleTide->Location = System::Drawing::Point(28, 45);
			this->cb_SolidEarthPoleTide->Name = L"cb_SolidEarthPoleTide";
			this->cb_SolidEarthPoleTide->Size = System::Drawing::Size(59, 17);
			this->cb_SolidEarthPoleTide->TabIndex = 0;
			this->cb_SolidEarthPoleTide->Text = L"Enable";
			this->cb_SolidEarthPoleTide->UseVisualStyleBackColor = true;
			// 
			// grp_SolidEarthTides
			// 
			this->grp_SolidEarthTides->Controls->Add(this->cb_FreqDepCorr);
			this->grp_SolidEarthTides->Controls->Add(this->cb_SolidEarthMoon);
			this->grp_SolidEarthTides->Controls->Add(this->cb_SolidEarthSun);
			this->grp_SolidEarthTides->Location = System::Drawing::Point(252, 54);
			this->grp_SolidEarthTides->Name = L"grp_SolidEarthTides";
			this->grp_SolidEarthTides->Size = System::Drawing::Size(218, 128);
			this->grp_SolidEarthTides->TabIndex = 5;
			this->grp_SolidEarthTides->TabStop = false;
			this->grp_SolidEarthTides->Text = L"Solid Earth Tides";
			// 
			// cb_FreqDepCorr
			// 
			this->cb_FreqDepCorr->AutoSize = true;
			this->cb_FreqDepCorr->Location = System::Drawing::Point(28, 95);
			this->cb_FreqDepCorr->Name = L"cb_FreqDepCorr";
			this->cb_FreqDepCorr->Size = System::Drawing::Size(188, 17);
			this->cb_FreqDepCorr->TabIndex = 3;
			this->cb_FreqDepCorr->Text = L"Frequency Dependent Corrections";
			this->cb_FreqDepCorr->UseVisualStyleBackColor = true;
			// 
			// cb_SolidEarthMoon
			// 
			this->cb_SolidEarthMoon->AutoSize = true;
			this->cb_SolidEarthMoon->Location = System::Drawing::Point(28, 31);
			this->cb_SolidEarthMoon->Name = L"cb_SolidEarthMoon";
			this->cb_SolidEarthMoon->Size = System::Drawing::Size(53, 17);
			this->cb_SolidEarthMoon->TabIndex = 0;
			this->cb_SolidEarthMoon->Text = L"Moon";
			this->cb_SolidEarthMoon->UseVisualStyleBackColor = true;
			// 
			// cb_SolidEarthSun
			// 
			this->cb_SolidEarthSun->AutoSize = true;
			this->cb_SolidEarthSun->Location = System::Drawing::Point(28, 63);
			this->cb_SolidEarthSun->Name = L"cb_SolidEarthSun";
			this->cb_SolidEarthSun->Size = System::Drawing::Size(45, 17);
			this->cb_SolidEarthSun->TabIndex = 1;
			this->cb_SolidEarthSun->Text = L"Sun";
			this->cb_SolidEarthSun->UseVisualStyleBackColor = true;
			// 
			// grp_DirectTidalAcceleration
			// 
			this->grp_DirectTidalAcceleration->Controls->Add(this->lbl_EphemerisFileName);
			this->grp_DirectTidalAcceleration->Controls->Add(this->btn_ChooseEphemeris);
			this->grp_DirectTidalAcceleration->Controls->Add(this->cb_Moon);
			this->grp_DirectTidalAcceleration->Controls->Add(this->cb_Sun);
			this->grp_DirectTidalAcceleration->Location = System::Drawing::Point(20, 54);
			this->grp_DirectTidalAcceleration->Name = L"grp_DirectTidalAcceleration";
			this->grp_DirectTidalAcceleration->Size = System::Drawing::Size(200, 268);
			this->grp_DirectTidalAcceleration->TabIndex = 4;
			this->grp_DirectTidalAcceleration->TabStop = false;
			this->grp_DirectTidalAcceleration->Text = L"Direct Tidal Acceleration";
			// 
			// lbl_EphemerisFileName
			// 
			this->lbl_EphemerisFileName->AutoSize = true;
			this->lbl_EphemerisFileName->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_EphemerisFileName->Location = System::Drawing::Point(25, 152);
			this->lbl_EphemerisFileName->Name = L"lbl_EphemerisFileName";
			this->lbl_EphemerisFileName->Size = System::Drawing::Size(119, 14);
			this->lbl_EphemerisFileName->TabIndex = 3;
			this->lbl_EphemerisFileName->Text = L"No File Selected";
			// 
			// btn_ChooseEphemeris
			// 
			this->btn_ChooseEphemeris->Location = System::Drawing::Point(25, 105);
			this->btn_ChooseEphemeris->Name = L"btn_ChooseEphemeris";
			this->btn_ChooseEphemeris->Size = System::Drawing::Size(134, 23);
			this->btn_ChooseEphemeris->TabIndex = 2;
			this->btn_ChooseEphemeris->Text = L"Choose Ephemeris File";
			this->btn_ChooseEphemeris->UseVisualStyleBackColor = true;
			// 
			// cb_Moon
			// 
			this->cb_Moon->AutoSize = true;
			this->cb_Moon->Location = System::Drawing::Point(25, 31);
			this->cb_Moon->Name = L"cb_Moon";
			this->cb_Moon->Size = System::Drawing::Size(53, 17);
			this->cb_Moon->TabIndex = 0;
			this->cb_Moon->Text = L"Moon";
			this->cb_Moon->UseVisualStyleBackColor = true;
			// 
			// cb_Sun
			// 
			this->cb_Sun->AutoSize = true;
			this->cb_Sun->Location = System::Drawing::Point(25, 63);
			this->cb_Sun->Name = L"cb_Sun";
			this->cb_Sun->Size = System::Drawing::Size(45, 17);
			this->cb_Sun->TabIndex = 1;
			this->cb_Sun->Text = L"Sun";
			this->cb_Sun->UseVisualStyleBackColor = true;
			// 
			// lbl_TidalEffects
			// 
			this->lbl_TidalEffects->AutoSize = true;
			this->lbl_TidalEffects->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_TidalEffects->Location = System::Drawing::Point(249, 18);
			this->lbl_TidalEffects->Name = L"lbl_TidalEffects";
			this->lbl_TidalEffects->Size = System::Drawing::Size(144, 25);
			this->lbl_TidalEffects->TabIndex = 3;
			this->lbl_TidalEffects->Text = L"Tidal Effects";
			// 
			// tab_Output
			// 
			this->tab_Output->Controls->Add(this->chk_PoleTide);
			this->tab_Output->Controls->Add(this->chk_OutOceanTide);
			this->tab_Output->Controls->Add(this->chk_Step2Acc);
			this->tab_Output->Controls->Add(this->chk_IndirectSun);
			this->tab_Output->Controls->Add(this->chk_OutIndirectMoon);
			this->tab_Output->Controls->Add(this->chk_DirectTidalAcc);
			this->tab_Output->Controls->Add(this->chk_OutNonCons);
			this->tab_Output->Controls->Add(this->chk_OutSolarPressure);
			this->tab_Output->Controls->Add(this->chk_OutGravityGradients);
			this->tab_Output->Controls->Add(this->chk_OutTrackAngle);
			this->tab_Output->Controls->Add(this->chk_OutKeplerVector);
			this->tab_Output->Controls->Add(this->chk_OutVelocityInertial);
			this->tab_Output->Controls->Add(this->chk_OutOrbitTerrestrial);
			this->tab_Output->Controls->Add(this->chk_OutOrbitInertial);
			this->tab_Output->Controls->Add(this->chk_OutJD2000);
			this->tab_Output->Controls->Add(this->chk_GAST);
			this->tab_Output->Controls->Add(this->chk_OutTime);
			this->tab_Output->Controls->Add(this->txt_Header);
			this->tab_Output->Controls->Add(this->checkBox1);
			this->tab_Output->Controls->Add(this->grp_AccuracyOutput);
			this->tab_Output->Location = System::Drawing::Point(4, 22);
			this->tab_Output->Name = L"tab_Output";
			this->tab_Output->Padding = System::Windows::Forms::Padding(3);
			this->tab_Output->Size = System::Drawing::Size(696, 408);
			this->tab_Output->TabIndex = 1;
			this->tab_Output->Text = L"Output";
			this->tab_Output->UseVisualStyleBackColor = true;
			// 
			// chk_PoleTide
			// 
			this->chk_PoleTide->AutoSize = true;
			this->chk_PoleTide->Location = System::Drawing::Point(420, 351);
			this->chk_PoleTide->Name = L"chk_PoleTide";
			this->chk_PoleTide->Size = System::Drawing::Size(138, 17);
			this->chk_PoleTide->TabIndex = 19;
			this->chk_PoleTide->Text = L"Pole Tide Accelerations";
			this->chk_PoleTide->UseVisualStyleBackColor = true;
			// 
			// chk_OutOceanTide
			// 
			this->chk_OutOceanTide->AutoSize = true;
			this->chk_OutOceanTide->Location = System::Drawing::Point(420, 318);
			this->chk_OutOceanTide->Name = L"chk_OutOceanTide";
			this->chk_OutOceanTide->Size = System::Drawing::Size(149, 17);
			this->chk_OutOceanTide->TabIndex = 18;
			this->chk_OutOceanTide->Text = L"Ocean Tide Accelerations";
			this->chk_OutOceanTide->UseVisualStyleBackColor = true;
			// 
			// chk_Step2Acc
			// 
			this->chk_Step2Acc->AutoSize = true;
			this->chk_Step2Acc->Location = System::Drawing::Point(420, 282);
			this->chk_Step2Acc->Name = L"chk_Step2Acc";
			this->chk_Step2Acc->Size = System::Drawing::Size(118, 17);
			this->chk_Step2Acc->TabIndex = 17;
			this->chk_Step2Acc->Text = L"Step 2 Acclerations";
			this->chk_Step2Acc->UseVisualStyleBackColor = true;
			// 
			// chk_IndirectSun
			// 
			this->chk_IndirectSun->AutoSize = true;
			this->chk_IndirectSun->Location = System::Drawing::Point(420, 245);
			this->chk_IndirectSun->Name = L"chk_IndirectSun";
			this->chk_IndirectSun->Size = System::Drawing::Size(206, 17);
			this->chk_IndirectSun->TabIndex = 16;
			this->chk_IndirectSun->Text = L"Indirect Tidal Accelerations of the Sun";
			this->chk_IndirectSun->UseVisualStyleBackColor = true;
			// 
			// chk_OutIndirectMoon
			// 
			this->chk_OutIndirectMoon->AutoSize = true;
			this->chk_OutIndirectMoon->Location = System::Drawing::Point(420, 204);
			this->chk_OutIndirectMoon->Name = L"chk_OutIndirectMoon";
			this->chk_OutIndirectMoon->Size = System::Drawing::Size(196, 17);
			this->chk_OutIndirectMoon->TabIndex = 15;
			this->chk_OutIndirectMoon->Text = L"Indirect Tidal Accelerations of Moon";
			this->chk_OutIndirectMoon->UseVisualStyleBackColor = true;
			// 
			// chk_DirectTidalAcc
			// 
			this->chk_DirectTidalAcc->AutoSize = true;
			this->chk_DirectTidalAcc->Location = System::Drawing::Point(420, 168);
			this->chk_DirectTidalAcc->Name = L"chk_DirectTidalAcc";
			this->chk_DirectTidalAcc->Size = System::Drawing::Size(147, 17);
			this->chk_DirectTidalAcc->TabIndex = 14;
			this->chk_DirectTidalAcc->Text = L"Direct Tidal Accelerations";
			this->chk_DirectTidalAcc->UseVisualStyleBackColor = true;
			// 
			// chk_OutNonCons
			// 
			this->chk_OutNonCons->AutoSize = true;
			this->chk_OutNonCons->Location = System::Drawing::Point(420, 133);
			this->chk_OutNonCons->Name = L"chk_OutNonCons";
			this->chk_OutNonCons->Size = System::Drawing::Size(248, 17);
			this->chk_OutNonCons->TabIndex = 13;
			this->chk_OutNonCons->Text = L"Output non-conservative forces in Orbit System";
			this->chk_OutNonCons->UseVisualStyleBackColor = true;
			// 
			// chk_OutSolarPressure
			// 
			this->chk_OutSolarPressure->AutoSize = true;
			this->chk_OutSolarPressure->Location = System::Drawing::Point(420, 96);
			this->chk_OutSolarPressure->Name = L"chk_OutSolarPressure";
			this->chk_OutSolarPressure->Size = System::Drawing::Size(94, 17);
			this->chk_OutSolarPressure->TabIndex = 12;
			this->chk_OutSolarPressure->Text = L"Solar Pressure";
			this->chk_OutSolarPressure->UseVisualStyleBackColor = true;
			// 
			// chk_OutGravityGradients
			// 
			this->chk_OutGravityGradients->AutoSize = true;
			this->chk_OutGravityGradients->Location = System::Drawing::Point(420, 62);
			this->chk_OutGravityGradients->Name = L"chk_OutGravityGradients";
			this->chk_OutGravityGradients->Size = System::Drawing::Size(107, 17);
			this->chk_OutGravityGradients->TabIndex = 11;
			this->chk_OutGravityGradients->Text = L"Gravity Gradients";
			this->chk_OutGravityGradients->UseVisualStyleBackColor = true;
			// 
			// chk_OutTrackAngle
			// 
			this->chk_OutTrackAngle->AutoSize = true;
			this->chk_OutTrackAngle->Location = System::Drawing::Point(420, 29);
			this->chk_OutTrackAngle->Name = L"chk_OutTrackAngle";
			this->chk_OutTrackAngle->Size = System::Drawing::Size(84, 17);
			this->chk_OutTrackAngle->TabIndex = 10;
			this->chk_OutTrackAngle->Text = L"Track Angle";
			this->chk_OutTrackAngle->UseVisualStyleBackColor = true;
			// 
			// chk_OutKeplerVector
			// 
			this->chk_OutKeplerVector->AutoSize = true;
			this->chk_OutKeplerVector->Location = System::Drawing::Point(23, 347);
			this->chk_OutKeplerVector->Name = L"chk_OutKeplerVector";
			this->chk_OutKeplerVector->Size = System::Drawing::Size(116, 17);
			this->chk_OutKeplerVector->TabIndex = 9;
			this->chk_OutKeplerVector->Text = L"Keplerian Elements";
			this->chk_OutKeplerVector->UseVisualStyleBackColor = true;
			// 
			// chk_OutVelocityInertial
			// 
			this->chk_OutVelocityInertial->AutoSize = true;
			this->chk_OutVelocityInertial->Location = System::Drawing::Point(23, 324);
			this->chk_OutVelocityInertial->Name = L"chk_OutVelocityInertial";
			this->chk_OutVelocityInertial->Size = System::Drawing::Size(158, 17);
			this->chk_OutVelocityInertial->TabIndex = 8;
			this->chk_OutVelocityInertial->Text = L"Velocities(Vx,Vy,Vz) - inertial";
			this->chk_OutVelocityInertial->UseVisualStyleBackColor = true;
			// 
			// chk_OutOrbitTerrestrial
			// 
			this->chk_OutOrbitTerrestrial->AutoSize = true;
			this->chk_OutOrbitTerrestrial->Location = System::Drawing::Point(23, 301);
			this->chk_OutOrbitTerrestrial->Name = L"chk_OutOrbitTerrestrial";
			this->chk_OutOrbitTerrestrial->Size = System::Drawing::Size(176, 17);
			this->chk_OutOrbitTerrestrial->TabIndex = 7;
			this->chk_OutOrbitTerrestrial->Text = L"Orbit(R,Phi,Lambda) - Terrestrial";
			this->chk_OutOrbitTerrestrial->UseVisualStyleBackColor = true;
			// 
			// chk_OutOrbitInertial
			// 
			this->chk_OutOrbitInertial->AutoSize = true;
			this->chk_OutOrbitInertial->Location = System::Drawing::Point(23, 278);
			this->chk_OutOrbitInertial->Name = L"chk_OutOrbitInertial";
			this->chk_OutOrbitInertial->Size = System::Drawing::Size(120, 17);
			this->chk_OutOrbitInertial->TabIndex = 6;
			this->chk_OutOrbitInertial->Text = L"Orbit(X,Y,Z) - inertial";
			this->chk_OutOrbitInertial->UseVisualStyleBackColor = true;
			// 
			// chk_OutJD2000
			// 
			this->chk_OutJD2000->AutoSize = true;
			this->chk_OutJD2000->Location = System::Drawing::Point(23, 255);
			this->chk_OutJD2000->Name = L"chk_OutJD2000";
			this->chk_OutJD2000->Size = System::Drawing::Size(63, 17);
			this->chk_OutJD2000->TabIndex = 5;
			this->chk_OutJD2000->Text = L"JD2000";
			this->chk_OutJD2000->UseVisualStyleBackColor = true;
			// 
			// chk_GAST
			// 
			this->chk_GAST->AutoSize = true;
			this->chk_GAST->Location = System::Drawing::Point(23, 232);
			this->chk_GAST->Name = L"chk_GAST";
			this->chk_GAST->Size = System::Drawing::Size(55, 17);
			this->chk_GAST->TabIndex = 4;
			this->chk_GAST->Text = L"GAST";
			this->chk_GAST->UseVisualStyleBackColor = true;
			// 
			// chk_OutTime
			// 
			this->chk_OutTime->AutoSize = true;
			this->chk_OutTime->Location = System::Drawing::Point(23, 208);
			this->chk_OutTime->Name = L"chk_OutTime";
			this->chk_OutTime->Size = System::Drawing::Size(60, 17);
			this->chk_OutTime->TabIndex = 3;
			this->chk_OutTime->Text = L"Time(s)";
			this->chk_OutTime->UseVisualStyleBackColor = true;
			// 
			// txt_Header
			// 
			this->txt_Header->Location = System::Drawing::Point(109, 161);
			this->txt_Header->Name = L"txt_Header";
			this->txt_Header->Size = System::Drawing::Size(247, 20);
			this->txt_Header->TabIndex = 2;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(23, 163);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(85, 17);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"chk_Header";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// grp_AccuracyOutput
			// 
			this->grp_AccuracyOutput->Controls->Add(this->rb_AccuracyMax);
			this->grp_AccuracyOutput->Controls->Add(this->rb_mmlevel);
			this->grp_AccuracyOutput->Location = System::Drawing::Point(23, 48);
			this->grp_AccuracyOutput->Name = L"grp_AccuracyOutput";
			this->grp_AccuracyOutput->Size = System::Drawing::Size(333, 74);
			this->grp_AccuracyOutput->TabIndex = 0;
			this->grp_AccuracyOutput->TabStop = false;
			this->grp_AccuracyOutput->Text = L"Output-Accuracy";
			// 
			// rb_AccuracyMax
			// 
			this->rb_AccuracyMax->AutoSize = true;
			this->rb_AccuracyMax->Location = System::Drawing::Point(204, 33);
			this->rb_AccuracyMax->Name = L"rb_AccuracyMax";
			this->rb_AccuracyMax->Size = System::Drawing::Size(69, 17);
			this->rb_AccuracyMax->TabIndex = 1;
			this->rb_AccuracyMax->TabStop = true;
			this->rb_AccuracyMax->Text = L"Maximum";
			this->rb_AccuracyMax->UseVisualStyleBackColor = true;
			// 
			// rb_mmlevel
			// 
			this->rb_mmlevel->AutoSize = true;
			this->rb_mmlevel->Location = System::Drawing::Point(55, 33);
			this->rb_mmlevel->Name = L"rb_mmlevel";
			this->rb_mmlevel->Size = System::Drawing::Size(66, 17);
			this->rb_mmlevel->TabIndex = 0;
			this->rb_mmlevel->TabStop = true;
			this->rb_mmlevel->Text = L"mm-level";
			this->rb_mmlevel->UseVisualStyleBackColor = true;
			// 
			// tab_Plot
			// 
			this->tab_Plot->Location = System::Drawing::Point(4, 22);
			this->tab_Plot->Name = L"tab_Plot";
			this->tab_Plot->Padding = System::Windows::Forms::Padding(3);
			this->tab_Plot->Size = System::Drawing::Size(696, 408);
			this->tab_Plot->TabIndex = 1;
			this->tab_Plot->Text = L"Plot";
			this->tab_Plot->UseVisualStyleBackColor = true;
			// 
			// tab_AtmospherParameters
			// 
			this->tab_AtmospherParameters->Controls->Add(this->grp_AtmosphereModel);
			this->tab_AtmospherParameters->Controls->Add(this->grp_Interpolate);
			this->tab_AtmospherParameters->Controls->Add(this->grp_SolarFlux);
			this->tab_AtmospherParameters->Controls->Add(this->grp_AP);
			this->tab_AtmospherParameters->Controls->Add(this->grp_MagneticActivity);
			this->tab_AtmospherParameters->Location = System::Drawing::Point(4, 22);
			this->tab_AtmospherParameters->Name = L"tab_AtmospherParameters";
			this->tab_AtmospherParameters->Padding = System::Windows::Forms::Padding(3);
			this->tab_AtmospherParameters->Size = System::Drawing::Size(696, 408);
			this->tab_AtmospherParameters->TabIndex = 4;
			this->tab_AtmospherParameters->Text = L"Atmosphere Parameters";
			this->tab_AtmospherParameters->UseVisualStyleBackColor = true;
			// 
			// grp_AtmosphereModel
			// 
			this->grp_AtmosphereModel->Controls->Add(this->rb_DTM94);
			this->grp_AtmosphereModel->Controls->Add(this->rb_MSIS86);
			this->grp_AtmosphereModel->Location = System::Drawing::Point(390, 292);
			this->grp_AtmosphereModel->Name = L"grp_AtmosphereModel";
			this->grp_AtmosphereModel->Size = System::Drawing::Size(242, 68);
			this->grp_AtmosphereModel->TabIndex = 4;
			this->grp_AtmosphereModel->TabStop = false;
			this->grp_AtmosphereModel->Text = L"Atmosphere Model";
			// 
			// rb_DTM94
			// 
			this->rb_DTM94->AutoSize = true;
			this->rb_DTM94->Location = System::Drawing::Point(7, 44);
			this->rb_DTM94->Name = L"rb_DTM94";
			this->rb_DTM94->Size = System::Drawing::Size(61, 17);
			this->rb_DTM94->TabIndex = 1;
			this->rb_DTM94->Text = L"DTM94";
			this->rb_DTM94->UseVisualStyleBackColor = true;
			this->rb_DTM94->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::rb_DTM94_CheckedChanged);
			// 
			// rb_MSIS86
			// 
			this->rb_MSIS86->AutoSize = true;
			this->rb_MSIS86->Checked = true;
			this->rb_MSIS86->Location = System::Drawing::Point(7, 20);
			this->rb_MSIS86->Name = L"rb_MSIS86";
			this->rb_MSIS86->Size = System::Drawing::Size(63, 17);
			this->rb_MSIS86->TabIndex = 0;
			this->rb_MSIS86->TabStop = true;
			this->rb_MSIS86->Text = L"MSIS86";
			this->rb_MSIS86->UseVisualStyleBackColor = true;
			this->rb_MSIS86->CheckedChanged += gcnew System::EventHandler(this, &Orbitint::rb_MSIS86_CheckedChanged);
			// 
			// grp_Interpolate
			// 
			this->grp_Interpolate->Controls->Add(this->btn_InterpolateFillIn);
			this->grp_Interpolate->Controls->Add(this->chk_Interpolate);
			this->grp_Interpolate->Location = System::Drawing::Point(61, 292);
			this->grp_Interpolate->Name = L"grp_Interpolate";
			this->grp_Interpolate->Size = System::Drawing::Size(295, 68);
			this->grp_Interpolate->TabIndex = 3;
			this->grp_Interpolate->TabStop = false;
			this->grp_Interpolate->Text = L"-";
			// 
			// btn_InterpolateFillIn
			// 
			this->btn_InterpolateFillIn->Location = System::Drawing::Point(171, 25);
			this->btn_InterpolateFillIn->Name = L"btn_InterpolateFillIn";
			this->btn_InterpolateFillIn->Size = System::Drawing::Size(75, 23);
			this->btn_InterpolateFillIn->TabIndex = 1;
			this->btn_InterpolateFillIn->Text = L"Fill in";
			this->btn_InterpolateFillIn->UseVisualStyleBackColor = true;
			// 
			// chk_Interpolate
			// 
			this->chk_Interpolate->AutoSize = true;
			this->chk_Interpolate->Location = System::Drawing::Point(19, 29);
			this->chk_Interpolate->Name = L"chk_Interpolate";
			this->chk_Interpolate->Size = System::Drawing::Size(76, 17);
			this->chk_Interpolate->TabIndex = 0;
			this->chk_Interpolate->Text = L"Interpolate";
			this->chk_Interpolate->UseVisualStyleBackColor = true;
			// 
			// grp_SolarFlux
			// 
			this->grp_SolarFlux->Controls->Add(this->txt_DailyF107A);
			this->grp_SolarFlux->Controls->Add(this->lbl_DailyF107A);
			this->grp_SolarFlux->Controls->Add(this->txt_DailyF107);
			this->grp_SolarFlux->Controls->Add(this->lbl_DailyF107);
			this->grp_SolarFlux->Location = System::Drawing::Point(61, 206);
			this->grp_SolarFlux->Name = L"grp_SolarFlux";
			this->grp_SolarFlux->Size = System::Drawing::Size(571, 62);
			this->grp_SolarFlux->TabIndex = 2;
			this->grp_SolarFlux->TabStop = false;
			this->grp_SolarFlux->Text = L"Solar Flux";
			// 
			// txt_DailyF107A
			// 
			this->txt_DailyF107A->Location = System::Drawing::Point(268, 36);
			this->txt_DailyF107A->Name = L"txt_DailyF107A";
			this->txt_DailyF107A->Size = System::Drawing::Size(46, 20);
			this->txt_DailyF107A->TabIndex = 3;
			this->txt_DailyF107A->Text = L"150";
			// 
			// lbl_DailyF107A
			// 
			this->lbl_DailyF107A->AutoSize = true;
			this->lbl_DailyF107A->Location = System::Drawing::Point(265, 16);
			this->lbl_DailyF107A->Name = L"lbl_DailyF107A";
			this->lbl_DailyF107A->Size = System::Drawing::Size(67, 13);
			this->lbl_DailyF107A->TabIndex = 2;
			this->lbl_DailyF107A->Text = L"Daily F10.7A";
			// 
			// txt_DailyF107
			// 
			this->txt_DailyF107->Location = System::Drawing::Point(33, 36);
			this->txt_DailyF107->Name = L"txt_DailyF107";
			this->txt_DailyF107->Size = System::Drawing::Size(46, 20);
			this->txt_DailyF107->TabIndex = 1;
			this->txt_DailyF107->Text = L"150";
			// 
			// lbl_DailyF107
			// 
			this->lbl_DailyF107->AutoSize = true;
			this->lbl_DailyF107->Location = System::Drawing::Point(30, 16);
			this->lbl_DailyF107->Name = L"lbl_DailyF107";
			this->lbl_DailyF107->Size = System::Drawing::Size(60, 13);
			this->lbl_DailyF107->TabIndex = 0;
			this->lbl_DailyF107->Text = L"Daily F10.7";
			// 
			// grp_AP
			// 
			this->grp_AP->Controls->Add(this->txt_DailyAP);
			this->grp_AP->Controls->Add(this->lbl_DailyAP);
			this->grp_AP->Location = System::Drawing::Point(61, 119);
			this->grp_AP->Name = L"grp_AP";
			this->grp_AP->Size = System::Drawing::Size(571, 57);
			this->grp_AP->TabIndex = 1;
			this->grp_AP->TabStop = false;
			this->grp_AP->Text = L"AP";
			// 
			// txt_DailyAP
			// 
			this->txt_DailyAP->Location = System::Drawing::Point(30, 28);
			this->txt_DailyAP->Name = L"txt_DailyAP";
			this->txt_DailyAP->Size = System::Drawing::Size(49, 20);
			this->txt_DailyAP->TabIndex = 1;
			this->txt_DailyAP->Text = L"0";
			// 
			// lbl_DailyAP
			// 
			this->lbl_DailyAP->AutoSize = true;
			this->lbl_DailyAP->Location = System::Drawing::Point(30, 11);
			this->lbl_DailyAP->Name = L"lbl_DailyAP";
			this->lbl_DailyAP->Size = System::Drawing::Size(47, 13);
			this->lbl_DailyAP->TabIndex = 0;
			this->lbl_DailyAP->Text = L"Daily AP";
			// 
			// grp_MagneticActivity
			// 
			this->grp_MagneticActivity->Controls->Add(this->rb_3HourAp);
			this->grp_MagneticActivity->Controls->Add(this->rb_DailyAp);
			this->grp_MagneticActivity->Location = System::Drawing::Point(61, 41);
			this->grp_MagneticActivity->Name = L"grp_MagneticActivity";
			this->grp_MagneticActivity->Size = System::Drawing::Size(571, 55);
			this->grp_MagneticActivity->TabIndex = 0;
			this->grp_MagneticActivity->TabStop = false;
			this->grp_MagneticActivity->Text = L"Magnetic Activity";
			// 
			// rb_3HourAp
			// 
			this->rb_3HourAp->AutoSize = true;
			this->rb_3HourAp->Checked = true;
			this->rb_3HourAp->Location = System::Drawing::Point(320, 20);
			this->rb_3HourAp->Name = L"rb_3HourAp";
			this->rb_3HourAp->Size = System::Drawing::Size(72, 17);
			this->rb_3HourAp->TabIndex = 1;
			this->rb_3HourAp->TabStop = true;
			this->rb_3HourAp->Text = L"3-hour AP";
			this->rb_3HourAp->UseVisualStyleBackColor = true;
			// 
			// rb_DailyAp
			// 
			this->rb_DailyAp->AutoSize = true;
			this->rb_DailyAp->Location = System::Drawing::Point(30, 20);
			this->rb_DailyAp->Name = L"rb_DailyAp";
			this->rb_DailyAp->Size = System::Drawing::Size(65, 17);
			this->rb_DailyAp->TabIndex = 0;
			this->rb_DailyAp->Text = L"Daily AP";
			this->rb_DailyAp->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(252, 360);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Default";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(32, 360);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"To File";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(489, 360);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(176, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"From File";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(62, 260);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(568, 77);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Integrator";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(329, 36);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(97, 36);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(348, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Precision";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(114, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Stepsize [s]";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(32, 53);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(633, 201);
			this->textBox5->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(258, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(188, 25);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Initial Conditions";
			// 
			// btn_Exit
			// 
			this->btn_Exit->Location = System::Drawing::Point(516, 463);
			this->btn_Exit->Name = L"btn_Exit";
			this->btn_Exit->Size = System::Drawing::Size(176, 23);
			this->btn_Exit->TabIndex = 8;
			this->btn_Exit->Text = L"Exit";
			this->btn_Exit->UseVisualStyleBackColor = true;
			this->btn_Exit->Click += gcnew System::EventHandler(this, &Orbitint::btn_Exit_Click);
			// 
			// btn_CancelIntegration
			// 
			this->btn_CancelIntegration->Location = System::Drawing::Point(279, 463);
			this->btn_CancelIntegration->Name = L"btn_CancelIntegration";
			this->btn_CancelIntegration->Size = System::Drawing::Size(169, 23);
			this->btn_CancelIntegration->TabIndex = 7;
			this->btn_CancelIntegration->Text = L"Cancel Integration";
			this->btn_CancelIntegration->UseVisualStyleBackColor = true;
			// 
			// btn_StartIntegration
			// 
			this->btn_StartIntegration->Location = System::Drawing::Point(59, 463);
			this->btn_StartIntegration->Name = L"btn_StartIntegration";
			this->btn_StartIntegration->Size = System::Drawing::Size(160, 23);
			this->btn_StartIntegration->TabIndex = 6;
			this->btn_StartIntegration->Text = L"Start Integration";
			this->btn_StartIntegration->UseVisualStyleBackColor = true;
			this->btn_StartIntegration->Click += gcnew System::EventHandler(this, &Orbitint::btn_StartIntegration_Click);
			// 
			// lbl_Progress
			// 
			this->lbl_Progress->AutoSize = true;
			this->lbl_Progress->Location = System::Drawing::Point(335, 489);
			this->lbl_Progress->Name = L"lbl_Progress";
			this->lbl_Progress->Size = System::Drawing::Size(48, 13);
			this->lbl_Progress->TabIndex = 9;
			this->lbl_Progress->Text = L"Progress";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(59, 505);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(633, 19);
			this->progressBar1->TabIndex = 10;
			// 
			// statStrip_Main
			// 
			this->statStrip_Main->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStatusLabel1, 
				this->toolStripStatusLabel2});
			this->statStrip_Main->Location = System::Drawing::Point(0, 527);
			this->statStrip_Main->Name = L"statStrip_Main";
			this->statStrip_Main->Size = System::Drawing::Size(753, 22);
			this->statStrip_Main->TabIndex = 11;
			this->statStrip_Main->Text = L"ready";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel2->Text = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// Orbitint
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(753, 549);
			this->Controls->Add(this->statStrip_Main);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->lbl_Progress);
			this->Controls->Add(this->btn_Exit);
			this->Controls->Add(this->tabControl_Main);
			this->Controls->Add(this->btn_CancelIntegration);
			this->Controls->Add(this->menu_MainWindow);
			this->Controls->Add(this->btn_StartIntegration);
			this->MainMenuStrip = this->menu_MainWindow;
			this->Name = L"Orbitint";
			this->Text = L"IAPG Orbit Integration v2.0";
			this->menu_MainWindow->ResumeLayout(false);
			this->menu_MainWindow->PerformLayout();
			this->tabControl_Main->ResumeLayout(false);
			this->tab_InitialConditions->ResumeLayout(false);
			this->tab_InitialConditions->PerformLayout();
			this->grp_Integrator->ResumeLayout(false);
			this->grp_Integrator->PerformLayout();
			this->tab_Gravity->ResumeLayout(false);
			this->tab_Gravity->PerformLayout();
			this->grp_PolarMotion->ResumeLayout(false);
			this->grp_PolarMotion->PerformLayout();
			this->grp_GravityFieldModel->ResumeLayout(false);
			this->grp_GravityFieldModel->PerformLayout();
			this->grp_Tranformation->ResumeLayout(false);
			this->grp_Tranformation->PerformLayout();
			this->grp_CoordinateSystem->ResumeLayout(false);
			this->grp_CoordinateSystem->PerformLayout();
			this->tab_SurfaceForces->ResumeLayout(false);
			this->tab_SurfaceForces->PerformLayout();
			this->grp_SurfaceForces->ResumeLayout(false);
			this->grp_SurfaceForces->PerformLayout();
			this->grp_MeanArea->ResumeLayout(false);
			this->grp_MeanArea->PerformLayout();
			this->grp_ChooseSurfaceModel->ResumeLayout(false);
			this->grp_ChooseSurfaceModel->PerformLayout();
			this->grp_MassOfSatellite->ResumeLayout(false);
			this->grp_MassOfSatellite->PerformLayout();
			this->tab_AtmosphericForces->ResumeLayout(false);
			this->tab_AtmosphericForces->PerformLayout();
			this->grp_param_tau->ResumeLayout(false);
			this->grp_param_tau->PerformLayout();
			this->grp_param_p->ResumeLayout(false);
			this->grp_param_p->PerformLayout();
			this->grp_ChooseModel->ResumeLayout(false);
			this->grp_ChooseModel->PerformLayout();
			this->grp_ClValue->ResumeLayout(false);
			this->grp_ClValue->PerformLayout();
			this->grp_AmbientTemperature->ResumeLayout(false);
			this->grp_AmbientTemperature->PerformLayout();
			this->grp_MeanAirDensity->ResumeLayout(false);
			this->grp_MeanAirDensity->PerformLayout();
			this->grp_CdValue->ResumeLayout(false);
			this->grp_CdValue->PerformLayout();
			this->grp_ChooseForceModel->ResumeLayout(false);
			this->grp_ChooseForceModel->PerformLayout();
			this->tab_Tides->ResumeLayout(false);
			this->tab_Tides->PerformLayout();
			this->grp_OceanTides->ResumeLayout(false);
			this->grp_OceanTides->PerformLayout();
			this->grp_OrderInterval->ResumeLayout(false);
			this->grp_OrderInterval->PerformLayout();
			this->grp_OceanTideModel->ResumeLayout(false);
			this->grp_OceanTideModel->PerformLayout();
			this->grp_SolidEarthPoleTide->ResumeLayout(false);
			this->grp_SolidEarthPoleTide->PerformLayout();
			this->grp_SolidEarthTides->ResumeLayout(false);
			this->grp_SolidEarthTides->PerformLayout();
			this->grp_DirectTidalAcceleration->ResumeLayout(false);
			this->grp_DirectTidalAcceleration->PerformLayout();
			this->tab_Output->ResumeLayout(false);
			this->tab_Output->PerformLayout();
			this->grp_AccuracyOutput->ResumeLayout(false);
			this->grp_AccuracyOutput->PerformLayout();
			this->tab_AtmospherParameters->ResumeLayout(false);
			this->grp_AtmosphereModel->ResumeLayout(false);
			this->grp_AtmosphereModel->PerformLayout();
			this->grp_Interpolate->ResumeLayout(false);
			this->grp_Interpolate->PerformLayout();
			this->grp_SolarFlux->ResumeLayout(false);
			this->grp_SolarFlux->PerformLayout();
			this->grp_AP->ResumeLayout(false);
			this->grp_AP->PerformLayout();
			this->grp_MagneticActivity->ResumeLayout(false);
			this->grp_MagneticActivity->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->statStrip_Main->ResumeLayout(false);
			this->statStrip_Main->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			 private: System::Void btn_Exit_Click(System::Object^  sender, System::EventArgs^  e) {
						 Application::Exit();

					  }

			 private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 }	 
			 
	
	protected: System::Void btn_Default_Click(System::Object^  sender, System::EventArgs^  e)
			   {
				   array<System::String^>^ s_buffer_f = gcnew array <System::String^>(8);
				   ta = 0.0L;/*starttime*/
				   te = 85820.0L; /*endtime*/
				   X[1] =  1.54118855194000e6L;
				   X[2] =  -6.66961408972000e6L;
				   X[3] =  0.07638146797970e6L;
				   X[4] =  0.11249789489500e3L;
				   X[5] =  0.11338514633800e3L;
				   X[6] =  7.63782874423000e3L;
				   txt_InitialConditions->Clear();
				   sprintf_s(buf,"year: %4d\n", year);
				   s_buffer_f[0] = gcnew System::String(buf);			   
				   sprintf_s(buf,"month: %3d\n", month);
				   s_buffer_f[1] = gcnew System::String(buf);
				   sprintf_s(buf,"day: %3d\n", day);
				   s_buffer_f[2] = gcnew System::String(buf);
				   sprintf_s(buf, "starttime: %9.0Lf\n", ta);
				   s_buffer_f[3] = gcnew System::String(buf);
				   sprintf_s(buf,"endtime: %9.0Lf\n", te);
				   s_buffer_f[4] = gcnew System::String(buf);
				   sprintf_s(buf,"\npos:  %10.15Lf %10.15Lf %10.15Lf\n", X[1], X[2], X[3]);
				   s_buffer_f[5] = gcnew System::String(buf);
				   sprintf_s(buf,"\nvel:  %10.15Lf %10.15Lf %10.15Lf\n", X[4], X[5], X[6]);
				   s_buffer_f[6] = gcnew System::String(buf);
				   sprintf_s(buf,"\nIntegrator %2d %8.1Le %8.1Le\n", flag, abstol, reltol);
				   s_buffer_f[7] = gcnew System::String(buf);
				   //txt_InitialConditions->AppendText(gcnew System::String(s_buffer_f.str().c_str()));
				   for (short sCount = 0; sCount < s_buffer_f->Length; sCount++)
				   {
					   txt_InitialConditions->AppendText(s_buffer_f[sCount]);
				   }
				   StartWerteOK=true;
				   StartWerteChang = false;
				   Kepler = false;
			   
			   };
			 //lock_gui();


				   /*initial conditions*/
//   ta = 0.0L;/*starttime*/
//   te = 85820.0L; /*endtime*/
//   x[1] =  1.54118855194000e6L;
//   x[2] =  -6.66961408972000e6L;
//   x[3] =  0.07638146797970e6L;
//   x[4] =  0.11249789489500e3L;
//   x[5] =  0.11338514633800e3L;
//   x[6] =  7.63782874423000e3L;
//
//   txt_InitialConditions->Clear();
//   sprintf (buf, "year: %4d\n", year);
//   txt_InitialConditions->AppendText(buf);
//   sprintf (buf, "month: %3d\n", month);
//   txt_InitialConditions->AppendText(buf);
//   sprintf (buf, "day: %3d\n", day);
//   txt_InitialConditions->AppendText(buf);
//   sprintf (buf, "starttime: %9.0Lf\n", ta);
//   txt_InitialConditions->AppendText(buf);
//   sprintf (buf, "endtime: %9.0Lf\n", te);
//   txt_InitialConditions->AppendText(buf);
//   sprintf (buf, "pos:  %10.15Lf %10.15Lf %10.15Lf", x[1], x[2], x[3]);
//   txt_InitialConditions->AppendText(buf);
//   sprintf (buf, "vel:  %10.15Lf %10.15Lf %10.15Lf", x[4], x[5], x[6]);
//   txt_InitialConditions->AppendText(buf);
//   sprintf (buf, "\nIntegrator %2d %8.1Le %8.1Le\n", flag, abstol, reltol);
//   txt_InitialConditions->AppendText(buf);
//   txt_InitialConditions->Refresh();
//   //StartWerteOK=true;
//   //StartWerteChang = false;
//   //Kepler = false;
////       double TZ, TINF, RO, D2[6],D[8], Temp[2];
////       init_moddtm94();
////       init_atmo();
////
////       double clat=45.0L;
////       double clong=45.0L;
////       double doy=80.0L;
////       double sf=150.0L;
////       double sfm=150.0L;
////       double akp=1.0L;
////       double alt=400.0L;
////       double zeit=3.0L;
////       double AP[8];
////       double zeitut=0.0;
////       for(int i=0;i<8;i++) AP[i]=4.0L;
////
////       MODDTM94 ((int)doy, sf ,sfm , akp ,alt-120.0L, zeit , clat, clong,&TZ, &TINF, &RO, &D2[0]);
////
////	   
////       GTS5(doy,zeitut,alt,clat,clong,zeit,sfm,sf,AP[1],&D[0],&Temp[0]);
////
////// File Output
////       //File* ATM;
////	   std::ofstream ATM;	   
////	   ATM.open(L"ATMO_VERGLEICH.TXT");
////	   
////       //ATM=fopen("ATMO_VERGLEICH.TXT","w");
////       ATM<<"MSIS - DTM\n";
////       ATM<<"     Tinf           T@Alt                rho                  Helium                Wasserstoff          atom. Sauerstoff\n";
////
////       //ATM<<"%5.2Lf %5.2Lf | %5.2Lf %5.2Lf | %8.4LE %8.4LE | %8.4LE %8.4LE | %8.4LE %8.4LE  | %8.4LE %8.4LE\n",
////       //       Temp[1],TINF,Temp[2],TZ,D[6],RO*1.0e3L,D[1],D2[2]*1.0e6L,D[7],D2[1]*1.0e6L, D[2],D2[3]*1.0e6L);
////
////	   ATM<<Temp[1]<<" "<<TINF<<" | "<<Temp[2]<<" "<<TZ<<" | "<<D[6]<<" "<<RO*1.0e3L<<" | "<<D[1]<<" "<<D2[2]*1.0e6L<<" | "<<D[7]<<" "<<D2[1]*1.0e6L<<" | "<<D[2]<<" "<<D2[3]*1.0e6L;
////
////       ATM<<"\n     mol. Sauerstoff        mol. Stickstoff      atom. Stickstoff          Argon\n";
////
////       //ATM<<" %8.4LE %8.4LE | %8.4LE %8.4LE |    %8.4LE     |    %8.4LE    \n",
////       //        D[4],D2[5]*1.0e6L,D[3],D2[4]*1.0e6L, D[8],D[5]);
////
////	   ATM<<" "<< D[4]<<" "<<D2[5]*1.0e6L<<" | "<<D[3]<<" "<<D2[4]*1.0e6L<<" |    "<<D[8]<<"     |    "<<D[5]<<"    \n";
////
////	   ATM.close();
	
private: System::Void chk_AtmosphericDrag_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 fn_AtmosphericForcesController(chk_AtmosphericDrag->CheckState);			 
		 }


private: System::Void chk_SolarPressure_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->chk_UseSurfaceModel->Visible = (this->chk_SolarPressure->Checked || this->chk_AtmosphericDrag->Checked);
			 this->grp_MeanArea->Visible = ((this->chk_SolarPressure->Checked || this->chk_AtmosphericDrag->Checked)&&(this->chk_UseSurfaceModel->Checked == false));
			 this->grp_MassOfSatellite->Visible = (this->chk_SolarPressure->Checked || this->chk_AtmosphericDrag->Checked);			 
			 if (chk_AtmosphericDrag->Checked == false && chk_SolarPressure->Checked == false){
				 this->chk_UseSurfaceModel->Checked = false;
				 this->chk_AirDensityViaModel->Checked = false;
				 this->tabControl_Main->Controls->RemoveByKey("tab_AtmospherParameters");
			 }
		 }

		 private: System::Void fn_AtmosphericForcesController(CheckState checkState)
		  {
			  
			  switch(checkState){
				 case CheckState::Checked:
					 this->tabControl_Main->Controls->Add(this->tab_AtmosphericForces);
					 this->tabControl_Main->Controls->SetChildIndex(this->tab_AtmosphericForces,3);
					 this->tab_AtmosphericForces->Enabled = true;
					 this->chk_WindModel->Visible = true;
					 
					 this->tabControl_Main->Refresh();
					 break;
				 case CheckState::Unchecked:
					 this->tabControl_Main->Controls->Remove(this->tab_AtmosphericForces);
					 this->chk_WindModel->Visible = false;		
					 this->tabControl_Main->Controls->RemoveByKey("tab_AtmospherParameters");
					 this->chk_AirDensityViaModel->Checked = false;
					 break;					 
			  }
			  this->chk_UseSurfaceModel->Visible = (this->chk_SolarPressure->Checked || this->chk_AtmosphericDrag->Checked);
			  this->grp_MeanArea->Visible = ((this->chk_SolarPressure->Checked || this->chk_AtmosphericDrag->Checked)&&(this->chk_UseSurfaceModel->Checked == false));
			  this->grp_MassOfSatellite->Visible = (this->chk_SolarPressure->Checked || this->chk_AtmosphericDrag->Checked);
			  if (chk_AtmosphericDrag->Checked == false && chk_SolarPressure->Checked == false)
				 this->chk_UseSurfaceModel->Checked = false;

		  }
private: System::Void chk_UseSurfaceModel_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->grp_MeanArea->Visible = !this->chk_UseSurfaceModel->Checked;
			 this->grp_ChooseSurfaceModel->Visible = this->chk_UseSurfaceModel->Checked;
			 this->tab_AtmospherParameters->Visible = this->chk_UseSurfaceModel->Checked;
		 }
private: System::Void cb_AirDensityViaModel_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->grp_AmbientTemperature->Visible = this->chk_AirDensityViaModel->Checked;
			 this->grp_MeanAirDensity->Visible = this->chk_AirDensityViaModel->Checked;
			 if (this->chk_AirDensityViaModel->Checked)
			 {
				 this->tabControl_Main->Controls->Add(this->tab_AtmospherParameters);
			 }
			 else
			 {
				 this->tabControl_Main->Controls->RemoveByKey("tab_AtmospherParameters");
			 }
		 }
private: System::Void rb_DragAndLift_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 AtmoForceModelNr = this->rb_DragAndLift->TabIndex;
			 this->grp_ClValue->Visible = this->rb_DragAndLift->Checked;	
			 this->grp_CdValue->Visible = this->rb_DragAndLift->Checked;
		 }
private: System::Void rb_OneParameter_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 AtmoForceModelNr = this->rb_OneParameter->TabIndex;
			 this->chk_DeriveAlpha->Visible = this->rb_OneParameter->Checked;
			 this->grp_CdValue->Visible = this->rb_onlyDrag->Checked;
			 this->grp_ClValue->Visible = this->rb_onlyDrag->Checked;
		 }
private: System::Void rb_TwoParameter_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 AtmoForceModelNr = this->rb_TwoParameter->TabIndex;
			 this->grp_param_p->Visible=this->rb_TwoParameter->Checked;
			 this->grp_param_tau->Visible = this->rb_TwoParameter->Checked;
			 this->grp_ChooseModel->Visible = this->rb_TwoParameter->Checked;
			 this->grp_CdValue->Visible = this->rb_onlyDrag->Checked;
			 this->grp_ClValue->Visible = this->rb_DragAndLift->Checked;
		 }
private: System::Void rb_onlyDrag_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 AtmoForceModelNr = this->rb_onlyDrag->TabIndex;
			 this->grp_CdValue->Visible = this->rb_onlyDrag->Checked;
			 this->grp_ClValue->Visible = this->rb_DragAndLift->Checked;
		 }
private: System::Void cb_EnableOceanTide_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->grp_OrderInterval->Visible = this->chk_EnableOceanTide->Checked;
			 this->grp_OceanTideModel->Visible = this->chk_EnableOceanTide->Checked;
		 }
private: System::Void btn_ToFile_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void btn_ChooseCoefficientFile_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->od_gravityCoeffFile->DefaultExt = "*.geo";
			 this->od_gravityCoeffFile->Filter = "gravity coefficient files(*.geo)|*.geo";
			 if(this->od_gravityCoeffFile->ShowDialog()== System::Windows::Forms::DialogResult::OK){
				FILE *ein;
				bool open = true;
				char cha;
				char arr_c_buff[512];
				int i_MaxGrad;
				int i_MaxOrdnung;
				double d_GM;
				double d_ae;
				double d_t0;
				//open=potkoeffile->Execute();
				lbl_CoefficientFile->Text = "coefficientfile: " + this->od_gravityCoeffFile->FileName;		
				//open = fopen(this->od_gravityCoeffFile->FileName->ToCharArray(),'r');
				//potfilename = (this->od_gravityCoeffFile->FileName)->;				
				System::String^ potfilename_Dialog =(this->od_gravityCoeffFile->FileName);
				gravity::potfilename = (char *)(void *)Marshal::StringToHGlobalAnsi(potfilename_Dialog);				
				//this->statStrip_Main->Items[1]->Text=" ";
				//StatusBar1->Panels->Items[1]->Text=" ";
				// read Header
				
				if (open)
				{
				 ein = fopen(potfilename, "r");
				 fgets(arr_c_buff,sizeof(arr_c_buff),ein);//read the first line already
				 cha = '#';
				 while (cha != 'K'){
					 if(fgets(arr_c_buff,sizeof(arr_c_buff),ein)!=NULL){
						 sscanf(arr_c_buff,"%c %d %d  %Lf  %Lf     %Lf", &cha, &i_MaxGrad, &i_MaxOrdnung, &d_GM, &d_ae, &d_t0);				 					 
					 }				 
				 }
				 fclose(ein);
				 max_grad = i_MaxGrad;
				 max_ordnung = i_MaxOrdnung;
				 GM = d_GM;
				 ae = d_ae;
				 t0 = d_t0;

				 lbl_Mmax->Text = L"Mmax = " + max_ordnung.ToString();
			     lbl_Lmax->Text = L"Lmax = " + max_grad.ToString();
				 lbl_GM->Text = L"GM = " + GM.ToString();
				 lbl_R->Text = L"R = " + (ae.ToString());
				 if (t0) lbl_Note->Text = "t0 = " + (t0.ToString());
				 else lbl_Note->Text = "no time variable coefficients";

				 
				}
			 }
		 }
private: System::Void btn_StartIntegration_Click(System::Object^  sender, System::EventArgs^  e) {
			   int i, ig;
			   double tref, jt, UT;

			   //DecimalSeparator = '.';

			   this->statStrip_Main->Text = "busy ...";
			   //this->statStrip_Main->Items[1]->Text = "";
			   this->statStrip_Main->Refresh();


			// initial GAST
			   julianjh(year,month,day,0.0L,&t_gl);
			   UT=ta/3600.0L;
			   if(this->chk_GAST->Checked == true)
			   {
				 //GAST0 = StrToFloat(ConstGast_edit->Text);//Need to look at this
			   }
			   else
			   {
				 jul2gast(&UT,&t_gl,&GAST0);
			   }
			   GAST = GAST0;
				// Rotation matrices for transformations
			   double nut_time; julianjh(year,month,day,ta/3600.0L,&nut_time);

				// Precession
			   struct Winkel prez=prezwink(nut_time);
			   prezmat=rotmtx(-prez.w2/180.0L*M_PI,3) & rotmtx(prez.w3/180.0L*M_PI,2) & rotmtx(-prez.w1/180.0L*M_PI,3);
			   prezmat2 = prezmat; prezmat2.transponed();			   
	
				// Nutation
			   struct Winkel nut;
			   if (!lies_nut_dat) return;
			   nutwink(nut_time,&nut);
			   nutmat=rotmtx((-nut.w1-nut.w2)/180.0L*M_PI,1) & rotmtx(-nut.w3/180.0L*M_PI,3) & rotmtx(nut.w1/180.0L*M_PI,1);
			   nutmat2=nutmat; nutmat2.transponed();

			   // Polar Motion
			   xp=System::Convert::ToDouble(this->txt_xp->Text);
			   yp=System::Convert::ToDouble(this->txt_xp->Text);
			   polmat=rotmtx(-xp/3600.0L/180.0L*M_PI,2) & rotmtx(-yp/3600.0L/180.0L*M_PI,1);
			   polmat2=polmat;polmat2.transponed();				
			   if(rb_Spherical->Checked)
				   func = rb_Spherical->TabIndex;
			   else if (rb_Cartesian->Checked)
				   func = rb_Cartesian->TabIndex;			   
			   //tref is reference date considering time variable gravity field model
			   //coefficients
			   tref = (double) year + (double) month/12.0L + (double) day/365.0L;
			   gravity::initmemory(func); 
			   gravity::initnorm(func);
			   if (lmax) ig=gravity::read_potfile(tref); 			   
			   else
			   {
				 Clm[0][0] = 1.0L;
				 Slm[0][0] = 0.0L;
				 ig=1;
			   }
			   // Transformation method
			   if (this->rb_Omega->Checked)
				   TrafoNr = this->rb_Omega->TabIndex;
			   else if(this->rb_GAST->Checked)
				   TrafoNr = this->rb_GAST->TabIndex;
			   else if(this->rb_Exact->Checked)
				   TrafoNr = this->rb_Exact->TabIndex;		   
				

			// set integrator flag
			   flag = 1;

			// Solar Pressure
			   SolCheck=this->chk_SolarPressure->Checked;
				
			   if(this->chk_OutOceanTide->Checked && !(this->chk_EnableOceanTide->Checked))
			   {
				   this->statStrip_Main->Text = "You have to enable ocean tides if you want to print accelerations due to ocean tides";				   
				   //err_disp();
				   return;
			   }




			   if (chk_EnableOceanTide->Checked)
			   {
				    otidemax = Convert::ToInt32(txt_DegOrdOceanTide->Text);
					if(lmax < otidemax || mmax < otidemax)
					{
						this->statStrip_Main->Text="Degree or Order of Ocean Tides higher than selected Gravity Field!";
						//err_disp();
						return;
					}
				}

			   // Atmosphere initialisation
			   AtmoCheck = chk_AtmosphericDrag->Checked;
			   Lagrcheck = chk_Interpolate->Checked;                      // AP Interpolation
			   //AtmoForceModelNr = AtmoForceM->ItemIndex; Handled in the Radio Button handlers

			   //AtmoModelNr=AtmoModel->ItemIndex; Handled in Radio Button Handlers.

			   if(AtmoCheck || this->chk_AirDensityViaModel->Checked)
			   {
				if(AtmoModelNr==0)                                // MSIS
				 i=init_atmo();
				  if(i==0)
				  {
					  this->toolStripStatusLabel2->Text="Couldn't initialize MSIS!";
					  this->toolStripStatusLabel1->Text="ready";
					  return;
				  }
				if(AtmoModelNr==1)                                // DTM
				 fn_Button10Click();                           // Read KP Values from yyyy.idf
				 i=init_moddtm94();
				  if(i==0)
				   {
					 this->toolStripStatusLabel2->Text="Couldn't initialize DTM!";
					 this->toolStripStatusLabel1->Text="ready";
					 return;
				   }
				}
			   else i=1;
			   /*NSat = RadioGroup2->ItemIndex;
			   if (RadioGroup1->ItemIndex == 1)
			   {
				  SW[9] = -1.0L;
			   }
			   apValueChangeExecute(Sender);
			   FluxChangeExecute(Sender);*/
};
private: System::Void rb_MSIS86_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 AtmoModelNr = this->rb_MSIS86->TabIndex;
		 }
private: System::Void rb_DTM94_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 AtmoModelNr = this->rb_DTM94->TabIndex;
		 }
private: System::Void rb_Thalhammer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			
		 }
private: System::Void rb_Klinkrad_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 
		 }

private: System::Void rb_Mazanek_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			
		 }

		 protected: void fn_Button10Click(){
					}
//---------------------------------------------------------------------------
// Fill in Solar Flux and AP/KP from downloaded files
//---------------------------------------------------------------------------
/*		 protected: void fn_Button10Click(){
						//DecimalSeparator = '.';
						this->toolStripStatusLabel2->Text=" ";						
						this->chk_AtmosphericDrag->Checked=true;
						//RadioGroup1->ItemIndex = 1; handled in handlers
						FILE *EIN;

						char Tempc[128],Tmp[10];
						int Tag,Monat,Jahr,AP1t,AP2t,AP3t,AP4t,AP5t,AP6t,AP7t,AP8t;                  // AP values for MSIS
						int AP,AP3,AP6,AP9,AP12,AP36,APd;
						int KP1t,KP2t,KP3t,KP4t,KP5t,KP6t,KP7t,KP8t;                                 // Kp values for DTM94

						double Flux_now=0.0L,Flux3=0.0L,Flux=0.0L;
						fn_ChangeStartWerte();

						double h3=3.0L/24.0L;    // AP intervall in days


						for(int i=0;i<40;i++)
							KPinterp[i]=0.0L;

						// Open yyyy.IDF
						string s_open = exepath_str.append((year).ToString()+".idf").c_str(),"rt"
						EIN=fopen((exepath_str + (year).ToString()+".idf").c_str(),"rt");
						if(EIN==NULL)
						{
							this->toolStripStatusLabel2->Text="Can't open IDF file";
						 return;
						}
						fgets(Tempc,127,EIN);fgets(Tempc,127,EIN);                                  // read heade

						int mjd_start=xjuldat(day,month,year)-2400000.5L;
						int mjd_now;


						// read data from yyyy.idf
						while(!feof(EIN))
						{
						fgets(Tempc,127,EIN);
						sscanf(Tempc,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %Lf",
							   &mjd_now,&AP1t,&AP2t,&AP3t,&AP4t,&AP5t,&AP6t,&AP7t,&AP8t,
							   &KP1t,&KP2t,&KP3t,&KP4t,&KP5t,&KP6t,&KP7t,&KP8t,&Flux_now);



						// Three days before start day
						if(mjd_now==mjd_start-3)
						{
						 AP36=AP6t+AP7t+AP8t;

						 for(int i=0;i<8;i++)
						   TIMEinterp[i]=mjd2jjh((double)mjd_now + (double)i * h3);

						 APinterp[0] = (double) AP1t;
						 APinterp[1] = (double) AP2t;
						 APinterp[2] = (double) AP3t;
						 APinterp[3] = (double) AP4t;
						 APinterp[4] = (double) AP5t;
						 APinterp[5] = (double) AP6t;
						 APinterp[6] = (double) AP7t;
						 APinterp[7] = (double) AP8t;

						 }  
						// Two days before start day
						if(mjd_now==mjd_start-2)
						{
						 AP36=AP36+AP1t+AP2t+AP3t+AP4t+AP5t;
						 AP12=AP6t+AP7t+AP8t;

						for(int i=0;i<8;i++)
						   TIMEinterp[i+8]=mjd2jjh((double)mjd_now + (double)i * h3);

						 APinterp[8] = (double) AP1t;
						 APinterp[9] = (double) AP2t;
						 APinterp[10] = (double) AP3t;
						 APinterp[11] = (double) AP4t;
						 APinterp[12] = (double) AP5t;
						 APinterp[13] = (double) AP6t;
						 APinterp[14] = (double) AP7t;
						 APinterp[15] = (double) AP8t;
						 }

						// One day before start day
						if(mjd_now==mjd_start-1)
						{
						 AP12=AP12+AP1t+AP2t+AP3t+AP4t+AP5t;
						 AP9=AP6t;AP6=AP7t;AP3=AP8t;Flux=Flux_now;
						 for(int i=0;i<8;i++)
						   TIMEinterp[i+16]=mjd2jjh((double)mjd_now + (double)i * h3);

						 APinterp[16] = (double) AP1t;
						 APinterp[17] = (double) AP2t;
						 APinterp[18] = (double) AP3t;
						 APinterp[19] = (double) AP4t;
						 APinterp[20] = (double) AP5t;
						 APinterp[21] = (double) AP6t;
						 APinterp[22] = (double) AP7t;
						 APinterp[23] = (double) AP8t;

						 KPinterp[16] = (double) KP1t;
						 KPinterp[17] = (double) KP2t;
						 KPinterp[18] = (double) KP3t;
						 KPinterp[19] = (double) KP4t;
						 KPinterp[20] = (double) KP5t;
						 KPinterp[21] = (double) KP6t;
						 KPinterp[22] = (double) KP7t;
						 KPinterp[23] = (double) KP8t;


						}

						// Start day
						if(mjd_now==mjd_start)
						{
						 AP=AP1t;APd=AP1t+AP2t+AP3t+AP4t+AP5t+AP6t+AP7t+AP8t;

						  for(int i=0;i<8;i++)
						   TIMEinterp[i+24]=mjd2jjh((double)mjd_now + (double)i * h3);

						 APinterp[24] = (double) AP1t;
						 APinterp[25] = (double) AP2t;
						 APinterp[26] = (double) AP3t;
						 APinterp[27] = (double) AP4t;
						 APinterp[28] = (double) AP5t;
						 APinterp[29] = (double) AP6t;
						 APinterp[30] = (double) AP7t;
						 APinterp[31] = (double) AP8t;

						 KPinterp[24] = (double) KP1t;;
						 KPinterp[25] = (double) KP2t;
						 KPinterp[26] = (double) KP3t;
						 KPinterp[27] = (double) KP4t;
						 KPinterp[28] = (double) KP5t;
						 KPinterp[29] = (double) KP6t;
						 KPinterp[30] = (double) KP7t;
						 KPinterp[31] = (double) KP8t;
						 }

						// One day after start day
						if(mjd_now==mjd_start+1)
						{
						 for(int i=0;i<8;i++)
						   TIMEinterp[i+32]=mjd2jjh((double)mjd_now + (double)i * h3);

						 APinterp[32] = (double) AP1t;
						 APinterp[33] = (double) AP2t;
						 APinterp[34] = (double) AP3t;
						 APinterp[35] = (double) AP4t;
						 APinterp[36] = (double) AP5t;
						 APinterp[37] = (double) AP6t;
						 APinterp[38] = (double) AP7t;
						 APinterp[39] = (double) AP8t;

						 KPinterp[32] = (double) KP1t;;
						 KPinterp[33] = (double) KP2t;
						 KPinterp[34] = (double) KP3t;
						 KPinterp[35] = (double) KP4t;
						 KPinterp[36] = (double) KP5t;
						 KPinterp[37] = (double) KP6t;
						 KPinterp[38] = (double) KP7t;
						 KPinterp[39] = (double) KP8t;
						 }
						}
						fclose(EIN);  


						// Solar Flux:  3 month average F10.7
						int m1=month, m2=month-1,m3=month-2;
						int j1=year,j2=year,j3=year;
						if(m2<=0)   m2+=12;j2-=1;
						if(m3<=0)   m3+=12;j3-=1;

						EIN=fopen("MONTHPLT.ADJ","rt");
						if(EIN==NULL)
						{
							this->toolStripStatusLabel2->Text="Can't open monthly solar flux file";
						 return;
						}
						while(!feof(EIN))
						{
						fgets(Tempc,127,EIN);
						sscanf(Tempc,"%4d %2d",&Jahr,&Monat);
						if((Monat==m1) & (Jahr==j1)){
						   sscanf(Tempc,"%*8c %9c",&Tmp);
						   Flux3+= Convert::ToDouble(Tmp);
						  }
						if((Monat==m2) & (Jahr==j2)){
						   sscanf(Tempc,"%*8c %9c",&Tmp);
						   Flux3+=Convert::ToDouble(Tmp);
						  }
						if((Monat==m3) & (Jahr==j3)){
						   sscanf(Tempc,"%*8c %9c",&Tmp);
						   Flux3+=Convert::ToDouble(Tmp);
						  }
						}
						fclose(EIN);


						//  Apply AP and Solar Flux Values
						/*Edit1->Text=FloatToStrF((double)APd/8.0L,ffFixed,5,2);
						Edit2->Text=FloatToStrF((double)AP,ffFixed,5,2);
						Edit3->Text=FloatToStrF((double)AP3,ffFixed,5,2);
						Edit4->Text=FloatToStrF((double)AP6,ffFixed,5,2);
						Edit5->Text=FloatToStrF((double)AP9,ffFixed,5,2);
						Edit6->Text=FloatToStrF((double)AP12/8.0L,ffFixed,5,2);
						Edit7->Text=FloatToStrF((double)AP36/8.0L,ffFixed,5,2);
						Edit8->Text=FloatToStrF(Flux,ffFixed,5,2);
						Edit9->Text=FloatToStrF(Flux3/30.0L,ffGeneral,5,2);*/


						// Doesn't work for the first three days of the year
/*						if((month==1)&( (day==1)||(day==2)||(day==3) ))
						  {
						   this->toolStripStatusLabel2->Text="Please fill in AP values manually!";
						  }


						double TI;
						 julianjh(2001,1,12,0.0L,&TI);

						  FILE *profile;
						  profile=fopen("kp.txt","w");

						  for(int h=0;h<40;h++)
							  fprintf(profile,"%18.16Lf  %3.1Lf %3.1Lf \n",TIMEinterp[h],APinterp[h],KPinterp[h]);

							  fprintf(profile,"%18.16Lf  \n",TI);

						fclose(profile);
					}
protected: void fn_ChangeStartWerte(){
			String^ sZeile;
			char cZeile [128];

			int numLines = this->txt_InitialConditions->Lines->Length;
			array<String^>^ tempArray = gcnew array<String^>(this->txt_InitialConditions->Lines->Length);
			tempArray = this->txt_InitialConditions->Lines;
			int index = 0;

			while (index < numLines) {
				sZeile =  tempArray[index];
				cZeile = sZeile->ToCharArray();
				//strcpy (cZeile, StrToChar (AnsiString(sZeile)));
				if ( System::String::Compare(sZeile, "year") == 0 ) year = sZeile->Substring(6);
				else
				if (System::String::Compare(sZeile, "month") == 0) month = sZeile->Substring(6);
				else
				if (System::String::Compare(sZeile, "day") == 0) day = sZeile->Substring(6);
				else
				if (System::String::Compare(sZeile, "starttime") == 0) ta = sZeile->Substring(11);
				else
				if (System::String::Compare(sZeile, "endtime") == 0) te = sZeile->Substring(11);
				else
				if (System::String::Compare(sZeile, "pos") == 0) sscanf (cZeile+5, "%Lf %Lf %Lf", x+1, x+2, x+3);
				else
				if (System::String::Compare(sZeile, "vel") == 0) sscanf (cZeile+5, "%Lf %Lf %Lf", x+4, x+5, x+6);
				if (System::String::Compare(sZeile, "kep") == 0)
				{
					sscanf (cZeile+5, "%Lf %Lf %Lf %Lf %Lf %Lf",&a,&ecc,&inc,&omasc,&omper,&f);
					inc = inc*M_PI/180.0L;
					omasc = omasc*M_PI/180.0L;
					omper = omper*M_PI/180.0L;
					f = f*M_PI/180.0L;
					kep2cart(a,ecc,inc,omasc,omper,f,x[1],x[2],x[3],x[4],x[5],x[6]);
				}
				index++;
			}
			this->txt_InitialConditions->Clear();			
			sprintf (buf, "year: %4d\n", year);
			tempArray[0] = gcnew System::String(buf);
			sprintf (buf, "month: %3d\n", month);
			tempArray[1] = gcnew System::String(buf);
			sprintf (buf, "day: %3d\n", day);
			tempArray[2] = gcnew System::String(buf);
			sprintf (buf, "starttime: %9.12Lf\n", ta);
			tempArray[3] = gcnew System::String(buf);
			sprintf (buf, "endtime: %9.0Lf\n", te);
			tempArray[4] = gcnew System::String(buf);
			if (Kepler)
			{
				sprintf (buf, "kep:  %10.12Lf %1.12Lf %2.12Lf %2.12Lf %2.12Lf %2.12Lf",
				 a, ecc, inc*180.L/M_PI, omasc*180.L/M_PI, omper*180.L/M_PI, f*180.L/M_PI);
				tempArray[5] = gcnew System::String(buf);;
			} else
			{
				sprintf (buf, "pos:  %10.15Lf %10.15Lf %10.15Lf", x[1], x[2], x[3]);
				tempArray[5] = gcnew System::String(buf);
				sprintf (buf, "vel:  %10.15Lf %10.15Lf %10.15Lf", x[4], x[5], x[6]);
				tempArray[6] = gcnew System::String(buf);
			}
			sprintf (buf, "\nIntegrator %2d %8.1Le %8.1Le\n", flag, abstol, reltol);
			tempArray[7] = gcnew System::String(buf);
			this->txt_InitialConditions->Refresh ();
			StartWerteOK=true;
			StartWerteChang = false;
*/		   };
}

