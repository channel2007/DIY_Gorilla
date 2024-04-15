# 前言
  自製Game&Watch大金剛

# 準備材料
* Raspberry pi PICO雙核心RP2040  x 1
* 3.2吋SPI串列埠TFT液晶顯示器模組ILI9341驅動LCD觸控螢幕240*320  x 2
* DS3231 高精度I2C實時時鐘 (RTC)  x 1
* PAM8302 2.5W 單通道 D類 音頻功率 放大器模塊  x 1
* 小喇叭揚聲器 1W2瓦4R8歐  x 1
* 輕觸開關 輕觸按鍵 輕觸微動開關 6 x 6 高度 4.3mm  x 8

# 線路圖


# 安裝函數庫
* [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)
  * 開啟User_Setup.h檔案修改以下參數
  * //#define TFT_MISO 19
  * //#define TFT_CS   15
  * //#define TFT_RST  -1
  * #define TFT_RST  21
  * #define TFT_DC   20
  * #define TFT_MOSI 19
  * #define TFT_SCLK 18
* [DS3231](https://github.com/NorthernWidget/DS3231)
* [ESP8266Audio](https://github.com/earlephilhower/ESP8266Audio)

# 官方粉絲團
[無限升級](https://www.facebook.com/unlimited.upgrade)
