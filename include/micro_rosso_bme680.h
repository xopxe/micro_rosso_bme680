#ifndef __env_bme680_h
#define __env_bme680_h

#include <Wire.h>

class EnvBME680 {
public:
  EnvBME680();
  static bool setup( TwoWire &wire = Wire,
                     const char* topic_temp = "/internal/temperature",
                     const char* topic_humi = "/internal/humidity",
                     const char* topic_pres = "/internal/pressure",
                     const char* topic_gasr = "/internal/gas_resistance"
   ); 
};

#endif  // __env_bme680_h
