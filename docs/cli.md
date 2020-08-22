# QMK CLI :id=qmk-cli

## Overview :id=overview

The QMK CLI makes building and working with QMK keyboards easier. We have provided a number of commands to help you work with QMK:

<<<<<<< HEAD
* `qmk compile-json`

# Setup

Simply add the `qmk_firmware/bin` directory to your `PATH`. You can run the `qmk` commands from any directory.

```
export PATH=$PATH:$HOME/qmk_firmware/bin
```

You may want to add this to your `.profile`, `.bash_profile`, `.zsh_profile`, or other shell startup scripts.

# Commands

## `qmk compile-json`

This command allows you to compile JSON files you have downloaded from <https://config.qmk.fm>.

**Usage**:

```
qmk compile-json mine.json
```
=======
### Requirements :id=requirements

QMK requires Python 3.6 or greater. We try to keep the number of requirements small but you will also need to install the packages listed in [`requirements.txt`](https://github.com/qmk/qmk_firmware/blob/master/requirements.txt). These are installed automatically when you install the QMK CLI.

### Install Using Homebrew (macOS, some Linux) :id=install-using-homebrew

If you have installed [Homebrew](https://brew.sh) you can tap and install QMK:

```
brew install qmk/qmk/qmk
export QMK_HOME='~/qmk_firmware' # Optional, set the location for `qmk_firmware`
qmk setup  # This will clone `qmk/qmk_firmware` and optionally set up your build environment
```

### Install Using pip :id=install-using-easy_install-or-pip

If your system is not listed above you can install QMK manually. First ensure that you have Python 3.6 (or later) installed and have installed pip. Then install QMK with this command:

```
python3 -m pip install qmk
export QMK_HOME='~/qmk_firmware' # Optional, set the location for `qmk_firmware`
qmk setup  # This will clone `qmk/qmk_firmware` and optionally set up your build environment
```

### Packaging For Other Operating Systems :id=packaging-for-other-operating-systems

We are looking for people to create and maintain a `qmk` package for more operating systems. If you would like to create a package for your OS please follow these guidelines:

* Follow best practices for your OS when they conflict with these guidelines
    * Document why in a comment when you do deviate
* Install using a virtualenv
* Instruct the user to set the environment variable `QMK_HOME` to have the firmware source checked out somewhere other than `~/qmk_firmware`.
>>>>>>> upstream/master
