<<<<<<< HEAD
BOOTMAGIC_ENABLE  = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE   = no       # Mouse keys(+4700)
EXTRAKEY_ENABLE   = yes       # Audio control and System control(+450)
CONSOLE_ENABLE    = no         # Console for debug(+400)
COMMAND_ENABLE    = no        # Commands for debug and configuration
TAP_DANCE_ENABLE  = no
AUDIO_ENABLE      = yes
=======
BOOTMAGIC_ENABLE   = lite       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE    = no       # Mouse keys(+4700)
EXTRAKEY_ENABLE    = yes       # Audio control and System control(+450)
TAP_DANCE_ENABLE   = no
>>>>>>> upstream/master
SPACE_CADET_ENABLE = no

<<<<<<< HEAD
ifeq (,$(findstring planck/rev6,$(KEYBOARD))) # Make sure it's NOT the Planck Rev6
    RGBLIGHT_ENABLE             = yes
    INDICATOR_LIGHTS            = yes
    RGBLIGHT_TWINKLE            = yes
    RGBLIGHT_STARTUP_ANIMATION  = yes
=======
ifneq ($(strip $(KEYBOARD)), planck/rev6)
    CONSOLE_ENABLE    			= no
    COMMAND_ENABLE    			= no
    ifeq ($(strip $(LAYOUT_HAS_RGB)), yes)
        RGBLIGHT_ENABLE         = yes
        INDICATOR_LIGHTS            = yes
        RGBLIGHT_TWINKLE            = yes
        RGBLIGHT_STARTUP_ANIMATION  = yes
    endif
else
    CONSOLE_ENABLE    			= yes
    COMMAND_ENABLE    			= yes
    RGBLIGHT_ENABLE             = yes
    RGBLIGHT_STARTUP_ANIMATION  = yes
    RGB_MATRIX_ENABLE           = no
    AUDIO_ENABLE       			= yes
    EEPROM_DRIVER 				= i2c
>>>>>>> upstream/master
endif
ifneq (,$(findstring planck/light,$(KEYBOARD))) # Make sure it IS the Planck Light
    RGB_MATRIX_ENABLE           = yes
<<<<<<< HEAD
    RGBLIGHT_ENABLE             = no
    RGBLIGHT_STARTUP_ANIMATION  = no
=======
    RGBLIGHT_ENABLE             = yes
    RGBLIGHT_STARTUP_ANIMATION  = yes
    AUDIO_ENABLE       			= yes
    # HAPTIC_ENABLE               += SOLENOID
>>>>>>> upstream/master
endif
ifneq (,$(findstring planck/ez,$(KEYBOARD))) # Make sure it IS the Planck Light
    RGBLIGHT_ENABLE = no
    # SERIAL_LINK_ENABLE = yes
    ENCODER_ENABLE = yes
    RGB_MATRIX_ENABLE = IS31FL3737
    INDICATOR_LIGHTS            = yes
    RGBLIGHT_TWINKLE            = yes
    RGBLIGHT_STARTUP_ANIMATION  = yes
<<<<<<< HEAD
=======
    CONSOLE_ENABLE    			= yes
    COMMAND_ENABLE    			= yes
    AUDIO_ENABLE       			= yes
>>>>>>> upstream/master
endif

ifeq ($(strip $(PROTOCOL)), VUSB)
NKRO_ENABLE       = no
else
NKRO_ENABLE       = yes
endif


MACROS_ENABLED    = no
