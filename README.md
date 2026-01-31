# Batch-Memory

Execute Windows batch scripts entirely from memory, without writing `.bat` files to disk!

## Overview

**Batch-Memory** is a simple C/C++ tool that allows you to execute Windows batch scripts directly from memory by streaming them into `cmd.exe` via standard input.

No temporary `.bat` files are created.  
No disk writes are performed.

This makes it ideal for tools that need clean execution, reduced disk artifacts, or a simple way to run large batch scripts programmatically.

## How It Works

Windows does not provide a native way to execute batch files directly from a memory buffer.  
Instead, batch scripts are interpreted by `cmd.exe`.

Batch-Memory works by:
1. Launching `cmd.exe`
2. Redirecting its standard input (STDIN)
3. Streaming the batch script text directly from memory
4. Exiting cleanly when execution finishes

From `cmd.exe`’s perspective, this behaves the same as running a `.bat` file — without ever creating one.

## Features

- ✅ Executes batch scripts fully from memory
- ✅ No `.bat` files written to disk
- ✅ Supports large scripts (1,000+ lines)
- ✅ Clean, single-function API
- ✅ Minimal WinAPI usage
- ✅ Easy to integrate into any C++ project
- ✅ Open-source and auditable

## Example Usage

### `main.cpp`
```cpp
#include "batch_exec.h"
#include "batch_script.h"

int main()
{
    BatMem(batchScript);
    return 0;
}
