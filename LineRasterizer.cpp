#include <CS200/Image.hpp>
#include <cstdlib>

using namespace CS200;

const Color BLACK{0x000000FF};
const Color WHITE{0xFFFFFFFF};
const Color JAGUAR_BLACK{0x1F0322FF};
const Color DISCO_PURPLE{0x8a1c7cFF};
const Color CABARET_RED{0xda4167FF};
const Color BATTLESHIP_GRAY{0x899d78FF};

const int WIDTH = 256;
const int HEIGHT = 256;
const Color BEAUTY_BUSH_PINK{0xf0bcd4FF};
Image gImage{WIDTH, HEIGHT, BEAUTY_BUSH_PINK};

//Use SETPIXEL function to set a pixel with given xy position and color.
void SETPIXEL(int column, int row, Color intensity) { gImage.SetPixel(column, row, intensity); }

void DrawLine(int x0, int y0, int x1, int y1, Color intensity);

int main(void)
{
	DrawLine(10, 50, 246, 206, BLACK);
	gImage.SaveToPNG("test0.png");

	gImage.Clear(BEAUTY_BUSH_PINK);
	DrawLine(246, 206, 10, 50, BLACK);
	gImage.SaveToPNG("test1.png");

	gImage.Clear(BEAUTY_BUSH_PINK);
	DrawLine(50, 10, 206, 246, BLACK);
	gImage.SaveToPNG("test2.png");

	gImage.Clear(BEAUTY_BUSH_PINK);
	DrawLine(206, 246, 50, 10, BLACK);
	gImage.SaveToPNG("test3.png");

	gImage.Clear(BEAUTY_BUSH_PINK);
	DrawLine(50, 246, 206, 10, BLACK);
	gImage.SaveToPNG("test4.png");

	gImage.Clear(BEAUTY_BUSH_PINK);
	DrawLine(206, 10, 50, 246, BLACK);
	gImage.SaveToPNG("test5.png");

	gImage.Clear(BEAUTY_BUSH_PINK);
	DrawLine(10, 206, 246, 50, BLACK);
	gImage.SaveToPNG("test6.png");

	gImage.Clear(BEAUTY_BUSH_PINK);
	DrawLine(246, 50, 10, 206, BLACK);
	gImage.SaveToPNG("test7.png");

	gImage.Clear(BEAUTY_BUSH_PINK);
	DrawLine(10, 128, 246, 128, BLACK);
	gImage.SaveToPNG("test8.png");

	gImage.Clear(BEAUTY_BUSH_PINK);
	DrawLine(128, 10, 128, 248, BLACK);
	gImage.SaveToPNG("test9.png");

    return 0;
}

void DrawLine(int x0, int y0, int x1, int y1, Color intensity)
{


	////Draw vertical line
	////if(x0 == x1)
	////Draw horizontal line
	////if(y0 == y1)

	////int x = x0;
	////int y = y0;

	//int xStart = x0;
	//int yStart = y0;
	//int xEnd = x1;
	//int yEnd = y1;
	////First of all put the pixels for starting point and end point
	//SETPIXEL(xStart, yStart, intensity);
	//SETPIXEL(xEnd, yEnd, intensity);

	///*if(xStart < xEnd && yStart < yEnd)
	//{*/

	//	//Delta x and y and abs is to prevent th
	//	const int dx = xEnd - xStart;
	//	const int dy = yEnd - yStart;

	//   //나누기 연산을 없애기 위해
	//	int d = (2 * dy) - dx;
	//	const int incrE =  2 * dy;
	//	const int incrNE = 2 * (dy - dx);

	//	while (xStart < xEnd)
	//	{
	//		if (d <= 0)
	//		{
	//			d += incrE;
	//			xStart++;
	//			//xStart++;
	//		}
	//		else
	//		{
	//			d += incrNE;
	//			xStart++;
	//			yStart++;
	//		}
	//		SETPIXEL(xStart, yStart, intensity);
	//	}
	//	while (xStart > xEnd)
	//	{
	//		//?
	//		if(d >= 0)
	//		{
	//			d += incrE;
	//			xStart--;
	//		}
	//		else
	//		{
	//			d += incrNE;
	//			xStart--;
	//			yStart--;
	//		}
	//		SETPIXEL(xStart, yStart, intensity);
	//	}
		//while (xEnd < yEnd)
		//{
		//		if (d <= 0)
		//		{
		//			d += incrE;
		//			xEnd++;
		//			//xStart++;
		//		}
		//		else
		//		{
		//			d += incrNE;
		//			xEnd++;
		//			yEnd++;

		//		}
		//	SETPIXEL(yEnd, yEnd, intensity);
		//}

		//int d = (2 * dy) - dx;
		//int incrE = 2 * dy;
		//int incrNE = 2 * (dy - dx);
	 //  while (xStart >= xEnd)
	 //  {
		//   if (d <= 0)
		//   {
		//	   d += incrE;
		//	   xStart++;
		//   }
		//   else
		//   {
		//	   d += incrNE;
		//	   xStart++;
		//	   yStart++;
		//   }
		//   SETPIXEL(xStart, yStart, intensity);
	 //  		/*if(d >= 0)
		//	{
		//		d += incrE;
		//		xStart--;
	 //  		}
	 //       else
	 //       {
		//		d += incrNE;
		//		xStart--;
		//		yStart--;
	 //       }
		//	SETPIXEL(xStart, yStart, intensity);*/
	 //  }


	//}
	/*x0 = 9;
	y1 = 4;
	SETPIXEL(x0, y0, intensity);*/
	//todo
}