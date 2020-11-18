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


由此以上可知順時針與逆時針旋轉時，兩個腳位的狀態變化
###### 順時針旋轉時

| pluse  | AVout |BVout
| ------------- |:-------------:|:-------------:|
| 1      | 1|0|
| 2      | 1|1|
| 3      | 0|1|
| 4      | 0|0|
###### 逆時針旋轉時

| pluse  | AVout |BVout
| ------------- |:-------------:|:-------------:|
| 1      | 0|1|
| 2      | 1|1|
| 3      | 1|0|
| 4      | 0|0|



#### 程式碼部份
`flagA`與`flagB`兩個變數用來判別現在是在順時針旋轉還是逆時針旋轉

若是由AVout先觸發，改變狀態成為1，就是順時針旋轉，`flagA`改變成1，`flagB`維持0

若是由BVout先觸發，改變狀態成為1，就是逆時針旋轉，`flagB`改變成1，`flagA`維持0

透過`flagA`與`flagB`狀態去控制主要計數變數`count`是要++ or --

並在兩個都同時結束時的狀態：AVout與BVout狀態都為0時，將`flagA  flagB`歸零

