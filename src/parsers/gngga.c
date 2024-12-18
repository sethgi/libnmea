#include "../nmea/parser_types.h"
#include "gngga.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GNGGA);
	NMEA_PARSER_PREFIX(parser, "GNGGA");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_gngga_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_gngga_s));
	// Set the default undulation to an invalid value
	// nmea_gngga_s *data = (nmea_gngga_s *) parser->data;
	return 0;
}

int
free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int
parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_gngga_s *data = (nmea_gngga_s *) parser->data;

	switch (val_index) {
	case NMEA_GNGGA_TIME:
		/* Parse time */
		if (-1 == nmea_time_fractional_parse(value, &data->time)) {
			return -1;
		}
		break;

	case NMEA_GNGGA_LATITUDE:
		/* Parse latitude */
		if (-1 == nmea_position_parse(value, &data->latitude)) {
			return -1;
		}
		break;

	case NMEA_GNGGA_LATITUDE_CARDINAL:
		/* Parse cardinal direction */
		data->latitude.cardinal = nmea_cardinal_direction_parse(value);
		if (NMEA_CARDINAL_DIR_UNKNOWN == data->latitude.cardinal) {
			return -1;
		}
		break;

	case NMEA_GNGGA_LONGITUDE:
		/* Parse longitude */
		if (-1 == nmea_position_parse(value, &data->longitude)) {
			return -1;
		}
		break;

	case NMEA_GNGGA_LONGITUDE_CARDINAL:
		/* Parse cardinal direction */
		data->longitude.cardinal = nmea_cardinal_direction_parse(value);
		if (NMEA_CARDINAL_DIR_UNKNOWN == data->longitude.cardinal) {
			return -1;
		}
		break;

	case NMEA_GNGGA_STATUS:
		data->positioning_status = atoi(value);
		break;

	case NMEA_GNGGA_N_SATELLITES:
		/* Parse number of satellies */
		data->n_satellites = atoi(value);
		break;

	case NMEA_GNGGA_ALTITUDE:
		/* Parse altitude */
		data->altitude = atof(value);
		break;

	case NMEA_GNGGA_EARTH_HEIGHT_RELATIVE:
		data->earth_height_relative = atof(value);
		break;

	case NMEA_GNGGA_DIFFERENTIAL_TIME:
		data->differential_time = atof(value);
		break;

	case NMEA_GNGGA_DIFFERENTIAL_REFERENCE_LABEL:
		data->differential_reference_label = atof(value);
		break;

	default:
		break;
	}

	return 0;
}
