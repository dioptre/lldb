//===-- SystemRuntime.h -----------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef liblldb_SystemRuntime_h_
#define liblldb_SystemRuntime_h_

// C Includes
// C++ Includes
// Other libraries and framework includes
// Project includes
#include "lldb/lldb-public.h"
#include "lldb/Core/ModuleList.h"
#include "lldb/Core/PluginInterface.h"
#include "lldb/lldb-private.h"


namespace lldb_private {

//----------------------------------------------------------------------
/// @class SystemRuntime SystemRuntime.h "lldb/Target/SystemRuntime.h"
/// @brief A plug-in interface definition class for system runtimes.
///
/// The system runtime plugins can collect information from the system
/// libraries during a Process' lifetime and provide information about
/// how objects/threads were originated.
///
/// For instance, a system runtime plugin use a breakpoint when threads
/// are created to record the backtrace of where that thread was created.
/// Later, when backtracing the created thread, it could extend the backtrace
/// to show where it was originally created from.  
///
/// The plugin will insert its own breakpoint when Created and start collecting
/// information.  Later when it comes time to augment a Thread, it can be
/// asked to provide that information.
///
//----------------------------------------------------------------------

class SystemRuntime :
    public PluginInterface
{
public:
    //------------------------------------------------------------------
    /// Find a system runtime plugin for a given process.
    ///
    /// Scans the installed SystemRuntime plugins and tries to find
    /// an instance that can be used to track image changes in \a
    /// process.
    ///
    /// @param[in] process
    ///     The process for which to try and locate a system runtime
    ///     plugin instance.
    //------------------------------------------------------------------
    static SystemRuntime* 
    FindPlugin (Process *process);

    //------------------------------------------------------------------
    /// Construct with a process.
    // -----------------------------------------------------------------
    SystemRuntime(lldb_private::Process *process);

    //------------------------------------------------------------------
    /// Destructor.
    ///
    /// The destructor is virtual since this class is designed to be
    /// inherited by the plug-in instance.
    //------------------------------------------------------------------
    virtual
    ~SystemRuntime();

    //------------------------------------------------------------------
    /// Called after attaching to a process.
    ///
    /// Allow the SystemRuntime plugin to execute some code after attaching
    /// to a process. 
    //------------------------------------------------------------------
    virtual void
    DidAttach ();

    //------------------------------------------------------------------
    /// Called after launching a process.
    ///
    /// Allow the SystemRuntime plugin to execute some code after launching
    /// a process. 
    //------------------------------------------------------------------
    virtual void
    DidLaunch();

    //------------------------------------------------------------------
    /// Called when modules have been loaded in the process.
    ///
    /// Allow the SystemRuntime plugin to enable logging features in the
    /// system runtime libraries.
    //------------------------------------------------------------------
    virtual void
    ModulesDidLoad(lldb_private::ModuleList &module_list);

    //------------------------------------------------------------------
    /// Call this method to print the backtrace of where this thread was
    /// enqueued, if at all.  Returns the number of frames printed.
    //------------------------------------------------------------------
    virtual uint32_t
    GetStatus (lldb_private::Stream &strm, lldb_private::ExecutionContext &exe_ctx);

protected:
    //------------------------------------------------------------------
    // Member variables.
    //------------------------------------------------------------------
    Process *m_process;
private:
    DISALLOW_COPY_AND_ASSIGN (SystemRuntime);
};

} // namespace lldb_private

#endif  // liblldb_SystemRuntime_h_
