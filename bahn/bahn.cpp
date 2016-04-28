// bahn.cpp : main project file.

#include "stdafx.h"
#include "Orbitint.h"
//#include "P:\SharedWithWork\Files_downloaded_by_AirDroid\OrbInt\Bahnint_aktuell\Bahnint260804\de.h"
//#include "P:\SharedWithWork\Files_downloaded_by_AirDroid\OrbInt\Bahnint_aktuell\Bahnint260804\vmrech.h"



using namespace bahn;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Orbitint());
	
	return 0;
	
}