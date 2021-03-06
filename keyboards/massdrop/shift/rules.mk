# project specific files
SRC = matrix.c
SRC += config_led.c
SRC += spi.c
SRC += usb.c

#For platform and packs
ARM_ATSAM = SAMD51J18A
MCU = cortex-m4

CUSTOM_MATRIX = yes

# Build Options
#   comment out to disable the options.
#
<<<<<<< HEAD:keyboards/massdrop/shift/rules.mk
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
=======
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
>>>>>>> upstream/master:keyboards/dc01/left/rules.mk
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
<<<<<<< HEAD:keyboards/massdrop/shift/rules.mk
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI support (+2400 to 4200, depending on config)
=======
MIDI_ENABLE = no            # MIDI support
>>>>>>> upstream/master:keyboards/dc01/left/rules.mk
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
<<<<<<< HEAD:keyboards/massdrop/shift/rules.mk
HD44780_ENABLE = no         # Enable support for HD44780 based LCDs (+400)
VIRTSER_ENABLE = no         # USB Serial Driver
RAW_ENABLE = no             # Raw device
AUTO_SHIFT_ENABLE = no      # Auto Shift

# Custom RGB matrix handling
RGB_MATRIX_ENABLE = custom
=======
CUSTOM_MATRIX = yes         # Use custom matrix
SRC += matrix.c \
       i2c_master.c
>>>>>>> upstream/master:keyboards/dc01/left/rules.mk
