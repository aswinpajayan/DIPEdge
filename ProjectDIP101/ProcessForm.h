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
			//i want to create a temporary directory to hold my project output 
			MySobel::set_index(0);
			String^ output_folder = gcnew String("..\\out_folder_DIP");
			Debug::WriteLine(output_folder);
			if (System::IO::Directory::Exists(output_folder)) {
				System::IO::Directory::Delete(output_folder,true);
			}
			System::IO::Directory::CreateDirectory(output_folder);
			//
		}
	private: System::Windows::Forms::PictureBox^  picBoxSobel;
	private: System::Windows::Forms::Button^  btnBrowseImage;
	private: System::Windows::Forms::Button^  btnDetectEdges;
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
	private: System::Windows::Forms::PictureBox^  picBoxGrayScale;








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
			this->picBoxGrayScale = (gcnew System::Windows::Forms::PictureBox());
			this->picBoxSobel = (gcnew System::Windows::Forms::PictureBox());
			this->btnBrowseImage = (gcnew System::Windows::Forms::Button());
			this->btnDetectEdges = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxOriginal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxGrayScale))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxSobel))->BeginInit();
			this->SuspendLayout();
			// 
			// picBoxOriginal
			// 
			this->picBoxOriginal->Location = System::Drawing::Point(10, 47);
			this->picBoxOriginal->Name = L"picBoxOriginal";
			this->picBoxOriginal->Size = System::Drawing::Size(300, 200);
			this->picBoxOriginal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBoxOriginal->TabIndex = 0;
			this->picBoxOriginal->TabStop = false;
			// 
			// picBoxGrayScale
			// 
			this->picBoxGrayScale->Location = System::Drawing::Point(316, 47);
			this->picBoxGrayScale->Name = L"picBoxGrayScale";
			this->picBoxGrayScale->Size = System::Drawing::Size(300, 200);
			this->picBoxGrayScale->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBoxGrayScale->TabIndex = 2;
			this->picBoxGrayScale->TabStop = false;
			// 
			// picBoxSobel
			// 
			this->picBoxSobel->Location = System::Drawing::Point(10, 253);
			this->picBoxSobel->Name = L"picBoxSobel";
			this->picBoxSobel->Size = System::Drawing::Size(300, 200);
			this->picBoxSobel->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBoxSobel->TabIndex = 3;
			this->picBoxSobel->TabStop = false;
			// 
			// btnBrowseImage
			// 
			this->btnBrowseImage->Location = System::Drawing::Point(10, 12);
			this->btnBrowseImage->Name = L"btnBrowseImage";
			this->btnBrowseImage->Size = System::Drawing::Size(96, 23);
			this->btnBrowseImage->TabIndex = 4;
			this->btnBrowseImage->Text = L"Browse Image";
			this->btnBrowseImage->UseVisualStyleBackColor = true;
			this->btnBrowseImage->Click += gcnew System::EventHandler(this, &ProcessForm::btnBrowseImage_Click);
			// 
			// btnDetectEdges
			// 
			this->btnDetectEdges->Location = System::Drawing::Point(112, 12);
			this->btnDetectEdges->Name = L"btnDetectEdges";
			this->btnDetectEdges->Size = System::Drawing::Size(96, 23);
			this->btnDetectEdges->TabIndex = 5;
			this->btnDetectEdges->Text = L"Detect Edges";
			this->btnDetectEdges->UseVisualStyleBackColor = true;
			this->btnDetectEdges->Click += gcnew System::EventHandler(this, &ProcessForm::btnDetectEdges_Click);
			// 
			// ProcessForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(638, 465);
			this->Controls->Add(this->btnDetectEdges);
			this->Controls->Add(this->btnBrowseImage);
			this->Controls->Add(this->picBoxSobel);
			this->Controls->Add(this->picBoxGrayScale);
			this->Controls->Add(this->picBoxOriginal);
			this->Name = L"ProcessForm";
			this->Text = L"ProcessForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxOriginal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxGrayScale))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxSobel))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	





private: System::Void btnBrowseImage_Click(System::Object^  sender, System::EventArgs^  e) {
	// this method is executed when browse image is clicked ,
	// this opens up a openFileDialog to select the image to be processed 

	OpenFileDialog^ selImage = gcnew OpenFileDialog();

	// the following line ensures that by default it will display only png files 
	selImage->Filter = "image files |*.png;*.jpg";
	selImage->Title = "select and image File for processing";


	// the following line opens up the image select dialog box and waits for the user input 
	if (selImage->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		picBoxGrayScale->Image = nullptr;
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
private: System::Void btnDetectEdges_Click(System::Object^  sender, System::EventArgs^  e) {
	MySobel^ sobel = gcnew MySobel(imagePath);
	
	Debug::WriteLine(sobel->inputImage->PixelFormat);
	if (sobel->inputImage->PixelFormat != PixelFormat::Format32bppArgb
		&& sobel->inputImage->PixelFormat != PixelFormat::Format32bppRgb
		&& sobel->inputImage->PixelFormat != PixelFormat::Format24bppRgb)
	{
		MessageBox::Show("this file format cannot be processed");
		return;
	}
	picBoxSobel->Image = sobel->getSobelImage();
	picBoxGrayScale->Image = System::Drawing::Image::FromFile("..\\out_folder_DIP\\grayscaleImage_" + MySobel::get_index() + ".png");


	Debug::WriteLine("picBox updated");
}
};
}
