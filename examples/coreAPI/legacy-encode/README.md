# `legacy-encode` Sample

This sample shows how to use the oneAPI Video Processing Library (oneVPL) to
perform a simple video encode.

| Optimized for    | Description
|----------------- | ----------------------------------------
| OS               | Ubuntu* 20.04; Windows* 10
| Hardware         | Compatible with Intel® oneAPI Video Processing Library(oneVPL) GPU implementation, which can be found at https://github.com/oneapi-src/oneVPL-intel-gpu 
|                  | and Intel® Media SDK GPU implementation, which can be found at https://github.com/Intel-Media-SDK/MediaSDK
| Software         | Intel® oneAPI Video Processing Library(oneVPL) CPU implementation
| What You Will Learn | How to use oneVPL to encode an raw video file to H.265
| Time to Complete | 5 minutes


## Purpose

This sample is a command line application that takes a file containing a raw
native format video elementary stream as an argument, encodes it with oneVPL and
writes the encoded output to `out.h265` in H.265 format.

Native raw frame format: CPU=I420, GPU=NV12.

## Key Implementation details

| Configuration     | Default setting
| ----------------- | ----------------------------------
| Target device     | CPU
| Input format      | I420
| Output format     | H.265 video elementary stream
| Output resolution | same as input


## License

This code sample is licensed under MIT license.


## Building the `hello-encode` Program

### On a Linux* System

Perform the following steps:

1. Install the prerequisite software. To build and run the sample you need to
   install prerequisite software and set up your environment:

   - Intel® oneAPI Base Toolkit for Linux*
   - [CMake](https://cmake.org)

2. Set up your environment using the following command.
   ```
   source <oneapi_install_dir>/setvars.sh
   ```
   Here `<oneapi_install_dir>` represents the root folder of your oneAPI
   installation, which is `/opt/intel/oneapi/` when installed as root, and
   `~/intel/oneapi/` when installed as a normal user.  If you customized the
   installation folder, it is in your custom location.

3. Build the program using the following commands:
   ```
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

4. Run the program using the following command:
   ```
   cmake --build . --target run
   ```


### On a Windows* System Using Visual Studio* Version 2017 or Newer

#### Building the program using CMake

1. Install the prerequisite software. To build and run the sample you need to
   install prerequisite software and set up your environment:

   - Intel® oneAPI Base Toolkit for Windows*
   - [CMake](https://cmake.org)

2. Set up your environment using the following command.
   ```
   <oneapi_install_dir>\setvars.bat
   ```
   Here `<oneapi_install_dir>` represents the root folder of your oneAPI
   installation, which is which is `C:\Program Files (x86)\Intel\oneAPI\`
   when installed using default options. If you customized the installation
   folder, the `setvars.bat` is in your custom location.  Note that if a
   compiler is not part of your oneAPI installation you should run in a Visual
   Studio 64-bit command prompt.

3. Build the program using the following commands:
   ```
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

4. Run the program using the following command:
   ```
   cmake --build . --target run
   ```


## Running the Sample

### Application Parameters

The instructions given above run the sample executable with the arguments
`-i <sample_dir>/content/cars_128x96.i420 -w 128 -h 96`.


### Example of Output

```
Encoding hello-encode/content/cars_128x96.i420 -> out.h265
Encoded 60 frames
```

You can find the output file `out.h265` in the build directory.

You can display the output with a video player that supports raw streams such as
FFplay. You can use the following command to display the output with FFplay:

```
ffplay out.h265
```
