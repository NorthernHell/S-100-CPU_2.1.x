/**************************************************************************
File:               isaafb_package.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
***************************************************************************
Attached documents: 

***************************************************************************
Description:			Package identification

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/
#ifndef _ISAAFB_PACKAGE_H /* nested Headers management */
#define _ISAAFB_PACKAGE_H

/* include item definition */

#include "now.h" /* "now */
#include "matrix.h" /* "matrix */
#include "ipidcontroller.h" /* "ipidcontroller */
#include "gettimestring.h" /* "get_time_string */
#include "setpoint.h" /* "setpoint */
#include "ratio.h" /* "ratio */
#include "gettimestruct.h" /* "get_time_struct */
#include "trackandhold.h" /* "trackandhold */
#include "leadlagcontroller.h" /* "leadlagcontroller */
#include "leadlagbacontroller.h" /* "leadlagbacontroller */
#include "characterizer.h" /* "characterizer */
#include "setpriority.h" /* "set_priority */
#include "scaler.h" /* "scaler */
#include "bias.h" /* "bias */
#include "ratiocalibration.h" /* "ratiocalibration */
#include "transferswitch.h" /* "transferswitch */
#include "digitalalarm.h" /* "digitalalarm */
#include "batchswitch.h" /* "batchswitch */
#include "analogalarm.h" /* "analogalarm */
#include "comparator.h" /* "comparator */
#include "ratelimiter.h" /* "ratelimiter */
#include "limiter.h" /* "limiter */
#include "signalselector.h" /* "signalselector */
#include "retentiveontimer.h" /* "retentiveontimer */
#include "batchtotalizer.h" /* "batchtotalizer */
#include "flipflop.h" /* "flipflop */
#include "biascalibration.h" /* "biascalibration */
#include "pid_al.h" /* "pid_al */

/* package definition */

#define ISA_DECLARE_PACK_ISAAFB \
ISA_DECLARE_PACKNAME("isaafb_package") \
ISA_DECLARE_HANDLE("nowFblClassInit", nowFblClassInit) \
ISA_DECLARE_HANDLE("nowFblClassExit", nowFblClassExit) \
ISA_DECLARE_HANDLE("nowFblInstInit", nowFblInstInit) \
ISA_DECLARE_HANDLE("nowFblInstExit", nowFblInstExit) \
ISA_DECLARE_HANDLE("nowFblCall", nowFblCall) \
ISA_DECLARE_HANDLE("matrixFblClassInit", matrixFblClassInit) \
ISA_DECLARE_HANDLE("matrixFblClassExit", matrixFblClassExit) \
ISA_DECLARE_HANDLE("matrixFblInstInit", matrixFblInstInit) \
ISA_DECLARE_HANDLE("matrixFblInstExit", matrixFblInstExit) \
ISA_DECLARE_HANDLE("matrixFblCall", matrixFblCall) \
ISA_DECLARE_HANDLE("ipidcontrollerFblClassInit", ipidcontrollerFblClassInit) \
ISA_DECLARE_HANDLE("ipidcontrollerFblClassExit", ipidcontrollerFblClassExit) \
ISA_DECLARE_HANDLE("ipidcontrollerFblInstInit", ipidcontrollerFblInstInit) \
ISA_DECLARE_HANDLE("ipidcontrollerFblInstExit", ipidcontrollerFblInstExit) \
ISA_DECLARE_HANDLE("ipidcontrollerFblCall", ipidcontrollerFblCall) \
ISA_DECLARE_HANDLE("get_time_stringUsfCall", get_time_stringUsfCall) \
ISA_DECLARE_HANDLE("setpointFblClassInit", setpointFblClassInit) \
ISA_DECLARE_HANDLE("setpointFblClassExit", setpointFblClassExit) \
ISA_DECLARE_HANDLE("setpointFblInstInit", setpointFblInstInit) \
ISA_DECLARE_HANDLE("setpointFblInstExit", setpointFblInstExit) \
ISA_DECLARE_HANDLE("setpointFblCall", setpointFblCall) \
ISA_DECLARE_HANDLE("ratioFblClassInit", ratioFblClassInit) \
ISA_DECLARE_HANDLE("ratioFblClassExit", ratioFblClassExit) \
ISA_DECLARE_HANDLE("ratioFblInstInit", ratioFblInstInit) \
ISA_DECLARE_HANDLE("ratioFblInstExit", ratioFblInstExit) \
ISA_DECLARE_HANDLE("ratioFblCall", ratioFblCall) \
ISA_DECLARE_HANDLE("get_time_structFblClassInit", get_time_structFblClassInit) \
ISA_DECLARE_HANDLE("get_time_structFblClassExit", get_time_structFblClassExit) \
ISA_DECLARE_HANDLE("get_time_structFblInstInit", get_time_structFblInstInit) \
ISA_DECLARE_HANDLE("get_time_structFblInstExit", get_time_structFblInstExit) \
ISA_DECLARE_HANDLE("get_time_structFblCall", get_time_structFblCall) \
ISA_DECLARE_HANDLE("trackandholdFblClassInit", trackandholdFblClassInit) \
ISA_DECLARE_HANDLE("trackandholdFblClassExit", trackandholdFblClassExit) \
ISA_DECLARE_HANDLE("trackandholdFblInstInit", trackandholdFblInstInit) \
ISA_DECLARE_HANDLE("trackandholdFblInstExit", trackandholdFblInstExit) \
ISA_DECLARE_HANDLE("trackandholdFblCall", trackandholdFblCall) \
ISA_DECLARE_HANDLE("leadlagcontrollerFblClassInit", leadlagcontrollerFblClassInit) \
ISA_DECLARE_HANDLE("leadlagcontrollerFblClassExit", leadlagcontrollerFblClassExit) \
ISA_DECLARE_HANDLE("leadlagcontrollerFblInstInit", leadlagcontrollerFblInstInit) \
ISA_DECLARE_HANDLE("leadlagcontrollerFblInstExit", leadlagcontrollerFblInstExit) \
ISA_DECLARE_HANDLE("leadlagcontrollerFblCall", leadlagcontrollerFblCall) \
ISA_DECLARE_HANDLE("leadlagbacontrollerFblClassInit", leadlagbacontrollerFblClassInit) \
ISA_DECLARE_HANDLE("leadlagbacontrollerFblClassExit", leadlagbacontrollerFblClassExit) \
ISA_DECLARE_HANDLE("leadlagbacontrollerFblInstInit", leadlagbacontrollerFblInstInit) \
ISA_DECLARE_HANDLE("leadlagbacontrollerFblInstExit", leadlagbacontrollerFblInstExit) \
ISA_DECLARE_HANDLE("leadlagbacontrollerFblCall", leadlagbacontrollerFblCall) \
ISA_DECLARE_HANDLE("characterizerFblClassInit", characterizerFblClassInit) \
ISA_DECLARE_HANDLE("characterizerFblClassExit", characterizerFblClassExit) \
ISA_DECLARE_HANDLE("characterizerFblInstInit", characterizerFblInstInit) \
ISA_DECLARE_HANDLE("characterizerFblInstExit", characterizerFblInstExit) \
ISA_DECLARE_HANDLE("characterizerFblCall", characterizerFblCall) \
ISA_DECLARE_HANDLE("set_priorityUsfCall", set_priorityUsfCall) \
ISA_DECLARE_HANDLE("scalerFblClassInit", scalerFblClassInit) \
ISA_DECLARE_HANDLE("scalerFblClassExit", scalerFblClassExit) \
ISA_DECLARE_HANDLE("scalerFblInstInit", scalerFblInstInit) \
ISA_DECLARE_HANDLE("scalerFblInstExit", scalerFblInstExit) \
ISA_DECLARE_HANDLE("scalerFblCall", scalerFblCall) \
ISA_DECLARE_HANDLE("biasFblClassInit", biasFblClassInit) \
ISA_DECLARE_HANDLE("biasFblClassExit", biasFblClassExit) \
ISA_DECLARE_HANDLE("biasFblInstInit", biasFblInstInit) \
ISA_DECLARE_HANDLE("biasFblInstExit", biasFblInstExit) \
ISA_DECLARE_HANDLE("biasFblCall", biasFblCall) \
ISA_DECLARE_HANDLE("ratiocalibrationFblClassInit", ratiocalibrationFblClassInit) \
ISA_DECLARE_HANDLE("ratiocalibrationFblClassExit", ratiocalibrationFblClassExit) \
ISA_DECLARE_HANDLE("ratiocalibrationFblInstInit", ratiocalibrationFblInstInit) \
ISA_DECLARE_HANDLE("ratiocalibrationFblInstExit", ratiocalibrationFblInstExit) \
ISA_DECLARE_HANDLE("ratiocalibrationFblCall", ratiocalibrationFblCall) \
ISA_DECLARE_HANDLE("transferswitchFblClassInit", transferswitchFblClassInit) \
ISA_DECLARE_HANDLE("transferswitchFblClassExit", transferswitchFblClassExit) \
ISA_DECLARE_HANDLE("transferswitchFblInstInit", transferswitchFblInstInit) \
ISA_DECLARE_HANDLE("transferswitchFblInstExit", transferswitchFblInstExit) \
ISA_DECLARE_HANDLE("transferswitchFblCall", transferswitchFblCall) \
ISA_DECLARE_HANDLE("digitalalarmFblClassInit", digitalalarmFblClassInit) \
ISA_DECLARE_HANDLE("digitalalarmFblClassExit", digitalalarmFblClassExit) \
ISA_DECLARE_HANDLE("digitalalarmFblInstInit", digitalalarmFblInstInit) \
ISA_DECLARE_HANDLE("digitalalarmFblInstExit", digitalalarmFblInstExit) \
ISA_DECLARE_HANDLE("digitalalarmFblCall", digitalalarmFblCall) \
ISA_DECLARE_HANDLE("batchswitchFblClassInit", batchswitchFblClassInit) \
ISA_DECLARE_HANDLE("batchswitchFblClassExit", batchswitchFblClassExit) \
ISA_DECLARE_HANDLE("batchswitchFblInstInit", batchswitchFblInstInit) \
ISA_DECLARE_HANDLE("batchswitchFblInstExit", batchswitchFblInstExit) \
ISA_DECLARE_HANDLE("batchswitchFblCall", batchswitchFblCall) \
ISA_DECLARE_HANDLE("analogalarmFblClassInit", analogalarmFblClassInit) \
ISA_DECLARE_HANDLE("analogalarmFblClassExit", analogalarmFblClassExit) \
ISA_DECLARE_HANDLE("analogalarmFblInstInit", analogalarmFblInstInit) \
ISA_DECLARE_HANDLE("analogalarmFblInstExit", analogalarmFblInstExit) \
ISA_DECLARE_HANDLE("analogalarmFblCall", analogalarmFblCall) \
ISA_DECLARE_HANDLE("comparatorFblClassInit", comparatorFblClassInit) \
ISA_DECLARE_HANDLE("comparatorFblClassExit", comparatorFblClassExit) \
ISA_DECLARE_HANDLE("comparatorFblInstInit", comparatorFblInstInit) \
ISA_DECLARE_HANDLE("comparatorFblInstExit", comparatorFblInstExit) \
ISA_DECLARE_HANDLE("comparatorFblCall", comparatorFblCall) \
ISA_DECLARE_HANDLE("ratelimiterFblClassInit", ratelimiterFblClassInit) \
ISA_DECLARE_HANDLE("ratelimiterFblClassExit", ratelimiterFblClassExit) \
ISA_DECLARE_HANDLE("ratelimiterFblInstInit", ratelimiterFblInstInit) \
ISA_DECLARE_HANDLE("ratelimiterFblInstExit", ratelimiterFblInstExit) \
ISA_DECLARE_HANDLE("ratelimiterFblCall", ratelimiterFblCall) \
ISA_DECLARE_HANDLE("limiterFblClassInit", limiterFblClassInit) \
ISA_DECLARE_HANDLE("limiterFblClassExit", limiterFblClassExit) \
ISA_DECLARE_HANDLE("limiterFblInstInit", limiterFblInstInit) \
ISA_DECLARE_HANDLE("limiterFblInstExit", limiterFblInstExit) \
ISA_DECLARE_HANDLE("limiterFblCall", limiterFblCall) \
ISA_DECLARE_HANDLE("signalselectorFblClassInit", signalselectorFblClassInit) \
ISA_DECLARE_HANDLE("signalselectorFblClassExit", signalselectorFblClassExit) \
ISA_DECLARE_HANDLE("signalselectorFblInstInit", signalselectorFblInstInit) \
ISA_DECLARE_HANDLE("signalselectorFblInstExit", signalselectorFblInstExit) \
ISA_DECLARE_HANDLE("signalselectorFblCall", signalselectorFblCall) \
ISA_DECLARE_HANDLE("retentiveontimerFblClassInit", retentiveontimerFblClassInit) \
ISA_DECLARE_HANDLE("retentiveontimerFblClassExit", retentiveontimerFblClassExit) \
ISA_DECLARE_HANDLE("retentiveontimerFblInstInit", retentiveontimerFblInstInit) \
ISA_DECLARE_HANDLE("retentiveontimerFblInstExit", retentiveontimerFblInstExit) \
ISA_DECLARE_HANDLE("retentiveontimerFblCall", retentiveontimerFblCall) \
ISA_DECLARE_HANDLE("batchtotalizerFblClassInit", batchtotalizerFblClassInit) \
ISA_DECLARE_HANDLE("batchtotalizerFblClassExit", batchtotalizerFblClassExit) \
ISA_DECLARE_HANDLE("batchtotalizerFblInstInit", batchtotalizerFblInstInit) \
ISA_DECLARE_HANDLE("batchtotalizerFblInstExit", batchtotalizerFblInstExit) \
ISA_DECLARE_HANDLE("batchtotalizerFblCall", batchtotalizerFblCall) \
ISA_DECLARE_HANDLE("flipflopFblClassInit", flipflopFblClassInit) \
ISA_DECLARE_HANDLE("flipflopFblClassExit", flipflopFblClassExit) \
ISA_DECLARE_HANDLE("flipflopFblInstInit", flipflopFblInstInit) \
ISA_DECLARE_HANDLE("flipflopFblInstExit", flipflopFblInstExit) \
ISA_DECLARE_HANDLE("flipflopFblCall", flipflopFblCall) \
ISA_DECLARE_HANDLE("biascalibrationFblClassInit", biascalibrationFblClassInit) \
ISA_DECLARE_HANDLE("biascalibrationFblClassExit", biascalibrationFblClassExit) \
ISA_DECLARE_HANDLE("biascalibrationFblInstInit", biascalibrationFblInstInit) \
ISA_DECLARE_HANDLE("biascalibrationFblInstExit", biascalibrationFblInstExit) \
ISA_DECLARE_HANDLE("biascalibrationFblCall", biascalibrationFblCall) \
ISA_DECLARE_HANDLE("pid_alFblClassInit", pid_alFblClassInit) \
ISA_DECLARE_HANDLE("pid_alFblClassExit", pid_alFblClassExit) \
ISA_DECLARE_HANDLE("pid_alFblInstInit", pid_alFblInstInit) \
ISA_DECLARE_HANDLE("pid_alFblInstExit", pid_alFblInstExit) \
ISA_DECLARE_HANDLE("pid_alFblCall", pid_alFblCall)

#endif /* _ISAAFB_PACKAGE_H */

/* eof ********************************************************************/

