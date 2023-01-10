LogDebugger
License: MIT

Use log file as a dump/core file to debug code. This can be easily to figure out which code line is related to the current log line, so we can easily debug issues.

log one line:
----------------------------------------------------------------                                                              
| 8 byte     time stamp                                                                                 |
----------------------------------------------------------------
| 16 byte   code path + source version (if enabled source version control)  |
----------------------------------------------------------------
| 8 byte    process id (if enabled procees control)                                        |
----------------------------------------------------------------
| 8 byte    thread id (if enabled thread control)                                            |
----------------------------------------------------------------
| * byte    content                                                                                         |
----------------------------------------------------------------


                                                            ^
                                                            ||
                                                            ||
                                                            ||
                                                            v

log db one line:
---------------------------------------------------------------- 
| 2 byte code position hash                                                                          |
---------------------------------------------------------------- 
| 16 byte code path                                                                                      |
---------------------------------------------------------------- 
| 16 byte source version                                                                               |
---------------------------------------------------------------- 


                                                            ^
                                                            ||
                                                            ||
                                                            ||
                                                            v

code:
---------------------------------------------------------------- 
| code position                                                                                             |
---------------------------------------------------------------- 


Process:
Write log:
code line -> make prefix -> make log line / make db file-> zip log line -> write log

Read log:
read log line -> unzip log line -> get prefix -> read db file -> jump to code line

In the future:
- make log prefix as a binary file to related to log lines
