extern "C" {

	#include <efi.h>
	#include <efilib.h>

}

#include <functional>

EFI_STATUS cxx_main(EFI_HANDLE, EFI_SYSTEM_TABLE*);

extern "C" {

	EFI_STATUS
	EFIAPI
	efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
        InitializeLib(ImageHandle, SystemTable);
        SystemTable->BootServices->SetWatchdogTimer(0, 0, 0, nullptr); // Disable UEFI's timer which after ~5min would reset the computer.
        return cxx_main(ImageHandle, SystemTable);
	}

}

template<typename RetVal, typename ... Args>
auto uefi(RetVal (*ptr)(Args...), Args... args) {
    typedef RetVal (*FuncPtr)(Args...);
    typedef __attribute__((ms_abi)) FuncPtr MSFuncPtr;
    MSFuncPtr mptr = reinterpret_cast<MSFuncPtr>(ptr);
    return std::invoke(mptr, args...);
}

EFI_STATUS cxx_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable) {
    return EFI_SUCCESS;
}
