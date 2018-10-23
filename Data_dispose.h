#pragma once
//#define Uinit_N 100
class Data_dispose
{
public:
	Data_dispose();
	~Data_dispose();
public:
	//static const string SERVER_IP = "172.20.10.2";
  //  static const  QString SERVER_PORT = "8080";
	static const int Uinit_N = 100;
	static double window_data[20];
	static double Window_data[Uinit_N][4][20];
};

