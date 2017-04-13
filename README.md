# Swamp

Cooperative multitasking operating system for Cortex-M0 **STM32F0xx** controllers.
See *sample.c* to understand how to use the system and its modules.

Building samples:
```
make MODULES="sample kernel" all
make MODULES="sample kernel cdc" all
make MODULES="sample kernel hid" all
```

Clean samples:
```
make MODULES="sample kernel cdc hid" clean
```

Building your application:
```
make MODULES="app kernel" all
```
