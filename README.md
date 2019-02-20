libosmo-fl2k
===========
This is a fork of http://git.osmocom.org/osmo-fl2k which compiles for Win64 under Microsoft Visual Studio (verified with VS 2015). See release section for pre-compiled binaries.

Compared to original / upstream software, optional wrappers for stderr/stout have been added.

To use the libosmo-fl2k programs on a x64 Windows machine you first have to install the libusb driver for your FL2000-based VGA adapter. I recommend using zadig (http://zadig.akeo.ie/) to do so. Be aware that FL2000 dongles are composite USB devices since they have the (optional) feature to bring their driver in an embedded memory drive. Use the zadig option "list all devices” and disable "ignore hubs or composite parents" to select the composite device (typically id 1D5C-2000) instead of its VGA subdevice (typically id 1D5C-2000-00).

To compile libosmo-fl2k yourself, you first need to acquire the libusb and pthreads-win32 libraries and copy the relevant files (see below) in folders called "libusb" and "pthread" placed parallel to the libosmo-fl2k folder. Suitable sources are https://github.com/libusb/libusb/archive/v1.0.22.zip and the subdirectory "Pre-built.2" from ftp://sourceware.org/pub/pthreads-win32/pthreads-w32-2-9-1-release.zip). 

The folder structure has to look like this

    libosmo-fl2k
        include
        src
        vs15
        <and so on>
    
    pthread
        include
        lib
        <and so on>
	
    libusb
        libusb
        msvc
        <and so on>
    
Next you have to open libusb/msvc/libusb_2015.sln and compile libusb for Win64 (Release and Debug Build).
   
Then simply open libosmo-fl2k/vs15/fl2k.sln in Visual Studio and select between debug/release build options.

Original readme from http://git.osmocom.org/osmo-fl2k:
===========
# osmo-fl2k
#### turns FL2000-based USB 3.0 to VGA adapters into low cost DACs

For more information see https://osmocom.org/projects/osmo-fl2k/wiki
