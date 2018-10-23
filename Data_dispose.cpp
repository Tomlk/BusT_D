#include "Data_dispose.h"

double Data_dispose::window_data[20] = {0};
//Unit_N 区域内的单元个数 4：每个单元有4个测温点  每个测温点能保存历史的20次数据来作图
double Data_dispose::Window_data[Uinit_N][4][20] = { {{0}} };
Data_dispose::Data_dispose()
{
	//初始化数据

}


Data_dispose::~Data_dispose()
{
}
