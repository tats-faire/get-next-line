# get-next-line

A small program that returns one line at a time from a file descriptor. Thanks to a static char variable, it bookmarks where it has stopped. It can "remember" multiple (up to 4096) file descriptors without mixing them up.
