#include <iostream>
#include <math.h>
#include <fstream>
#include <math.h>
#define PI 3.14159

using namespace std;

int main()
{
	double a, b, theta;
	int d=1;
	a = sin (300000);
	b = -4 * PI + 3.14159;
	theta = b;
	int c = b / 2 / PI;
	while (theta < -PI) theta += 2 * PI;
		while (theta > PI) theta -= 2 * PI;
	b = sin(theta);
	cout<<a<<"   "<<b<<"   "<<theta<<endl;
	/*FILE *fp=fopen("ddd.dat", "wb+");
	fwrite(a, sizeof(double), 1 , fp);
	fclose (fp);*/
	ofstream fout;
	fout.open("ddd.dat");
	fout << a << "   " << b << "   " << theta << "\n";
	fout << flush; fout.close();
	return 0;
}