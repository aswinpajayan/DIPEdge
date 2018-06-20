#include "ProcessForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProjectDIP101::ProcessForm form;
	Application::Run(%form);
	/*System::Diagnostics::Debug::WriteLine("exiting the application");*/
}
