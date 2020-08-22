#!/bin/bash

dir=$(cd -P -- "$(dirname -- "$0")" && pwd -P)
download_dir=~/qmk_utils
avrtools=avr8-gnu-toolchain
armtools=gcc-arm-none-eabi
util_dir=$(dirname "$0")

echo "Installing dependencies needed for the installation (quazip)"
<<<<<<< HEAD
pacman --needed -S base-devel mingw-w64-x86_64-toolchain msys/git msys/p7zip msys/python3 msys/unzip
=======
pacman --needed --noconfirm --disable-download-timeout -Sy base-devel mingw-w64-x86_64-toolchain mingw-w64-x86_64-clang git mingw-w64-x86_64-python3-pip unzip
>>>>>>> upstream/master

source "$dir/win_shared_install.sh"

function install_avr {
    rm -f -r "$avrtools"
    wget "http://ww1.microchip.com/downloads/en/DeviceDoc/avr8-gnu-toolchain-3.6.1.1752-win32.any.x86.zip"
    echo "Extracting AVR toolchain..."
<<<<<<< HEAD
	unzip -q avr8-gnu-toolchain-3.6.1.1752-win32.any.x86.zip
	mv avr8-gnu-toolchain-win32_x86/ avr8-gnu-toolchain
    rm __MACOSX -R
    rm avr8-gnu-toolchain-3.6.1.1752-win32.any.x86.zip
    pacman --needed -S mingw-w64-x86_64-avrdude
}

function install_arm {
    wget -O gcc-arm-none-eabi.zip "https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2017q2/gcc-arm-none-eabi-6-2017-q2-update-win32.zip?product=GNU%20ARM%20Embedded%20Toolchain,ZIP,,Windows,6-2017-q2-update"
    unzip -d gcc-arm-none-eabi gcc-arm-none-eabi.zip
    rm gcc-arm-none-eabi.zip
}
=======
    unzip -q -d . avr-gcc-8.3.0-x86-mingw.zip
    mv avr-gcc-8.3.0-x86-mingw avr8-gnu-toolchain
    rm avr8-gnu-toolchain/bin/make.exe
    rm avr-gcc-8.3.0-x86-mingw.zip

    pacman --needed --noconfirm --disable-download-timeout -S mingw-w64-x86_64-avrdude mingw-w64-x86_64-bootloadhid mingw-w64-x86_64-dfu-programmer mingw-w64-x86_64-teensy-loader-cli
}

function install_arm {
    rm -f -r "$armtools"
    wget -O gcc-arm-none-eabi-8-2019-q3-update-win32.zip "https://developer.arm.com/-/media/Files/downloads/gnu-rm/8-2019q3/RC1.1/gcc-arm-none-eabi-8-2019-q3-update-win32.zip"
    echo "Extracting ARM toolchain..."
    unzip -q -d gcc-arm-none-eabi gcc-arm-none-eabi-8-2019-q3-update-win32.zip
    rm gcc-arm-none-eabi-8-2019-q3-update-win32.zip
>>>>>>> upstream/master

    pacman --needed --noconfirm --disable-download-timeout -S mingw-w64-x86_64-dfu-util
}

pushd "$download_dir"

if [ ! -d "$avrtools" ]; then
    while true; do
        echo
        echo "The AVR toolchain is not installed."
        echo "This is needed for building AVR based keboards."
        read -p "Do you want to install it? (Y/N) " res
        case $res in
            [Yy]* ) install_avr; break;;
            [Nn]* ) break;;
            * ) echo "Invalid answer";;
        esac
    done
else
    while true; do
        echo
        echo "The AVR toolchain is already installed"
        read -p "Do you want to reinstall? (Y/N) " res
        case $res in
            [Yy]* ) install_avr; break;;
            [Nn]* ) break;;
            * ) echo "Invalid answer";;
        esac
    done
fi

if [ ! -d "$armtools" ]; then
    while true; do
        echo
        echo "The ARM toolchain is not installed."
        echo "This is needed for building ARM based keyboards."
        read -p "Do you want to install it? (Y/N) " res
        case $res in
            [Yy]* ) install_arm; break;;
            [Nn]* ) break;;
            * ) echo "Invalid answer";;
        esac
    done
else
    while true; do
        echo
        echo "The ARM toolchain is already installed"
        read -p "Do you want to reinstall? (Y/N) " res
        case $res in
            [Yy]* ) install_arm; break;;
            [Nn]* ) break;;
            * ) echo "Invalid answer";;
        esac
    done
fi
popd

pip3 install -r "${util_dir}/../requirements.txt"

cp -f "$dir/activate_msys2.sh" "$download_dir/"

if grep "^source ~/qmk_utils/activate_msys2.sh$" ~/.bashrc
then
    echo
    echo "The line source ~/qmk_utils/activate_msys2.sh is already added to your /.bashrc"
    echo "Not adding it twice!"
else
    while true; do
        echo
        echo "Do you want to add 'source ~/qmk_utils/activate_msys2.sh' to the end of your"
        echo ".bashrc file? Without this make won't find the needed utils, so if you don't"
        echo "want to do it automatically, then you have to do it manually later."
        read -p "(Y/N)? " res
        case $res in
            [Yy]* ) echo "source ~/qmk_utils/activate_msys2.sh" >> ~/.bashrc; break;;
            [Nn]* ) break;;
            * ) echo "Invalid answer";;
        esac
    done
fi

echo
echo "******************************************************************************"
echo "Installation completed!"
echo "Please close this Window and restart MSYS2 MinGW"
echo "******************************************************************************"
