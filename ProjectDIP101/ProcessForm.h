#pragma once

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxOriginal))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxProcessed))->BeginInit();
			this->SuspendLayout();
			// 
			// picBoxOriginal
			// 
			this->picBoxOriginal->Location = System::Drawing::Point(22, 44);
			this->picBoxOriginal->Name = L"picBoxOriginal";
			this->picBoxOriginal->Size = System::Drawing::Size(360, 220);
			this->picBoxOriginal->TabIndex = 0;
			this->picBoxOriginal->TabStop = false;
			this->picBoxOriginal->SizeMode = PictureBoxSizeMode::StretchImage;
			
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->detectorsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(774, 24);
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
			this->picBoxProcessed->TabIndex = 2;
			this->picBoxProcessed->TabStop = false;
			this->picBoxProcessed->SizeMode = PictureBoxSizeMode::StretchImage;
			// 
			// ProcessForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(774, 276);
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
		picBoxOriginal->Image = System::Drawing::Image::FromFile(selImage->FileName);
		Debug::WriteLine("open dialog Opened");
	}
}
};
}
