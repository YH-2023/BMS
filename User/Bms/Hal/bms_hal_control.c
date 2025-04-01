#include "bms_hal_control.h"


#include "drv_softi2c_bq769x0.h"

#include "bms_debug.h"


// BMS����
void BMS_HalCtrlWakeup(void)
{
	BQ769X0_Wakeup();
}

// ����BMS����˯��ģʽ
void BMS_HalCtrlSleep(void)
{
	BQ769X0_EntryShip();
}

// ���Ʒŵ�״̬
void BMS_HalCtrlDischarge(BMS_StateTypedef NewState)
{
	BQ769X0_ControlDSGOrCHG(DSG_CONTROL, (BQ769X0_StateTypedef)NewState);
}

// ���Ƴ��״̬
void BMS_HalCtrlCharge(BMS_StateTypedef NewState)
{
	BQ769X0_ControlDSGOrCHG(CHG_CONTROL, (BQ769X0_StateTypedef)NewState);
}

// ���Ƶ��ڻ��ڵ�о����,������֧��32��
void BMS_HalCtrlCellsBalance(BMS_CellIndexTypedef CellIndex, BMS_StateTypedef NewState)
{
	BQ769X0_CellBalanceControl((BQ769X0_CellIndexTypedef)CellIndex, (BQ769X0_StateTypedef)NewState);
}
// ������������װ�õ���ͣ

void BMS_HalCtrlEnergyRecovery(BMS_StateTypedef NewState)
{
	BQ769X0_ControlEnergyRecovery(ENERGY_RECOVERY_CONTROL, (BQ769X0_StateTypedef)NewState);
	if (NewState == BMS_STATE_ENABLE)
	{
		BMS_INFO("Energy Recovery Enabled");
	}
	else
	{
		BMS_INFO("Energy Recovery Disabled");
	}
}

