#include "MySobel.h"
using namespace System::Diagnostics;

MySobel::MySobel(String^ imagePath)
{
	 this->inputImage = gcnew Bitmap(imagePath);
	 this->width = inputImage->Width;
	 this->height = inputImage->Height;
	 this->size =  width * height;
}
Bitmap^ MySobel::getSobelEdge(void) {
	Debug::WriteLine("Starting sobel Edge Detection");
	Byte* grayData = new Byte[size];
	grayData = MySobel::convertTo8bpp();
/// SOBEL Kernels
/// Gx = |1		0		-1|		Gy	=| 1		2		1|
///		 |2		0		-2|			 | 0		0		0|
///		 |1		0		-1|			 |-1	   -2	   -1|
	//convolving sobel operator with the grayscale Image
	double* magnitude = new double[size];		//to store magnitude of edge response
	double* phase = new double[size];			//to store the phase of edge response 
	double dx, dy;
	
	Byte* curPixel = grayData + width;
	for (int y = 1; y < size; y++) {
			dx = (*(curPixel - width - 1)) + (*(curPixel - 1)) * 2 + (*(curPixel + width - 1)) - (*(curPixel - width + 1)) - (*(curPixel + 1)) * 2 - (*(curPixel + width + 1));
			dy = (*(curPixel - width - 1)) + (*(curPixel -width)) * 2 + (*(curPixel - width + 1)) - (*(curPixel + width -1)) - (*(curPixel + width)) * 2 - (*(curPixel + width + 1));
			*(magnitude) = Math::Sqrt(dx*dx + dy * dy);
			*(phase) = Math::Atan2(dy, dx) + Math::PI;
			phase++;
			magnitude++;
			curPixel++;			//increments the pointer byte by byte
	}
	return this->inputImage;
	
}

/// This method takes the RGB image bitmap and returns the  grayscale image for processing
Byte* MySobel::convertTo8bpp()
{
	//this byte array is going to hold the grayscale data
	Byte* grayData = new Byte[size];
	Rectangle canvas =  Rectangle(0, 0, this->width, this->height);
	// We are taking the pixel data into the bitmap data object 
	System::Drawing::Imaging::BitmapData^ imageData = this->inputImage->LockBits(canvas,ImageLockMode::ReadWrite, inputImage->PixelFormat);
	UInt32 *ptr = (UInt32*)imageData->Scan0.ToPointer();		//this line get the pointer to the first pixel - assuming the pointer to be 32 bit 
	///
	///  now each of the pixel will be having an R,G and B Channel and sometimes an Alhpa Channel
	/// (for transparency in Png images)
	///	we will iterate through each of the pixels using pointers and have to convert them to grayscale 
	///
	int inputStride = imageData->Stride / 4; // stride represents the offset after each line an image array
	///Stride is divided by four assuming an ARGB image 
	/// change the above line to imageData/3 for an RGB image
	Byte red, green, blue;
	int gray;
	UInt32 *curLocation;
	UInt32 curPixel;
	for (int y = 0; y < this->height; y++) {
		for (int x = 0; x < this->width; x++) {
			curLocation = ptr + x + y * inputStride;
			curPixel = *(curLocation); // getting the current pixel value 32 bit pixel value in ARGB format
			//Debug::WriteLine("pixel in image is 0x{0:X}", curPixel);
			blue	= (Byte)curPixel;
			green	= (Byte)(curPixel >> 8);
			red		= (Byte)(curPixel >> 16);

			gray = (red + green + blue) / 3;
			/// Excat formula to construct grayscale image from rgb is given as
			/// byte gray = (byte)(0.2126 * r + 0.7152 * g + 0.0722 * b);
			/// this formula is taking consideration about the varition in sensitivity of 
			/// red blue and green pixels . But as we are just interested in edges , 
			/// we will use the averaging method
			curPixel = gray ;
			curPixel = curPixel << 8;
			curPixel = curPixel | gray;
			curPixel = curPixel << 8;
			curPixel = curPixel | gray | 0xFF000000;
			*(curLocation) = curPixel;
			/*Debug::WriteLine("manipulated pixel is 0x{0:X}", curPixel);
			Debug::WriteLine("calculated gray value 0x{0:X}",gray);
			Debug::WriteLine("calculated red value 0x{0:X}", red);
			Debug::WriteLine("calculated blue value 0x{0:X}", blue);
			Debug::WriteLine("calculated green value 0x{0:X}", green);*/
			*(grayData + x + y * width) = gray;
		}
		
	}
	Debug::WriteLine("finished processing");
	inputImage->UnlockBits(imageData);
	Debug::WriteLine("written image");
	return grayData;
}
