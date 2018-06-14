#pragma once
#include "MySobel.h"
namespace ProjectDIP101 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for ProcessForm
	/// This form is used to hold the images before and after detection 
	/// </summary>
	public ref class ProcessForm : public System::Windows::Forms::Form
	{
	public:
		ProcessForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::PictureBox^  picBoxSobel;
	public:

	public:
		String ^ imagePath;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProcessForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  picBoxOriginal;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  detectorsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gaussianBlurToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cannyToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  picBoxProcessed;
	protected:

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
			this->picBoxOriginal = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->detectorsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gaussianBlurToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cannyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->picBoxProcessed = (gcnew System::Windows::Forms::PictureBox());
			this->picBoxSobel = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxOriginal))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxProcessed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxSobel))->BeginInit();
			this->SuspendLayout();
			// 
			// picBoxOriginal
			// 
			this->picBoxOriginal->Location = System::Drawing::Point(22, 44);
			this->picBoxOriginal->Name = L"picBoxOriginal";
			this->picBoxOriginal->Size = System::Drawing::Size(360, 220);
			this->picBoxOriginal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBoxOriginal->TabIndex = 0;
			this->picBoxOriginal->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->detectorsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1138, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->openToolStripMenuItem->Text = L"open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &ProcessForm::openToolStripMenuItem_Click);
			// 
			// detectorsToolStripMenuItem
			// 
			this->detectorsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->sobelToolStripMenuItem,
					this->gaussianBlurToolStripMenuItem, this->cannyToolStripMenuItem
			});
			this->detectorsToolStripMenuItem->Name = L"detectorsToolStripMenuItem";
			this->detectorsToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->detectorsToolStripMenuItem->Text = L"detectors";
			// 
			// sobelToolStripMenuItem
			// 
			this->sobelToolStripMenuItem->Name = L"sobelToolStripMenuItem";
			this->sobelToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->sobelToolStripMenuItem->Text = L"sobel";
			this->sobelToolStripMenuItem->Click += gcnew System::EventHandler(this, &ProcessForm::sobelToolStripMenuItem_Click);
			// 
			// gaussianBlurToolStripMenuItem
			// 
			this->gaussianBlurToolStripMenuItem->Name = L"gaussianBlurToolStripMenuItem";
			this->gaussianBlurToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->gaussianBlurToolStripMenuItem->Text = L"gaussian blur";
			// 
			// cannyToolStripMenuItem
			// 
			this->cannyToolStripMenuItem->Name = L"cannyToolStripMenuItem";
			this->cannyToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->cannyToolStripMenuItem->Text = L"canny";
			// 
			// picBoxProcessed
			// 
			this->picBoxProcessed->Location = System::Drawing::Point(398, 44);
			this->picBoxProcessed->Name = L"picBoxProcessed";
			this->picBoxProcessed->Size = System::Drawing::Size(360, 220);
			this->picBoxProcessed->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBoxProcessed->TabIndex = 2;
			this->picBoxProcessed->TabStop = false;
			// 
			// picBoxSobel
			// 
			this->picBoxSobel->Location = System::Drawing::Point(764, 44);
			this->picBoxSobel->Name = L"picBoxSobel";
			this->picBoxSobel->Size = System::Drawing::Size(360, 220);
			this->picBoxSobel->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBoxSobel->TabIndex = 3;
			this->picBoxSobel->TabStop = false;
			// 
			// ProcessForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1138, 299);
			this->Controls->Add(this->picBoxSobel);
			this->Controls->Add(this->picBoxProcessed);
			this->Controls->Add(this->picBoxOriginal);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"ProcessForm";
			this->Text = L"ProcessForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxOriginal))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxProcessed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxSobel))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	// this method is executed when open in the tool strip menu is clicked ,
	// this opens up a openFileDialog to select the image to be processed 

	OpenFileDialog^ selImage = gcnew OpenFileDialog();

	// the following line ensures that by default it will display only png files 
	selImage->Filter = "png files |*.png";
	selImage->Title = "select and image File for processing";
	
	
	// the following line opens up the image select dialog box and waits for the user input 
	if (selImage->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		picBoxProcessed->Image = nullptr;
		picBoxSobel->Image = nullptr;
		imagePath = selImage->FileName;
		picBoxOriginal->Image = System::Drawing::Image::FromFile(imagePath);
		Debug::WriteLine("file selected");
		/*UInt32 test = 0xffAACCAA;
		Byte temp;
		Debug::WriteLine(test);
		Debug::WriteLine(test >> 8);
		temp = (Byte)(test >> 16);*/
		Debug::WriteLine("temp");
		
	}  
}
private: System::Void sobelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MySobel^ sobel = gcnew MySobel(imagePath);
	Debug::WriteLine(sobel->inputImage->GetPropertyItem(20753));
	Debug::WriteLine(sobel->inputImage->PixelFormat);
	if (sobel->inputImage->PixelFormat != PixelFormat::Format32bppArgb
		&& sobel->inputImage->PixelFormat != PixelFormat::Format32bppRgb)
	{
		MessageBox::Show("this file format cannot be processed");
		return;
	}
	picBoxSobel->Image = sobel->getSobelImage();
	picBoxProcessed->Image = System::Drawing::Image::FromFile("..\\grayscaleImage_" + MySobel::get_index() + ".png");
	
	
	Debug::WriteLine("picBox updated");
	
}


};
}
