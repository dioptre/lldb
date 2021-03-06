"""
Test that ValueObjectPrinter does not cause an infinite loop when a reference to a struct that contains a pointer to itself is printed.
"""

import os, time
import unittest2
import lldb
from lldbtest import *
import lldbutil

class DataFormatterRefPtrRecursionTestCase(TestBase):

    mydir = TestBase.compute_mydir(__file__)

    @skipUnlessDarwin
    @dsym_test
    def test_with_dsym_and_run_command(self):
        """Test that ValueObjectPrinter does not cause an infinite loop when a reference to a struct that contains a pointer to itself is printed."""
        self.buildDsym()
        self.data_formatter_commands()

    @dwarf_test
    def test_with_dwarf_and_run_command(self):
        """Test that ValueObjectPrinter does not cause an infinite loop when a reference to a struct that contains a pointer to itself is printed."""
        self.buildDwarf()
        self.data_formatter_commands()

    def setUp(self):
        # Call super's setUp().
        TestBase.setUp(self)
        # Find the line number to break at.
        self.line = line_number('main.cpp', '// Set break point at this line.')

    def data_formatter_commands(self):
        """Test that ValueObjectPrinter does not cause an infinite loop when a reference to a struct that contains a pointer to itself is printed."""
        self.runCmd("file a.out", CURRENT_EXECUTABLE_SET)

        lldbutil.run_break_set_by_file_and_line (self, "main.cpp", self.line, num_expected_locations=1, loc_exact=True)

        self.runCmd("run", RUN_SUCCEEDED)

        # The stop reason of the thread should be breakpoint.
        self.expect("thread list", STOPPED_DUE_TO_BREAKPOINT,
            substrs = ['stopped',
                       'stop reason = breakpoint'])

        self.expect("frame variable foo", substrs = []);
        self.expect("frame variable foo --ptr-depth=1", substrs = ['ID = 1']);
        self.expect("frame variable foo --ptr-depth=2", substrs = ['ID = 1']);
        self.expect("frame variable foo --ptr-depth=3", substrs = ['ID = 1']);

if __name__ == '__main__':
    import atexit
    lldb.SBDebugger.Initialize()
    atexit.register(lambda: lldb.SBDebugger.Terminate())
    unittest2.main()
