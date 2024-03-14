# Installing wxWidgets

wxWidgets is a C++ library that provides a set of classes for creating native GUI applications. This README provides instructions for installing wxWidgets on various operating systems.

## Table of Contents

- [Installation on Debian-based Linux distributions](#installation-on-debian-based-linux-distributions)
- [Installation on Arch Linux](#installation-on-arch-linux)
- [Installation on Fedora-based Linux distributions](#installation-on-fedora-based-linux-distributions)
- [Installation on Windows](#installation-on-windows)
- [Installation on macOS](#installation-on-macos)
- [Troubleshooting](#troubleshooting)

## Installation on Debian-based Linux distributions

1. **Install wxWidgets package**: Use the package manager (apt) to install wxWidgets.

   ```bash
   sudo apt update
   sudo apt install libwxgtk3.0-dev
   ```

## Installation on Arch Linux

1. **Install wxWidgets package**: Use the package manager (pacman) to install wxWidgets.

   ```bash
   sudo pacman -Syu
   sudo pacman -S wxgtk3
   ```

## Installation on Fedora-based Linux distributions

1. **Install wxWidgets package**: Use the package manager (dnf) to install wxWidgets.

   ```bash
   sudo dnf install wxGTK3-devel
   ```

## Installation on Windows

1. **Download wxWidgets**: Go to the [wxWidgets download page](https://www.wxwidgets.org/downloads/) and download the Windows installer for the latest version.

2. **Run the installer**: Double-click the downloaded installer and follow the on-screen instructions to install wxWidgets.

3. **Set up environment variables (optional)**: If the installer didn't set up the necessary environment variables, you may need to do it manually. Add the wxWidgets installation directory to the PATH environment variable and set WXWIN environment variable to point to the wxWidgets installation directory.

## Installation on macOS

1. **Install wxWidgets using Homebrew**: Open Terminal and run the following command to install wxWidgets using Homebrew.

   ```bash
   brew install wxwidgets
   ```

## Troubleshooting

### Common Troubleshooting Steps

#### Check wxWidgets Version

Ensure that you have installed the correct version of wxWidgets for your project. Some features or APIs may differ between versions, so make sure you're using the appropriate version.

#### Check Dependencies

Make sure that all required dependencies for wxWidgets are installed on your system. This includes development tools, compilers, and any additional libraries required by wxWidgets.

### Troubleshooting on Windows

#### Path Configuration

If you're encountering issues with finding wxWidgets libraries or headers, double-check your environment variables. Ensure that the wxWidgets installation directory is included in your PATH variable.

### Troubleshooting on macOS

#### Homebrew Issues

If you're using Homebrew to install wxWidgets on macOS and encountering issues, try updating Homebrew and reinstalling wxWidgets.

   ```bash
   brew update
   brew reinstall wxwidgets
   ```

### Troubleshooting on Other Linux Distributions

#### Package Availability

If you're using a Linux distribution other than Debian, Arch, or Fedora, ensure that the wxWidgets packages are available in your distribution's package repository. If not, you may need to compile wxWidgets from source.

### Troubleshooting on Manjaro Linux

#### Check Installed Packages

To check if you have installed wxWidgets correctly on Manjaro Linux, you can use the pacman package manager. Open a terminal and run the following command:

   ```bash
   pacman -Q | grep wx
   ```

This command will list all installed packages that contain "wx" in their names. If wxWidgets is installed, you should see related packages listed here.

#### Check Library Files

Another way to check if wxWidgets is installed correctly is to check for its library files. wxWidgets should have installed its libraries in standard locations such as /usr/lib or /usr/local/lib. You can use the ls command to list files in those directories and look for wxWidgets related libraries.

   ```bash
   ls /usr/lib | grep libwx
   ```

This command will list all files in /usr/lib directory that contain "libwx" in their names. If wxWidgets is installed, you should see related library files listed here.

#### Check wx-config

wxWidgets usually installs a script called wx-config, which is used to provide information about the wxWidgets installation, including compiler flags and library paths. You can check if wx-config is available in your system and get some information about your wxWidgets installation by running:

   ```bash
   wx-config --version
   ```

If wxWidgets is installed correctly, this command should output the version of wxWidgets installed.

If any of these checks fail or if you're unsure about the output, you may need to reinstall wxWidgets or consult the documentation for the specific distribution you're using (in this case, Manjaro Linux) for further troubleshooting steps.

This README should cover installation instructions for wxWidgets on various operating systems, along with troubleshooting steps for Windows, macOS, other Linux distributions, and Manjaro Linux. Feel free to modify it further as needed for your project.