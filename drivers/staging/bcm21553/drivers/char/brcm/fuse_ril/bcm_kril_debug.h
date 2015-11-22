/****************************************************************************
*
*     Copyright (c) 2009 Broadcom Corporation
*
*   Unless you and Broadcom execute a separate written software license 
*   agreement governing use of this software, this software is licensed to you 
*   under the terms of the GNU General Public License version 2, available 
*    at http://www.gnu.org/licenses/old-licenses/gpl-2.0.html (the "GPL"). 
*
*   Notwithstanding the above, under no circumstances may you combine this 
*   software in any way with any other Broadcom software provided under a license 
*   other than the GPL, without Broadcom's express prior written consent.
*
****************************************************************************/

#ifndef _BCM_KRIL_DEBUG_H
#define _BCM_KRIL_DEBUG_H
#include "bcmlog.h"

#ifdef CONFIG_BRCM_UNIFIED_LOGGING
#define DBG_ERROR    BCMLOG_ANDROID_KRIL_BASIC
#define DBG_INFO       BCMLOG_ANDROID_KRIL_BASIC
#define DBG_TRACE     BCMLOG_ANDROID_KRIL_DETAIL
#define DBG_TRACE2   BCMLOG_ANDROID_KRIL_DETAIL

#define KRIL_DEBUG(level,fmt,args...) BCMLOG_Printf(level, fmt, ##args);

#else

#define DBG_ERROR	0x01
#define DBG_INFO	0x02
#define DBG_TRACE	0x04
#define DBG_TRACE2	0x08
#define DBG_DATA	0x10
#define DBG_DATA2	0x20

#define DBG_DEFAULT_LEVEL	(DBG_ERROR)
//#define DBG_DEFAULT_LEVEL	(DBG_ERROR|DBG_INFO|DBG_TRACE|DBG_TRACE2)

#define KRIL_DEBUG(level,fmt,args...) do { if (level & logLevel) printk( "%s:: " fmt, __FUNCTION__, ##args ); } while (0)
//#define KRIL_DEBUG(level,fmt,args...)

static int logLevel = DBG_DEFAULT_LEVEL;
#endif
#endif //_BCM_KRIL_DEBUG_H
