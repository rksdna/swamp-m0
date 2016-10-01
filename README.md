#Swamp

Cooperative multitasking operating system for Cortex-M0 **STM32F0xx** controllers.
See *samples* directory to understand how to use the system.

Building samples:
```
make FILES="samples/source/kernel_sample.c" DIRS="kernel" all
make FILES="samples/source/cdc_sample.c" DIRS="kernel cdc" all
make FILES="samples/source/hid_sample.c" DIRS="kernel hid" all
```

Clean samples:
```
make DIRS="kernel cdc hid samples" clean
```

Building your application:
```
make TARGET="app" DIRS="app kernel cdc" all
```
