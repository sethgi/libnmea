#ifndef INC_NMEA_GNGGA_H
#define INC_NMEA_GNGGA_H

#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	struct timespec time;
	nmea_position longitude;
	nmea_position latitude;
	int positioning_status;
	int n_satellites;
	double precision_factor;
	double altitude;
	double earth_height_relative;
	double differential_time;
	double differential_reference_label;
} nmea_gngga_s;

/* Value indexes */
#define NMEA_GNGGA_TIME			0
#define NMEA_GNGGA_LATITUDE		1
#define NMEA_GNGGA_LATITUDE_CARDINAL	2
#define NMEA_GNGGA_LONGITUDE		3
#define NMEA_GNGGA_LONGITUDE_CARDINAL	4
#define NMEA_GNGGA_STATUS		5
#define NMEA_GNGGA_N_SATELLITES		6
#define NMEAN_GNGGA_PRECISION_FACTOR		7
#define NMEA_GNGGA_ALTITUDE		8
#define NMEA_GNGGA_EARTH_HEIGHT_RELATIVE		9
#define NMEA_GNGGA_DIFFERENTIAL_TIME		10
#define NMEA_GNGGA_DIFFERENTIAL_REFERENCE_LABEL		11

#endif 