#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

#include "errors.h"
#include "grbl.h"

GRBL_Settings settings;
FILE* fpsim = NULL;

GRBL_Settings get_default_settings()
{
	GRBL_Settings result;

	result.gs0 = 10;					// (Step pulse time, microseconds)
	result.gs1 = 25;					// (Step idle delay, milliseconds)
	result.gs2 = 0;						// (Step pulse invert, mask)
	result.gs3 = 2;						// (Step direction invert, mask)
	result.gs4 = 0;						// (Invert step enable pin, boolean)
	result.gs5 = 0;						// (Invert limit pins, boolean)
	result.gs6 = 0;						// (Invert probe pin, boolean)
	result.gs10 = 1;					// (Status report options, mask)
	result.gs11 = 0.010;			// (Junction deviation, millimeters)
	result.gs12 = 0.002;			// (Arc tolerance, millimeters)
	result.gs13 = 0;					// (Report in inches, boolean)
	result.gs20 = 0;					// (Soft limits enable, boolean)
	result.gs21 = 0;					// (Hard limits enable, boolean)
	result.gs22 = 0;					// (Homing cycle enable, boolean)
	result.gs23 = 0;					// (Homing direction invert, mask)
	result.gs24 = 25.000;			// (Homing locate feed rate, mm / min)
	result.gs25 = 500.000;		// (Homing search seek rate, mm / min)
	result.gs26 = 250;				// (Homing switch debounce delay, milliseconds)
	result.gs27 = 1.000;			// (Homing switch pull - off distance, millimeters)
	result.gs30 = 7000;				// (Maximum spindle speed, RPM)
	result.gs31 = 0;					// (Minimum spindle speed, RPM)
	result.gs32 = 0;					// (Laser - mode enable, boolean)
	result.gs100 = 800.000;		// (X - axis travel resolution, step / mm)
	result.gs101 = 800.000;		// (Y - axis travel resolution, step / mm)
	result.gs102 = 800.000;		// (Z - axis travel resolution, step / mm)
	result.gs110 = 2400.000;	// (X - axis maximum rate, mm / min)
	result.gs111 = 2400.000;	// (Y - axis maximum rate, mm / min)
	result.gs112 = 1500.000;	// (Z - axis maximum rate, mm / min)
	result.gs120 = 1500.000;	// (X - axis acceleration, mm / sec ^ 2)
	result.gs121 = 1500.000;	// (Y - axis acceleration, mm / sec ^ 2)
	result.gs122 = 1000.000;	// (Z - axis acceleration, mm / sec ^ 2)
	result.gs130 = 298.000;		// (X - axis maximum travel, millimeters)
	result.gs131 = 178.000;		// (Y - axis maximum travel, millimeters)
	result.gs132 = 45.000;		// (Z - axis maximum travel, millimeters)

	return result;
}

int grbl_init(int verbose)
{
	_V_("\nInitialize GRBL");

	fpsim = fopen("/dev/ttysim", "rw");;
	if (fpsim == NULL)
		show_error(E_SIM_PORT);

	atexit(grbl_shutdown);

	_V_("GRBL Simulator connected");

	settings = get_default_settings();
	return E_SUCCESS;
}

void grbl_shutdown()
{
	if (fpsim)
		fclose(fpsim);
}

int grbl_homing(int verbose, int enable)
{
	if (enable)
	{
		_V_("\nenable homing");
		settings.gs22 = enable;
	}
	else
	{
		_V_("\ndisable homing");
		settings.gs22 = enable;
	}

	return E_SUCCESS;
}

void grbl_run(int verbose)
{
	char line[250];
	int fdsim = fileno(fpsim);


	_V_("\nGRBL Simulator Running\n");
	while (fgets(line, 250, fpsim) != NULL)
	{
		printf("%s", line); // Print the read line
	}
	_V_("\nGRBL Simulator Shutdown\n");
}
