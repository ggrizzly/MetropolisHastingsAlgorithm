#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000000

double q(double x);
void metropolis(int numIter, double *points);
double uniform_random(double mm, double nn);

double pts[N] = { 0 };
double MU = 0.0;
double SIG = 1.0;

int main(void) {
    metropolis(N,pts)
    printf("DONE/n/r");

    FILE *fp;
    fp=fopen("metropolis.txt", "w");
    int j = 0;
    for (j = 0; j < N; j++) {
         fprintf(fp, "%f\n", pts[j]);
         //fprintf(fp, "%Lf\n", pts[j]);
    }
    fclose(fp);
    
    return EXIT_SUCCESS;
}

}

double q(double x) { //Gaussian
  return (double) ((1.0/(sqrt(2.0*M_PI*pow(SIG,2.0)))*(exp(-(pow(x-MU,2.0)))/(2.0*pow(SIG,2.0)))));
}

void metropolis(int numIter, double *points) {
        double r = 0.0;
        double p = q(r);

        // Random number seeder needed for Random Number Generator (WARNING! ONLY DO ONCE IN PROGRAM PER RUN)
        srand (time(NULL));

        int i = 0;
        while(i < numIter) {
                double rn = r + uniform_random(-1.0,0.0); //random value from -1 to 1
                double pn = q(rn);
                if (pn >= p) {
                        p = pn;
                        r = rn;
                } else {
                        double u = uniform_random(0.0,0.0); //random value from 0 to 1
                        if(u < (double) (pn/p)) {
                                p = pn;
                                r = rn;
                        }
                }
                points[i] = r;
                i++;
        }
}

double uniform_random(double mm, double nn) {
        return (double) (mm + rand() / (RAND_MAX / (nn - mm + 1.0) + 1.0));
        /*
        Formula used:
        Generator of numbers between M and N-1, you have
        M + rand() / (RAND_MAX / (N - M + 1) + 1)
        http://c-faq.com/lib/randrange.html
        Setting nn = 1.0 will make it from -1, to 2. So it is indeed M to N-1, don't know if error.
        */
}