import os
import lldbtest

from builder_base import *

#print "Hello, darwin plugin!"

def buildDsym(sender=None, architecture=None, compiler=None, dictionary=None, clean=True):
    """Build the binaries with dsym debug info."""
    commands = []

    if clean:
        commands.append(["make", "clean", getCmdLine(dictionary)])
    commands.append(["make", "MAKE_DSYM=YES", getArchSpec(architecture), getCCSpec(compiler), getCmdLine(dictionary)])

    lldbtest.system(commands, sender=sender)

    # True signifies that we can handle building dsym.
    return True
