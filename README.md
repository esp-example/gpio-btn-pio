# ESP32 GPIO Button example

example output

```
I (325) main_task: Started on CPU0
I (335) main_task: Calling app_main()
I (335) button: IoT Button Version: 3.4.0
I (335) gpio: GPIO[0]| InputEn: 1| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (345) main_task: Returned from app_main()
I (18985) GPIO-BTN: button event: long press
I (24485) GPIO-BTN: button event: short press
```

## How to build PlatformIO based project


```shell
# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Build specific environment
$ pio run -e esp32dev

# Upload firmware for the specific environment
$ pio run -e esp32dev --target upload

# Clean build files
$ pio run --target clean
```