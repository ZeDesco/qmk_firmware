"""QMK Python Hello World

This is an example QMK CLI script.
"""
from milc import cli


@cli.argument('-n', '--name', default='World', help='Name to greet.')
<<<<<<< HEAD
@cli.entrypoint('QMK Hello World.')
def main(cli):
=======
@cli.subcommand('QMK Hello World.', hidden=False if cli.config.user.developer else True)
def hello(cli):
>>>>>>> upstream/master
    """Log a friendly greeting.
    """
    cli.log.info('Hello, %s!', cli.config.general.name)
