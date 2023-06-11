# We all had to start somewhere...

In this week's episode of "stuff you find when looking around old hard drives"...

This repository contains the source code of the end-of-semester project written
as a part of my university course work. Most of the original files' timestamps
point to May/June 2009, which makes sense as "Object Programming" was one of the
courses I was attending back then.

Looking through this was a very humbling experience. It obviously has no
technical significance, but it gives an insight into what very junior developers
can do when given a task to solve and a very vague idea about the language and
environment they're using. At the same time, the developer's primary mission is
not to fail.

I don't seem to have archived the actual description of the assignment, but it
seems like the task was to create some sort of database-ish kind of thing that
can read and save its state to a file. MFC and Visual Studio 2008 was the
standard environment during the course so that's why it was used here too.

The sources come with a plethora of WTFs :
 * Hand-rolled implementation of a linked list that uses a `static` pointer to
   its beginning and a `static` counter to hold its length.
 * The database file format uses ASCII-encoded bytes, i.e. the byte `0xF0`
   is stored as literal `"240 "` in the file, occupying, well, four bytes.
 * I apparently couldn't figure out how to use `wchar_t` and what all those `W`
   classes and functions are for, so `_UNICODE` is not defined and the project
   uses "ANSI strings" everywhere.
 * As a consequence of that, the ACP is implicitly assumed to be Windows-1250
   because that's the one I was running. The source files are in this code page
   as well.
 * (Most) class and variable names as well as error messages are in Polish.
 * You need the object's index to access it. In a linked list!
 * "Obvious" things like large objects being passed by value and total lack of
   RAII are just cherries on top.

I'd like to think that I've come a long way since then.
