"""Generate a keymap.c from a configurator export.
"""
<<<<<<< HEAD
import json
import os
import sys
=======
from pathlib import Path
>>>>>>> upstream/master

from milc import cli


<<<<<<< HEAD

@cli.argument('-o', '--output', help='File to write to')
@cli.argument('filename', help='Configurator JSON file')
@cli.entrypoint('Create a keymap.c from a QMK Configurator export.')
def main(cli):
    """Generate a keymap.c from a configurator export.

    This command uses the `qmk.keymap` module to generate a keymap.c from a configurator export. The generated keymap is written to stdout, or to a file if -o is provided.
    """
    # Error checking
    if cli.args.filename == ('-'):
        cli.log.error('Reading from STDIN is not (yet) supported.')
        cli.print_usage()
        exit(1)
    if not os.path.exists(qmk.path.normpath(cli.args.filename)):
        cli.log.error('JSON file does not exist!')
        cli.print_usage()
        exit(1)

    # Environment processing
    if cli.config.general.output == ('-'):
        cli.config.general.output = None

    # Parse the configurator json
    with open(qmk.path.normpath(cli.args.filename), 'r') as fd:
        user_keymap = json.load(fd)

    # Generate the keymap
    keymap_c = qmk.keymap.generate(user_keymap['keyboard'], user_keymap['layout'], user_keymap['layers'])

    if cli.config.general.output:
        output_dir = os.path.dirname(cli.config.general.output)

        if not os.path.exists(output_dir):
            os.makedirs(output_dir)

        output_file = qmk.path.normpath(cli.config.general.output)
        with open(output_file, 'w') as keymap_fd:
            keymap_fd.write(keymap_c)

        cli.log.info('Wrote keymap to %s.', cli.config.general.output)

    else:
        print(keymap_c)
=======
@cli.argument('-o', '--output', arg_only=True, type=Path, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.argument('filename', arg_only=True, help='Configurator JSON file')
@cli.subcommand('Creates a keymap.c from a QMK Configurator export.', hidden=True)
def json_keymap(cli):
    """Renamed to `qmk json2c`.
    """
    cli.log.error('This command has been renamed to `qmk json2c`.')
    exit(1)
>>>>>>> upstream/master
