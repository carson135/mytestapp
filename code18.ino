// update form hithub

int servopin=4;// first code
int myangle;//����Ƕȱ���
int pulsewidth;//�����������
int val;
void servopulse(int servopin,int myangle)//����һ�����庯��
{
pulsewidth=(myangle*11)+500;//���Ƕ�ת��Ϊ500-2480 ������ֵ
digitalWrite(servopin,HIGH);//������ӿڵ�ƽ����
delayMicroseconds(pulsewidth);//��ʱ����ֵ��΢����
digitalWrite(servopin,LOW);//������ӿڵ�ƽ����
delay(20-pulsewidth/1000);
}
void setup()
{
pinMode(servopin,OUTPUT);//�趨����ӿ�Ϊ����ӿ�
Serial.begin(9600);//���ӵ����ж˿ڣ�������Ϊ9600
Serial.println("servo=o_seral_simple ready" ) ;
}
void loop()//��0 ��9 ����ת��Ϊ0 ��180 �Ƕȣ�����LED ��˸��Ӧ���Ĵ���
{
val=Serial.read();//
if(val>'0'&&val<='9')
{
val=val-'0';//��������ת��Ϊ��ֵ����
val=val*(180/9);//������ת��Ϊ�Ƕ�
Serial.print("moving servo to ");
Serial.print(val,DEC);
Serial.println();
for(int i=0;i<=50;i++) //�������㹻��ʱ������ת��ָ���Ƕ�
{
servopulse(servopin,val);//�������庯��
}
}
}
