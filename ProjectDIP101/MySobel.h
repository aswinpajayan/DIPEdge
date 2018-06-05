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
	ref class MySobel
	{
	public:
		MySobel(String^ imagePath);
		Bitmap^ getSobelEdge(void);
		Byte* convertTo8bpp();
		Bitmap ^ inputImage;

	private:
		
		int width = 0;
		int height = 0;
		int size;


	};
