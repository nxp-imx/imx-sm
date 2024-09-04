Debug Monitor {#MONITOR}
=============

If the SM is compiled using the M=1|2 option (default is M=1) then it will include
a debug monitor. The debug monitor allows command-line interaction via the SM
debug UART. Inclusion of the debug monitor affects SM timing and therefore should never
be deployed in a product!

- M=0 no monitor
- M=1 will drop straight into the monitor at boot
- M=2 will enter the monitor on SM debug UART character reception

**Use of the debug monitor can change timing and cause adverse effects. No guarantees
are made with regards to its use. M=0 is the only valid option for production.**

Note the terminal needs to be in a mode that sends CR or LF for a new line (not
CR+LF).

The monitor can asynchronously display error messages including exception and fault
reporting. See @ref PORT_NXP_PRINT.

Many monitor commands take numeric aguments. These conform to C standards and as such if
they start with a 0 are octal and if 0x are hex.

The following commands are supported. Arguments are in *italics*. Optional arguments are
in [].

General Commands
----------------

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| ?                           | list commands                                                |
| help                        | list commands                                                |
| exit                        | exit the debug monitor                                       |
| quit                        | exit the debug monitor                                       |

Info Commands
-------------

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| info                        | display SM/SoC info like unique ID, etc.                     |
| ele info                    | display ELE info like FW version, lifecycle, etc.            |
| err                         | display logged errors (API or RDC captured), clears log      |
| btime                       | display boot time info                                       |
| trdc.raw *rdc* [*did*]      | raw dump of TRDC *rdc*, limit to *did* if specified          |
| trdc *rdc* [*did*]          | formatted dump of TRDC *rdc*, limit to *did* if specified    |
| syslog [*flags*]            | display syslog, flags and log device specific                |
| gcov                        | dump GCOV data if build with GCOV=1                          |

System Commands
---------------

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| reason                      | display reset reason for the system                          |
| shutdown [gful]             | power off system (optional graceful flag)                    |
| reset [gful]                | request system reset (optional graceful flag)                |
| stage primary [container]   | set boot stage to primary and reset                          |
| stage secondary [container] | set boot stage to secondary  and reset                       |
| stage recovery [container]  | set boot stage to recovery  and reset                        |
| stage serial[container]     | set boot stage to serial  and reset                          |
| suspend                     | request all LM suspend (sleep)                               |
| wake                        | request all LM wake (resume)                                 |
| ssm *mode* *flags*          | set SM system sleep mode/flags (used for system sleep)       |
| idle                        | enter SM idle (system suspend if all LM in suspend)          |
| wdog warm                   | configure wdog to generate warm reset                        |
| wdog cold                   | configure wdog to generate warm reset and drive WDOG_ANY     |
| wdog irq                    | configure wdog to drive WDOG_ANY                             |
| wdog off                    | turn off the watchdog                                        |
| wdog trigger                | trigger the watchdog                                         |
| fault *id*                  | trigger the *id* fault                                       |
| assert *status*             | assert with status *status*                                  |

Logical Machine Commands
------------------------

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| lm info                     | display info for all logical machines                        |
| lm *lm* default             | set default LM to *lm*                                       |
| lm [*lm*] boot              | boot LM (default unless *lm* specified)                      |
| lm [*lm*] shutdown [gful]   | power off LM (default unless *lm* specified)                 |
| lm [*lm*] reset [rs] [gful] | reset/reboot LM with reason *rs* (default unless *lm* spec)  |
| lm [*lm*] suspend           | suspend LM (default unless *lm* specified)                   |
| lm [*lm*] wake              | wake LM (default unless *lm* specified)                      |
| lm [*lm*] reason            | display reset reason for LM (default unless *lm* specified)  |
| lm [*lm*] power             | power up an LM (default unless *lm* specified)               |

The output of reason commands on NXP board ports is described in the @ref PORT_NXP_PRINT
section.

Group Commands
--------------

These operate on groups of LM as defined by the SM config.

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| grp [*grp*] boot            | boot LM group (0 unless *grp* specified)                     |
| grp [*grp*] shutdown [gful] | power off LM group (optional grp=0 and graceful flag)        |
| grp [*grp*] reset [gful]    | reset/reboot LM group (optional grp=0 and graceful flag)     |

Resource Commands
-----------------

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| power.r [*domain*]          | read/get power mode of *domain* (default = all)              |
| power.w *domain* *state*    | set power mode of *domain* to *state* (off, on)              |
| perf.r                      | display level/rate for all performance domains               |
| perf.w *domain* *level*     | set *level* for performance *domain*                         |
| clock.r                     | display rate/enable for all clocks                           |
| clock.r range               | display range for all clocks                                 |
| clock.r parent              | display parents for all clocks                               |
| clock.r ext *ext*           | display extended data for type *ext* for all clocks          |
| clock.w *clock* *state*     | enable/display *clock* (on = enable, off = disable)          |
| clock.w *clock* reparent *parent* | set parent for *clock* to *parent*                     |
| clock.w *clock* rate *rate* | set rate for *clock* to *rate*                               |
| clock.w *clock* ext *ext* *extConfigValue* | set extended configuration for type *ext*     |
| clock.reset *clock*         | reset *clock* to boot state                                  |
| sensor.r                    | display all sensor values                                    |
| sensor.w *sensor*           | enable/display *sensor* (on = enable, off = disable)         |
| volt.r                      | display mode/microvolts for all voltage domains              |
| volt.w *domain* *mode/uV*   | set *mode/microvolts* for voltage *domain*                   |
| bb.r rtc                    | display time in seconds for all RTC                          |
| bb.r ticks                  | display time in ticks for all RTC                            |
| bb.r gpr [*gpr*]            | display value for GPR *gpr*, default to display all          |
| bb.w rtc *rtc* *sec*        | set RTC *rtc* to time *sec* seconds                          |
| bb.w ticks *rtc* *tick*     | set RTC *rtc* to time *tick* ticks                           |
| bb.w gpr *gpr* *value*      | set GPR *gpr* to *value*                                     |
| cpu.r                       | display mode/vector for all CPUs                             |
| cpu.w *cpu* start           | start CPU *cpu*                                              |
| cpu.w *cpu* hold            | hold CPU *cpu*                                               |
| cpu.w *cpu* stop            | stop CPU *cpu*                                               |
| cpu.w *cpu* vector *addr*   | set boot vectors for CPU *cpu*                               |
| ctrl.r                      | display values for all controls                              |
| ctrl.w *ctrl* *list...*     | set *list* values for *ctrl* control                         |
| ctrl.notify *ctrl* *flags*  | set notify flags to *flags* for *ctrl* control               |

Data R/W Commands
-----------------

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| md[.l] *address* [*count*]  | display *count* 32-bit values at *address*                   |
| md.w *address* [*count*]    | display *count* 16-bit values at *address*                   |
| md.b *address* [*count*]    | display *count* 8-bit values at *address*                    |
| mm[.l] *address value*      | modify 32-bit value  at *address*                            |
| mm.w *address value*        | modify 16-bit value at *address*                             |
| mm.b *address value*        | modify 8-bit  value at *address*                             |

Fuse Commands
-------------

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| fuse.r *wordIdx*            | display fuse *wordIdx* (if possible)                         |
| fuse.w *wordIdx* *value*    | write *value* to fuse *wordIdx* (if possible)                |

Board Commands
--------------

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| pmic.r *i2c_id reg*         | read pmic register (i.e. pmic.r 0x8 0x1)                     |
| custom                      | call BRD_SM_Custom()                                         |

