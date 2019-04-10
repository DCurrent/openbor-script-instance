# DC Instance

Instancing control allows a library to keep several unique configurations at once in a given function. That way you won't need to clog up your functions constantly adjusting the library’s properties back and forth when you need more than one configuration. Just set up your desired configurations one time and then switch between instances as needed.

Prior to 2019-04-10, each of my OpenBOR script libraries had their own instance support functions. Instance support is now migrated to this library, and included by the other libraries for their internal use. To maintain simplicity and consistency, each library defines its own function macros to control instancing. See each library's config.h file for their indivdiual instance control functions.

By default, the active instance is 0. To create more, switch to a new active instance with an ID of your choice, and adjust the other configuration settings as preferred. Your new instance is ready to use.

## Dependencies

None

## Installation

1. Install any listed dependencies. See an individual dependency's readme for specific instructions.
1. Download and unzip the [latest release](../../releases).
1. Place the *dc_instance* folder into your *data/scripts* folder.
1. Add ```#include data/scripts/dc_instance/main.c``` into any other script you would like to add this library’s functionality to. If you are downloading as part of one of my other libraries, they already have this step completed.
1. (Optional) Open *config.h* to modify default values used in the library.

## Use Examples

Note these examples are for the [DC D20 Library](https://github.com/DCurrent/openbor-script-D20). Each library will have its own instance control macros. In most cases it's just the library name as a prefix. See each library's config.h file.

Get active instance ID.
```c
int i = dc_d20_get_instance();
```

Set (switch to) active instance, or create an instance with the supplied ID if one is not already present.
```c
int i = {int};

dc_d20_set_instance(i);
```

Free (destroy) the active instance. All variables are destroyed - meaning the library will now supply default values for any get operation. If not already, you are now at the default instance.
```c
dc_d20_free_instance();
```

Reset the active instance. Similar to Free, except the instance itself is maintained.
```c
dc_d20_reset_instance();
```

Dump the active instance. All variables for the active instance are sent to the log for debugging.
```c
dc_d20_reset_instance();
```
