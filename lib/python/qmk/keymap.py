"""Functions that help you work with QMK keymaps.
"""
<<<<<<< HEAD
import json
import logging
import os
from traceback import format_exc
=======
from pathlib import Path
>>>>>>> upstream/master

from milc import cli

from qmk.keyboard import rules_mk
import qmk.path
from qmk.errors import NoSuchKeyboardError

# The `keymap.c` template to use when a keyboard doesn't have its own
DEFAULT_KEYMAP_C = """#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
__KEYMAP_GOES_HERE__
};
"""


def template(keyboard):
    """Returns the `keymap.c` template for a keyboard.

    If a template exists in `keyboards/<keyboard>/templates/keymap.c` that
    text will be used instead of `DEFAULT_KEYMAP_C`.

    Args:
        keyboard
            The keyboard to return a template for.
    """
    template_file = Path('keyboards/%s/templates/keymap.c' % keyboard)

    if template_file.exists():
        return template_file.read_text()

    return DEFAULT_KEYMAP_C


def _strip_any(keycode):
    """Remove ANY() from a keycode.
    """
    if keycode.startswith('ANY(') and keycode.endswith(')'):
        keycode = keycode[4:-1]

    return keycode


def is_keymap_dir(keymap):
    """Return True if Path object `keymap` has a keymap file inside.
    """
    for file in ('keymap.c', 'keymap.json'):
        if (keymap / file).is_file():
            return True


def generate(keyboard, layout, layers):
    """Returns a keymap.c for the specified keyboard, layout, and layers.

    Args:
        keyboard
            The name of the keyboard

        layout
            The LAYOUT macro this keymap uses.

        layers
            An array of arrays describing the keymap. Each item in the inner array should be a string that is a valid QMK keycode.
    """
    layer_txt = []

    for layer_num, layer in enumerate(layers):
        if layer_num != 0:
            layer_txt[-1] = layer_txt[-1] + ','

        layer = map(_strip_any, layer)
        layer_keys = ', '.join(layer)
        layer_txt.append('\t[%s] = %s(%s)' % (layer_num, layout, layer_keys))

    keymap = '\n'.join(layer_txt)
    keymap_c = template(keyboard)

    return keymap_c.replace('__KEYMAP_GOES_HERE__', keymap)


def write(keyboard, keymap, layout, layers):
    """Generate the `keymap.c` and write it to disk.

    Returns the filename written to.

    Args:
        keyboard
            The name of the keyboard

        keymap
            The name of the keymap

        layout
            The LAYOUT macro this keymap uses.

        layers
            An array of arrays describing the keymap. Each item in the inner array should be a string that is a valid QMK keycode.
    """
    keymap_c = generate(keyboard, layout, layers)
    keymap_file = qmk.path.keymap(keyboard) / keymap / 'keymap.c'

    keymap_file.parent.mkdir(parents=True, exist_ok=True)
    keymap_file.write_text(keymap_c)

    cli.log.info('Wrote keymap to {fg_cyan}%s', keymap_file)

    return keymap_file


def locate_keymap(keyboard, keymap):
    """Returns the path to a keymap for a specific keyboard.
    """
    if not qmk.path.is_keyboard(keyboard):
        raise KeyError('Invalid keyboard: ' + repr(keyboard))

    # Check the keyboard folder first, last match wins
    checked_dirs = ''
    keymap_path = ''

    for dir in keyboard.split('/'):
        if checked_dirs:
            checked_dirs = '/'.join((checked_dirs, dir))
        else:
            checked_dirs = dir

        keymap_dir = Path('keyboards') / checked_dirs / 'keymaps'

        if (keymap_dir / keymap / 'keymap.c').exists():
            keymap_path = keymap_dir / keymap / 'keymap.c'
        if (keymap_dir / keymap / 'keymap.json').exists():
            keymap_path = keymap_dir / keymap / 'keymap.json'

    if keymap_path:
        return keymap_path

    # Check community layouts as a fallback
    rules = rules_mk(keyboard)

    if "LAYOUTS" in rules:
        for layout in rules["LAYOUTS"].split():
            community_layout = Path('layouts/community') / layout / keymap
            if community_layout.exists():
                if (community_layout / 'keymap.json').exists():
                    return community_layout / 'keymap.json'
                if (community_layout / 'keymap.c').exists():
                    return community_layout / 'keymap.c'


def list_keymaps(keyboard):
    """ List the available keymaps for a keyboard.

    Args:
        keyboard: the keyboards full name with vendor and revision if necessary, example: clueboard/66/rev3

    Returns:
        a set with the names of the available keymaps
    """
    # parse all the rules.mk files for the keyboard
    rules = rules_mk(keyboard)
    names = set()

    if rules:
        # qmk_firmware/keyboards
        keyboards_dir = Path('keyboards')
        # path to the keyboard's directory
        kb_path = keyboards_dir / keyboard
        # walk up the directory tree until keyboards_dir
        # and collect all directories' name with keymap.c file in it
        while kb_path != keyboards_dir:
            keymaps_dir = kb_path / "keymaps"
            if keymaps_dir.exists():
                names = names.union([keymap.name for keymap in keymaps_dir.iterdir() if is_keymap_dir(keymap)])
            kb_path = kb_path.parent

        # if community layouts are supported, get them
        if "LAYOUTS" in rules:
            for layout in rules["LAYOUTS"].split():
                cl_path = Path('layouts/community') / layout
                if cl_path.exists():
                    names = names.union([keymap.name for keymap in cl_path.iterdir() if is_keymap_dir(keymap)])

    return sorted(names)
