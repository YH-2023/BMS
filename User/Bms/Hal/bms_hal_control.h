#ifndef __BMS_HAL_CONTROL_H__
#define __BMS_HAL_CONTROL_H__



#include "bms_type.h"

// 定义 GPIO 端口和引脚，需要根据实际硬件连接进行修改
#define ENERGY_RECOVERY_GPIO_PORT GPIOA
#define ENERGY_RECOVERY_GPIO_PIN GPIO_PIN_0


void BMS_HalCtrlWakeup(void);
void BMS_HalCtrlSleep(void);
void BMS_HalCtrlDischarge(BMS_StateTypedef NewState);
void BMS_HalCtrlCharge(BMS_StateTypedef NewState);
void BMS_HalCtrlCellsBalance(BMS_CellIndexTypedef CellIndex, BMS_StateTypedef NewState);
void BMS_HalCtrlEnergyRecovery(BMS_StateTypedef NewState);



#endif


