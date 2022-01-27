# ESP32 QR Code Reader

## Limitations

- Need an ESP32 module with PSRAM - See below.

## Compatible Hardware

The QR Code recognition lib required a lot of memory, so I was only able to get this to work with an ESP32 that has PSRRAM available and also the Quirc library is modified to use that directly.

- [ESP32](https://espressif.com/en/products/hardware/esp32/overview) module
- PSRAM Available
- Camera module - Tested with OV2640

ESP32 modules with camera that have PSRAM and should work:

- CAMERA_MODEL_WROVER_KIT
- CAMERA_MODEL_ESP_EYE
- CAMERA_MODEL_M5STACK_PSRAM
- CAMERA_MODEL_M5STACK_V2_PSRAM
- CAMERA_MODEL_M5STACK_WIDE
- CAMERA_MODEL_AI_THINKER

ESP32 modules without PSRAM that will not work:

- CAMERA_MODEL_M5STACK_ESP32CAM
- CAMERA_MODEL_TTGO_T_JOURNAL

## License

This code is released under the MIT License.

### References

- https://github.com/dlbeer/quirc
- https://github.com/sipeed/MaixPy
- https://github.com/Schaggo/QR-ARDUINO
- https://github.com/donny681/ESP32_CAMERA_QR
- https://github.com/alvarowolfx/ESP32QRCodeReader
