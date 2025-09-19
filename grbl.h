#ifndef __GRBL__
#define __GRBL__

#define _V_(m)	if (verbose) printf(m)

// ------------------------------------------------
//			store the global settings
// ------------------------------------------------
typedef struct grbl_settings
{
	int gs0;			// (Step pulse time, microseconds)
	int gs1;			// (Step idle delay, milliseconds)
	int gs2;			// (Step pulse invert, mask)
	int gs3;			// (Step direction invert, mask)
	int gs4;			// (Invert step enable pin, boolean)
	int gs5;			// (Invert limit pins, boolean)
	int gs6;			// (Invert probe pin, boolean)
	int gs10;			// (Status report options, mask)
	float gs11;		// (Junction deviation, millimeters)
	float gs12;		// (Arc tolerance, millimeters)
	int gs13;			// (Report in inches, boolean)
	int gs20;			// (Soft limits enable, boolean)
	int gs21;			// (Hard limits enable, boolean)
	int gs22;			// (Homing cycle enable, boolean)
	int gs23;			// (Homing direction invert, mask)
	float gs24;		// (Homing locate feed rate, mm / min)
	float gs25;		// (Homing search seek rate, mm / min)
	int gs26;			// (Homing switch debounce delay, milliseconds)
	float gs27;		// (Homing switch pull - off distance, millimeters)
	int gs30;			// (Maximum spindle speed, RPM)
	int gs31;			// (Minimum spindle speed, RPM)
	int gs32;			// (Laser - mode enable, boolean)
	float gs100;	// (X - axis travel resolution, step / mm)
	float gs101;	// (Y - axis travel resolution, step / mm)
	float gs102;	// (Z - axis travel resolution, step / mm)
	float gs110;	// (X - axis maximum rate, mm / min)
	float gs111;	// (Y - axis maximum rate, mm / min)
	float gs112;	// (Z - axis maximum rate, mm / min)
	float gs120;	// (X - axis acceleration, mm / sec ^ 2)
	float gs121;	// (Y - axis acceleration, mm / sec ^ 2)
	float gs122;	// (Z - axis acceleration, mm / sec ^ 2)
	float gs130;	// (X - axis maximum travel, millimeters)
	float gs131;	// (Y - axis maximum travel, millimeters)
	float gs132;	// (Z - axis maximum travel, millimeters)
} GRBL_Settings;

// ------------------------------------------------
//			grbl functions
// ------------------------------------------------

GRBL_Settings get_default_settings();
int grbl_init(int verbose);
void grbl_shutdown();
void grbl_run(int verbose);
int grbl_homing(int verbose, int enable);

#endif // __GRBL__
