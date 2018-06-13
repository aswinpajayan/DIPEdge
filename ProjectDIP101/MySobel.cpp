#include "MySobel.h"
#include<stdio.h>
using namespace System::Diagnostics;

MySobel::MySobel(String^ imagePath)
{
	 this->inputImage = gcnew Bitmap(imagePath);
	 this->width = inputImage->Width;
	 this->height = inputImage->Height;
	 this->size =  width * height;
	 magnitude = new double[this->size];		//to store magnitude of edge response
	 orientation = new double[this->size];			//to store the phase of edge response
	 Debug::WriteLine(" magnitude pointer at 0x{0:X}", (int)magnitude);
	 Debug::WriteLine(" orientation pointer at 0x{0:X}", (int)orientation);
}
	void MySobel::getSobelEdge(void) {
	Debug::WriteLine("Starting sobel Edge Detection");
	Byte* grayData = new Byte[size];
	grayData = MySobel::convertTo8bpp();
/// SOBEL Kernels
///	Gx = |1		0		-1|		Gy	=| 1		2		1|
///		 |2		0		-2|			 | 0		0		0|
///		 |1		0		-1|			 |-1	   -2	   -1|
	//convolving sobel operator with the grayscale Image
	 
	double dx, dy;								// temp variables to store the edge response
	maxMagnitude = 0;							// to store the maximum magnitude , we need this value to normalise the edge response
	
	Byte* curPixel = grayData + width + 1;			// adding width to the starting of array automatically skips the top edge pixels 
	Byte* endPixel = grayData + size - width - 1;	// again this is for avoising bottom edge pixels 
	
	Byte pixel_0, pixel_2, pixel_7, pixel_9;
	double *magnitude_, *orientation_;
	magnitude_ = magnitude;
	orientation_ = orientation;
	while(curPixel <= endPixel) {
		/// It seems that buffering the mask will be speeding up the code as it can avoid duplicate calculations and data fetch
		//Byte* buffer = new Byte[9];						// to hold the nieghbouring pixel values for each pixel
				/*	|0	1	2|
					|3	4	5|
					|7	8	9|	
					pixel marked 4 is the current pixel */
		//*(buffer) = *(curPixel - width - 1);
		//*(buffer + 1) = *(curPixel - width);
		//*(buffer + 2) = *(curPixel - width + 1);
		//*(buffer + 3) = *(curPixel - 1);
		////*(buffer + 4) = *(curPixel);  not required for sobel kernel
		//*(buffer + 5) = *(curPixel + 1);
		//*(buffer + 6) = *(curPixel + width - 1);
		//*(buffer + 7) = *(curPixel + width);
		//*(buffer + 8) = *(curPixel + width + 1);
		pixel_0 = *(curPixel - width - 1);
		pixel_2 = *(curPixel - width + 1);
		pixel_7 = *(curPixel + width - 1);
		pixel_9 = *(curPixel + width + 1);
		dx = pixel_0 + (*(curPixel - 1)) * 2 + pixel_7 - pixel_2 - (*(curPixel + 1)) * 2 - pixel_9;
		dy = pixel_0 + (*(curPixel -width)) * 2 + pixel_2 - pixel_7 - (*(curPixel + width)) * 2 - pixel_9;
		*(magnitude_) = Math::Sqrt(dx*dx + dy * dy);
		maxMagnitude = (maxMagnitude > *(magnitude_)) ? maxMagnitude : *(magnitude_);
		*(orientation_) = Math::Atan2(dy, dx) + Math::PI;
		orientation_++;
		magnitude_++;
		curPixel++;			//increments the pointer byte by byte
	}
}

	Bitmap^ MySobel::getSobelImage(void) {
		this->getSobelEdge();
		/* ----- now we have the magnitude and orientation arrays ---------------
		These can be suitably expressed by an HSV image with hue from phase data
		and value from magnitude , value is given as 1 ----------------*/
		double hue, sat, value;
		sat = 1;
		Rectangle canvas = Rectangle(0, 0, this->width, this->height);
		// We are taking the pixel data into the bitmap data object 
		// we will use the image created to display the sobel edge 
		System::Drawing::Imaging::BitmapData^ sobelImageData = this->inputImage->LockBits(canvas, ImageLockMode::ReadWrite, inputImage->PixelFormat);
		UInt32 *ptr = (UInt32*)sobelImageData->Scan0.ToPointer();
		int inputStride = sobelImageData->Stride / 4; // stride represents the offset after each line an image array
		///Stride is divided by four assuming an ARGB image 
		/// change the above line to imageData/3 for an RGB image
		Byte red, green, blue;
		UInt32 *curLocation;
		UInt32 curPixel;
		UInt32 index = 0;
		for (int y = 0; y < this->height; y++) {
			for (int x = 0; x < this->width; x++) {
				curLocation =(UInt32*)( y * inputStride + x + ptr);
				hue = *(orientation + index);
				value = *(magnitude + index) / maxMagnitude;
				HSV2RGB(hue, sat, value, &red, &green, &blue);
				*(curLocation) = (0xFF000000 | ((UInt32)red) << 16 |((UInt32)(green)) << 8 |(UInt32)blue); // getting the current pixel value 32 bit pixel value in ARGB format
				index++;
										   
				
			}
		}

		Debug::WriteLine("finished processing");
		inputImage->UnlockBits(sobelImageData);
		Debug::WriteLine("written image");
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

			//gray = (red + green + blue) / 3;
			/// Excat formula to construct grayscale image from rgb is given as
			 Byte gray = (Byte)(0.2126 * red + 0.7152 * green + 0.0722 * blue);
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
	String^ path = gcnew String("grayscaleImage.png");
	if (File::Exists(path))
		File::Delete(path);
	inputImage->Save(path);
	Debug::WriteLine("written image");
	return grayData;
}

void MySobel::HSV2RGB(double hue, double sat, double value, Byte * red, Byte * green, Byte * blue)
{
	// hue_ 0-6
	// the output of Math::Atan2(dx,dy) is in radians , we have to split the whole colors into 6 different ones
	double hue_ = hue / (2 * Math::PI) * 6;

	double c = sat * value;
	double x = c * (1 - Math::Abs((Math::Floor(hue_/2))- 1));
	double red_, green_, blue_;
	if (hue_ < 1)
	{
		red_ = c;
		green_ = x;
		blue_ = 0;
	}
	else if (hue_ < 2)
	{
		red_ = x;
		green_ = c;
		blue_ = 0;
	}
	else if (hue_ < 3)
	{
		red_ = 0;
		green_ = c;
		blue_ = x;
	}
	else if (hue_ < 4)
	{
		red_ = 0;
		green_ = x;
		blue_ = c;
	}
	else if (hue_ < 5)
	{
		red_ = x;
		green_ = 0;
		blue_ = c;
	}
	else
	{
		red_ = c;
		green_ = 0;
		blue_ = x;
	}

	double m = value - c;

	red_ += m;
	green_ += m;
	blue_ += m;

	*red = (Byte)(red_ * 255);
	*green = (Byte)(green_ * 255);
	*blue = (Byte)(blue_ * 255);
}

