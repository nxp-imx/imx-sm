SCMI Protocol {#SCMI_PROTO}
=============

The system manager (SM) implements the platform side of the SCMI protocol as defined in the
[ARM SCMI Spec](@ref DOCS). Implementation details can be found here:

- [SCMI protocol module](@ref scmi_proto) - agent side (reference API)
- [RPC_SCMI module](@ref RPC_SCMI) - platform side

NXP has created some vendor extension protocols as allowed by the spec. These all have a
protocol ID >= 0x80.

Many messages have access controls defined in the [configuration data](@ref CONFIGURATION). These
limit which agents can can send a message. Violation usually results in a return status of
::SCMI_ERR_DENIED.

The table below lists all the supported protocols and messages. All required messages are support
and some of the optional messages are supported.

| Protocol | Protocol<BR>ID | Message | Message<BR>ID | Access<BR>Control |
|---|---|---|---|---|
| Base | 0x10 | [PROTOCOL_VERSION](@ref SCMI_PROTO_BASE_PROTOCOL_VERSION) | 0x0 |  |
| Base | 0x10 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_BASE_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Base | 0x10 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_BASE_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Base | 0x10 | [BASE_DISCOVER_VENDOR](@ref SCMI_PROTO_BASE_BASE_DISCOVER_VENDOR) | 0x3 |  |
| Base | 0x10 | [BASE_DISCOVER_SUB_VENDOR](@ref SCMI_PROTO_BASE_BASE_DISCOVER_SUB_VENDOR) | 0x4 |  |
| Base | 0x10 | [BASE_DISCOVER_IMPLEMENTATION_VERSION](@ref SCMI_PROTO_BASE_BASE_DISCOVER_IMPLEMENTATION_VERSION) | 0x5 |  |
| Base | 0x10 | [BASE_DISCOVER_LIST_PROTOCOLS](@ref SCMI_PROTO_BASE_BASE_DISCOVER_LIST_PROTOCOLS) | 0x6 |  |
| Base | 0x10 | [BASE_DISCOVER_AGENT](@ref SCMI_PROTO_BASE_BASE_DISCOVER_AGENT) | 0x7 |  |
| Base | 0x10 | [BASE_SET_DEVICE_PERMISSIONS](@ref SCMI_PROTO_BASE_BASE_SET_DEVICE_PERMISSIONS) | 0x9 | PRIV |
| Base | 0x10 | [BASE_RESET_AGENT_CONFIGURATION](@ref SCMI_PROTO_BASE_BASE_RESET_AGENT_CONFIGURATION) | 0xB | PRIV |
| Base | 0x10 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_BASE_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Power | 0x11 | [PROTOCOL_VERSION](@ref SCMI_PROTO_POWER_PROTOCOL_VERSION) | 0x0 |  |
| Power | 0x11 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_POWER_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Power | 0x11 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_POWER_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Power | 0x11 | [POWER_DOMAIN_ATTRIBUTES](@ref SCMI_PROTO_POWER_POWER_DOMAIN_ATTRIBUTES) | 0x3 |  |
| Power | 0x11 | [POWER_STATE_SET](@ref SCMI_PROTO_POWER_POWER_STATE_SET) | 0x4 | SET |
| Power | 0x11 | [POWER_STATE_GET](@ref SCMI_PROTO_POWER_POWER_STATE_GET) | 0x5 |  |
| Power | 0x11 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_POWER_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Sys | 0x12 | [PROTOCOL_VERSION](@ref SCMI_PROTO_SYS_PROTOCOL_VERSION) | 0x0 |  |
| Sys | 0x12 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_SYS_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Sys | 0x12 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_SYS_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Sys | 0x12 | [SYSTEM_POWER_STATE_SET](@ref SCMI_PROTO_SYS_SYSTEM_POWER_STATE_SET) | 0x3 | SET<BR>PRIV<BR>EXCLUSIVE |
| Sys | 0x12 | [SYSTEM_POWER_STATE_NOTIFY](@ref SCMI_PROTO_SYS_SYSTEM_POWER_STATE_NOTIFY) | 0x5 | NOTIFY |
| Sys | 0x12 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_SYS_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Sys\n(notification) | 0x12 | [SYSTEM_POWER_STATE_NOTIFIER](@ref SCMI_PROTO_SYS_SYSTEM_POWER_STATE_NOTIFIER) | 0x0 |  |
| Perf | 0x13 | [PROTOCOL_VERSION](@ref SCMI_PROTO_PERF_PROTOCOL_VERSION) | 0x0 |  |
| Perf | 0x13 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_PERF_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Perf | 0x13 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_PERF_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Perf | 0x13 | [PERFORMANCE_DOMAIN_ATTRIBUTES](@ref SCMI_PROTO_PERF_PERFORMANCE_DOMAIN_ATTRIBUTES) | 0x3 |  |
| Perf | 0x13 | [PERFORMANCE_DESCRIBE_LEVELS](@ref SCMI_PROTO_PERF_PERFORMANCE_DESCRIBE_LEVELS) | 0x4 |  |
| Perf | 0x13 | [PERFORMANCE_LIMITS_SET](@ref SCMI_PROTO_PERF_PERFORMANCE_LIMITS_SET) | 0x5 | SET |
| Perf | 0x13 | [PERFORMANCE_LIMITS_GET](@ref SCMI_PROTO_PERF_PERFORMANCE_LIMITS_GET) | 0x6 |  |
| Perf | 0x13 | [PERFORMANCE_LEVEL_SET](@ref SCMI_PROTO_PERF_PERFORMANCE_LEVEL_SET) | 0x7 | PRIV |
| Perf | 0x13 | [PERFORMANCE_LEVEL_GET](@ref SCMI_PROTO_PERF_PERFORMANCE_LEVEL_GET) | 0x8 |  |
| Perf | 0x13 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_PERF_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Clock | 0x14 | [PROTOCOL_VERSION](@ref SCMI_PROTO_CLOCK_PROTOCOL_VERSION) | 0x0 |  |
| Clock | 0x14 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_CLOCK_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Clock | 0x14 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_CLOCK_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Clock | 0x14 | [CLOCK_ATTRIBUTES](@ref SCMI_PROTO_CLOCK_CLOCK_ATTRIBUTES) | 0x3 |  |
| Clock | 0x14 | [CLOCK_DESCRIBE_RATES](@ref SCMI_PROTO_CLOCK_CLOCK_DESCRIBE_RATES) | 0x4 |  |
| Clock | 0x14 | [CLOCK_RATE_SET](@ref SCMI_PROTO_CLOCK_CLOCK_RATE_SET) | 0x5 | EXCLUSIVE |
| Clock | 0x14 | [CLOCK_RATE_GET](@ref SCMI_PROTO_CLOCK_CLOCK_RATE_GET) | 0x6 |  |
| Clock | 0x14 | [CLOCK_CONFIG_SET](@ref SCMI_PROTO_CLOCK_CLOCK_CONFIG_SET) | 0x7 | SET |
| Clock | 0x14 | [CLOCK_CONFIG_GET](@ref SCMI_PROTO_CLOCK_CLOCK_CONFIG_GET) | 0xB |  |
| Clock | 0x14 | [CLOCK_POSSIBLE_PARENTS_GET](@ref SCMI_PROTO_CLOCK_CLOCK_POSSIBLE_PARENTS_GET) | 0xC |  |
| Clock | 0x14 | [CLOCK_PARENT_SET](@ref SCMI_PROTO_CLOCK_CLOCK_PARENT_SET) | 0xD | EXCLUSIVE |
| Clock | 0x14 | [CLOCK_PARENT_GET](@ref SCMI_PROTO_CLOCK_CLOCK_PARENT_GET) | 0xE |  |
| Clock | 0x14 | [CLOCK_GET_PERMISSIONS](@ref SCMI_PROTO_CLOCK_CLOCK_GET_PERMISSIONS) | 0xF |  |
| Clock | 0x14 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_CLOCK_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Sensor | 0x15 | [PROTOCOL_VERSION](@ref SCMI_PROTO_SENSOR_PROTOCOL_VERSION) | 0x0 |  |
| Sensor | 0x15 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_SENSOR_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Sensor | 0x15 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_SENSOR_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Sensor | 0x15 | [SENSOR_DESCRIPTION_GET](@ref SCMI_PROTO_SENSOR_SENSOR_DESCRIPTION_GET) | 0x3 |  |
| Sensor | 0x15 | [SENSOR_TRIP_POINT_NOTIFY](@ref SCMI_PROTO_SENSOR_SENSOR_TRIP_POINT_NOTIFY) | 0x4 | NOTIFY |
| Sensor | 0x15 | [SENSOR_TRIP_POINT_CONFIG](@ref SCMI_PROTO_SENSOR_SENSOR_TRIP_POINT_CONFIG) | 0x5 | EXCLUSIVE |
| Sensor | 0x15 | [SENSOR_READING_GET](@ref SCMI_PROTO_SENSOR_SENSOR_READING_GET) | 0x6 |  |
| Sensor | 0x15 | [SENSOR_CONFIG_GET](@ref SCMI_PROTO_SENSOR_SENSOR_CONFIG_GET) | 0x9 |  |
| Sensor | 0x15 | [SENSOR_CONFIG_SET](@ref SCMI_PROTO_SENSOR_SENSOR_CONFIG_SET) | 0xA | SET |
| Sensor | 0x15 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_SENSOR_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Sensor\n(notification) | 0x15 | [SENSOR_TRIP_POINT_EVENT](@ref SCMI_PROTO_SENSOR_SENSOR_TRIP_POINT_EVENT) | 0x0 |  |
| Reset | 0x16 | [PROTOCOL_VERSION](@ref SCMI_PROTO_RESET_PROTOCOL_VERSION) | 0x0 |  |
| Reset | 0x16 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_RESET_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Reset | 0x16 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_RESET_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Reset | 0x16 | [RESET_DOMAIN_ATTRIBUTES](@ref SCMI_PROTO_RESET_RESET_DOMAIN_ATTRIBUTES) | 0x3 |  |
| Reset | 0x16 | [RESET](@ref SCMI_PROTO_RESET_RESET) | 0x4 | EXCLUSIVE |
| Reset | 0x16 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_RESET_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Voltage | 0x17 | [PROTOCOL_VERSION](@ref SCMI_PROTO_VOLTAGE_PROTOCOL_VERSION) | 0x0 |  |
| Voltage | 0x17 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_VOLTAGE_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Voltage | 0x17 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_VOLTAGE_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Voltage | 0x17 | [VOLTAGE_DOMAIN_ATTRIBUTES](@ref SCMI_PROTO_VOLTAGE_VOLTAGE_DOMAIN_ATTRIBUTES) | 0x3 |  |
| Voltage | 0x17 | [VOLTAGE_DESCRIBE_LEVELS](@ref SCMI_PROTO_VOLTAGE_VOLTAGE_DESCRIBE_LEVELS) | 0x4 |  |
| Voltage | 0x17 | [VOLTAGE_CONFIG_SET](@ref SCMI_PROTO_VOLTAGE_VOLTAGE_CONFIG_SET) | 0x5 | SET |
| Voltage | 0x17 | [VOLTAGE_CONFIG_GET](@ref SCMI_PROTO_VOLTAGE_VOLTAGE_CONFIG_GET) | 0x6 |  |
| Voltage | 0x17 | [VOLTAGE_LEVEL_SET](@ref SCMI_PROTO_VOLTAGE_VOLTAGE_LEVEL_SET) | 0x7 | EXCLUSIVE |
| Voltage | 0x17 | [VOLTAGE_LEVEL_GET](@ref SCMI_PROTO_VOLTAGE_VOLTAGE_LEVEL_GET) | 0x8 |  |
| Voltage | 0x17 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_VOLTAGE_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Pinctrl | 0x19 | [PROTOCOL_VERSION](@ref SCMI_PROTO_PINCTRL_PROTOCOL_VERSION) | 0x0 |  |
| Pinctrl | 0x19 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_PINCTRL_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Pinctrl | 0x19 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_PINCTRL_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Pinctrl | 0x19 | [PINCTRL_ATTRIBUTES](@ref SCMI_PROTO_PINCTRL_PINCTRL_ATTRIBUTES) | 0x3 |  |
| Pinctrl | 0x19 | [PINCTRL_SETTINGS_GET](@ref SCMI_PROTO_PINCTRL_PINCTRL_SETTINGS_GET) | 0x5 |  |
| Pinctrl | 0x19 | [PINCTRL_SETTINGS_CONFIGURE](@ref SCMI_PROTO_PINCTRL_PINCTRL_SETTINGS_CONFIGURE) | 0x6 | EXCLUSIVE |
| Pinctrl | 0x19 | [PINCTRL_REQUEST](@ref SCMI_PROTO_PINCTRL_PINCTRL_REQUEST) | 0x7 | EXCLUSIVE |
| Pinctrl | 0x19 | [PINCTRL_RELEASE](@ref SCMI_PROTO_PINCTRL_PINCTRL_RELEASE) | 0x8 |  |
| Pinctrl | 0x19 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_PINCTRL_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Lmm | 0x80 | [PROTOCOL_VERSION](@ref SCMI_PROTO_LMM_PROTOCOL_VERSION) | 0x0 |  |
| Lmm | 0x80 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_LMM_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Lmm | 0x80 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_LMM_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Lmm | 0x80 | [LMM_ATTRIBUTES](@ref SCMI_PROTO_LMM_LMM_ATTRIBUTES) | 0x3 | NONE<BR>GET |
| Lmm | 0x80 | [LMM_BOOT](@ref SCMI_PROTO_LMM_LMM_BOOT) | 0x4 | PRIV |
| Lmm | 0x80 | [LMM_RESET](@ref SCMI_PROTO_LMM_LMM_RESET) | 0x5 | PRIV |
| Lmm | 0x80 | [LMM_SHUTDOWN](@ref SCMI_PROTO_LMM_LMM_SHUTDOWN) | 0x6 | PRIV |
| Lmm | 0x80 | [LMM_WAKE](@ref SCMI_PROTO_LMM_LMM_WAKE) | 0x7 | SET |
| Lmm | 0x80 | [LMM_SUSPEND](@ref SCMI_PROTO_LMM_LMM_SUSPEND) | 0x8 | PRIV |
| Lmm | 0x80 | [LMM_NOTIFY](@ref SCMI_PROTO_LMM_LMM_NOTIFY) | 0x9 | NOTIFY |
| Lmm | 0x80 | [LMM_RESET_REASON](@ref SCMI_PROTO_LMM_LMM_RESET_REASON) | 0xA | GET |
| Lmm | 0x80 | [LMM_POWER_ON](@ref SCMI_PROTO_LMM_LMM_POWER_ON) | 0xB | PRIV |
| Lmm | 0x80 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_LMM_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Lmm\n(notification) | 0x80 | [LMM_EVENT](@ref SCMI_PROTO_LMM_LMM_EVENT) | 0x0 |  |
| Bbm | 0x81 | [PROTOCOL_VERSION](@ref SCMI_PROTO_BBM_PROTOCOL_VERSION) | 0x0 |  |
| Bbm | 0x81 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_BBM_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Bbm | 0x81 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_BBM_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Bbm | 0x81 | [BBM_GPR_SET](@ref SCMI_PROTO_BBM_BBM_GPR_SET) | 0x3 | EXCLUSIVE |
| Bbm | 0x81 | [BBM_GPR_GET](@ref SCMI_PROTO_BBM_BBM_GPR_GET) | 0x4 | GET |
| Bbm | 0x81 | [BBM_RTC_ATTRIBUTES](@ref SCMI_PROTO_BBM_BBM_RTC_ATTRIBUTES) | 0x5 |  |
| Bbm | 0x81 | [BBM_RTC_TIME_SET](@ref SCMI_PROTO_BBM_BBM_RTC_TIME_SET) | 0x6 | EXCLUSIVE |
| Bbm | 0x81 | [BBM_RTC_TIME_GET](@ref SCMI_PROTO_BBM_BBM_RTC_TIME_GET) | 0x7 |  |
| Bbm | 0x81 | [BBM_RTC_ALARM_SET](@ref SCMI_PROTO_BBM_BBM_RTC_ALARM_SET) | 0x8 | PRIV |
| Bbm | 0x81 | [BBM_BUTTON_GET](@ref SCMI_PROTO_BBM_BBM_BUTTON_GET) | 0x9 |  |
| Bbm | 0x81 | [BBM_RTC_NOTIFY](@ref SCMI_PROTO_BBM_BBM_RTC_NOTIFY) | 0xA | NOTIFY |
| Bbm | 0x81 | [BBM_BUTTON_NOTIFY](@ref SCMI_PROTO_BBM_BBM_BUTTON_NOTIFY) | 0xB | NOTIFY |
| Bbm | 0x81 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_BBM_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Bbm\n(notification) | 0x81 | [BBM_RTC_EVENT](@ref SCMI_PROTO_BBM_BBM_RTC_EVENT) | 0x0 |  |
| Bbm\n(notification) | 0x81 | [BBM_BUTTON_EVENT](@ref SCMI_PROTO_BBM_BBM_BUTTON_EVENT) | 0x1 |  |
| Cpu | 0x82 | [PROTOCOL_VERSION](@ref SCMI_PROTO_CPU_PROTOCOL_VERSION) | 0x0 |  |
| Cpu | 0x82 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_CPU_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Cpu | 0x82 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_CPU_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Cpu | 0x82 | [CPU_ATTRIBUTES](@ref SCMI_PROTO_CPU_CPU_ATTRIBUTES) | 0x3 |  |
| Cpu | 0x82 | [CPU_START](@ref SCMI_PROTO_CPU_CPU_START) | 0x4 | EXCLUSIVE |
| Cpu | 0x82 | [CPU_STOP](@ref SCMI_PROTO_CPU_CPU_STOP) | 0x5 | EXCLUSIVE |
| Cpu | 0x82 | [CPU_RESET_VECTOR_SET](@ref SCMI_PROTO_CPU_CPU_RESET_VECTOR_SET) | 0x6 | EXCLUSIVE |
| Cpu | 0x82 | [CPU_SLEEP_MODE_SET](@ref SCMI_PROTO_CPU_CPU_SLEEP_MODE_SET) | 0x7 | EXCLUSIVE |
| Cpu | 0x82 | [CPU_IRQ_WAKE_SET](@ref SCMI_PROTO_CPU_CPU_IRQ_WAKE_SET) | 0x8 | EXCLUSIVE |
| Cpu | 0x82 | [CPU_NON_IRQ_WAKE_SET](@ref SCMI_PROTO_CPU_CPU_NON_IRQ_WAKE_SET) | 0x9 | EXCLUSIVE |
| Cpu | 0x82 | [CPU_PD_LPM_CONFIG_SET](@ref SCMI_PROTO_CPU_CPU_PD_LPM_CONFIG_SET) | 0xA | EXCLUSIVE |
| Cpu | 0x82 | [CPU_PER_LPM_CONFIG_SET](@ref SCMI_PROTO_CPU_CPU_PER_LPM_CONFIG_SET) | 0xB | EXCLUSIVE |
| Cpu | 0x82 | [CPU_INFO_GET](@ref SCMI_PROTO_CPU_CPU_INFO_GET) | 0xC |  |
| Cpu | 0x82 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_CPU_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Fusa | 0x83 | [PROTOCOL_VERSION](@ref SCMI_PROTO_FUSA_PROTOCOL_VERSION) | 0x0 |  |
| Fusa | 0x83 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_FUSA_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Fusa | 0x83 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_FUSA_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Fusa | 0x83 | [FUSA_FEENV_STATE_GET](@ref SCMI_PROTO_FUSA_FUSA_FEENV_STATE_GET) | 0x3 | GET |
| Fusa | 0x83 | [FUSA_FEENV_STATE_NOTIFY](@ref SCMI_PROTO_FUSA_FUSA_FEENV_STATE_NOTIFY) | 0x5 | NOTIFY |
| Fusa | 0x83 | [FUSA_SEENV_STATE_GET](@ref SCMI_PROTO_FUSA_FUSA_SEENV_STATE_GET) | 0x6 |  |
| Fusa | 0x83 | [FUSA_SEENV_STATE_SET](@ref SCMI_PROTO_FUSA_FUSA_SEENV_STATE_SET) | 0x7 |  |
| Fusa | 0x83 | [FUSA_FAULT_GET](@ref SCMI_PROTO_FUSA_FUSA_FAULT_GET) | 0x8 | GET |
| Fusa | 0x83 | [FUSA_FAULT_SET](@ref SCMI_PROTO_FUSA_FUSA_FAULT_SET) | 0x9 | EXCLUSIVE |
| Fusa | 0x83 | [FUSA_FAULT_GROUP_NOTIFY](@ref SCMI_PROTO_FUSA_FUSA_FAULT_GROUP_NOTIFY) | 0xA | NOTIFY |
| Fusa | 0x83 | [FUSA_SCHECK_EVNTRIG](@ref SCMI_PROTO_FUSA_FUSA_SCHECK_EVNTRIG) | 0xB |  |
| Fusa | 0x83 | [FUSA_SCHECK_TEST_EXEC](@ref SCMI_PROTO_FUSA_FUSA_SCHECK_TEST_EXEC) | 0xE | EXCLUSIVE |
| Fusa | 0x83 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_FUSA_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Fusa\n(notification) | 0x83 | [FUSA_FEENV_STATE_EVENT](@ref SCMI_PROTO_FUSA_FUSA_FEENV_STATE_EVENT) | 0x0 | EXCLUSIVE |
| Fusa\n(notification) | 0x83 | [FUSA_SEENV_STATE_REQ_EVENT](@ref SCMI_PROTO_FUSA_FUSA_SEENV_STATE_REQ_EVENT) | 0x1 |  |
| Fusa\n(notification) | 0x83 | [FUSA_FAULT_EVENT](@ref SCMI_PROTO_FUSA_FUSA_FAULT_EVENT) | 0x2 |  |
| Misc | 0x84 | [PROTOCOL_VERSION](@ref SCMI_PROTO_MISC_PROTOCOL_VERSION) | 0x0 |  |
| Misc | 0x84 | [PROTOCOL_ATTRIBUTES](@ref SCMI_PROTO_MISC_PROTOCOL_ATTRIBUTES) | 0x1 |  |
| Misc | 0x84 | [PROTOCOL_MESSAGE_ATTRIBUTES](@ref SCMI_PROTO_MISC_PROTOCOL_MESSAGE_ATTRIBUTES) | 0x2 |  |
| Misc | 0x84 | [MISC_CONTROL_SET](@ref SCMI_PROTO_MISC_MISC_CONTROL_SET) | 0x3 | EXCLUSIVE |
| Misc | 0x84 | [MISC_CONTROL_GET](@ref SCMI_PROTO_MISC_MISC_CONTROL_GET) | 0x4 | GET |
| Misc | 0x84 | [MISC_CONTROL_ACTION](@ref SCMI_PROTO_MISC_MISC_CONTROL_ACTION) | 0x5 | EXCLUSIVE |
| Misc | 0x84 | [MISC_DISCOVER_BUILD_INFO](@ref SCMI_PROTO_MISC_MISC_DISCOVER_BUILD_INFO) | 0x6 |  |
| Misc | 0x84 | [MISC_ROM_PASSOVER_GET](@ref SCMI_PROTO_MISC_MISC_ROM_PASSOVER_GET) | 0x7 |  |
| Misc | 0x84 | [MISC_CONTROL_NOTIFY](@ref SCMI_PROTO_MISC_MISC_CONTROL_NOTIFY) | 0x8 | NOTIFY |
| Misc | 0x84 | [MISC_REASON_ATTRIBUTES](@ref SCMI_PROTO_MISC_MISC_REASON_ATTRIBUTES) | 0x9 |  |
| Misc | 0x84 | [MISC_RESET_REASON](@ref SCMI_PROTO_MISC_MISC_RESET_REASON) | 0xA |  |
| Misc | 0x84 | [MISC_SI_INFO](@ref SCMI_PROTO_MISC_MISC_SI_INFO) | 0xB |  |
| Misc | 0x84 | [MISC_CFG_INFO](@ref SCMI_PROTO_MISC_MISC_CFG_INFO) | 0xC |  |
| Misc | 0x84 | [MISC_SYSLOG](@ref SCMI_PROTO_MISC_MISC_SYSLOG) | 0xD |  |
| Misc | 0x84 | [NEGOTIATE_PROTOCOL_VERSION](@ref SCMI_PROTO_MISC_NEGOTIATE_PROTOCOL_VERSION) | 0x10 |  |
| Misc\n(notification) | 0x84 | [MISC_CONTROL_EVENT](@ref SCMI_PROTO_MISC_MISC_CONTROL_EVENT) | 0x0 |  |

SCMI Payloads {#SCMI_PAYLOADS}
=============

## Base: PROTOCOL_VERSION ## {#SCMI_PROTO_BASE_PROTOCOL_VERSION}

See SCMI_BaseProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x0                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Base: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_BASE_PROTOCOL_ATTRIBUTES}

See SCMI_BaseProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x1                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x1                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Base: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_BASE_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_BaseProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Base: BASE_DISCOVER_VENDOR ## {#SCMI_PROTO_BASE_BASE_DISCOVER_VENDOR}

See SCMI_BaseDiscoverVendor() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x3                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint8          | vendor_identifier[16]                                        |
    ---------------------------------------------------------------------------------

## Base: BASE_DISCOVER_SUB_VENDOR ## {#SCMI_PROTO_BASE_BASE_DISCOVER_SUB_VENDOR}

See SCMI_BaseDiscoverSubVendor() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x4                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint8          | vendor_identifier[16]                                        |
    ---------------------------------------------------------------------------------

## Base: BASE_DISCOVER_IMPLEMENTATION_VERSION ## {#SCMI_PROTO_BASE_BASE_DISCOVER_IMPLEMENTATION_VERSION}

See SCMI_BaseDiscoverImplementationVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x5                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | implementation_version                                       |
    ---------------------------------------------------------------------------------

## Base: BASE_DISCOVER_LIST_PROTOCOLS ## {#SCMI_PROTO_BASE_BASE_DISCOVER_LIST_PROTOCOLS}

See SCMI_BaseDiscoverListProtocols() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | uint32         | skip                                                         |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | num_protocols                                                |
    ---------------------------------------------------------------------------------
    | uint32         | protocols[N]                                                 |
    ---------------------------------------------------------------------------------

## Base: BASE_DISCOVER_AGENT ## {#SCMI_PROTO_BASE_BASE_DISCOVER_AGENT}

See SCMI_BaseDiscoverAgent() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | uint32         | agent_id                                                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | agent_id                                                     |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Base: BASE_SET_DEVICE_PERMISSIONS ## {#SCMI_PROTO_BASE_BASE_SET_DEVICE_PERMISSIONS}

See SCMI_BaseSetDevicePermissions() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x9                     |
    ---------------------------------------------------------------------------------
    | uint32         | agent_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | device_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x9                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Base: BASE_RESET_AGENT_CONFIGURATION ## {#SCMI_PROTO_BASE_BASE_RESET_AGENT_CONFIGURATION}

See SCMI_BaseResetAgentConfiguration() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0xB                     |
    ---------------------------------------------------------------------------------
    | uint32         | agent_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0xB                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Base: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_BASE_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_BaseNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x90/0x10, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Power: PROTOCOL_VERSION ## {#SCMI_PROTO_POWER_PROTOCOL_VERSION}

See SCMI_PowerProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x0                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Power: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_POWER_PROTOCOL_ATTRIBUTES}

See SCMI_PowerProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x1                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x1                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | statistics_address_low                                       |
    ---------------------------------------------------------------------------------
    | uint32         | statistics_address_high                                      |
    ---------------------------------------------------------------------------------
    | uint32         | statistics_len                                               |
    ---------------------------------------------------------------------------------

## Power: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_POWER_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_PowerProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Power: POWER_DOMAIN_ATTRIBUTES ## {#SCMI_PROTO_POWER_POWER_DOMAIN_ATTRIBUTES}

See SCMI_PowerDomainAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Power: POWER_STATE_SET ## {#SCMI_PROTO_POWER_POWER_STATE_SET}

See SCMI_PowerStateSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | power_state                                                  |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Power: POWER_STATE_GET ## {#SCMI_PROTO_POWER_POWER_STATE_GET}

See SCMI_PowerStateGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | power_state                                                  |
    ---------------------------------------------------------------------------------

## Power: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_POWER_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_PowerNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x91/0x11, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Sys: PROTOCOL_VERSION ## {#SCMI_PROTO_SYS_PROTOCOL_VERSION}

See SCMI_SysProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x0                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Sys: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_SYS_PROTOCOL_ATTRIBUTES}

See SCMI_SysProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x1                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x1                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Sys: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_SYS_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_SysProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Sys: SYSTEM_POWER_STATE_SET ## {#SCMI_PROTO_SYS_SYSTEM_POWER_STATE_SET}

See SCMI_SystemPowerStateSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | system_state                                                 |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Sys: SYSTEM_POWER_STATE_NOTIFY ## {#SCMI_PROTO_SYS_SYSTEM_POWER_STATE_NOTIFY}

See SCMI_SystemPowerStateNotify() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | uint32         | notify_enable                                                |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Sys: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_SYS_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_SysNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x92/0x12, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Sys: SYSTEM_POWER_STATE_NOTIFIER ## {#SCMI_PROTO_SYS_SYSTEM_POWER_STATE_NOTIFIER}

See SCMI_SystemPowerStateNotifier() for details.

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x92/0x12, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | uint32         | agent_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | system_state                                                 |
    ---------------------------------------------------------------------------------
    | uint32         | timeout                                                      |
    ---------------------------------------------------------------------------------

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x92/0x12, msg=0x0                     |
    ---------------------------------------------------------------------------------

## Perf: PROTOCOL_VERSION ## {#SCMI_PROTO_PERF_PROTOCOL_VERSION}

See SCMI_PerfProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x0                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Perf: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_PERF_PROTOCOL_ATTRIBUTES}

See SCMI_PerfProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x1                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x1                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | statistics_address_low                                       |
    ---------------------------------------------------------------------------------
    | uint32         | statistics_address_high                                      |
    ---------------------------------------------------------------------------------
    | uint32         | statistics_len                                               |
    ---------------------------------------------------------------------------------

## Perf: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_PERF_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_PerfProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Perf: PERFORMANCE_DOMAIN_ATTRIBUTES ## {#SCMI_PROTO_PERF_PERFORMANCE_DOMAIN_ATTRIBUTES}

See SCMI_PerformanceDomainAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | rate_limit                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | sustained_freq                                               |
    ---------------------------------------------------------------------------------
    | uint32         | sustained_perf_level                                         |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Perf: PERFORMANCE_DESCRIBE_LEVELS ## {#SCMI_PROTO_PERF_PERFORMANCE_DESCRIBE_LEVELS}

See SCMI_PerformanceDescribeLevels() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | skip_index                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | num_levels                                                   |
    ---------------------------------------------------------------------------------
    | PERF_LEVEL     | perf_levels[N]                                               |
    ---------------------------------------------------------------------------------

## Perf: PERFORMANCE_LIMITS_SET ## {#SCMI_PROTO_PERF_PERFORMANCE_LIMITS_SET}

See SCMI_PerformanceLimitsSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | range_max                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | range_min                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Perf: PERFORMANCE_LIMITS_GET ## {#SCMI_PROTO_PERF_PERFORMANCE_LIMITS_GET}

See SCMI_PerformanceLimitsGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | range_max                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | range_min                                                    |
    ---------------------------------------------------------------------------------

## Perf: PERFORMANCE_LEVEL_SET ## {#SCMI_PROTO_PERF_PERFORMANCE_LEVEL_SET}

See SCMI_PerformanceLevelSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | performance_level                                            |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Perf: PERFORMANCE_LEVEL_GET ## {#SCMI_PROTO_PERF_PERFORMANCE_LEVEL_GET}

See SCMI_PerformanceLevelGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x8                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x8                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | performance_level                                            |
    ---------------------------------------------------------------------------------

## Perf: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_PERF_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_PerfNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x93/0x13, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Clock: PROTOCOL_VERSION ## {#SCMI_PROTO_CLOCK_PROTOCOL_VERSION}

See SCMI_ClockProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x0                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Clock: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_CLOCK_PROTOCOL_ATTRIBUTES}

See SCMI_ClockProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x1                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x1                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Clock: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_CLOCK_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_ClockProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_ATTRIBUTES ## {#SCMI_PROTO_CLOCK_CLOCK_ATTRIBUTES}

See SCMI_ClockAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_DESCRIBE_RATES ## {#SCMI_PROTO_CLOCK_CLOCK_DESCRIBE_RATES}

See SCMI_ClockDescribeRates() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | rate_index                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | num_rates_flags                                              |
    ---------------------------------------------------------------------------------
    | CLOCK_RATE     | rates[N]                                                     |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_RATE_SET ## {#SCMI_PROTO_CLOCK_CLOCK_RATE_SET}

See SCMI_ClockRateSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------
    | CLOCK_RATE     | rate                                                         |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_RATE_GET ## {#SCMI_PROTO_CLOCK_CLOCK_RATE_GET}

See SCMI_ClockRateGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | CLOCK_RATE     | rate                                                         |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_CONFIG_SET ## {#SCMI_PROTO_CLOCK_CLOCK_CONFIG_SET}

See SCMI_ClockConfigSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | extended_config_val                                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_CONFIG_GET ## {#SCMI_PROTO_CLOCK_CLOCK_CONFIG_GET}

See SCMI_ClockConfigGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xB                     |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xB                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | config                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | extended_config_val                                          |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_POSSIBLE_PARENTS_GET ## {#SCMI_PROTO_CLOCK_CLOCK_POSSIBLE_PARENTS_GET}

See SCMI_ClockPossibleParentsGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xC                     |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | skip_parents                                                 |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xC                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | num_parents_flags                                            |
    ---------------------------------------------------------------------------------
    | uint32         | parents[N]                                                   |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_PARENT_SET ## {#SCMI_PROTO_CLOCK_CLOCK_PARENT_SET}

See SCMI_ClockParentSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xD                     |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | parent_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xD                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_PARENT_GET ## {#SCMI_PROTO_CLOCK_CLOCK_PARENT_GET}

See SCMI_ClockParentGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xE                     |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xE                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | parent_id                                                    |
    ---------------------------------------------------------------------------------

## Clock: CLOCK_GET_PERMISSIONS ## {#SCMI_PROTO_CLOCK_CLOCK_GET_PERMISSIONS}

See SCMI_ClockGetPermissions() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xF                     |
    ---------------------------------------------------------------------------------
    | uint32         | clock_id                                                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0xF                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | permissions                                                  |
    ---------------------------------------------------------------------------------

## Clock: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_CLOCK_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_ClockNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x94/0x14, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Sensor: PROTOCOL_VERSION ## {#SCMI_PROTO_SENSOR_PROTOCOL_VERSION}

See SCMI_SensorProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x0                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Sensor: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_SENSOR_PROTOCOL_ATTRIBUTES}

See SCMI_SensorProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x1                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x1                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_reg_address_low                                       |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_reg_address_high                                      |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_reg_len                                               |
    ---------------------------------------------------------------------------------

## Sensor: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_SENSOR_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_SensorProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Sensor: SENSOR_DESCRIPTION_GET ## {#SCMI_PROTO_SENSOR_SENSOR_DESCRIPTION_GET}

See SCMI_SensorDescriptionGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | uint32         | desc_index                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | num_sensor_flags                                             |
    ---------------------------------------------------------------------------------
    | SENSOR_DESC    | desc[N]                                                      |
    ---------------------------------------------------------------------------------

## Sensor: SENSOR_TRIP_POINT_NOTIFY ## {#SCMI_PROTO_SENSOR_SENSOR_TRIP_POINT_NOTIFY}

See SCMI_SensorTripPointNotify() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_event_control                                         |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Sensor: SENSOR_TRIP_POINT_CONFIG ## {#SCMI_PROTO_SENSOR_SENSOR_TRIP_POINT_CONFIG}

See SCMI_SensorTripPointConfig() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | trip_point_ev_ctrl                                           |
    ---------------------------------------------------------------------------------
    | int32          | trip_point_val_low                                           |
    ---------------------------------------------------------------------------------
    | int32          | trip_point_val_high                                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Sensor: SENSOR_READING_GET ## {#SCMI_PROTO_SENSOR_SENSOR_READING_GET}

See SCMI_SensorReadingGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | SENSOR_READING | readings[N]                                                  |
    ---------------------------------------------------------------------------------

## Sensor: SENSOR_CONFIG_GET ## {#SCMI_PROTO_SENSOR_SENSOR_CONFIG_GET}

See SCMI_SensorConfigGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x9                     |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x9                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_config                                                |
    ---------------------------------------------------------------------------------

## Sensor: SENSOR_CONFIG_SET ## {#SCMI_PROTO_SENSOR_SENSOR_CONFIG_SET}

See SCMI_SensorConfigSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0xA                     |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_config                                                |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0xA                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Sensor: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_SENSOR_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_SensorNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x95/0x15, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Sensor: SENSOR_TRIP_POINT_EVENT ## {#SCMI_PROTO_SENSOR_SENSOR_TRIP_POINT_EVENT}

See SCMI_SensorTripPointEvent() for details.

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x95/0x15, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | uint32         | agent_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | sensor_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | trip_point_desc                                              |
    ---------------------------------------------------------------------------------

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x95/0x15, msg=0x0                     |
    ---------------------------------------------------------------------------------

## Reset: PROTOCOL_VERSION ## {#SCMI_PROTO_RESET_PROTOCOL_VERSION}

See SCMI_ResetProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x0                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Reset: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_RESET_PROTOCOL_ATTRIBUTES}

See SCMI_ResetProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x1                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x1                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Reset: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_RESET_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_ResetProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Reset: RESET_DOMAIN_ATTRIBUTES ## {#SCMI_PROTO_RESET_RESET_DOMAIN_ATTRIBUTES}

See SCMI_ResetDomainAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | latency                                                      |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Reset: RESET ## {#SCMI_PROTO_RESET_RESET}

See SCMI_Reset() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | reset_state                                                  |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Reset: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_RESET_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_ResetNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x96/0x16, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Voltage: PROTOCOL_VERSION ## {#SCMI_PROTO_VOLTAGE_PROTOCOL_VERSION}

See SCMI_VoltageProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x0                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Voltage: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_VOLTAGE_PROTOCOL_ATTRIBUTES}

See SCMI_VoltageProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x1                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x1                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Voltage: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_VOLTAGE_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_VoltageProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Voltage: VOLTAGE_DOMAIN_ATTRIBUTES ## {#SCMI_PROTO_VOLTAGE_VOLTAGE_DOMAIN_ATTRIBUTES}

See SCMI_VoltageDomainAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Voltage: VOLTAGE_DESCRIBE_LEVELS ## {#SCMI_PROTO_VOLTAGE_VOLTAGE_DESCRIBE_LEVELS}

See SCMI_VoltageDescribeLevels() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | level_index                                                  |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x4                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | int32          | voltage[N]                                                   |
    ---------------------------------------------------------------------------------

## Voltage: VOLTAGE_CONFIG_SET ## {#SCMI_PROTO_VOLTAGE_VOLTAGE_CONFIG_SET}

See SCMI_VoltageConfigSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | config                                                       |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Voltage: VOLTAGE_CONFIG_GET ## {#SCMI_PROTO_VOLTAGE_VOLTAGE_CONFIG_GET}

See SCMI_VoltageConfigGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | config                                                       |
    ---------------------------------------------------------------------------------

## Voltage: VOLTAGE_LEVEL_SET ## {#SCMI_PROTO_VOLTAGE_VOLTAGE_LEVEL_SET}

See SCMI_VoltageLevelSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | int32          | voltage_level                                                |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Voltage: VOLTAGE_LEVEL_GET ## {#SCMI_PROTO_VOLTAGE_VOLTAGE_LEVEL_GET}

See SCMI_VoltageLevelGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x8                     |
    ---------------------------------------------------------------------------------
    | uint32         | domain_id                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x8                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | int32          | voltage_level                                                |
    ---------------------------------------------------------------------------------

## Voltage: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_VOLTAGE_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_VoltageNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x97/0x17, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Pinctrl: PROTOCOL_VERSION ## {#SCMI_PROTO_PINCTRL_PROTOCOL_VERSION}

See SCMI_PinctrlProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x0                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x0                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Pinctrl: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_PINCTRL_PROTOCOL_ATTRIBUTES}

See SCMI_PinctrlProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x1                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x1                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes_low                                               |
    ---------------------------------------------------------------------------------
    | uint32         | attributes_high                                              |
    ---------------------------------------------------------------------------------

## Pinctrl: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_PINCTRL_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_PinctrlProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x2                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Pinctrl: PINCTRL_ATTRIBUTES ## {#SCMI_PROTO_PINCTRL_PINCTRL_ATTRIBUTES}

See SCMI_PinctrlAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | uint32         | identifier                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x3                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Pinctrl: PINCTRL_SETTINGS_GET ## {#SCMI_PROTO_PINCTRL_PINCTRL_SETTINGS_GET}

See SCMI_PinctrlSettingsGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | uint32         | identifier                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x5                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | function_selected                                            |
    ---------------------------------------------------------------------------------
    | uint32         | num_configs                                                  |
    ---------------------------------------------------------------------------------
    | PIN_CONFIG     | configs[N]                                                   |
    ---------------------------------------------------------------------------------

## Pinctrl: PINCTRL_SETTINGS_CONFIGURE ## {#SCMI_PROTO_PINCTRL_PINCTRL_SETTINGS_CONFIGURE}

See SCMI_PinctrlSettingsConfigure() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | uint32         | identifier                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | function_id                                                  |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | PIN_CONFIG     | configs[N]                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x6                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Pinctrl: PINCTRL_REQUEST ## {#SCMI_PROTO_PINCTRL_PINCTRL_REQUEST}

See SCMI_PinctrlRequest() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | uint32         | identifier                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x7                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Pinctrl: PINCTRL_RELEASE ## {#SCMI_PROTO_PINCTRL_PINCTRL_RELEASE}

See SCMI_PinctrlRelease() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x8                     |
    ---------------------------------------------------------------------------------
    | uint32         | identifier                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x8                     |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Pinctrl: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_PINCTRL_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_PinctrlNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x99/0x19, msg=0x10                    |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Lmm: PROTOCOL_VERSION ## {#SCMI_PROTO_LMM_PROTOCOL_VERSION}

See SCMI_LmmProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x0                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x0                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Lmm: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_LMM_PROTOCOL_ATTRIBUTES}

See SCMI_LmmProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x1                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x1                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Lmm: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_LMM_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_LmmProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Lmm: LMM_ATTRIBUTES ## {#SCMI_PROTO_LMM_LMM_ATTRIBUTES}

See SCMI_LmmAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x3                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x3                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | state                                                        |
    ---------------------------------------------------------------------------------
    | int32          | errStatus                                                    |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Lmm: LMM_BOOT ## {#SCMI_PROTO_LMM_LMM_BOOT}

See SCMI_LmmBoot() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x4                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x4                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Lmm: LMM_RESET ## {#SCMI_PROTO_LMM_LMM_RESET}

See SCMI_LmmReset() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Lmm: LMM_SHUTDOWN ## {#SCMI_PROTO_LMM_LMM_SHUTDOWN}

See SCMI_LmmShutdown() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x6                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x6                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Lmm: LMM_WAKE ## {#SCMI_PROTO_LMM_LMM_WAKE}

See SCMI_LmmWake() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x7                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x7                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Lmm: LMM_SUSPEND ## {#SCMI_PROTO_LMM_LMM_SUSPEND}

See SCMI_LmmSuspend() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Lmm: LMM_NOTIFY ## {#SCMI_PROTO_LMM_LMM_NOTIFY}

See SCMI_LmmNotify() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x9                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x9                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Lmm: LMM_RESET_REASON ## {#SCMI_PROTO_LMM_LMM_RESET_REASON}

See SCMI_LmmResetReason() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | boot_flags                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | shutdown_flags                                               |
    ---------------------------------------------------------------------------------
    | uint32         | ext_info[N]                                                  |
    ---------------------------------------------------------------------------------

## Lmm: LMM_POWER_ON ## {#SCMI_PROTO_LMM_LMM_POWER_ON}

See SCMI_LmmPowerOn() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0xB                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0xB                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Lmm: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_LMM_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_LmmNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x80, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Lmm: LMM_EVENT ## {#SCMI_PROTO_LMM_LMM_EVENT}

See SCMI_LmmEvent() for details.

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x80, msg=0x0                          |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | event_lm                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x80, msg=0x0                          |
    ---------------------------------------------------------------------------------

## Bbm: PROTOCOL_VERSION ## {#SCMI_PROTO_BBM_PROTOCOL_VERSION}

See SCMI_BbmProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x0                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x0                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Bbm: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_BBM_PROTOCOL_ATTRIBUTES}

See SCMI_BbmProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x1                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x1                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Bbm: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_BBM_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_BbmProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Bbm: BBM_GPR_SET ## {#SCMI_PROTO_BBM_BBM_GPR_SET}

See SCMI_BbmGprSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x3                          |
    ---------------------------------------------------------------------------------
    | uint32         | index                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | value                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x3                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Bbm: BBM_GPR_GET ## {#SCMI_PROTO_BBM_BBM_GPR_GET}

See SCMI_BbmGprGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x4                          |
    ---------------------------------------------------------------------------------
    | uint32         | index                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x4                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | value                                                        |
    ---------------------------------------------------------------------------------

## Bbm: BBM_RTC_ATTRIBUTES ## {#SCMI_PROTO_BBM_BBM_RTC_ATTRIBUTES}

See SCMI_BbmRtcAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | uint32         | rtc_id                                                       |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Bbm: BBM_RTC_TIME_SET ## {#SCMI_PROTO_BBM_BBM_RTC_TIME_SET}

See SCMI_BbmRtcTimeSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x6                          |
    ---------------------------------------------------------------------------------
    | uint32         | rtc_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | RTC_TIME       | val                                                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x6                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Bbm: BBM_RTC_TIME_GET ## {#SCMI_PROTO_BBM_BBM_RTC_TIME_GET}

See SCMI_BbmRtcTimeGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x7                          |
    ---------------------------------------------------------------------------------
    | uint32         | rtc_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x7                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | RTC_TIME       | val                                                          |
    ---------------------------------------------------------------------------------

## Bbm: BBM_RTC_ALARM_SET ## {#SCMI_PROTO_BBM_BBM_RTC_ALARM_SET}

See SCMI_BbmRtcAlarmSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | uint32         | rtc_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | RTC_TIME       | val                                                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Bbm: BBM_BUTTON_GET ## {#SCMI_PROTO_BBM_BBM_BUTTON_GET}

See SCMI_BbmButtonGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x9                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x9                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | buttonState                                                  |
    ---------------------------------------------------------------------------------

## Bbm: BBM_RTC_NOTIFY ## {#SCMI_PROTO_BBM_BBM_RTC_NOTIFY}

See SCMI_BbmRtcNotify() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | uint32         | rtc_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Bbm: BBM_BUTTON_NOTIFY ## {#SCMI_PROTO_BBM_BBM_BUTTON_NOTIFY}

See SCMI_BbmButtonNotify() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0xB                          |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0xB                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Bbm: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_BBM_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_BbmNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x81, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Bbm: BBM_RTC_EVENT ## {#SCMI_PROTO_BBM_BBM_RTC_EVENT}

See SCMI_BbmRtcEvent() for details.

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x81, msg=0x0                          |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x81, msg=0x0                          |
    ---------------------------------------------------------------------------------

## Bbm: BBM_BUTTON_EVENT ## {#SCMI_PROTO_BBM_BBM_BUTTON_EVENT}

See SCMI_BbmButtonEvent() for details.

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x81, msg=0x1                          |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x81, msg=0x1                          |
    ---------------------------------------------------------------------------------

## Cpu: PROTOCOL_VERSION ## {#SCMI_PROTO_CPU_PROTOCOL_VERSION}

See SCMI_CpuProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x0                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x0                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Cpu: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_CPU_PROTOCOL_ATTRIBUTES}

See SCMI_CpuProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x1                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x1                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Cpu: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_CPU_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_CpuProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Cpu: CPU_ATTRIBUTES ## {#SCMI_PROTO_CPU_CPU_ATTRIBUTES}

See SCMI_CpuAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x3                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x3                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Cpu: CPU_START ## {#SCMI_PROTO_CPU_CPU_START}

See SCMI_CpuStart() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x4                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x4                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Cpu: CPU_STOP ## {#SCMI_PROTO_CPU_CPU_STOP}

See SCMI_CpuStop() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Cpu: CPU_RESET_VECTOR_SET ## {#SCMI_PROTO_CPU_CPU_RESET_VECTOR_SET}

See SCMI_CpuResetVectorSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x6                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | reset_vector_low                                             |
    ---------------------------------------------------------------------------------
    | uint32         | reset_vector_high                                            |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x6                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Cpu: CPU_SLEEP_MODE_SET ## {#SCMI_PROTO_CPU_CPU_SLEEP_MODE_SET}

See SCMI_CpuSleepModeSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x7                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | sleep_mode                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x7                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Cpu: CPU_IRQ_WAKE_SET ## {#SCMI_PROTO_CPU_CPU_IRQ_WAKE_SET}

See SCMI_CpuIrqWakeSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | maskIdx                                                      |
    ---------------------------------------------------------------------------------
    | uint32         | numMask                                                      |
    ---------------------------------------------------------------------------------
    | uint32         | mask[N]                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Cpu: CPU_NON_IRQ_WAKE_SET ## {#SCMI_PROTO_CPU_CPU_NON_IRQ_WAKE_SET}

See SCMI_CpuNonIrqWakeSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x9                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | maskIdx                                                      |
    ---------------------------------------------------------------------------------
    | uint32         | numMask                                                      |
    ---------------------------------------------------------------------------------
    | uint32         | mask[N]                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x9                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Cpu: CPU_PD_LPM_CONFIG_SET ## {#SCMI_PROTO_CPU_CPU_PD_LPM_CONFIG_SET}

See SCMI_CpuPdLpmConfigSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | num_configs                                                  |
    ---------------------------------------------------------------------------------
    | PD_LPM_CONFIG  | pdConfigs[N]                                                 |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Cpu: CPU_PER_LPM_CONFIG_SET ## {#SCMI_PROTO_CPU_CPU_PER_LPM_CONFIG_SET}

See SCMI_CpuPerLpmConfigSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0xB                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | num_configs                                                  |
    ---------------------------------------------------------------------------------
    | PER_LPM_CONFIG | perConfigs[N]                                                |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0xB                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Cpu: CPU_INFO_GET ## {#SCMI_PROTO_CPU_CPU_INFO_GET}

See SCMI_CpuInfoGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0xC                          |
    ---------------------------------------------------------------------------------
    | uint32         | cpu_id                                                       |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0xC                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | run_mode                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | sleep_mode                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | reset_vector_low                                             |
    ---------------------------------------------------------------------------------
    | uint32         | reset_vector_high                                            |
    ---------------------------------------------------------------------------------

## Cpu: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_CPU_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_CpuNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x82, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Fusa: PROTOCOL_VERSION ## {#SCMI_PROTO_FUSA_PROTOCOL_VERSION}

See SCMI_FusaProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x0                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x0                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Fusa: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_FUSA_PROTOCOL_ATTRIBUTES}

See SCMI_FusaProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x1                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x1                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes1                                                  |
    ---------------------------------------------------------------------------------
    | uint32         | attributes2                                                  |
    ---------------------------------------------------------------------------------

## Fusa: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_FUSA_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_FusaProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_FEENV_STATE_GET ## {#SCMI_PROTO_FUSA_FUSA_FEENV_STATE_GET}

See SCMI_FusaFeenvStateGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x3                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x3                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | feenv_state                                                  |
    ---------------------------------------------------------------------------------
    | uint32         | msel_mode                                                    |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_FEENV_STATE_NOTIFY ## {#SCMI_PROTO_FUSA_FUSA_FEENV_STATE_NOTIFY}

See SCMI_FusaFeenvStateNotify() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | uint32         | notify_enable                                                |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_SEENV_STATE_GET ## {#SCMI_PROTO_FUSA_FUSA_SEENV_STATE_GET}

See SCMI_FusaSeenvStateGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x6                          |
    ---------------------------------------------------------------------------------
    | uint32         | seenv_id                                                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x6                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | seenv_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | lm_id                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | seenv_state                                                  |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_SEENV_STATE_SET ## {#SCMI_PROTO_FUSA_FUSA_SEENV_STATE_SET}

See SCMI_FusaSeenvStateSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x7                          |
    ---------------------------------------------------------------------------------
    | uint32         | seenv_state                                                  |
    ---------------------------------------------------------------------------------
    | uint32         | ping_cookie                                                  |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x7                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_FAULT_GET ## {#SCMI_PROTO_FUSA_FUSA_FAULT_GET}

See SCMI_FusaFaultGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | uint32         | fault_id                                                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_FAULT_SET ## {#SCMI_PROTO_FUSA_FUSA_FAULT_SET}

See SCMI_FusaFaultSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x9                          |
    ---------------------------------------------------------------------------------
    | uint32         | fault_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x9                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_FAULT_GROUP_NOTIFY ## {#SCMI_PROTO_FUSA_FUSA_FAULT_GROUP_NOTIFY}

See SCMI_FusaFaultGroupNotify() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | uint32         | fault_id_first                                               |
    ---------------------------------------------------------------------------------
    | uint32         | fault_mask                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | notify_enable                                                |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | fault_id_first_get                                           |
    ---------------------------------------------------------------------------------
    | uint32         | notify_enabled                                               |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_SCHECK_EVNTRIG ## {#SCMI_PROTO_FUSA_FUSA_SCHECK_EVNTRIG}

See SCMI_FusaScheckEvntrig() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0xB                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0xB                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_SCHECK_TEST_EXEC ## {#SCMI_PROTO_FUSA_FUSA_SCHECK_TEST_EXEC}

See SCMI_FusaScheckTestExec() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0xE                          |
    ---------------------------------------------------------------------------------
    | uint32         | target_test_id                                               |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0xE                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Fusa: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_FUSA_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_FusaNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x83, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_FEENV_STATE_EVENT ## {#SCMI_PROTO_FUSA_FUSA_FEENV_STATE_EVENT}

See SCMI_FusaFeenvStateEvent() for details.

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x83, msg=0x0                          |
    ---------------------------------------------------------------------------------
    | uint32         | feenv_state                                                  |
    ---------------------------------------------------------------------------------
    | uint32         | msel_mode                                                    |
    ---------------------------------------------------------------------------------

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x83, msg=0x0                          |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_SEENV_STATE_REQ_EVENT ## {#SCMI_PROTO_FUSA_FUSA_SEENV_STATE_REQ_EVENT}

See SCMI_FusaSeenvStateReqEvent() for details.

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x83, msg=0x1                          |
    ---------------------------------------------------------------------------------
    | uint32         | ping_cookie                                                  |
    ---------------------------------------------------------------------------------

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x83, msg=0x1                          |
    ---------------------------------------------------------------------------------

## Fusa: FUSA_FAULT_EVENT ## {#SCMI_PROTO_FUSA_FUSA_FAULT_EVENT}

See SCMI_FusaFaultEvent() for details.

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x83, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | uint32         | fault_id                                                     |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x83, msg=0x2                          |
    ---------------------------------------------------------------------------------

## Misc: PROTOCOL_VERSION ## {#SCMI_PROTO_MISC_PROTOCOL_VERSION}

See SCMI_MiscProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x0                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x0                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

## Misc: PROTOCOL_ATTRIBUTES ## {#SCMI_PROTO_MISC_PROTOCOL_ATTRIBUTES}

See SCMI_MiscProtocolAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x1                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x1                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Misc: PROTOCOL_MESSAGE_ATTRIBUTES ## {#SCMI_PROTO_MISC_PROTOCOL_MESSAGE_ATTRIBUTES}

See SCMI_MiscProtocolMessageAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | uint32         | message_id                                                   |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x2                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------

## Misc: MISC_CONTROL_SET ## {#SCMI_PROTO_MISC_MISC_CONTROL_SET}

See SCMI_MiscControlSet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x3                          |
    ---------------------------------------------------------------------------------
    | uint32         | ctrl_id                                                      |
    ---------------------------------------------------------------------------------
    | uint32         | numVal                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | val[N]                                                       |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x3                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Misc: MISC_CONTROL_GET ## {#SCMI_PROTO_MISC_MISC_CONTROL_GET}

See SCMI_MiscControlGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x4                          |
    ---------------------------------------------------------------------------------
    | uint32         | ctrl_id                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x4                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | numVal                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | val[N]                                                       |
    ---------------------------------------------------------------------------------

## Misc: MISC_CONTROL_ACTION ## {#SCMI_PROTO_MISC_MISC_CONTROL_ACTION}

See SCMI_MiscControlAction() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | uint32         | ctrl_id                                                      |
    ---------------------------------------------------------------------------------
    | uint32         | action                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | numArg                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | arg[N]                                                       |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x5                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | numRtn                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | rtn[N]                                                       |
    ---------------------------------------------------------------------------------

## Misc: MISC_DISCOVER_BUILD_INFO ## {#SCMI_PROTO_MISC_MISC_DISCOVER_BUILD_INFO}

See SCMI_MiscDiscoverBuildInfo() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x6                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x6                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | build_num                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | build_commit                                                 |
    ---------------------------------------------------------------------------------
    | uint8          | build_date[16]                                               |
    ---------------------------------------------------------------------------------
    | uint8          | build_time[16]                                               |
    ---------------------------------------------------------------------------------

## Misc: MISC_ROM_PASSOVER_GET ## {#SCMI_PROTO_MISC_MISC_ROM_PASSOVER_GET}

See SCMI_MiscRomPassoverGet() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x7                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x7                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | numPassover                                                  |
    ---------------------------------------------------------------------------------
    | uint32         | passover[N]                                                  |
    ---------------------------------------------------------------------------------

## Misc: MISC_CONTROL_NOTIFY ## {#SCMI_PROTO_MISC_MISC_CONTROL_NOTIFY}

See SCMI_MiscControlNotify() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | uint32         | ctrl_id                                                      |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x8                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Misc: MISC_REASON_ATTRIBUTES ## {#SCMI_PROTO_MISC_MISC_REASON_ATTRIBUTES}

See SCMI_MiscReasonAttributes() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x9                          |
    ---------------------------------------------------------------------------------
    | uint32         | reasonId                                                     |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x9                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | attributes                                                   |
    ---------------------------------------------------------------------------------
    | uint8          | name[16]                                                     |
    ---------------------------------------------------------------------------------

## Misc: MISC_RESET_REASON ## {#SCMI_PROTO_MISC_MISC_RESET_REASON}

See SCMI_MiscResetReason() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0xA                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | boot_flags                                                   |
    ---------------------------------------------------------------------------------
    | uint32         | shutdown_flags                                               |
    ---------------------------------------------------------------------------------
    | uint32         | ext_info[N]                                                  |
    ---------------------------------------------------------------------------------

## Misc: MISC_SI_INFO ## {#SCMI_PROTO_MISC_MISC_SI_INFO}

See SCMI_MiscSiInfo() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0xB                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0xB                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | device_id                                                    |
    ---------------------------------------------------------------------------------
    | uint32         | si_rev                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | part_num                                                     |
    ---------------------------------------------------------------------------------
    | uint8          | si_name[16]                                                  |
    ---------------------------------------------------------------------------------

## Misc: MISC_CFG_INFO ## {#SCMI_PROTO_MISC_MISC_CFG_INFO}

See SCMI_MiscCfgInfo() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0xC                          |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0xC                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | mSel                                                         |
    ---------------------------------------------------------------------------------
    | uint8          | cfg_name[16]                                                 |
    ---------------------------------------------------------------------------------

## Misc: MISC_SYSLOG ## {#SCMI_PROTO_MISC_MISC_SYSLOG}

See SCMI_MiscSyslog() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0xD                          |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------
    | uint32         | log_index                                                    |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0xD                          |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------
    | uint32         | num_log_flags                                                |
    ---------------------------------------------------------------------------------
    | uint32         | syslog[N]                                                    |
    ---------------------------------------------------------------------------------

## Misc: NEGOTIATE_PROTOCOL_VERSION ## {#SCMI_PROTO_MISC_NEGOTIATE_PROTOCOL_VERSION}

See SCMI_MiscNegotiateProtocolVersion() for details.

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | uint32         | version                                                      |
    ---------------------------------------------------------------------------------

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=0, proto=0x84, msg=0x10                         |
    ---------------------------------------------------------------------------------
    | int32          | status                                                       |
    ---------------------------------------------------------------------------------

## Misc: MISC_CONTROL_EVENT ## {#SCMI_PROTO_MISC_MISC_CONTROL_EVENT}

See SCMI_MiscControlEvent() for details.

    Receive
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x84, msg=0x0                          |
    ---------------------------------------------------------------------------------
    | uint32         | ctrl_id                                                      |
    ---------------------------------------------------------------------------------
    | uint32         | flags                                                        |
    ---------------------------------------------------------------------------------

    Send
    ---------------------------------------------------------------------------------
    | uint32         | header (type=2, proto=0x84, msg=0x0                          |
    ---------------------------------------------------------------------------------


