/*
 ============================================================================
 Name        : VectorAddition.c
 Author      : Matt Duffy
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RIGHT_ANGLE 90.0
#define ONE_INDEXED_ARRAY_OFFSET 1
#define DEGREES_PER_RADIAN (180.0/3.14159265359)

void projectVectorPolarToCartesian(double magnitude, double angle, double *x, double *y);
void projectVectorCartesianToPolar(double x1, double x2, double y1, double y2, double *magnitude, double *angle);

int main(void) {

//	int done;

	char another = 'n';

	do {

		/*
		 * Get input
		 */
		double magnitude1=0, angle1=0, magnitude2=0, angle2=0;
		puts("Enter first vector as magnitude and angle separated by a space \n  e.g. for a vector |1| @ 90* enter: 1 90 >\n");
		scanf("%lf %lf", &magnitude1, &angle1);
		puts("\nEnter second vector >\n");
		scanf("%lf %lf", &magnitude2, &angle2);


		/*
		 * Maths
		 */
		double x1=0, y1=0, x2=0, y2=0;
		// V1
		projectVectorPolarToCartesian(magnitude1, angle1, &x1, &y1);

		// V2
		projectVectorPolarToCartesian(magnitude2, angle2, &x2, &y2);

		// Resultant: needs x1, y1, x2, y2 as input
		double magnitudeOut=0, angleOut=0;
		projectVectorCartesianToPolar(x1, x2, y1, y2, &magnitudeOut, &angleOut);


		/*
		 * Format Output
		 */
		printf("\n|%3.2f| @ %3.2f* \t + \t |%3.2f| @ %3.2f* \t = \t |%3.2f| @ %3.2f*\n", magnitude1, angle1, magnitude2, angle2, magnitudeOut, angleOut);

		//Check for more input
		puts("\nWould you like to calculate another? [ (Y)es / (N)o: Exit ]\n");
		scanf(" %c", &another); // leading space to swallow output buffer CRLF

	} while (another == 'Y' || another == 'y');

	return EXIT_SUCCESS;
}

void projectVectorPolarToCartesian(double magnitude, double angle, double *x, double *y) {

	}


void projectVectorCartesianToPolar(double x1, double x2, double y1, double y2, double *magnitude, double *angle) {

	int resultantQuadrant[2][2] = {
			/*x < 0*/	{3,2},
			/*x > 0*/ 	{4,1}}; // Quadrant of sum is found by sumQuadrant[xOut>0][yOut>0]
	double resultantOffset[4] = {0.0,180.0,180.0,0.0};

	double xOut=0, yOut=0, computedAngle=0, angleOffset=0;

	xOut = x1+x2;
	yOut = y1+y2;
	*magnitude = sqrt(pow(xOut, 2) + pow(yOut, 2));
	angleOffset = resultantOffset[resultantQuadrant[xOut>0][yOut>0] - ONE_INDEXED_ARRAY_OFFSET];
	computedAngle = DEGREES_PER_RADIAN * atan(yOut/xOut);
	*angle = computedAngle + angleOffset;
}
