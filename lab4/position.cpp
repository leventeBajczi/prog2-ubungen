#include <cmath>
#include "position.h"

static double d2r (double deg) { return deg / 180.0 * PI; }
static double r2d (double rad) { return rad / PI * 180.0; }

double getDistance (const Position& p1, const Position& p2) {
	// https://www.movable-type.co.uk/scripts/latlong.html
	double f1 = d2r(p1.lat());
	double f2 = d2r(p2.lat());
	double df = d2r(p2.lat()-p1.lat());
	double dl = d2r(p2.lon()-p1.lon());

	double a = sin(df/2) * sin(df/2) + cos(f1) * cos(f2) * sin(dl/2) * sin(dl/2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));

	return 6371e3 * c;
}
