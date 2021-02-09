# Template for making small UEFI applications quickly

This is a simple template I use to compile C++ UEFI applications with cmake and run QEMU with TianoCore for testing. After successful compilation files **BOOTX64.efi** and **BOOTX64.efi.debug** will be placed in project's root folder. File **BOOTX64.efi** can be directly placed on a usb stick in **/EFI/BOOT/**, the other with **.debug** extension has additional sections with debug info for source code level debugging using gdb.

## Using
### Configuring project
```sh
mkdir build
cd build
cmake ..
```
### Compiling
```sh
make
```
### Running QEMU
It will spawn QEMU with **-s** options to enable gdb remote debugging on localhost:1234 
```sh
make run
```

