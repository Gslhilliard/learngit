//-------------------------------------------------------------------//
//*******************************************************************//
///////////////////////////////////////////////////////////////////////
//////////////////////////////电机设置/////////////////////////////////
///////////////////////////////////////////////////////////////////////
 
#define leftA_PIN 5
#define leftB_PIN 6
#define righA_PIN 9
#define righB_PIN 10
void motor_pinint( );     //引脚初始化
void forward( );          //前进
void back( );             //后退
void turnLeftOrigin( );   //原地左
void turnRightOrigin( );  //原地右
void turnRightforword( ); //右前
void turnLeftforword( );  //左前
void turnLeftback( );     //左后
void turnRightback( );    //右后
void _stop();             //停车
 
//-------------------------------------------------------------------//
//*******************************************************************//
///////////////////////////////////////////////////////////////////////
//////////////////////////////蓝牙遥控/////////////////////////////////
///////////////////////////////////////////////////////////////////////
int receive;
void reve(void);
 
//----------------------------------------------------------------//
 
void setup()
{
  Serial.begin(9600); //串口波特率9600（手机端使用）
  motor_pinint( );
}
void loop()
{
   reve();
}
 
void reve(void)
{
          receive=Serial.parseInt();
       if(receive==7)     {forward( )         ;delay(500);_stop();}//前进
  else if(receive==6)     {back( )            ;delay(500);_stop();}//后退
  else if(receive==1)     {_stop()            ;delay(500);_stop();}//停车
  else if(receive==3)     {turnLeftforword( ) ;delay(500);_stop();}//左前
  else if(receive==2)     {turnRightforword( );delay(500);_stop();}//右前
  else if(receive==5)     {turnLeftback( )    ;delay(500);_stop();}//左后
  else if(receive==4)     {turnRightback( )   ;delay(500);_stop();}//右后
  else if(receive==8)     {turnLeftOrigin( )  ;delay(250);_stop();}//原地左
  else if(receive==9)     {turnRightOrigin( ) ;delay(250);_stop();}//原地右
}
 
/*电机引脚初始化*/
void motor_pinint( )
{
  pinMode (leftA_PIN, OUTPUT); //设置引脚为输出引脚
  pinMode (leftB_PIN, OUTPUT); //设置引脚为输出引脚
  pinMode (righA_PIN, OUTPUT); //设置引脚为输出引脚
  pinMode (righB_PIN, OUTPUT); //设置引脚为输出引脚
  }
/**************************************************
forward子函数——前进子函数
函数功能：控制车前进
**************************************************/
void forward( )
{
  analogWrite(leftA_PIN,180);      
  analogWrite(leftB_PIN,0);         //左轮前进
  analogWrite(righA_PIN,180);      
  analogWrite(righB_PIN,0);         //右轮前进
}
/**************************************************
back子函数——后退子函数
函数功能：控制车后退
**************************************************/
void back( )
{
  analogWrite(leftA_PIN,0);      
  analogWrite(leftB_PIN,180);        //左轮后退
  analogWrite(righA_PIN,0);      
  analogWrite(righB_PIN,180);        //右轮后退
}
/**************************************************
turnLeftOrigin子函数——原地左转子函数
函数功能：控制车原地左转
**************************************************/
void turnLeftOrigin( )
{
  analogWrite(leftA_PIN,0);      
  analogWrite(leftB_PIN,120);        //左轮后退
  analogWrite(righA_PIN,120);      
  analogWrite(righB_PIN,0);          //右轮前进
}
/**************************************************
turnRightOrigin子函数——原地右转子函数
函数功能：控制车原地右转
**************************************************/
void turnRightOrigin( )
{
  analogWrite(leftA_PIN,120);      
  analogWrite(leftB_PIN,0);        //左轮前进
  analogWrite(righA_PIN,0);      
  analogWrite(righB_PIN,120);      //右轮后退
}
/**************************************************
turnRightforword子函数——右前运动子函数
函数功能：控制车右前
**************************************************/
void turnRightforword( )
{
  analogWrite(leftA_PIN,200);      
  analogWrite(leftB_PIN,0);        //左轮快前进
  analogWrite(righA_PIN,120);      
  analogWrite(righB_PIN,0);        //右轮慢前进
}
/**************************************************
turnLeftforword子函数——左前运动子函数
函数功能：控制车左前
**************************************************/
void turnLeftforword( )
{
  analogWrite(leftA_PIN,120);      
  analogWrite(leftB_PIN,0);       //左轮慢前进
  analogWrite(righA_PIN,200);      
  analogWrite(righB_PIN,0);       //右轮快前进
}
/**************************************************
turnRightforword子函数——右后运动子函数
函数功能：控制车右后
**************************************************/
void turnRightback( )
{
  analogWrite(leftA_PIN,0);      
  analogWrite(leftB_PIN,200);        //左轮快后退
  analogWrite(righA_PIN,0);      
  analogWrite(righB_PIN,120);        //右轮慢后退
}
/**************************************************
turnLeftforword子函数——左后运动子函数
函数功能：控制车左后
**************************************************/
void turnLeftback( )
{
  analogWrite(leftA_PIN,0);      
  analogWrite(leftB_PIN,120);        //左轮慢后退
  analogWrite(righA_PIN,0);      
  analogWrite(righB_PIN,200);        //右轮快后退
}
/**************************************************
stop子函数—停止子函数
函数功能：控制车停止
**************************************************/
void _stop()
{
  analogWrite(leftA_PIN,0);      
  analogWrite(leftB_PIN,0);         //左轮静止不动
  analogWrite(righA_PIN,0);      
  analogWrite(righB_PIN,0);         //右轮静止不动
}
