// alog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#if 0
#define SYNC_LOG_CNT             1000
#define SYNC_LOG_MEMOVER_CNT     50

typedef struct 
{
	INT32U logCnt;
	EPON_SYNC_LOG_DATA syncLogs[SYNC_LOG_CNT];
}EPON_SYNC_LOG;

EPON_SYNC_LOG s_EponSyncLog;

void Epon_Sync_Log_Add(EPON_SYNC_LOG_DATA*pLogData)
{
   INT32U i = 0;
   INT32U syncLogCnt = 0;
   
	syncLogCnt = s_EponSyncLog.logCnt;
	if(syncLogCnt>=SYNC_LOG_CNT)
	{
        /*��������������ǰ�ƶ�50����¼��Ϊ�¼�¼�ڳ��ռ�*/
		memmove(s_EponSyncLog.syncLogs,
                s_EponSyncLog.syncLogs + SYNC_LOG_MEMOVER_CNT,
                (SYNC_LOG_CNT-SYNC_LOG_MEMOVER_CNT) * sizeof(EPON_SYNC_LOG_DATA));
        /*������ڳ����Ŀռ�*/
		memset(s_EponSyncLog.syncLogs + (SYNC_LOG_CNT - SYNC_LOG_MEMOVER_CNT),
               0, SYNC_LOG_MEMOVER_CNT * sizeof(EPON_SYNC_LOG_DATA));
        /*д�뵱ǰһ����־*/
		memmove(s_EponSyncLog.syncLogs + (SYNC_LOG_CNT - SYNC_LOG_MEMOVER_CNT),
                pLogData, sizeof(EPON_SYNC_LOG_DATA));
        s_EponSyncLog.logCnt = SYNC_LOG_CNT - SYNC_LOG_MEMOVER_CNT + 1;

		return;
	}
	/*����������пռ䣬��ֱ��д�뵱ǰһ����¼*/
    memmove(s_EponSyncLog.syncLogs + syncLogCnt, pLogData, sizeof(EPON_SYNC_LOG_DATA));
	s_EponSyncLog.logCnt++;
}
#endif

#define MAX_DIRTY_POINT   4
#define MAX_BMP_WIDTH      1600
#define MAX_BMP_HEIGHT     1200

typedef struct tagPOINT
{
    int x,y;
}POINT;

typedef struct tagRESULT
{
    POINT pts[MAX_DIRTY_POINT];/*��¼��������ǰ4�����λ��*/
    int count;
}RESULT;

/*8������*/
POINT dir[] = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };

void SearchDirty(char bmp[MAX_BMP_WIDTH][MAX_BMP_HEIGHT], 
                 int x, int y, RESULT *result)
{
    for(int i = 0; i < sizeof(dir)/sizeof(dir[0]); i++)
    {
        int nx = x + dir[i].x;
        int ny = y + dir[i].y;
        if( (nx >= 0 && nx < MAX_BMP_WIDTH) 
            && (ny >= 0 && nx < MAX_BMP_HEIGHT) 
            && (bmp[nx][ny] == 1) )
        {
            if(result->count < MAX_DIRTY_POINT)
            {
                /*��¼ǰMAX_DIRTY_POINT�����λ��*/
                result->pts[result->count].x = nx;
                result->pts[result->count].x = ny;
            }
            result->count++;
            if(result->count > MAX_DIRTY_POINT)
                break;

            SearchDirty(bmp, nx, ny, result);
        }
    }
}

int main(int argc, char* argv[])
{
	return 0;
}

