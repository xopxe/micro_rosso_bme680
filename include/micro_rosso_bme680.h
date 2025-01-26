#ifndef __env_bme680_h
#define __env_bme680_h

#include <Wire.h>

class EnvBME680
{
public:
  EnvBME680();
  static bool setup(TwoWire &wire = Wire,
                    const char *topic_temp = "/temperature",
                    const char *topic_humi = "/humidity",
                    const char *topic_pres = "/pressure",
                    const char *topic_gasr = "/gas_resistance",
                    timer_descriptor &timer = micro_rosso::timer_report);
};

#endif // __env_bme680_h
