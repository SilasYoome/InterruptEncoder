# InterruptEncoder
# 使用外部中斷執行編碼器

## 硬體與接腳

使用Arduino MEGA 2560，使用其中斷腳2、3

編碼器Vcc、GND、VAout、VBout

對接方式：

Encoder &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Arduino     
Vcc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;>>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5V

GND&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;>>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GND

VAout&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;>>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;D2

VBout&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;>>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;D3

## 編碼器運作原理與程式碼解說
編碼器具有兩隻位於不同準位的感測腳，我們命名為A與B，

若是順時針旋轉編碼器，感測腳A號會優先感測到，之後才是B腳感測；

相反的，若是逆時針旋轉編碼器，則是先由感測腳B感測，然後是A感測腳。

因此順時針與逆時針時的輸出波形如下： 

![image](https://github.com/SilasYoome/InterruptEncoder/blob/main/1920px-Quadrature_Diagram.svg.png)


