#ifndef _POSITION_H_
#define _POSITION_H_

#define PI 3.14159265359

class Position {
	double lt, ln;
public:
	Position (double lat = 0.0, double lon = 0.0) : lt(0.0), ln(0.0) { setLat(lat); setLon(lon); }
	void setLat (double lat) { if ((-90.0 <= lat) && (lat < 90.0)) this->lt = lat; }
	void setLon (double lon) { if ((-180.0 <= lon) && (lon < 180.0)) this->ln = lon; }
	double lat (void) const { return lt; }
	double lon (void) const { return ln; }
};

extern double getDistance (const Position& p1, const Position& p2);

#endif