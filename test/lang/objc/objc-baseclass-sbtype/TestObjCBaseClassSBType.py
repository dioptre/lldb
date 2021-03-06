"""
Use lldb Python API to test base class resolution for ObjC classes
"""

import os, time
import re
import unittest2
import lldb, lldbutil
from lldbtest import *

class ObjCDynamicValueTestCase(TestBase):

    mydir = TestBase.compute_mydir(__file__)

    @skipUnlessDarwin
    @python_api_test
    @dsym_test
    def test_get_baseclass_with_dsym(self):
        """Test fetching ObjC base class info."""
        if self.getArchitecture() == 'i386':
            # rdar://problem/9946499
            self.skipTest("Dynamic types for ObjC V1 runtime not implemented")
        self.buildDsym()
        self.do_get_baseclass_info()

    @skipUnlessDarwin
    @python_api_test
    @dwarf_test
    def test_get_baseclass_with_dwarf(self):
        """Test fetching ObjC dynamic values."""
        if self.getArchitecture() == 'i386':
            # rdar://problem/9946499
            self.skipTest("Dynamic types for ObjC V1 runtime not implemented")
        self.buildDwarf()
        self.do_get_baseclass_info()

    def setUp(self):
        # Call super's setUp().                                                                                                           
        TestBase.setUp(self)

        self.line = line_number('main.m', '// Set breakpoint here.')

    def do_get_baseclass_info(self):
        """Make sure we get dynamic values correctly both for compiled in classes and dynamic ones"""
        exe = os.path.join(os.getcwd(), "a.out")

        # Create a target from the debugger.

        target = self.dbg.CreateTarget (exe)
        self.assertTrue(target, VALID_TARGET)

        # Set up our breakpoints:

        target.BreakpointCreateByLocation('main.m', self.line)
        process = target.LaunchSimple (None, None, self.get_process_working_directory())

        self.assertTrue(process.GetState() == lldb.eStateStopped,
                        PROCESS_STOPPED)

        var = self.frame().FindVariable("foo")
        var_ptr_type = var.GetType()
        var_pte_type = var_ptr_type.GetPointeeType()
        self.assertTrue(var_ptr_type.GetNumberOfDirectBaseClasses() == 1, "Foo * has one base class")
        self.assertTrue(var_pte_type.GetNumberOfDirectBaseClasses() == 1, "Foo has one base class")

        self.assertTrue(var_ptr_type.GetDirectBaseClassAtIndex(0).IsValid(), "Foo * has a valid base class")
        self.assertTrue(var_pte_type.GetDirectBaseClassAtIndex(0).IsValid(), "Foo * has a valid base class")

        self.assertTrue(var_ptr_type.GetDirectBaseClassAtIndex(0).GetName() == var_pte_type.GetDirectBaseClassAtIndex(0).GetName(), "Foo and its pointer type don't agree on their base class")

if __name__ == '__main__':
    import atexit
    lldb.SBDebugger.Initialize()
    atexit.register(lambda: lldb.SBDebugger.Terminate())
    unittest2.main()
