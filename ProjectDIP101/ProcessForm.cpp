#include "ProcessForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProjectDIP101::ProcessForm form;
	//i want to create a temporary directory to hold my project output 
	MySobel::set_index(0);
	String^ output_folder = gcnew String("..\\out_folder_DIP");
	if (System::IO::Directory::Exists(output_folder)) {
		System::IO::Directory::Delete(output_folder);
		System::IO::Directory::CreateDirectory(output_folder);
	}
	Application::Run(%form);
	System::Diagnostics::Debug::WriteLine("exiting the application");
}
