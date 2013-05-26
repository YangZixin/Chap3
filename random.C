#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>
//#include "TGraph.h"
//#include "TAxis.h"

#define q 0.5
#define F_D 1.2
#define g 9.8
#define STEP 1000
double PI = 3.14159;
double *omega_to_plot = NULL;
double *theta_to_plot = NULL;
double *Time_to_Plot = NULL;

using namespace std;

void PendulumSwing(double l, double Omega_D)
{
	double theta = 0.2;
	double omega = 0;
	double PresentTime;
	double delta_t = 0.01;
	//int numOfPlot = STEP * delta_t * Omega_D /2 / PI + 1000;
	int numOfPlot = STEP;
	int n = 1;
	omega_to_plot = new double[numOfPlot];
	theta_to_plot = new double[numOfPlot];
	Time_to_Plot = new double[numOfPlot];
	omega_to_plot[0] = omega;
	theta_to_plot[0] = theta;
	Time_to_Plot[0] = 0;
	for (int i = 0; i < STEP; i++)
	{
		int move = 2 * PI / Omega_D / delta_t + i * 0.001;
		
		for (int j = 0; j < move; j++)
		{
			omega += - delta_t * (g / l) * sin(theta) - delta_t * q * omega + delta_t * F_D * sin(Omega_D * PresentTime);
			theta += omega * delta_t;
			while (theta < -PI) theta += 2 * PI;
			while (theta > PI) theta -= 2 * PI;
			PresentTime += delta_t;
		}
		
		omega_to_plot[i] = omega;
		theta_to_plot[i] = theta;
		Time_to_Plot[i] = PresentTime;
	}
}

void main()
{
	/*double l, Omega_D;
	cout<<"l=";
	cin>>l;
	cout<<"Omega_D=";
	cin>>Omega_D;*/
	PendulumSwing(9, 0.667);
	TGraph* gr1 = new TGraph(STEP, theta_to_plot, omega_to_plot);
	gr1->GetXaxis()->SetTitle("/theta (rad)");
	gr1->GetYaxis()->SetTitle("/omega (rad/s)");
	gr1->SetTitle("Poincare section");
	gr1->SetMarkerStyle(7);
	gr1->SetMarkerColor(32);
	gr1->SetMarkerSize(1);
	gr1->Draw("AP");

}
