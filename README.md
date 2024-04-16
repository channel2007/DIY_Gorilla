# 前言
自製Game&Watch大金剛

# 成品測試影片
<a href="https://youtu.be/6KFh7SLxClU" target="_blank"><img src="https://github.com/channel2007/DIY_DonkeyKong/blob/master/picture/DIY_DonkeyKong.png" 
alt="播放影片" width="640" height="480" border="10" /></a>

# 準備材料
* Raspberry pi PICO雙核心RP2040  x 1
* 3.2吋SPI串列埠TFT液晶顯示器模組ILI9341驅動LCD觸控螢幕240*320  x 2
* DS3231 高精度I2C實時時鐘 (RTC)  x 1
* PAM8302 2.5W 單通道 D類 音頻功率 放大器模塊  x 1
* 小喇叭揚聲器 1W2瓦4R8歐  x 1
* 輕觸開關 輕觸按鍵 輕觸微動開關 6 x 6 高度 4.3mm  x 8

# 線路圖
* 接線圖
* ![alt DonkeyKong](https://github.com/channel2007/DIY_DonkeyKong/blob/master/picture/circuitDiagram_1.jpg "DonkeyKong")

* 接線說明
* ![alt DonkeyKong](https://github.com/channel2007/DIY_DonkeyKong/blob/master/picture/circuitDiagram_2.jpg "DonkeyKong")

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

# 操作方法
* 上下左右：移動
* A：跳
* GAME A：難度1
* GAME B：難度2
* TIME：顯示時間模式，遊戲中：音效開關

# 密技
* 按住GAME A+GAME B+TIME在按上：無敵開關
* 按住GAME A+GAME B+TIME在按下：自動玩開關

# 官方粉絲團
[無限升級](https://www.facebook.com/unlimited.upgrade)
