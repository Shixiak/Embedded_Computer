/*esp32 数字输入
 * 本例用来演示digitalRead()，也就是数字读的使用方法。esp32中的数字读与arduino uno是类似的。
 * 数字读，也叫数字输入，数字采样。用来检测一个电路中，某一个点相对于地的电平高低。
 * 使用ESP32C3开发板。
 * 电路连接方式是使用一个自恢复按键开关（pushbutton)和一个3.3K电阻（其它阻值也可以，建议1K以上）串联形成一个电路。电路的一端接入GND，也就是0V。另一端接入VCC，ESP开发板上是3.3V。
 * 然后从开关和电阻连接的点，引出一个导线，接入端口2（其它端口也可以）。
 * GND ------- button ------ 电阻 ------- 3.3V
 *                      |
 *                      |
 *                   GPIO 2
 * 
 * 效果：打开串口查看器，观察数据。默认显示0或者1（如上图连接，就是1，如果互换GND和3.3V，就是0），按下按钮，数字变为0。
 * 1代表检测到电路此处电平为高电平，0代表检测到此处为低电平。
 * 
 * by bloomlj ， codes2things team ,2022.9.9
*/

//定义一个测量用的端口
#define BUTTONPIN 2

//初始化一个全局变量，用来存储按钮的状态。
int in;

void setup() {
  // put your setup code here, to run once:
  //设置端口为输入。
  pinMode(BUTTONPIN,INPUT);
  //以9600波特率，打开串口
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //数字读设置好的端口，存到in。
  in = digitalRead(BUTTONPIN);
  //串口输出in（也就是发送给电脑），这样在电脑上的Arduino IDE上可以看到in的结果了。
  Serial.println(in);
  //延迟以下，等待硬件执行
  delay(100);

}
