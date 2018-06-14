#pragma once
//#include<Gdiplus.h>
	///the basic code used here for edge detection is originally uploaded by computerphile. 
	/// i am just tweaking the code for optimisation 
	/// i have added GUI and ported the entire code from C# to VC++ and added some additional stuff 
	/// original code by Dr.MarkPound can be found out here 
	///			http://bit.ly/computerphileEdge
	/// for his tutorials - https://www.youtube.com/watch?v=uihBwtPIBxM
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Text;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::IO;
	using namespace System;
	ref class MySobel
	{
	public:
		MySobel(String^ imagePath);
		const static String^ out_grayImage = gcnew String("F:\\photos\\grayscaleImage.png");	//file paths to output images
		const static String^ out_SobelImage = gcnew String("F:\\photos\\edgeImage.png");
		Bitmap ^ inputImage;
		/// this method is used to display the output of sobel edge detection
		Bitmap^ getSobelImage(void);
		/// this method is used to calculate find the edge magnitude and orientation
		void getSobelEdge(void);

		static void HSV2RGB(double hue, double sat, double value, Byte *red , Byte *green, Byte *blue );
		static void set_index(int index);
		static String^ get_index(void);

	private:
		
		int width = 0;
		int height = 0;
		int size;
		double* magnitude; 		//to store magnitude of edge response
		double* orientation;			//to store the phase of edge response
		double maxMagnitude = 0;
		Byte* convertTo8bpp();
		static int index;			//to store number of images processed since the uptime of the application 
		


	};
