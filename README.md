# micro rosso bme680

This a module for the [micro_rosso](https://github.com/xopxe/micro_rosso_platformio) system.

It provides support for the BME680 environmental (temperature/humidity/pressure/gas resistance) sensors by publishing ROS2 topics.

## Loading and starting

First, import the module into your project's `platformio.ini`:

```
lib_deps =
    ...
    https://github.com/xopxe/micro_rosso_bme680.git
```

Then, in your `main.cpp`:

```
...
#include "micro_rosso_bme680.h"
EnvBME680 env;
...
void setup() {
  Wire.begin(I2C_SDA, I2C_SCL); // initialize I2C as needed
  ...
  env.setup(Wire); // pass the I2C to use
  ...
}
```

The setup method allows passing optional topic names and a different micro_rosso timer to change the publication rate (by default, it uses the 5Hz timer). It is declared as follows:

```
  static bool setup(TwoWire &wire = Wire,
                    const char *topic_temp = "/temperature",
                    const char *topic_humi = "/humidity",
                    const char *topic_pres = "/pressure",
                    const char *topic_gasr = "/gas_resistance",
                    timer_descriptor &timer_report = micro_rosso::timer_report);
```

## Using the module

The module emits the following topics:
* temperature: [sensor_msgs/msg/temperature](https://docs.ros2.org/foxy/api/sensor_msgs/msg/Temperature.html)
* humidity: [sensor_msgs/msg/relative_humidity](http://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/RelativeHumidity.html)
* pressure: [sensor_msgs/msg/fluid_pressure](http://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/RelativeHumidity.html)
* gas resistance: [std_msgs/msg/float32](http://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/RelativeHumidity.html)

## Authors and acknowledgment

jvisca@fing.edu.uy - [Grupo MINA](https://www.fing.edu.uy/inco/grupos/mina/), Facultad de Ingeniería - Udelar, 2024

## License

MIT


