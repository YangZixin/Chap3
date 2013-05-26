#include<iostream>
#include<math.h>
#include"TGraph.h"
#include"TAxis.h"

double *angle = NULL;
double *angVelocity = NULL;
int numOfSteps = 100000;
double pi = 3.14159265358979323846;

using namespace std;

double pimod(double Anumber, double theMod)
{
        while(Anumber > theMod || Anumber < -theMod)
        {
                if (Anumber > theMod)
                        Anumber -= 2 * theMod;
                else
                        Anumber += 2 * theMod;
        }
        return Anumber;
}


void getAttractor(int num)
{
	TGraph* tg = new TGraph(num, angle, angVelocity);
        tg->GetXaxis()->SetTitle("angular displacement / radius");
        tg->GetYaxis()->SetTitle("andular velocity / radius per second");
        tg->SetTitle("the pendulum");
        tg->SetMarkerStyle(6);
        tg->SetMarkerSize(1);
        tg->SetMarkerColor(kBlue);
        tg->Draw("AP");
        delete[] angle;
	delete[] angVelocity;
}

void calculation(double l, double q, double fD, double Omiga)
{
	int i;
	double omiga, theta, t;
	const double dt = 0.004, g = 9.8;
	angle = new double[numOfSteps];
	angVelocity = new double[numOfSteps];
	theta = 3;
	omiga = -2;
	t = 0;
	for(i = 0; i < numOfSteps ; i++)
	{
		t += dt;
		omiga -= dt * (g / l * sin(theta) + q * omiga - fD * sin (Omiga * t));
		theta += omiga * dt;
		theta = pimod(theta, pi);
//		cout<< omiga << "  " << theta << endl;
		angle[i] = theta;
		angVelocity[i] = omiga;
	}
}

int main()
{
	calculation(/* l= */9.8, /* q= */0.5, /*fD= */1.2, /*Omiga= */2./3);
	getAttractor(numOfSteps);
}
